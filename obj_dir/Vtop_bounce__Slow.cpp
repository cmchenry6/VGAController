// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_bounce.h for the primary calling header

#include "Vtop_bounce.h"
#include "Vtop_bounce__Syms.h"

//==========

VL_CTOR_IMP(Vtop_bounce) {
    Vtop_bounce__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_bounce__Syms(this, name());
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_bounce::__Vconfigure(Vtop_bounce__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop_bounce::~Vtop_bounce() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop_bounce::_initial__TOP__2(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_initial__TOP__2\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_bounce__DOT__Q_R = 0xfU;
    vlTOPp->top_bounce__DOT__Q_G = 0xfU;
    vlTOPp->top_bounce__DOT__Q_B = 0xfU;
}

void Vtop_bounce::_settle__TOP__3(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_settle__TOP__3\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->hsync = (1U & (~ ((0x298U <= (IData)(vlTOPp->top_bounce__DOT__x_pix)) 
                              & (0x2c0U > (IData)(vlTOPp->top_bounce__DOT__x_pix)))));
    vlTOPp->vsync = (1U & (~ ((0x1e9U <= (IData)(vlTOPp->top_bounce__DOT__y_pix)) 
                              & (0x1ebU > (IData)(vlTOPp->top_bounce__DOT__y_pix)))));
    vlTOPp->top_bounce__DOT__pixel = (((((IData)(vlTOPp->top_bounce__DOT__x_pix) 
                                         >= (IData)(vlTOPp->top_bounce__DOT__qx)) 
                                        & ((IData)(vlTOPp->top_bounce__DOT__x_pix) 
                                           < ((IData)(0xaU) 
                                              + (IData)(vlTOPp->top_bounce__DOT__qx)))) 
                                       & ((IData)(vlTOPp->top_bounce__DOT__y_pix) 
                                          >= (IData)(vlTOPp->top_bounce__DOT__qy))) 
                                      & ((IData)(vlTOPp->top_bounce__DOT__y_pix) 
                                         < ((IData)(0xaU) 
                                            + (IData)(vlTOPp->top_bounce__DOT__qy))));
}

void Vtop_bounce::_eval_initial(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_eval_initial\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__pix_clk = vlTOPp->pix_clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vtop_bounce::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::final\n"); );
    // Variables
    Vtop_bounce__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_bounce::_eval_settle(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_eval_settle\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vtop_bounce::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_ctor_var_reset\n"); );
    // Body
    pix_clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    hsync = VL_RAND_RESET_I(1);
    vsync = VL_RAND_RESET_I(1);
    sdl_de = VL_RAND_RESET_I(1);
    sdl_x = VL_RAND_RESET_I(10);
    sdl_y = VL_RAND_RESET_I(10);
    sdl_r = VL_RAND_RESET_I(8);
    sdl_g = VL_RAND_RESET_I(8);
    sdl_b = VL_RAND_RESET_I(8);
    top_bounce__DOT__x_pix = VL_RAND_RESET_I(10);
    top_bounce__DOT__y_pix = VL_RAND_RESET_I(10);
    top_bounce__DOT__Q_R = VL_RAND_RESET_I(4);
    top_bounce__DOT__Q_G = VL_RAND_RESET_I(4);
    top_bounce__DOT__Q_B = VL_RAND_RESET_I(4);
    top_bounce__DOT__qx = VL_RAND_RESET_I(10);
    top_bounce__DOT__qy = VL_RAND_RESET_I(10);
    top_bounce__DOT__qdx = VL_RAND_RESET_I(1);
    top_bounce__DOT__qdy = VL_RAND_RESET_I(1);
    top_bounce__DOT__pixel = VL_RAND_RESET_I(1);
}
