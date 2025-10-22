// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadder_tb__Syms.h"


void Vadder_tb___024root__trace_chg_0_sub_0(Vadder_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadder_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_tb___024root__trace_chg_0\n"); );
    // Init
    Vadder_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadder_tb___024root*>(voidSelf);

    Vadder_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;

    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;

    // Body
    Vadder_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadder_tb___024root__trace_chg_0_sub_0(Vadder_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_tb___024root__trace_chg_0_sub_0\n"); );
    Vadder_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);

    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.tester__DOT__a),4);
        bufp->chgCData(oldp+1,(vlSelfRef.tester__DOT__b),4);
        bufp->chgCData(oldp+2,(((((2U & ((((IData)(vlSelfRef.tester__DOT__a) 
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
                                               + (IData)(vlSelfRef.tester__DOT__b)))))),4);
        bufp->chgBit(oldp+3,((1U & (IData)(vlSelfRef.tester__DOT__a))));
        bufp->chgBit(oldp+4,((1U & (IData)(vlSelfRef.tester__DOT__b))));
        bufp->chgBit(oldp+5,((1U & ((IData)(vlSelfRef.tester__DOT__a) 
                                    + (IData)(vlSelfRef.tester__DOT__b)))));
        bufp->chgBit(oldp+6,((1U & ((IData)(vlSelfRef.tester__DOT__a) 
                                    >> 1U))));
        bufp->chgBit(oldp+7,((1U & ((IData)(vlSelfRef.tester__DOT__b) 
                                    >> 1U))));
        bufp->chgBit(oldp+8,((1U & (((IData)(vlSelfRef.tester__DOT__a) 
                                     >> 1U) + ((IData)(vlSelfRef.tester__DOT__b) 
                                               >> 1U)))));
        bufp->chgBit(oldp+9,((1U & ((IData)(vlSelfRef.tester__DOT__a) 
                                    >> 2U))));
        bufp->chgBit(oldp+10,((1U & ((IData)(vlSelfRef.tester__DOT__b) 
                                     >> 2U))));
        bufp->chgBit(oldp+11,((1U & (((IData)(vlSelfRef.tester__DOT__a) 
                                      >> 2U) + ((IData)(vlSelfRef.tester__DOT__b) 
                                                >> 2U)))));
        bufp->chgBit(oldp+12,((1U & ((IData)(vlSelfRef.tester__DOT__a) 
                                     >> 3U))));
        bufp->chgBit(oldp+13,((1U & ((IData)(vlSelfRef.tester__DOT__b) 
                                     >> 3U))));
        bufp->chgBit(oldp+14,((1U & (((IData)(vlSelfRef.tester__DOT__a) 
                                      >> 3U) + ((IData)(vlSelfRef.tester__DOT__b) 
                                                >> 3U)))));
    }
}

void Vadder_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_tb___024root__trace_cleanup\n"); );
    // Init
    Vadder_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadder_tb___024root*>(voidSelf);

    Vadder_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;

    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
}
