class C
{
public:
    int value;
    C(int v) : value(v) {}
    C(const C &v) : value(v.value) {}
    C(int v1, const C &v2) : value(v1 + v2.value) {}
    C(double v) : value(static_cast<int>(v)) {}

    C operator=(const C& a) {
        value = a.value;
        return *this;
    }

    C operator+(int v) const { return C(value + v); }

    C operator+=(const C& a) {
        value += a.value;
        return *this;
    }

    friend int operator+(const C& a, const C& b) {
        C res = a;
        res += b;
        return res.value;
    }

    C operator~() const { return C(~value); }

    C& operator++() {
        ++value;
        return *this;
    }

    C operator*(int v) const { return C(value * v); }

    C& operator[](int idx) { return *this; }
};