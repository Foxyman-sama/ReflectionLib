#ifndef ACCEPTORREFLECTION_HPP
#define ACCEPTORREFLECTION_HPP

#include "iacceptor.hpp"

class Acceptor 
    : public IAcceptor {
public:
    SocketPtr accept(ConstEndpoint _k_endpoint) override;
};

#endif
