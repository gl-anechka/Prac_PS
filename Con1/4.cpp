#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    constexpr int precision{10};

    double val;
    double sum{0.0};
    double sum_of_sq{0.0};
    int count{0};

    while (std::cin >> val) {
        sum += val;
        sum_of_sq += val * val;
        count++;
    }

    double mean = sum / count;
    double var = (sum_of_sq / count) - (mean * mean);
    double res = std::sqrt(var);

    std::cout << std::fixed << std::setprecision(precision);
    std::cout << mean << std::endl << res << std::endl;
}