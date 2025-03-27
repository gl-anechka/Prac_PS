#include <iostream>

class A
{
private:
    int val;
    bool f{true};

public:
    A() : f(false) {
        std::cin >> val;
    }
    A(const A& other) {
        std::cin >> val;
        val += other.val;
    }
    ~A() {
        if (f) {
            std::cout << val;
        }
    }
};