#ifndef IACCEPTORREFLECTION_HPP
#define IACCEPTORREFLECTION_HPP

#include "../../definitions.hpp"

class IAcceptor {
public:
#ifdef USE_COROUTINE
    virtual Awaitable<SocketPtr> accept(const Endpoint &_k_endpoint) = 0;
#else 
    virtual SocketPtr accept(const Endpoint &_k_endpoint) = 0;
#endif
};

#endif
