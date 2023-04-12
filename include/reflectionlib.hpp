#ifndef REFLECTIONLIBREFLECTION_HPP
#define REFLECTIONLIBREFLECTION_HPP

#include "config.h"

#ifdef USE_COROUTINE

// Connection libraries
#include "async/connection/iacceptor.hpp"
#include "async/connection/acceptor.hpp"
#include "async/connection/iconnection.hpp"
#include "async/connection/connection.hpp"
// Transfer libraries
#include "async/transfer/ireceiver.hpp"
#include "async/transfer/receiver.hpp"
#include "async/transfer/isender.hpp"
#include "async/transfer/sender.hpp"

#else

#include "sync/connection/iacceptor.hpp"
#include "sync/connection/acceptor.hpp"
#include "sync/connection/iconnection.hpp"
#include "sync/connection/connection.hpp"
// Transfer libraries
#include "sync/transfer/ireceiver.hpp"
#include "sync/transfer/receiver.hpp"
#include "sync/transfer/isender.hpp"
#include "sync/transfer/sender.hpp"

#endif

#endif
