#ifndef IRECEIVERREFLECTION_HPP
#define IRECEIVERREFLECTION_HPP

#include "../definitions.hpp"

class IReceiver {
public:
    virtual Data receive(SocketPtr _p_socket) = 0;
};

#endif
