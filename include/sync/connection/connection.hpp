#ifndef CONNECTIONREFLECTION_HPP
#define CONNECTIONREFLECTION_HPP

#include "iconnection.hpp"

class Connection 
    : public IConnection {
public:
    SocketPtr connect(ConstEndpoint _k_endpoint) override;
};

#endif
