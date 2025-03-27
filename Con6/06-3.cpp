#include <iostream>
#include <vector>

template<typename Iter, typename Func>
void myapply(Iter begin, Iter end, Func f)
{
    for (auto it = begin; it != end; ++it) {
        f(*it);
    }
}

template<typename Iter, typename Pred>
auto myfilter2(Iter begin, Iter end, Pred f)
{
    using T = typename std::iterator_traits<Iter>::value_type;
    std::vector<std::reference_wrapper<T>> res;

    for (auto it = begin; it != end; ++it) {
        if (f(*it)) {
            res.push_back(*it);
        }
    }

    return res;
}
