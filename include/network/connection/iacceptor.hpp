#ifndef IACCEPTORREFLECTION_HPP
#define IACCEPTORREFLECTION_HPP

#include "../../definitions.hpp"

class IAcceptor {
public:
#ifdef USE_COROUTINE
    virtual AwaitSPtr accept(ConstEndpoint _k_endpoint) = 0;
#else 
    virtual SocketPtr accept(ConstEndpoint _k_endpoint) = 0;
#endif
};

#endif
