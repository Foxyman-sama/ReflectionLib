#include <iostream>
#include "../include/reflectionlib.hpp"

constexpr size_t gk_count_of_symbols { 10'000'000 };

Awaitable<void> acceptTest() {
    try {
        for (size_t i { }; i < 100; ++i) {
            std::shared_ptr<IAcceptor> p_acceptor { std::make_shared<Acceptor>() };
            SocketPtr p_socket { co_await p_acceptor->accept(Endpoint { TCP::v4(), 9090 }) };
            std::cout << "acceptTest(): " << p_socket->remote_endpoint() << '\n';

            std::shared_ptr<ISender> p_sender { std::make_shared<Sender>() };
            Data data { gk_count_of_symbols, 'l' };
            co_await p_sender->send(p_socket, data);
            std::cout << "acceptTest(): send data SUCCESS!\n";

            std::shared_ptr<IReceiver> p_receiver { std::make_shared<Receiver>() };
            auto result { co_await p_receiver->receive(p_socket) };
            for (auto &&el : result) {
                if (el != 'l') {
                    throw std::exception { "acceptTest(): receive data ERROR!" };
                }
            }

            std::cout << "acceptTest(): receive data SUCCESS!\n\n";
        }
    }
    catch (const std::exception &k_e) {
        std::cerr << "acceptTest(): " << k_e.what() << '\n';
        system("pause");
    }
}
Awaitable<void> connectTest() {
    try {
        for (size_t i { }; i < 100; ++i) {
            std::shared_ptr<IConnection> p_connector { std::make_shared<Connection>() };
            SocketPtr p_socket {
                co_await p_connector->connect(Endpoint { Address::from_string("127.0.0.1"), 9090 })
            };
            std::cout << "connectTest(): " << p_socket->remote_endpoint() << '\n';

            std::shared_ptr<IReceiver> p_receiver { std::make_shared<Receiver>() };
            auto result { co_await p_receiver->receive(p_socket) };
            for (auto &&el : result) {
                if (el != 'l') {
                    throw std::exception { "connectTest(): receive data ERROR!" };
                }
            }

            std::cout << "connectTest(): receive data SUCCESS!\n";

            std::shared_ptr<ISender> p_sender { std::make_shared<Sender>() };
            co_await p_sender->send(p_socket, result);

            std::cout << "connectTest(): send data SUCCESS!\n";
        }
    }
    catch (const std::exception &k_e) {
        std::cerr << "connectTest(): " << k_e.what() << '\n';
        system("pause");
    }
}
int main() {    
    setlocale(0, "");
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::thread accept_th { [&]() {
        boost::asio::co_spawn(g_io, acceptTest(), boost::asio::detached);
    } };
    std::thread connect_th { [&]() {
        boost::asio::co_spawn(g_io, connectTest(), boost::asio::detached);
    } };
    accept_th.join();
    connect_th.join();
    
    auto start { std::chrono::steady_clock::now() };
    g_io.run();

    auto end { std::chrono::steady_clock::now() };
    auto delta { std::chrono::duration<double, std::milli>(end - start).count() };
    std::cout << '\n' << delta / 1000 << "s.\n\n";
    system("pause");
}