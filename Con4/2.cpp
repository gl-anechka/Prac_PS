#include <iostream>
#include <vector>

void process(std::vector<int64_t> &num, const int64_t val)
{
    int count{0};

    for (auto it = num.begin(); it != num.end(); ++it) {
        if (*it >= val) {
            ++count;
        }
    }

    num.reserve(num.size() + count);

    for (auto it = num.rbegin(); it != num.rend(); ++it) {
        if (*it >= val) {
            num.push_back(*it);
        }
    }
}