#ifndef IOUTPUTREFLECTION_HPP
#define IOUTPUTREFLECTION_HPP

#include <fstream>
#include <string>
#include "../../definitions.hpp"

class IOutput {
public:
#ifdef USE_COROUTINE
    virtual Awaitable<void> write(const std::string &_k_path,
                                  const Data &_k_data) noexcept = 0;
#else 
    virtual void write(const std::string &_k_path,
                       const Data &_k_data) noexcept = 0;
#endif
};

#endif
