#include <iostream>

constexpr int BUF_LEN{4};
constexpr char SYMBOL{'#'};

void print_seq(int count, char prev)
{
    if ((count > BUF_LEN) || (prev == SYMBOL)) {
        std::cout << SYMBOL << prev << std::hex << count << SYMBOL;
    } else {
        for (int i = 0; i < count; ++i) {
            std::cout << prev;
        }
    }
}

int main()
{
    char prev, cur;
    int count{1};

    if (!(std::cin >> std::noskipws >> prev)) {
        return 0;
    }

    while (std::cin.get(cur)) {
        if (cur != prev) {
            print_seq(count, prev);
            count = 1;
        } else {
            ++count;
        }
        prev = cur;
    }

    if (count != 0) {
        print_seq(count, prev);
    }

    return 0;
}
