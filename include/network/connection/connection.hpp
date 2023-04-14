#ifndef CONNECTIONREFLECTION_HPP
#define CONNECTIONREFLECTION_HPP

#include "iconnection.hpp"

class Connection 
    : public IConnection {
public:
#ifdef USE_COROUTINE
    virtual AwaitSPtr connect(ConstEndpoint _k_endpoint) override;
#else 
    virtual SocketPtr connect(ConstEndpoint _k_endpoint) override;
#endif
};

#endif
