#include "../../../include/async/connection/acceptor.hpp"

AwaitSPtr Acceptor::accept(ConstEndpoint _k_endpoint) {
    TCP::acceptor acceptor { g_io, _k_endpoint };
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    co_await acceptor.async_accept(*p_socket, boost::asio::use_awaitable);
    
    co_return p_socket;
}
