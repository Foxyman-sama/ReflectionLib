#include "../../../include/system/output/outputfile.hpp"

#ifdef USE_COROUTINE
Awaitable<void> OutputFile::write(const std::string &_k_path,
                                  const Data &_k_data) noexcept {
    std::ofstream fout { _k_path, std::ios_base::binary };
    fout.write(_k_data.getRawData(), _k_data.getSize());
    co_return;
}
#else 
void OutputFile::write(const std::string &_k_path,
                       const Data &_k_data) noexcept {
    std::ofstream fout { _k_path, std::ios_base::binary };
    fout.write(_k_data.getRawData(), _k_data.getSize());
    return;
}
#endif