// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadder_tb.h for the primary calling header

#ifndef VERILATED_VADDER_TB___024ROOT_H_
#define VERILATED_VADDER_TB___024ROOT_H_  // guard

#include "verilated.h"


class Vadder_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadder_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*3:0*/ tester__DOT__a;
    CData/*3:0*/ tester__DOT__b;
    CData/*3:0*/ tester__DOT__z;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadder_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadder_tb___024root(Vadder_tb__Syms* symsp, const char* v__name);
    ~Vadder_tb___024root();
    VL_UNCOPYABLE(Vadder_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
