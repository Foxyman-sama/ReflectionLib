#include "../../../include/network/transfer/sender.hpp"

#ifdef USE_COROUTINE
Awaitable<void> Sender::send(SocketPtr _p_socket,
                             const Data &_k_data) {
    size_t size_of_data { _k_data.getSize() };
    co_await boost::asio::async_write(
        *_p_socket,
        boost::asio::buffer(&size_of_data, sizeof(size_t)),
        boost::asio::use_awaitable
    );
    co_await boost::asio::async_write(
        *_p_socket,
        boost::asio::buffer(_k_data.getRawData(), size_of_data),
        boost::asio::use_awaitable
    );
}
#else 
void Sender::send(SocketPtr _p_socket,
                  const Data &_k_data) {
    size_t size_of_data { _k_data.getSize() };
    boost::asio::write(*_p_socket, boost::asio::buffer(&size_of_data, sizeof(size_t)));
    boost::asio::write(*_p_socket, boost::asio::buffer(_k_data.getRawData(), size_of_data));
}
#endif