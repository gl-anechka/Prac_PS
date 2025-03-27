#include <iostream>

template<typename T>
typename T::value_type process(const T &arg)
{
    if (arg.empty()) {
        return typename T::value_type();
    }

    auto it = arg.end();
    --it;

    typename T::value_type sum = *it;

    if (arg.size() >= 3) {
        std::advance(it, -2);
        sum += *it;
    }

    if (arg.size() >= 5) {
        std::advance(it, -2);
        sum += *it;
    }

    return sum;
}