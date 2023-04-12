#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <boost/asio.hpp>
#include <memory>
#include <vector>

namespace ip = boost::asio::ip;

using TCP           = ip::tcp;
using Address       = ip::address;
using SocketPtr     = std::shared_ptr<TCP::socket>;
using Data          = std::vector<char>;
using ConstData     = const Data &;
using Endpoint      = TCP::endpoint;
using ConstEndpoint = const Endpoint &;

inline boost::asio::io_context g_io { };

#endif
