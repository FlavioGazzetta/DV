// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder.h for the primary calling header

#include "Vadder__pch.h"
#include "Vadder___024root.h"

VL_ATTR_COLD void Vadder___024root___eval_static(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___eval_static\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vadder___024root___eval_initial__TOP(Vadder___024root* vlSelf);
VL_ATTR_COLD void Vadder___024root____Vm_traceActivitySetAll(Vadder___024root* vlSelf);

VL_ATTR_COLD void Vadder___024root___eval_initial(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___eval_initial\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadder___024root___eval_initial__TOP(vlSelf);
    Vadder___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vadder___024root___eval_final(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___eval_final\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder___024root___dump_triggers__stl(Vadder___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadder___024root___eval_phase__stl(Vadder___024root* vlSelf);

VL_ATTR_COLD void Vadder___024root___eval_settle(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___eval_settle\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadder___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("adder.sv", 9, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadder___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder___024root___dump_triggers__stl(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___dump_triggers__stl\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vadder___024root___stl_sequent__TOP__0(Vadder___024root* vlSelf);

VL_ATTR_COLD void Vadder___024root___eval_stl(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___eval_stl\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadder___024root___stl_sequent__TOP__0(vlSelf);
        Vadder___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vadder___024root___stl_sequent__TOP__0(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___stl_sequent__TOP__0\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tester__DOT__z = ((8U & (IData)(vlSelfRef.tester__DOT__z)) 
                                | ((4U & ((((IData)(vlSelfRef.tester__DOT__a) 
                                            >> 2U) 
                                           + ((IData)(vlSelfRef.tester__DOT__b) 
                                              >> 2U)) 
                                          << 2U)) | 
                                   ((2U & ((((IData)(vlSelfRef.tester__DOT__a) 
                                             >> 1U) 
                                            + ((IData)(vlSelfRef.tester__DOT__b) 
                                               >> 1U)) 
                                           << 1U)) 
                                    | (1U & ((IData)(vlSelfRef.tester__DOT__a) 
                                             + (IData)(vlSelfRef.tester__DOT__b))))));
}

VL_ATTR_COLD void Vadder___024root___eval_triggers__stl(Vadder___024root* vlSelf);

VL_ATTR_COLD bool Vadder___024root___eval_phase__stl(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___eval_phase__stl\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadder___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadder___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder___024root___dump_triggers__act(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___dump_triggers__act\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder___024root___dump_triggers__nba(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___dump_triggers__nba\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadder___024root____Vm_traceActivitySetAll(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root____Vm_traceActivitySetAll\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vadder___024root___ctor_var_reset(Vadder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder___024root___ctor_var_reset\n"); );
    Vadder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
