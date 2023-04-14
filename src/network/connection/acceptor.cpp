#include "../../../include/network/connection/acceptor.hpp"

#ifdef USE_COROUTINE
AwaitSPtr Acceptor::accept(ConstEndpoint _k_endpoint) {
    TCP::acceptor acceptor { g_io, _k_endpoint };
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    co_await acceptor.async_accept(*p_socket, boost::asio::use_awaitable);
    
    co_return p_socket;
}
#else 
SocketPtr Acceptor::accept(ConstEndpoint _k_endpoint) {
    TCP::acceptor acceptor { g_io, _k_endpoint };
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    acceptor.accept(*p_socket);   
    return p_socket;
}
#endif // USE_COROUTINE
