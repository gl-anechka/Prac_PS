template<typename Cont, typename Pred>
Cont myfilter(const Cont &arg, Pred func)
{
    Cont res;

    for (auto i : arg) {
        if (func(i)) {
            res.insert(res.end(), i);
        }
    }

    return res;
}