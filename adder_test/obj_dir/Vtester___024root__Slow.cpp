// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtester.h for the primary calling header

#include "Vtester__pch.h"
#include "Vtester__Syms.h"
#include "Vtester___024root.h"

void Vtester___024root___ctor_var_reset(Vtester___024root* vlSelf);

Vtester___024root::Vtester___024root(Vtester__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtester___024root___ctor_var_reset(this);
}

void Vtester___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtester___024root::~Vtester___024root() {
}
