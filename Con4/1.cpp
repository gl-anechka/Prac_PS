#include <iostream>
#include <vector>

void process(const std::vector<uint64_t> &num1, std::vector<uint64_t> &num2, int step)
{
    auto it1 = num1.begin();
    auto it2 = num2.rbegin();

    while (it1 < num1.end() && it2 < num2.rend()) {
        *it2 += *it1;
        it1 += step;
        ++it2;
    }
}