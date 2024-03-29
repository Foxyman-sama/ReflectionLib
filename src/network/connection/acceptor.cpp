#include "../../../include/network/connection/acceptor.hpp"

#ifdef USE_COROUTINE
Awaitable<SocketPtr> Acceptor::accept(const Endpoint &_k_endpoint) {
    static TCP::acceptor s_acceptor { g_io, _k_endpoint };
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    co_await s_acceptor.async_accept(*p_socket, boost::asio::use_awaitable);
    
    co_return p_socket;
}
#else 
SocketPtr Acceptor::accept(const Endpoint &_k_endpoint) {
    static TCP::acceptor s_acceptor { g_io, _k_endpoint };
    SocketPtr p_socket { std::make_shared<TCP::socket>(g_io) };
    s_acceptor.accept(*p_socket);   
    return p_socket;
}
#endif // USE_COROUTINE
