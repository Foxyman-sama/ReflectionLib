#include "../../../include/system/output/outputfile.hpp"

#ifdef USE_COROUTINE
AwaitVoid write(const std::string &_k_path,
                ConstData _k_data) noexcept {
    std::ofstream fout { _k_path, std::ios_base::binary };
    fout.write(_k_data.data(), _k_data.size());
    co_return;
}
#else 
void write(const std::string &_k_path,
           ConstData _k_data) noexcept {
    std::ofstream fout { _k_path, std::ios_base::binary };
    fout.write(_k_data.data(), _k_data.size());
    return;
}
#endif