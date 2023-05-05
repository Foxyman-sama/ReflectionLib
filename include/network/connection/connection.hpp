#ifndef CONNECTIONREFLECTION_HPP
#define CONNECTIONREFLECTION_HPP

#include "iconnection.hpp"

class Connection 
    : public IConnection {
public:
#ifdef USE_COROUTINE
    Awaitable<SocketPtr> connect(const Endpoint &_k_endpoint) override;
#else 
    SocketPtr connect(const Endpoint &_k_endpoint) override;
#endif
};

#endif
