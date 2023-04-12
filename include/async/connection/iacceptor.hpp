#ifndef IACCEPTORREFLECTION_HPP
#define IACCEPTORREFLECTION_HPP

#include "../definitions.hpp"

class IAcceptor {
public:
    virtual AwaitSPtr accept(ConstEndpoint _k_endpoint) = 0;
};

#endif
