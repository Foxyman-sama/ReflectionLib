#ifndef ACCEPTORREFLECTION_HPP
#define ACCEPTORREFLECTION_HPP

#include "iacceptor.hpp"

class Acceptor 
    : public IAcceptor {
public:
    AwaitSPtr accept(ConstEndpoint _k_endpoint) override;
};

#endif
