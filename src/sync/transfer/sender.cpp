#include "../../../include/sync/transfer/sender.hpp"

void Sender::send(SocketPtr _p_socket,
                  ConstData _k_data) {
    size_t size_of_data { _k_data.size() };
    boost::asio::write(*_p_socket, boost::asio::buffer(&size_of_data, sizeof(size_t)));
    boost::asio::write(*_p_socket, boost::asio::buffer(_k_data.data(), size_of_data));
}
