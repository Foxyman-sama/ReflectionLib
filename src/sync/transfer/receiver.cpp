#include "../../../include/sync/transfer/receiver.hpp"

Data Receiver::receive(SocketPtr _p_socket) {
    size_t size_of_data { };
    boost::asio::read(*_p_socket, boost::asio::buffer(&size_of_data, sizeof(size_t)));

    Data data { };
    data.resize(size_of_data);
    boost::asio::read(*_p_socket, boost::asio::buffer(data.data(), size_of_data));
    return data;
}
