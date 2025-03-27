#include <iostream>
#include <vector>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    if (v1.size() == 0 || v2.size() == 0) {
        return;
    }

    std::vector<int> new_v1 = v1;
    std::sort(new_v1.begin(), new_v1.end());
    new_v1.erase(std::unique(new_v1.begin(), new_v1.end()), new_v1.end());

    for (auto it = new_v1.rbegin(); it != new_v1.rend(); ++it) {
        if (*it >= 0 && *it < static_cast<int>(v2.size())) {
            v2.erase(v2.begin() + *it);
        }
    }
}