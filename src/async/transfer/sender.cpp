#include "../../../include/async/transfer/sender.hpp"

AwaitVoid Sender::send(SocketPtr _p_socket, 
                       ConstData _k_data) {
    size_t size_of_data { _k_data.size() };
    co_await boost::asio::async_write(
        *_p_socket,
        boost::asio::buffer(&size_of_data, sizeof(size_t)),
        boost::asio::use_awaitable
    );
    co_await boost::asio::async_write(
        *_p_socket,
        boost::asio::buffer(_k_data.data(), size_of_data),
        boost::asio::use_awaitable
    );
}
