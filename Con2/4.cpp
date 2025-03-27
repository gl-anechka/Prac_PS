#include <iostream>

class BinaryNumber
{
private:
    std::string val;

public:
    BinaryNumber(const std::string &s) : val(s) {}

    operator std::string () const {
        return val;
    }
    const BinaryNumber &operator++() {
        for (int i = val.length() - 1; i >= 0; i--) {
            if (val[i] == '0') {
                val[i] = '1';
                return *this;
            } else {
                val[i] = '0';
            }
        }
        val = '1' + val;
        return *this;
    }
};