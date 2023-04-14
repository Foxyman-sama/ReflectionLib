#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <boost/asio.hpp>
#include <memory>
#include <vector>
#include "networkcfg.hpp"

namespace ip = boost::asio::ip;

using TCP = ip::tcp;
using Address = ip::address;
using SocketPtr = std::shared_ptr<TCP::socket>;
using Data = std::vector<char>;
using ConstData = const Data &;
using Endpoint = TCP::endpoint;
using ConstEndpoint = const Endpoint &;
#ifdef USE_COROUTINE
template<
    typename T>
using Awaitable = boost::asio::awaitable<T>;

using AwaitVoid = Awaitable<void>;
using AwaitSPtr = Awaitable<SocketPtr>;
#endif

inline boost::asio::io_context g_io { };

#endif
