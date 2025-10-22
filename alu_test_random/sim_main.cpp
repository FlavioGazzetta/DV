#include "Vtester.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // Enable SV-side $dumpfile/$dumpvars traces before time 0
    Verilated::traceEverOn(true);

    Vtester top;

    while (!Verilated::gotFinish()) {
        top.eval();
        // Advance time so #delays in SV progress and VCD has a timeline
        main_time++;
    }

    top.final();
    return 0;
}
