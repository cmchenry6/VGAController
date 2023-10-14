module top_square (
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

reg square;
assign square = (x_pix > 220 && x_pix < 420) && (y_pix > 200 && y_pix < 300);

reg[3:0] paint_r;
reg[3:0] paint_g;
reg[3:0] paint_b;

assign paint_r = (square) ? 4'hF : 4'h1;
assign paint_g = (square) ? 4'hF : 4'h3;
assign paint_b = (square) ? 4'hF : 4'h7;

always@(posedge pix_clk) begin
	sdl_x <= x_pix;
	sdl_y <= y_pix;
	sdl_de <= de;
	sdl_r <= {2{paint_r}};
	sdl_g <= {2{paint_g}};
	sdl_b <= {2{paint_b}};
end

endmodule
