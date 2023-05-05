#include "../../../include/network/connection/connection.hpp"

#ifdef USE_COROUTINE
Awaitable<SocketPtr> Connection::connect(const Endpoint &_k_endpoint) {
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    co_await p_socket->async_connect(_k_endpoint, boost::asio::use_awaitable);

    co_return p_socket;
}
#else 
SocketPtr Connection::connect(const Endpoint &_k_endpoint) {
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    p_socket->connect(_k_endpoint);
    return p_socket;
}
#endif
