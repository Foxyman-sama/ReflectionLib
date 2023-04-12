#ifndef ISENDERREFLECTION_HPP
#define ISENDERREFLECTION_HPP

#include "../definitions.hpp"

class ISender {
public:
    virtual void send(SocketPtr _p_socket,
                      ConstData _k_data) = 0;
};

#endif
