#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <boost/asio.hpp>
#include <memory>
#include <vector>
#include "data.hpp"
#include "networkcfg.hpp"

namespace ip = boost::asio::ip;

using TCP = ip::tcp;
using Address = ip::address;
using SocketPtr = std::shared_ptr<TCP::socket>;
using Endpoint = TCP::endpoint;
#ifdef USE_COROUTINE
template<
    typename T>
using Awaitable = boost::asio::awaitable<T>;
#endif

inline boost::asio::io_context g_io { };

#endif
