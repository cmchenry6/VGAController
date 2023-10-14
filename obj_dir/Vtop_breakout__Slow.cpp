// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_breakout.h for the primary calling header

#include "Vtop_breakout.h"
#include "Vtop_breakout__Syms.h"

//==========

VL_CTOR_IMP(Vtop_breakout) {
    Vtop_breakout__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_breakout__Syms(this, name());
    Vtop_breakout* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_breakout::__Vconfigure(Vtop_breakout__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop_breakout::~Vtop_breakout() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop_breakout::_settle__TOP__2(Vtop_breakout__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_breakout::_settle__TOP__2\n"); );
    Vtop_breakout* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_breakout__DOT__pdl_r = (0x3ffU & ((IData)(0x32U) 
                                                  + (IData)(vlTOPp->top_breakout__DOT__pdl_l)));
    vlTOPp->hsync = (1U & (~ ((0x298U <= (IData)(vlTOPp->top_breakout__DOT__x_pix)) 
                              & (0x2c0U > (IData)(vlTOPp->top_breakout__DOT__x_pix)))));
    vlTOPp->vsync = (1U & (~ ((0x1e9U <= (IData)(vlTOPp->top_breakout__DOT__y_pix)) 
                              & (0x1ebU > (IData)(vlTOPp->top_breakout__DOT__y_pix)))));
    vlTOPp->top_breakout__DOT__frame = ((0x1e0U == (IData)(vlTOPp->top_breakout__DOT__y_pix)) 
                                        & (0U == (IData)(vlTOPp->top_breakout__DOT__x_pix)));
    vlTOPp->top_breakout__DOT__pdl = ((((IData)(vlTOPp->top_breakout__DOT__x_pix) 
                                        >= (IData)(vlTOPp->top_breakout__DOT__pdl_l)) 
                                       & ((IData)(vlTOPp->top_breakout__DOT__x_pix) 
                                          < (0x3ffU 
                                             & ((IData)(0x32U) 
                                                + (IData)(vlTOPp->top_breakout__DOT__pdl_l))))) 
                                      & (0x1d6U <= (IData)(vlTOPp->top_breakout__DOT__y_pix)));
    vlTOPp->top_breakout__DOT__q = (((((IData)(vlTOPp->top_breakout__DOT__x_pix) 
                                       >= (IData)(vlTOPp->top_breakout__DOT__qx)) 
                                      & ((IData)(vlTOPp->top_breakout__DOT__x_pix) 
                                         < ((IData)(0xaU) 
                                            + (IData)(vlTOPp->top_breakout__DOT__qx)))) 
                                     & ((IData)(vlTOPp->top_breakout__DOT__y_pix) 
                                        >= (IData)(vlTOPp->top_breakout__DOT__qy))) 
                                    & ((IData)(vlTOPp->top_breakout__DOT__y_pix) 
                                       < ((IData)(0xaU) 
                                          + (IData)(vlTOPp->top_breakout__DOT__qy))));
    vlTOPp->top_breakout__DOT__next_state = ((2U & (IData)(vlTOPp->top_breakout__DOT__curr_state))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->top_breakout__DOT__curr_state))
                                                  ? 0U
                                                  : 2U)
                                              : ((1U 
                                                  & (IData)(vlTOPp->top_breakout__DOT__curr_state))
                                                  ? 2U
                                                  : 1U));
    if (vlTOPp->top_breakout__DOT__q) {
        vlTOPp->top_breakout__DOT__paint_r = 0xfU;
        vlTOPp->top_breakout__DOT__paint_g = 0xfU;
        vlTOPp->top_breakout__DOT__paint_b = 0xfU;
    } else {
        vlTOPp->top_breakout__DOT__paint_r = ((IData)(vlTOPp->top_breakout__DOT__pdl)
                                               ? 0xfU
                                               : 1U);
        vlTOPp->top_breakout__DOT__paint_g = ((IData)(vlTOPp->top_breakout__DOT__pdl)
                                               ? 9U
                                               : 3U);
        vlTOPp->top_breakout__DOT__paint_b = ((IData)(vlTOPp->top_breakout__DOT__pdl)
                                               ? 0xfU
                                               : 7U);
    }
}

void Vtop_breakout::_eval_initial(Vtop_breakout__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_breakout::_eval_initial\n"); );
    Vtop_breakout* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__pix_clk = vlTOPp->pix_clk;
}

void Vtop_breakout::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_breakout::final\n"); );
    // Variables
    Vtop_breakout__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_breakout* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_breakout::_eval_settle(Vtop_breakout__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_breakout::_eval_settle\n"); );
    Vtop_breakout* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtop_breakout::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_breakout::_ctor_var_reset\n"); );
    // Body
    pix_clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    btn_left = VL_RAND_RESET_I(1);
    btn_right = VL_RAND_RESET_I(1);
    hsync = VL_RAND_RESET_I(1);
    vsync = VL_RAND_RESET_I(1);
    sdl_x = VL_RAND_RESET_I(10);
    sdl_y = VL_RAND_RESET_I(10);
    sdl_de = VL_RAND_RESET_I(1);
    sdl_r = VL_RAND_RESET_I(8);
    sdl_g = VL_RAND_RESET_I(8);
    sdl_b = VL_RAND_RESET_I(8);
    top_breakout__DOT__x_pix = VL_RAND_RESET_I(10);
    top_breakout__DOT__y_pix = VL_RAND_RESET_I(10);
    top_breakout__DOT__frame = VL_RAND_RESET_I(1);
    top_breakout__DOT__q = VL_RAND_RESET_I(1);
    top_breakout__DOT__qx = VL_RAND_RESET_I(10);
    top_breakout__DOT__qy = VL_RAND_RESET_I(10);
    top_breakout__DOT__qdx = VL_RAND_RESET_I(1);
    top_breakout__DOT__qdy = VL_RAND_RESET_I(1);
    top_breakout__DOT__pdl = VL_RAND_RESET_I(1);
    top_breakout__DOT__pdl_l = VL_RAND_RESET_I(10);
    top_breakout__DOT__pdl_r = VL_RAND_RESET_I(10);
    top_breakout__DOT__curr_state = VL_RAND_RESET_I(2);
    top_breakout__DOT__next_state = VL_RAND_RESET_I(2);
    top_breakout__DOT__paint_r = VL_RAND_RESET_I(4);
    top_breakout__DOT__paint_g = VL_RAND_RESET_I(4);
    top_breakout__DOT__paint_b = VL_RAND_RESET_I(4);
}
