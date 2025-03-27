#include <iostream>

int main()
{
    constexpr char zero{'0'};
    char cur;

    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> std::noskipws;
    std::cin >> cur;

    while (!std::cin.eof()) {
        if (!isdigit(cur)) {
            std::cout << cur;
            std::cin >> cur;
        } else if (cur == zero) {
            while (cur == zero && !std::cin.eof()) {
                std::cin >> cur;
            }
            if (!isdigit(cur) || std::cin.eof()) {
                std::cout << zero;
            }
        } else {
            while (isdigit(cur) && !std::cin.eof()) {
                std::cout << cur;
                std::cin >> cur;
            }
        }
    }
}