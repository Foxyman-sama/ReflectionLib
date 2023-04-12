#ifndef ICONNECTIONREFLECTION_HPP
#define ICONNECTIONREFLECTION_HPP

#include "../definitions.hpp"

class IConnection {
public:
    virtual SocketPtr connect(ConstEndpoint _k_endpoint) = 0;
};

#endif
