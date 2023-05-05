#ifndef ISENDERREFLECTION_HPP
#define ISENDERREFLECTION_HPP

#include "../../definitions.hpp"

class ISender {
public:
#ifdef USE_COROUTINE
    virtual Awaitable<void> send(SocketPtr _p_socket,
                                 const Data &_k_data) = 0;
#else 
    virtual void send(SocketPtr _p_socket,
                      const Data &_k_data) = 0;
#endif
};

#endif
