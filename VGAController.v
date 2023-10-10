// Charles McHenry
// VGA Controller for 640 x 480 @72 Hz
//
// Credits to Juan Manuel Rico's vga-clock
// https://github.com/mattvenn/vga-clock/tree/master

module Vgacontroller (
	input wire pix_clk,
	input wire reset,
	output wire hsync,
	output wire vsync,
	output reg x_pix [9:0],
	output reg y_pix [9:0],
	output wire inDisplay
	);
//Values below can be changed to accomodate for different screen resolutions
parameter activeHvideo = 640;
parameter activeVvideo = 480;
parameter hfp = 24;
parameter hsyncpulse = 40;
parameter hbp = 128;
parameter vfp = 9;
parameter vsyncpulse = 2;
parameter vbp = 520;

parameter htotal = activeHvideo + hfp + hsyncpulse + hbp;
parameter vtotal = activeVvideo + hfp + hsyncpulse + hbp;

reg hcount[9:0];
reg vcount[9:0];

always@(posedge pix_clk)
begin
	if (reset) begin
		hcount <= 0;
		vcount <= 0;
	end else begin
		if (hcount < htotal - 1)
			hcount <= hcount + 1;
		else
		begin
			hc <= 0;sync
			if (vc < vlines - 1) 
				vc <= vc + 1;
			else
				vc <= 0;
		end
	end
end

assign hsync = ~((hcount >= (activeHvideo + hfp)) && (hcount < (activeHvideo + hfp + hsyncpulse)));
assign vsync = ~((vcount >= (activeVvideo + vfp)) && (vcount < (activeVvideo + vfp + vsyncpulse)));
assign inDisplay = (hcount < activeHvideo && vcount < activeVvideo);

endmodule
