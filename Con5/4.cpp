#include <iostream>
#include <map>

constexpr uint64_t MOD{4294967161LL};

int main()
{
    std::map<std::pair<uint32_t, uint32_t>, uint64_t> matr;
    uint32_t r, c;
    uint64_t v;

    std::cin >> r >> c >> v;
    while (r != 0 || c != 0 || v != MOD) {
        matr[{r, c}] = v;
        std::cin >> r >> c >> v;
    }

    while (std::cin >> r >> c >> v) {
        matr[{r, c}] = (matr[{r, c}] + v) % MOD;
    }

    for (auto it = matr.begin(); it != matr.end(); ++it) {
        if (it->second != 0) {
            std::cout << it->first.first << " " << it->first.second << " " << it->second << std::endl;
        }
    }
}