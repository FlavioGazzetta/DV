// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtester.h for the primary calling header

#include "Vtester__pch.h"
#include "Vtester__Syms.h"
#include "Vtester___024root.h"

VL_ATTR_COLD void Vtester___024root___eval_initial__TOP(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_initial__TOP\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("wave.vcd"s);
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tester__DOT__a = 4U;
    vlSelfRef.tester__DOT__b = 1U;
    VL_WRITEF_NX("a=4 b=1 z=%0#\n",0,4,vlSelfRef.tester__DOT__z);
    VL_FINISH_MT("tester.sv", 30, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtester___024root___dump_triggers__stl(Vtester___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtester___024root___eval_triggers__stl(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_triggers__stl\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtester___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
