#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
private:
    vector<vector<int>> m;

public:
    Matrix() : m(vector<vector<int>>(3, vector<int>(3))) {}

    int &operator[](int i, int j) {
        return m[i][j];
    }

    vector<vector<int>>::iterator begin() {
        return m.begin();
    }

    vector<vector<int>>::iterator end() {
        return m.end();
    }
};