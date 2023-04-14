#ifndef SENDERREFLECTION_HPP
#define SENDERREFLECTION_HPP

#include "isender.hpp"

class Sender 
    : public ISender {
public:
#ifdef USE_COROUTINE
    virtual AwaitVoid send(SocketPtr _p_socket,
                           ConstData _k_data) override;
#else 
    virtual void send(SocketPtr _p_socket,
                      ConstData _k_data) override;
#endif
};

#endif
