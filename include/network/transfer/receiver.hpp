#ifndef RECEIVERREFLECTION_HPP
#define RECEIVERREFLECTION_HPP

#include "ireceiver.hpp"

class Receiver 
    : public IReceiver {
public:
#ifdef USE_COROUTINE
    Awaitable<Data> receive(SocketPtr _p_socket) override;
#else 
    Data receive(SocketPtr _p_socket) override;
#endif
};

#endif
