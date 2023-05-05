#ifndef DATAREFLECTION_HPP
#define DATAREFLECTION_HPP

#include <vector>
#include <string>

class Data {
private:
    std::vector<char> data_;

public:
    Data() noexcept;
    explicit Data(size_t _size) noexcept;
    explicit Data(size_t _size,
                  char _symbol) noexcept;
    explicit Data(const std::string &_k_data) noexcept;
    explicit Data(const std::vector<char> &_k_data) noexcept;

    const char *getRawData() const noexcept;
    char *getRawData() noexcept;
    size_t getSize() const noexcept;
    std::vector<char>::iterator begin() noexcept;
    std::vector<char>::iterator end() noexcept;

    void setSize(size_t _new_size) noexcept;
};

#endif
