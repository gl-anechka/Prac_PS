#include <iostream>
#include <array>
#include <string>
#include <map>

int main()
{
    std::map<std::string, std::array<int, 2>> arr;
    std::string cur_sur;
    int cur_gr;

    while (std::cin >> cur_sur >> cur_gr) {
        arr[cur_sur][0] += cur_gr;
        arr[cur_sur][1] += 1;
    }

    for (auto i : arr) {
        double mean = static_cast<double>(i.second[0]);
        mean /= static_cast<double>(i.second[1]);

        std::cout << i.first << " " << mean << std::endl;
    }
}