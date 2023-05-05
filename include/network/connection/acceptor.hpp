#ifndef ACCEPTORREFLECTION_HPP
#define ACCEPTORREFLECTION_HPP

#include "iacceptor.hpp"

class Acceptor 
    : public IAcceptor {
public:
#ifdef USE_COROUTINE
    Awaitable<SocketPtr> accept(const Endpoint &_k_endpoint) override;
#else 
    SocketPtr accept(const Endpoint &_k_endpoint) override;
#endif
};

#endif
