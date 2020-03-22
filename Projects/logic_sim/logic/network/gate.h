#ifndef GATE_H
#define GATE_H

#include "port.h"

enum LOGIC_RELATION {
    AND,
    OR,
    NAND,
    NOR,
    XOR,
    XNOR,
    RAND,
    SOURCE
};

class Gate  {
    public:
        char* name;
        LOGIC_RELATION lrelation;
        Port** inputs;
        Port** outputs;

        Gate(char* name, int numInputs, LOGIC_RELATION lrel) {
            name = name;
        }
};

#endif