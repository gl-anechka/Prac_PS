#include <iostream>
#include <vector>
#include <algorithm>

int count_bit(int val)
{
    int count{0};
    while (val > 0) {
        count += (val & 1);
        val >>= 1;
    }
    return count;
}

bool comp (const int &a, const int &b)
{
    int a_count = count_bit(a);
    int b_count = count_bit(b);

    return a_count < b_count;
}

int main()
{
    int cur;
    std::vector<int> arr;

    while (std::cin >> cur) {
        arr.push_back(cur);
    }

    std::stable_sort(arr.begin(), arr.end(), comp);

    for (auto i : arr) {
        std::cout << i << std::endl;
    }
}