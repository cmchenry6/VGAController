module top_breakout (
	input wire pix_clk,
	input wire reset,
	input wire btn_left,
	input wire btn_right,
	output wire hsync,
	output wire vsync,
	output wire [9:0] sdl_x,
	output wire [9:0] sdl_y,
	output wire sdl_de,
	output wire [7:0] sdl_r,
	output wire [7:0] sdl_g,
	output wire [7:0] sdl_b
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
reg [9:0] pdl_l, pdl_r; //left and right edges of paddle
reg [9:0] pdl_s = 6;
localparam PDL_SIZE = 80;
localparam PDL_HEIGHT = 10;
assign pdl_r = pdl_l + PDL_SIZE;

// blocks properties
localparam BLOCK_SIZE = 90;
localparam BLOCK_HEIGHT = 15;
typedef struct packed {
	reg [9:0] bx, by;
	reg [11:0] color;
	reg aliven; // alive, active low
} block;
//Top row
wire row1en;
block row1 [4:0];
localparam ROW1_COLOR = 12'hFF0; // yellow
localparam ROW1_Y = 60;
initial begin
row1[0].bx = 30; row1[0].by = ROW1_Y; row1[0].color = ROW1_COLOR;
row1[1].bx = row1[0].bx + BLOCK_SIZE + 30; row1[1].by = ROW1_Y; row1[1].color = ROW1_COLOR;
row1[2].bx = row1[1].bx + BLOCK_SIZE + 30; row1[2].by = ROW1_Y; row1[2].color = ROW1_COLOR;
row1[3].bx = row1[2].bx + BLOCK_SIZE + 30; row1[3].by = ROW1_Y; row1[3].color = ROW1_COLOR;
row1[4].bx = row1[3].bx + BLOCK_SIZE + 30; row1[4].by = ROW1_Y; row1[4].color = ROW1_COLOR;
end

// states
typedef enum {RESET, START, PLAY} t_state;
t_state state;
// localparam END;  // will implement this behavior later. for now, need a sim

always@(posedge pix_clk) begin 
	case (state)
		RESET: state = START;
		START: state = (btn_left || btn_right) ? PLAY : START;
		PLAY: state = (reset) ? RESET : PLAY;
	endcase
end


//paddle control
always@(posedge pix_clk) begin
	if (state == START) 
		pdl_l <= (H_RES - PDL_SIZE)/2;
	else if (frame && state == PLAY) begin
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

	if (state == START) begin
			qx <= (H_RES/2) - (Q_SIZE/2);
			qy <= V_RES - PDL_HEIGHT - Q_SIZE;
			qdx <= 1;
			qdy <= 1;
	end

	if (frame && (state == PLAY)) begin
		if (qdy == 0) begin // evaluate vertical(moving down)
			integer k;
			for (k = 0; k < 5; k = k + 1) begin
				if (~row1[k].aliven) begin
					if ((qy >= ROW1_Y - Q_SIZE) && (qy < ROW1_Y + BLOCK_HEIGHT) 
					     && (qx >= row1[k].bx) && (qx < row1[k].bx + BLOCK_SIZE)) begin
						qy <= 0; 
						qdy <= 1;
						row1[k].aliven <= 1;
					end
				end
			end

			if ((qy + Q_SIZE + qs >= V_RES - PDL_HEIGHT - 1) // colliding with paddle? 
			      && (qx >= pdl_l && qx <= pdl_r)) begin
				qy <= V_RES - PDL_HEIGHT - Q_SIZE;
				qdy <= 1;
				if (qdx) begin
					qdx <= (qx >= pdl_l && qx < (pdl_l + (PDL_SIZE)/2) ) ? 1 : 0;
				end else begin
					qdx <= (qx >= (pdl_l + PDL_SIZE/2) && qx <= pdl_r) ? 0 : 1;
				end

			end else if (qy + Q_SIZE + qs >= V_RES - 1) begin // hitting bottom of screen?
				state = RESET;
			end else 
				qy <= qy + qs;
		end else begin // evaluate vertical(moving up)
			integer j;
			for (j = 0; j < 5; j = j + 1) begin
				if (~row1[j].aliven) begin
					if ((qy <= ROW1_Y + BLOCK_HEIGHT) && (qy > ROW1_Y) 
					     && (qx >= row1[j].bx) && (qx < row1[j].bx + BLOCK_SIZE)) begin
						qy <= row1[j].by + BLOCK_HEIGHT;
						qdy <= 0;
						row1[j].aliven <= 1;
					end
				end
			end
						
			if (qy < qs) begin  // hitting top of screen?
				qy <= 0;
				qdy <= 0;
			end else 
				qy <= qy - qs;
		end


		if (qdx == 0) begin // evaluate horizontal
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


	end
end

assign q = (x_pix >= qx) && (x_pix < qx + Q_SIZE) && (y_pix >= qy) && (y_pix < qy + Q_SIZE);
assign pdl = (x_pix >= pdl_l) && (x_pix < pdl_r) && (y_pix >= V_RES - PDL_HEIGHT);
// assign row1en = (((x_pix >= row1[0].bx) && (x_pix < row1[0].bx + BLOCK_SIZE)) || ((x_pix >= row1[1].bx) && (x_pix < row1[1].bx + BLOCK_SIZE)) || ((x_pix >= row1[2].bx) && (x_pix < row1[2].bx + BLOCK_SIZE)) || ((x_pix >= row1[3].bx) && (x_pix < row1[3].bx + BLOCK_SIZE)) || ((x_pix >= row1[4].bx) && (x_pix < row1[4].bx + BLOCK_SIZE))) && (y_pix >= row1[0].by) && (y_pix < row1[0].by + BLOCK_HEIGHT);
assign row1en = ((x_pix >= row1[0].bx) && (x_pix < row1[4].bx + BLOCK_SIZE) && (y_pix >= ROW1_Y) && (y_pix < ROW1_Y + BLOCK_HEIGHT));

reg[3:0] paint_r;
reg[3:0] paint_g;
reg[3:0] paint_b;

always@(*) begin
	if (q) begin
		{paint_r, paint_g, paint_b} = 12'hFFF;
	end else if (pdl) begin
		{paint_r, paint_g, paint_b} = 12'hF9F;
	end else if (row1en) begin		
		integer i;
		for (i = 0; i < 5; i = i + 1) begin
			if ((x_pix >= row1[i].bx) && (x_pix < (row1[i].bx + BLOCK_SIZE))) begin
				{paint_r, paint_g, paint_b} = (row1[i].aliven == 0) ? ROW1_COLOR : 12'h137;
				break;
			end else
				{paint_r, paint_g, paint_b} = 12'h137;
		end		
	end else
		{paint_r, paint_g, paint_b} = 12'h137;
end

	assign sdl_x = x_pix;
	assign sdl_y = y_pix;
	assign sdl_de = de;
	assign sdl_r = {2{paint_r}};
	assign sdl_g = {2{paint_g}};
	assign sdl_b = {2{paint_b}};

endmodule
