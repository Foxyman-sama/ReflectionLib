#ifndef SENDERREFLECTION_HPP
#define SENDERREFLECTION_HPP

#include "isender.hpp"

class Sender 
    : public ISender {
public:
#ifdef USE_COROUTINE
    Awaitable<void> send(SocketPtr _p_socket,
                         const Data &_k_data) override;
#else 
    void send(SocketPtr _p_socket,
              const Data &_k_data) override;
#endif
};

#endif
