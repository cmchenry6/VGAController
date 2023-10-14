module top_bounce (
	input wire pix_clk,
	input wire reset,
	output wire hsync,
	output wire vsync,
	output reg sdl_de,
	output reg [9:0] sdl_x,
	output reg [9:0] sdl_y,
	output reg [7:0] sdl_r,
	output reg [7:0] sdl_g,
	output reg [7:0] sdl_b
	);

reg [9:0] x_pix;
reg [9:0] y_pix;
wire de;

VGAController vga_con ( .pix_clk(pix_clk),
       			.reset(reset),
		       	.hsync(hsync),
		       	.vsync(vsync),
		       	.hcount(x_pix),
		       	.vcount(y_pix),
		       	.de(de)
		);
localparam H_RES = 640;
localparam V_RES = 480;

reg frame;
assign frame = (y_pix == V_RES && x_pix == 0); // assigns frame high at the start of vertical blanking
reg [3:0] Q_R = 4'hF;
reg [3:0] Q_G = 4'hF;
reg [3:0] Q_B = 4'hF;
localparam Q_SIZE = 10;
reg [9:0] qx, qy; // position, evaluated at top left of the pixel
reg qdx, qdy; // direction (0 = right/down, 1 = left/up)
reg [9:0] qs = 5;


always@(posedge pix_clk) begin
	if (frame) begin
		// evaluate horizontal
		if (qdx == 0) begin
			if (qx + Q_SIZE + qs >= H_RES - 1) begin // hitting right of screen?
				qx <= H_RES - Q_SIZE - 1;
				qdx <= 1;
				Q_R = 4'hF;
				Q_G = 4'h0;
				Q_B = 4'hF;
			end else 
				qx <= qx + qs; // otherwise, move right
		end else begin
		        if (qx < qs) begin // hitting left of screen?
				qx <= 0;
		 		qdx <= 0;
				Q_R = 4'hF;
				Q_G = 4'hF;
				Q_B = 4'h0;
		     	end else
			       	qx <= qx - qs; // otherwise, move left
		end

		// evaluate vertical
		if (qdy == 0) begin
			if (qy + Q_SIZE + qs >= V_RES - 1) begin // hitting bottom of screen?
				qy <= V_RES - Q_SIZE - 1;
				qdy <= 1;
				Q_R = 4'h0;
				Q_G = 4'hF;
				Q_B = 4'hF;
			end else 
				qy <= qy + qs;
		end else begin
			if (qy < qs) begin  // hitting top of screen?
				qy <= 0;
				qdy <= 0;
				Q_R = 4'hF;
				Q_G = 4'h0;
				Q_B = 4'h0;
			end else 
				qy <= qy - qs;
		end
	end
end

reg pixel;
assign pixel = (x_pix >= qx) && (x_pix < qx + Q_SIZE) && (y_pix >= qy) && (y_pix < qy + Q_SIZE);

reg[3:0] paint_r;
reg[3:0] paint_g;
reg[3:0] paint_b;

assign paint_r = (pixel) ? Q_R : 4'h1;
assign paint_g = (pixel) ? Q_G : 4'h3;
assign paint_b = (pixel) ? Q_B : 4'h7;

always@(posedge pix_clk) begin
	sdl_x <= x_pix;
	sdl_y <= y_pix;
	sdl_de <= de;
	sdl_r <= {2{paint_r}};
	sdl_g <= {2{paint_g}};
	sdl_b <= {2{paint_b}};
end

endmodule
