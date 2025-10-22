// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtester.h for the primary calling header

#include "Vtester__pch.h"
#include "Vtester___024root.h"

VL_ATTR_COLD void Vtester___024root___eval_static(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_static\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtester___024root___eval_initial__TOP(Vtester___024root* vlSelf);
VL_ATTR_COLD void Vtester___024root____Vm_traceActivitySetAll(Vtester___024root* vlSelf);

VL_ATTR_COLD void Vtester___024root___eval_initial(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_initial\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtester___024root___eval_initial__TOP(vlSelf);
    Vtester___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtester___024root___eval_final(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_final\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtester___024root___dump_triggers__stl(Vtester___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtester___024root___eval_phase__stl(Vtester___024root* vlSelf);

VL_ATTR_COLD void Vtester___024root___eval_settle(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_settle\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtester___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tester.sv", 10, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtester___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtester___024root___dump_triggers__stl(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___dump_triggers__stl\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtester___024root___stl_sequent__TOP__0(Vtester___024root* vlSelf);

VL_ATTR_COLD void Vtester___024root___eval_stl(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_stl\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtester___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtester___024root___stl_sequent__TOP__0(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___stl_sequent__TOP__0\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tester__DOT__z = ((((2U & ((((IData)(vlSelfRef.tester__DOT__a) 
                                           >> 3U) + 
                                          ((IData)(vlSelfRef.tester__DOT__b) 
                                           >> 3U)) 
                                         << 1U)) | 
                                  (1U & (((IData)(vlSelfRef.tester__DOT__a) 
                                          >> 2U) + 
                                         ((IData)(vlSelfRef.tester__DOT__b) 
                                          >> 2U)))) 
                                 << 2U) | ((2U & ((
                                                   ((IData)(vlSelfRef.tester__DOT__a) 
                                                    >> 1U) 
                                                   + 
                                                   ((IData)(vlSelfRef.tester__DOT__b) 
                                                    >> 1U)) 
                                                  << 1U)) 
                                           | (1U & 
                                              ((IData)(vlSelfRef.tester__DOT__a) 
                                               + (IData)(vlSelfRef.tester__DOT__b)))));
}

VL_ATTR_COLD void Vtester___024root___eval_triggers__stl(Vtester___024root* vlSelf);

VL_ATTR_COLD bool Vtester___024root___eval_phase__stl(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___eval_phase__stl\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtester___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtester___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtester___024root___dump_triggers__act(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___dump_triggers__act\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtester___024root___dump_triggers__nba(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___dump_triggers__nba\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtester___024root____Vm_traceActivitySetAll(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root____Vm_traceActivitySetAll\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtester___024root___ctor_var_reset(Vtester___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtester___024root___ctor_var_reset\n"); );
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tester__DOT__a = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11582260003239124013ull);
    vlSelf->tester__DOT__b = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5601153816129816731ull);
    vlSelf->tester__DOT__z = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3819153809932592672ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
