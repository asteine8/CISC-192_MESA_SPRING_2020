#ifndef NET_H
#define NET_H

#include "port.h"

class Net {
    public:
        Port** inputPorts;
        Port** outputPorts;
};

#endif