// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_tb.h for the primary calling header

#include "Vadder_tb__pch.h"
#include "Vadder_tb__Syms.h"
#include "Vadder_tb___024root.h"

VL_ATTR_COLD void Vadder_tb___024root___eval_initial__TOP(Vadder_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_tb___024root___eval_initial__TOP\n"); );
    Vadder_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("wave.vcd"s);
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tester__DOT__a = 4U;
    vlSelfRef.tester__DOT__b = 1U;
    VL_WRITEF_NX("a=4 b=1 z=%0#\n",0,4,vlSelfRef.tester__DOT__z);
    VL_FINISH_MT("adder_tb.sv", 26, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_tb___024root___dump_triggers__stl(Vadder_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadder_tb___024root___eval_triggers__stl(Vadder_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_tb___024root___eval_triggers__stl\n"); );
    Vadder_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadder_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
