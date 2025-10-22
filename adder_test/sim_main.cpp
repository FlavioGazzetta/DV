#include "Vtester.h"
#include "verilated.h"
#include "verilated_vcd_c.h"   // ok to include even if you don't attach manually

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);   // <<< enable wave tracing before time 0

    Vtester top;

    while (!Verilated::gotFinish()) {
        top.eval();
        main_time++;
    }

    top.final();
    return 0;
}
