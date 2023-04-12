#ifndef RECEIVERREFLECTION_HPP
#define RECEIVERREFLECTION_HPP

#include "ireceiver.hpp"

class Receiver 
    : public IReceiver {
public:
    Awaitable<Data> receive(SocketPtr _p_socket) override;
};

#endif
