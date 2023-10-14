// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VTOP_BOUNCE__SYMS_H_
#define _VTOP_BOUNCE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vtop_bounce.h"

// SYMS CLASS
class Vtop_bounce__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtop_bounce*                   TOPp;
    
    // CREATORS
    Vtop_bounce__Syms(Vtop_bounce* topp, const char* namep);
    ~Vtop_bounce__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
