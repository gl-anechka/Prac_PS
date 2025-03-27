class Sum
{
private:
    int val;

public:
    Sum(int a, int b) : val(a + b) {}
    Sum(Sum a,  int b) : val(a.get() + b) {}
    Sum(int a,  Sum b) : val(a + b.get()) {}

    int get() const {
        return val;
    }
};