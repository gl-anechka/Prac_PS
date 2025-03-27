#include <iostream>
#include <list>

int main()
{
    std::list<int> num;
    int elem{0};

    while ((std::cin >> elem) && (elem != 0)) {
        num.push_back(elem);
    }

    while (std::cin >> elem) {
        if (elem < 0) {
            auto it = num.begin();
            int pos = -elem - 1;
            if (pos >= 0 && static_cast<size_t>(pos) < num.size()) {
                std::advance(it, pos);
                num.erase(it);
            }
        } else {
            auto it = num.begin();
            --elem;
            int val;
            std::cin >> val;
            if (elem >= 0 && static_cast<size_t>(elem) < num.size()) {
                std::advance(it, elem);
                num.insert(it, val);
            } else {
                num.push_back(val);
            }
        }
    }

    for (auto it = num.begin(); it != num.end(); ++it) {
        std::cout << *it << std::endl;
    }

    num.clear();
}
