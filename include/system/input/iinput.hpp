#ifndef IINPUTREFLECTION_HPP
#define IINPUTREFLECTION_HPP

#include <fstream>
#include <string>
#include "../../definitions.hpp"

class IInput {
public:
#ifdef USE_COROUTINE
    virtual Awaitable<Data> read(const std::string &_k_path) noexcept = 0;
#else 
    virtual Data read(const std::string &_k_path) noexcept = 0;
#endif
};

#endif
