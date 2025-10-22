// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtester.h for the primary calling header

#ifndef VERILATED_VTESTER___024ROOT_H_
#define VERILATED_VTESTER___024ROOT_H_  // guard

#include "verilated.h"


class Vtester__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtester___024root final : public VerilatedModule {
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
    Vtester__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtester___024root(Vtester__Syms* symsp, const char* v__name);
    ~Vtester___024root();
    VL_UNCOPYABLE(Vtester___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
