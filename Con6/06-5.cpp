#include <iostream>
#include <algorithm>

template<typename Iter, typename Func>
void selection_sort(Iter begin, Iter end, Func comp)
{
    for (auto it = begin; it!= end; ++it) {
        auto min = std::min_element(it, end, comp);
        std::iter_swap(it, min);
    }
}

template<typename Iter>
void selection_sort(Iter begin, Iter end)
{
    for (auto it = begin; it!= end; ++it) {
        auto min = std::min_element(it, end);
        std::iter_swap(it, min);
    }
}