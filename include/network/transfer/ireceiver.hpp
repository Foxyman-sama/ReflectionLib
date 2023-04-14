#ifndef IRECEIVERREFLECTION_HPP
#define IRECEIVERREFLECTION_HPP

#include "../../definitions.hpp"

class IReceiver {
public:
#ifdef USE_COROUTINE
    virtual Awaitable<Data> receive(SocketPtr _p_socket) = 0;
#else 
    virtual Data receive(SocketPtr _p_socket) = 0;
#endif
};

#endif
