// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtester__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtester::Vtester(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtester__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtester::Vtester(const char* _vcname__)
    : Vtester(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtester::~Vtester() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtester___024root___eval_debug_assertions(Vtester___024root* vlSelf);
#endif  // VL_DEBUG
void Vtester___024root___eval_static(Vtester___024root* vlSelf);
void Vtester___024root___eval_initial(Vtester___024root* vlSelf);
void Vtester___024root___eval_settle(Vtester___024root* vlSelf);
void Vtester___024root___eval(Vtester___024root* vlSelf);

void Vtester::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtester::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtester___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtester___024root___eval_static(&(vlSymsp->TOP));
        Vtester___024root___eval_initial(&(vlSymsp->TOP));
        Vtester___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtester___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtester::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtester::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vtester::eventsPending() { return false; }

uint64_t Vtester::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtester::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtester___024root___eval_final(Vtester___024root* vlSelf);

VL_ATTR_COLD void Vtester::final() {
    Vtester___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtester::hierName() const { return vlSymsp->name(); }
const char* Vtester::modelName() const { return "Vtester"; }
unsigned Vtester::threads() const { return 1; }
void Vtester::prepareClone() const { contextp()->prepareClone(); }
void Vtester::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtester::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtester___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtester___024root__trace_init_top(Vtester___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtester___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtester___024root*>(voidSelf);
    Vtester__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtester___024root__trace_decl_types(tracep);
    Vtester___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtester___024root__trace_register(Vtester___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtester::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtester::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtester___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
