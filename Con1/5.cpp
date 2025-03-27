#include <iostream>
#include <sstream>
#include <vector>

constexpr size_t OCTET{4};  //порция данных
constexpr size_t OFFSET{8};  //смещение для преобразования числа из строки
constexpr size_t DATA_LEN{16};  //длина строки данных в октетах

uint32_t to_uint32_big_endian(const std::vector<unsigned char>& data, uint32_t start_index)
{
    uint32_t result = 0;
    for (size_t i = 0; i < OCTET; ++i) {
        result = (result << OFFSET) | data[start_index + i];
    }
    return result;
}

int main()
{
    std::string line;
    std::vector<unsigned char> data;

    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        uint32_t offset;
        uint32_t byte;
        ss >> std::hex >> offset;

        for (size_t i = 0; i < DATA_LEN; ++i) {
            if (ss >> std::hex >> byte) {
                data.push_back(static_cast<unsigned char>(byte));
            }
        }
    }

    size_t total_bytes = data.size();
    size_t num_full_numbers = total_bytes / OCTET;

    for (size_t i = 0; i < num_full_numbers; ++i) {
        uint32_t number = to_uint32_big_endian(data, i * OCTET);
        std::cout << number << std::endl;
    }
}
