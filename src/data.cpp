#include "../include/data.hpp"

Data::Data() noexcept 
    : data_ { } { }
Data::Data(size_t _size) noexcept
    : data_ { } {
    data_.resize(_size);
}
Data::Data(size_t _size, 
           char _symbol) noexcept
    : data_ { } {
    data_.resize(_size, _symbol);
}
Data::Data(const Data &_k_data) noexcept { 
    setData(_k_data);
}
Data::Data(const std::string &_k_data) noexcept {
    setData(_k_data);
}
Data::Data(const std::vector<char> &_k_data) noexcept {
    setData(_k_data);
}

const std::vector<char>& Data::getData() const noexcept {
    return data_;
}
const char *Data::getRawData() const noexcept {
    return data_.data();
}
char *Data::getRawData() noexcept {
    return data_.data();
}
size_t Data::getSize() const noexcept {
    return data_.size();
}
std::vector<char>::iterator Data::begin() noexcept {
    return data_.begin();
}
std::vector<char>::iterator Data::end() noexcept {
    return data_.end();
}

void Data::setData(const Data &_k_data) noexcept { 
    setData(_k_data.data_);
}
void Data::setData(const std::string &_k_data) noexcept {
    data_.clear();
    data_.resize(_k_data.size() + 1);
    memcpy_s(data_.data(), data_.size(), _k_data.data(), _k_data.size());
}
void Data::setData(const std::vector<char> &_k_data) noexcept {
    data_.clear();
    data_.resize(_k_data.size());
    memcpy_s(data_.data(), data_.size(), _k_data.data(), _k_data.size());
}
void Data::setSize(size_t _new_size) noexcept {
    data_.resize(_new_size);
}
void Data::clear() noexcept {
    data_.clear();
}