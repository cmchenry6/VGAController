// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VTOP_BREAKOUT__SYMS_H_
#define _VTOP_BREAKOUT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vtop_breakout.h"

// SYMS CLASS
class Vtop_breakout__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtop_breakout*                 TOPp;
    
    // CREATORS
    Vtop_breakout__Syms(Vtop_breakout* topp, const char* namep);
    ~Vtop_breakout__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
