// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_bounce.h for the primary calling header

#include "Vtop_bounce.h"
#include "Vtop_bounce__Syms.h"

//==========

void Vtop_bounce::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_bounce::eval\n"); );
    Vtop_bounce__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_bounce.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_bounce::_eval_initial_loop(Vtop_bounce__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_bounce.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop_bounce::_sequent__TOP__1(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_sequent__TOP__1\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__top_bounce__DOT__qx;
    SData/*9:0*/ __Vdly__top_bounce__DOT__qy;
    SData/*9:0*/ __Vdly__top_bounce__DOT__x_pix;
    SData/*9:0*/ __Vdly__top_bounce__DOT__y_pix;
    // Body
    __Vdly__top_bounce__DOT__y_pix = vlTOPp->top_bounce__DOT__y_pix;
    __Vdly__top_bounce__DOT__x_pix = vlTOPp->top_bounce__DOT__x_pix;
    __Vdly__top_bounce__DOT__qy = vlTOPp->top_bounce__DOT__qy;
    __Vdly__top_bounce__DOT__qx = vlTOPp->top_bounce__DOT__qx;
    vlTOPp->sdl_b = (0xffU & ((((IData)(vlTOPp->top_bounce__DOT__pixel)
                                 ? (IData)(vlTOPp->top_bounce__DOT__Q_B)
                                 : 7U) << 4U) | ((IData)(vlTOPp->top_bounce__DOT__pixel)
                                                  ? (IData)(vlTOPp->top_bounce__DOT__Q_B)
                                                  : 7U)));
    vlTOPp->sdl_g = (0xffU & ((((IData)(vlTOPp->top_bounce__DOT__pixel)
                                 ? (IData)(vlTOPp->top_bounce__DOT__Q_G)
                                 : 3U) << 4U) | ((IData)(vlTOPp->top_bounce__DOT__pixel)
                                                  ? (IData)(vlTOPp->top_bounce__DOT__Q_G)
                                                  : 3U)));
    vlTOPp->sdl_r = (0xffU & ((((IData)(vlTOPp->top_bounce__DOT__pixel)
                                 ? (IData)(vlTOPp->top_bounce__DOT__Q_R)
                                 : 1U) << 4U) | ((IData)(vlTOPp->top_bounce__DOT__pixel)
                                                  ? (IData)(vlTOPp->top_bounce__DOT__Q_R)
                                                  : 1U)));
    vlTOPp->sdl_y = vlTOPp->top_bounce__DOT__y_pix;
    vlTOPp->sdl_x = vlTOPp->top_bounce__DOT__x_pix;
    vlTOPp->sdl_de = ((0x280U > (IData)(vlTOPp->top_bounce__DOT__x_pix)) 
                      & (0x1e0U > (IData)(vlTOPp->top_bounce__DOT__y_pix)));
    if (vlTOPp->reset) {
        __Vdly__top_bounce__DOT__x_pix = 0U;
        __Vdly__top_bounce__DOT__y_pix = 0U;
    } else {
        if ((0x33fU > (IData)(vlTOPp->top_bounce__DOT__x_pix))) {
            __Vdly__top_bounce__DOT__x_pix = (0x3ffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlTOPp->top_bounce__DOT__x_pix)));
        } else {
            __Vdly__top_bounce__DOT__y_pix = ((0x29fU 
                                               > (IData)(vlTOPp->top_bounce__DOT__y_pix))
                                               ? (0x3ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->top_bounce__DOT__y_pix)))
                                               : 0U);
            __Vdly__top_bounce__DOT__x_pix = 0U;
        }
    }
    if (((0x1e0U == (IData)(vlTOPp->top_bounce__DOT__y_pix)) 
         & (0U == (IData)(vlTOPp->top_bounce__DOT__x_pix)))) {
        if (vlTOPp->top_bounce__DOT__qdx) {
            if ((5U > (IData)(vlTOPp->top_bounce__DOT__qx))) {
                vlTOPp->top_bounce__DOT__Q_R = 0xfU;
                vlTOPp->top_bounce__DOT__Q_G = 0xfU;
                vlTOPp->top_bounce__DOT__Q_B = 0U;
                __Vdly__top_bounce__DOT__qx = 0U;
                vlTOPp->top_bounce__DOT__qdx = 0U;
            } else {
                __Vdly__top_bounce__DOT__qx = (0x3ffU 
                                               & ((IData)(vlTOPp->top_bounce__DOT__qx) 
                                                  - (IData)(5U)));
            }
        } else {
            if ((0x27fU <= ((IData)(0xfU) + (IData)(vlTOPp->top_bounce__DOT__qx)))) {
                vlTOPp->top_bounce__DOT__Q_R = 0xfU;
                vlTOPp->top_bounce__DOT__Q_G = 0U;
                vlTOPp->top_bounce__DOT__Q_B = 0xfU;
                __Vdly__top_bounce__DOT__qx = 0x275U;
                vlTOPp->top_bounce__DOT__qdx = 1U;
            } else {
                __Vdly__top_bounce__DOT__qx = (0x3ffU 
                                               & ((IData)(5U) 
                                                  + (IData)(vlTOPp->top_bounce__DOT__qx)));
            }
        }
        if (vlTOPp->top_bounce__DOT__qdy) {
            if ((5U > (IData)(vlTOPp->top_bounce__DOT__qy))) {
                vlTOPp->top_bounce__DOT__Q_R = 0xfU;
                vlTOPp->top_bounce__DOT__Q_G = 0U;
                vlTOPp->top_bounce__DOT__Q_B = 0U;
                __Vdly__top_bounce__DOT__qy = 0U;
                vlTOPp->top_bounce__DOT__qdy = 0U;
            } else {
                __Vdly__top_bounce__DOT__qy = (0x3ffU 
                                               & ((IData)(vlTOPp->top_bounce__DOT__qy) 
                                                  - (IData)(5U)));
            }
        } else {
            if ((0x1dfU <= ((IData)(0xfU) + (IData)(vlTOPp->top_bounce__DOT__qy)))) {
                vlTOPp->top_bounce__DOT__Q_R = 0U;
                vlTOPp->top_bounce__DOT__Q_G = 0xfU;
                vlTOPp->top_bounce__DOT__Q_B = 0xfU;
                __Vdly__top_bounce__DOT__qy = 0x1d5U;
                vlTOPp->top_bounce__DOT__qdy = 1U;
            } else {
                __Vdly__top_bounce__DOT__qy = (0x3ffU 
                                               & ((IData)(5U) 
                                                  + (IData)(vlTOPp->top_bounce__DOT__qy)));
            }
        }
    }
    vlTOPp->top_bounce__DOT__qx = __Vdly__top_bounce__DOT__qx;
    vlTOPp->top_bounce__DOT__qy = __Vdly__top_bounce__DOT__qy;
    vlTOPp->top_bounce__DOT__y_pix = __Vdly__top_bounce__DOT__y_pix;
    vlTOPp->top_bounce__DOT__x_pix = __Vdly__top_bounce__DOT__x_pix;
    vlTOPp->vsync = (1U & (~ ((0x1e9U <= (IData)(vlTOPp->top_bounce__DOT__y_pix)) 
                              & (0x1ebU > (IData)(vlTOPp->top_bounce__DOT__y_pix)))));
    vlTOPp->hsync = (1U & (~ ((0x298U <= (IData)(vlTOPp->top_bounce__DOT__x_pix)) 
                              & (0x2c0U > (IData)(vlTOPp->top_bounce__DOT__x_pix)))));
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

void Vtop_bounce::_eval(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_eval\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->pix_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pix_clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__pix_clk = vlTOPp->pix_clk;
}

VL_INLINE_OPT QData Vtop_bounce::_change_request(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_change_request\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop_bounce::_change_request_1(Vtop_bounce__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_change_request_1\n"); );
    Vtop_bounce* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop_bounce::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_bounce::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((pix_clk & 0xfeU))) {
        Verilated::overWidthError("pix_clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG