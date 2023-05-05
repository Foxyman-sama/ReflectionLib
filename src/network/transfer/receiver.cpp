#include "../../../include/network/transfer/receiver.hpp"

#ifdef USE_COROUTINE
Awaitable<Data> Receiver::receive(SocketPtr _p_socket) {
    size_t size_of_data { };
    co_await boost::asio::async_read(
        *_p_socket,
        boost::asio::buffer(&size_of_data, sizeof(size_t)),
        boost::asio::use_awaitable
    );

    Data data { size_of_data };
    co_await boost::asio::async_read(
        *_p_socket,
        boost::asio::buffer(data.getRawData(), size_of_data),
        boost::asio::use_awaitable
    );

    co_return data;
}
#else 
Data Receiver::receive(SocketPtr _p_socket) {
    size_t size_of_data { };
    boost::asio::read(*_p_socket, boost::asio::buffer(&size_of_data, sizeof(size_t)));

    Data data { size_of_data };
    boost::asio::read(*_p_socket, boost::asio::buffer(data.getRawData(), size_of_data));
    return data;
}
#endif