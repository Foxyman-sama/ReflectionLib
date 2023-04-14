#ifndef INPUTFILEREFLECTION_HPP
#define INPUTFILEREFLECTION_HPP

#include "iinput.hpp"

class InputFile 
    : public IInput {
public:
#ifdef USE_COROUTINE
    virtual Awaitable<Data> read(const std::string &_k_path) noexcept override;
#else 
    virtual Data read(const std::string &_k_path) noexcept override;
#endif
};

#endif
