#include "../../../include/system/input/inputfile.hpp"

#ifdef USE_COROUTINE
Awaitable<Data> InputFile::read(const std::string &_k_path) noexcept {
    std::ifstream fin { _k_path, std::ios_base::binary };
    fin.seekg(0, fin.end);

    size_t size_of_data { static_cast<size_t>(fin.tellg()) };
    fin.seekg(0, fin.beg);

    Data data { size_of_data };
    fin.read(data.getRawData(), size_of_data);
    co_return data;
}
#else 
Data InputFile::read(const std::string &_k_path) noexcept {
    std::ifstream fin { _k_path, std::ios_base::binary };
    fin.seekg(0, fin.end);

    size_t size_of_data { static_cast<size_t>(fin.tellg()) };
    fin.seekg(0, fin.beg);

    Data data { size_of_data };
    fin.read(data.getRawData(), size_of_data);
    return data;
}
#endif