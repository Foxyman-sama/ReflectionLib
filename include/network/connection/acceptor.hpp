#ifndef ACCEPTORREFLECTION_HPP
#define ACCEPTORREFLECTION_HPP

#include "iacceptor.hpp"

class Acceptor 
    : public IAcceptor {
public:
#ifdef USE_COROUTINE
    AwaitSPtr accept(ConstEndpoint _k_endpoint) override;
#else 
    SocketPtr accept(ConstEndpoint _k_endpoint) override;
#endif
};

#endif
