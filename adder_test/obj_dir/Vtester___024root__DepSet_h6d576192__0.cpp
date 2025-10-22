// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtester.h for the primary calling header

#include "Vtester__pch.h"
#include "Vtester__Syms.h"
#include "Vtester___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtester___024root___dump_triggers__act(Vtester___024root* vlSelf);
#endif  // VL_DEBUG

void Vtester___024root___eval_triggers__act(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_triggers__act\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtester___024root___dump_triggers__act(vlSelf);
    }
#endif
}
