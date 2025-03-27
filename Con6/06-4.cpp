#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

template <typename Iter1, typename Iter2>
Iter2 myremove(Iter1 begin, Iter1 end, Iter2 del_begin, Iter2 del_end)
{
    std::unordered_set<typename std::iterator_traits<Iter1>::value_type> valid_indices;
    auto elements_size = std::distance(del_begin, del_end);

    for (Iter1 it = begin; it != end; ++it) {
        if (*it >= 0 && *it < elements_size) {
            valid_indices.insert(*it);
        }
    }

    Iter2 write = del_begin;
    Iter2 read = del_begin;

    typename std::iterator_traits<Iter1>::value_type current_index{0};

    for (; read != del_end; ++read, ++current_index) {
        if (valid_indices.find(current_index) == valid_indices.end()) {
            if (write != read) {
                *write = std::move(*read);
            }
            ++write;
        }
    }
    return write;
}