#ifndef ICONNECTIONREFLECTION_HPP
#define ICONNECTIONREFLECTION_HPP

#include "../../definitions.hpp"

class IConnection {
public:
#ifdef USE_COROUTINE
    virtual Awaitable<SocketPtr> connect(const Endpoint &_k_endpoint) = 0;
#else 
    virtual SocketPtr connect(const Endpoint &_k_endpoint) = 0;
#endif
};

#endif
