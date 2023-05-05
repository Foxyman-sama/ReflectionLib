#ifndef DATAREFLECTION_HPP
#define DATAREFLECTION_HPP

#include <vector>
#include <string>

class Data {
private:
    std::vector<char> data_;

public:
    Data() noexcept;
    Data(size_t _size) noexcept;
    Data(size_t _size,
         char _symbol) noexcept;
    Data(const Data &_k_data) noexcept;
    Data(const std::string &_k_data) noexcept;
    Data(const std::vector<char> &_k_data) noexcept;

    const std::vector<char> &getData() const noexcept;
    const char *getRawData() const noexcept;
    char *getRawData() noexcept;
    size_t getSize() const noexcept;
    std::vector<char>::iterator begin() noexcept;
    std::vector<char>::iterator end() noexcept;

    void setData(const Data &_k_data) noexcept;
    void setData(const std::string &_k_data) noexcept;
    void setData(const std::vector<char> &_k_data) noexcept;
    void setSize(size_t _new_size) noexcept;
    void clear() noexcept;
};

#endif
