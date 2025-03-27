#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Functor
{
private:
    double sum{0.0};
    int count{0};

public:
    Functor() : sum(0), count(0) {}

    void operator()(double value) {
        sum += value;
        ++count;
    }

    double average() const {
        return sum / count;
    }
};

int main()
{
    constexpr int prec{10};
    std::vector<double> arr;
    double cur;

    while (std::cin >> cur) {
        arr.push_back(cur);
    }

    int drop_1 = arr.size() / 10; // 10% выборки
    std::sort(arr.begin() + drop_1, arr.end() - drop_1);
    int drop_2 = (arr.size() - 2 * drop_1) / 10; // 10% min и max

    Functor res = std::for_each(arr.begin() + drop_1 + drop_2, arr.end() - drop_1 - drop_2, Functor());

    std::cout << std::fixed << std::setprecision(prec) << res.average() << std::endl;
}