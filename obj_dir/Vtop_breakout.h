// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_BREAKOUT_H_
#define _VTOP_BREAKOUT_H_  // guard

#include "verilated.h"

//==========

class Vtop_breakout__Syms;

//----------

VL_MODULE(Vtop_breakout) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(pix_clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(btn_left,0,0);
    VL_IN8(btn_right,0,0);
    VL_OUT8(hsync,0,0);
    VL_OUT8(vsync,0,0);
    VL_OUT8(sdl_de,0,0);
    VL_OUT8(sdl_r,7,0);
    VL_OUT8(sdl_g,7,0);
    VL_OUT8(sdl_b,7,0);
    VL_OUT16(sdl_x,9,0);
    VL_OUT16(sdl_y,9,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top_breakout__DOT__frame;
    CData/*0:0*/ top_breakout__DOT__q;
    CData/*0:0*/ top_breakout__DOT__qdx;
    CData/*0:0*/ top_breakout__DOT__qdy;
    CData/*0:0*/ top_breakout__DOT__pdl;
    CData/*1:0*/ top_breakout__DOT__curr_state;
    CData/*1:0*/ top_breakout__DOT__next_state;
    CData/*3:0*/ top_breakout__DOT__paint_r;
    CData/*3:0*/ top_breakout__DOT__paint_g;
    CData/*3:0*/ top_breakout__DOT__paint_b;
    SData/*9:0*/ top_breakout__DOT__x_pix;
    SData/*9:0*/ top_breakout__DOT__y_pix;
    SData/*9:0*/ top_breakout__DOT__qx;
    SData/*9:0*/ top_breakout__DOT__qy;
    SData/*9:0*/ top_breakout__DOT__pdl_l;
    SData/*9:0*/ top_breakout__DOT__pdl_r;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__pix_clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop_breakout__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_breakout);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop_breakout(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop_breakout();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop_breakout__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop_breakout__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop_breakout__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop_breakout__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop_breakout__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop_breakout__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop_breakout__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtop_breakout__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop_breakout__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
