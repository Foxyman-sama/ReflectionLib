#ifndef OUTPUTFILEREFLECTION_HPP
#define OUTPUTFILEREFLECTION_HPP

#include "ioutput.hpp"

class OutputFile 
    : public IOutput {
public:
#ifdef USE_COROUTINE
    Awaitable<void> write(const std::string &_k_path,
                          const Data &_k_data) noexcept override;
#else 
    void write(const std::string &_k_path,
               const Data &_k_data) noexcept override;
#endif
};

#endif
