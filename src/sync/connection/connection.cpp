#include "../../../include/sync/connection/connection.hpp"

SocketPtr Connection::connect(ConstEndpoint _k_endpoint) {
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    p_socket->connect(_k_endpoint);
    return p_socket;
}
