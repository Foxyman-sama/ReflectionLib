#include "../../../include/async/transfer/receiver.hpp"

Awaitable<Data> Receiver::receive(SocketPtr _p_socket) {
    size_t size_of_data { };
    co_await boost::asio::async_read(
        *_p_socket,
        boost::asio::buffer(&size_of_data, sizeof(size_t)),
        boost::asio::use_awaitable
    );

    Data data { };
    data.resize(size_of_data);
    co_await boost::asio::async_read(
        *_p_socket,
        boost::asio::buffer(data.data(), size_of_data),
        boost::asio::use_awaitable
    );

    co_return data;
}
