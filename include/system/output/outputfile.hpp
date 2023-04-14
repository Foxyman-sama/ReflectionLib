#ifndef OUTPUTFILEREFLECTION_HPP
#define OUTPUTFILEREFLECTION_HPP

#include "ioutput.hpp"

class OutputFile 
    : public IOutput {
public:
#ifdef USE_COROUTINE
    virtual AwaitVoid write(const std::string &_k_path,
                            ConstData _k_data) noexcept override;
#else 
    virtual void write(const std::string &_k_path,
                       ConstData _k_data) noexcept override;
#endif
};

#endif
