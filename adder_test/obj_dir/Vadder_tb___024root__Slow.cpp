// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_tb.h for the primary calling header

#include "Vadder_tb__pch.h"
#include "Vadder_tb__Syms.h"
#include "Vadder_tb___024root.h"

void Vadder_tb___024root___ctor_var_reset(Vadder_tb___024root* vlSelf);

Vadder_tb___024root::Vadder_tb___024root(Vadder_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadder_tb___024root___ctor_var_reset(this);
}

void Vadder_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadder_tb___024root::~Vadder_tb___024root() {
}
