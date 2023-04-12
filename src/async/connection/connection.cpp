#include "../../../include/async/connection/connection.hpp"

AwaitSPtr Connection::connect(ConstEndpoint _k_endpoint) {
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    co_await p_socket->async_connect(_k_endpoint, boost::asio::use_awaitable);

    co_return p_socket;
}
