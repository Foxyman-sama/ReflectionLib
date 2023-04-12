#ifndef SENDERREFLECTION_HPP
#define SENDERREFLECTION_HPP

#include "isender.hpp"

class Sender 
    : public ISender {
public:
    AwaitVoid send(SocketPtr _p_socket,
                   ConstData _k_data) override;
};

#endif
