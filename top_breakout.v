module top_breakout (
	input wire pix_clk,
	input wire reset,
	input wire btn_left,
	input wire btn_right,
	output wire hsync,
	output wire vsync,
	output reg [9:0] sdl_x,
	output reg [9:0] sdl_y,
	output reg sdl_de,
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

//ball properties
localparam Q_SIZE = 10;
wire q; //used in drawing to see if the pixel currently on is a a ball pixel
reg [9:0] qx, qy; // position, evaluated at top left of the pixel
reg qdx;
reg qdy; // direction (0 = right/down, 1 = left/up)
reg [9:0] qs = 5;
//paddle properties
wire pdl; //used in drawing to see if the pixel currently on is a paddle pixel
reg[9:0] pdl_l, pdl_r; //left and right edges of paddle
reg [9:0] pdl_s = 4;
localparam PDL_SIZE = 50;
localparam PDL_HEIGHT = 10;
assign pdl_r = pdl_l + PDL_SIZE;

// states
localparam RESET = 2'b00;
localparam START = 2'b01;
localparam PLAY = 2'b10;
// localparam END;  // will implement this behavior later. for now, need a sim
reg [1:0] curr_state, next_state;

always@* begin // if failing, maybe try changing this to @(posedge)
	case (curr_state)
		RESET: next_state = START;
		START: next_state = PLAY;
		PLAY: next_state = PLAY;
		2'b11: next_state = RESET;
	endcase
end

always@(posedge pix_clk) begin
	curr_state <= next_state;
end

//paddle control
always@(posedge pix_clk) begin
	if (curr_state == START) 
		pdl_l <= (H_RES - PDL_SIZE)/2;
	else if (frame && curr_state == RESET) begin
		if (btn_left) begin
			if (pdl_l < pdl_s) begin
				pdl_l <= 0;
			end else 
				pdl_l <= pdl_l - pdl_s;
		end else if (btn_right) begin
			if (pdl_r + pdl_s >= H_RES - 1) begin
				pdl_l <= H_RES - PDL_SIZE - 1;
			end else
				pdl_l <= pdl_l + pdl_s;
		end
	end
end

//ball control
always@(posedge pix_clk) begin
	if (curr_state == START) begin
			qx <= (H_RES - PDL_SIZE)/2;
			qy <= V_RES - PDL_HEIGHT - 2;
			qdx <= 0;
			qdy <= 1;
	end
	if (frame && curr_state == PLAY) begin
		// evaluate horizontal
		if (qdx == 0) begin
			if (qx + Q_SIZE + qs >= H_RES - 1) begin // hitting right of screen?
				qx <= H_RES - Q_SIZE - 1;
				qdx <= 1;
			end else 
				qx <= qx + qs; // otherwise, move right
		end else begin
			if (qx < qs) begin // hitting left of screen?
				qx <= 0;
				qdx <= 0;
			end else
				qx <= qx - qs; // otherwise, move left
		end

		// evaluate vertical
		if (qdy == 0) begin
			if (qy + Q_SIZE + qs >= V_RES - 1) begin // hitting bottom of screen?
				qy <= V_RES - Q_SIZE - 1;
				qdy <= 1;
			end else 
				qy <= qy + qs;
		end else begin
			if (qy < qs) begin  // hitting top of screen?
				qy <= 0;
				qdy <= 0;
			end else 
				qy <= qy - qs;
		end
	end
end

assign q = (x_pix >= qx) && (x_pix < qx + Q_SIZE) && (y_pix >= qy) && (y_pix < qy + Q_SIZE);
assign pdl = (x_pix >= pdl_l) && (x_pix < pdl_r) && (y_pix >= V_RES - PDL_HEIGHT);

reg[3:0] paint_r;
reg[3:0] paint_g;
reg[3:0] paint_b;
always@(*) begin
	if (q) begin
		{paint_r, paint_g, paint_b} = 12'hFFF;
	end else if (pdl) begin
		{paint_r, paint_g, paint_b} = 12'hF9F;
	end else
		{paint_r, paint_g, paint_b} = 12'h137;
end

always@(posedge pix_clk) begin
	sdl_x <= x_pix;
	sdl_y <= y_pix;
	sdl_de <= de;
	sdl_r <= {2{paint_r}};
	sdl_g <= {2{paint_g}};
	sdl_b <= {2{paint_b}};
end

endmodule
