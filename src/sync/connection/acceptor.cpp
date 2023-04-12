#include "../../../include/sync/connection/acceptor.hpp"

SocketPtr Acceptor::accept(ConstEndpoint _k_endpoint) {
    TCP::acceptor acceptor { g_io, _k_endpoint };
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    acceptor.accept(*p_socket);   
    return p_socket;
}
