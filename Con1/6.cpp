#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double EPSILON{0.00001};
constexpr int PRECISION{5};
constexpr int EQUAL{2};
constexpr int INTERSEC{1};
constexpr int NOINTERSEC{0};

class Point
{
private:
    double x_, y_;

public:
    Point(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    Point& operator=(const Point &num) {
        x_ = num.x_;
        y_ = num.y_;
        return *this;
    }
};

class Line
{
private:
    double a_, b_, c_;

public:
    Line(Point p1 = Point(), Point p2 = Point()) {
        a_ = p2.y() - p1.y();
        b_ = p1.x() - p2.x();
        c_ = p1.x() * p2.y() - p2.x() * p1.y();
    }

    double a() const { return a_; }
    double b() const { return b_; }
    double c() const { return c_; }
};

bool eqtoz(double a)
{
    return (a < EPSILON && a > -EPSILON);
}

Point intersection(Line &l1, Line &l2, int &flag)
{
    double A1 = l1.a();
    double B1 = l1.b();
    double C1 = l1.c();

    double A2 = l2.a();
    double B2 = l2.b();
    double C2 = l2.c();

    double det = A1 * B2 - A2 * B1;
    double det_x = C1 * B2 - C2 * B1;
    double det_y = C2 * A1 - C1 * A2;

    Point res;

    if (eqtoz(det)) {
        if (eqtoz(det_x) && eqtoz(det_y)) {
            flag = EQUAL;
            return res;
        } else {
            flag = NOINTERSEC;
            return res;
        }
    } else {
        double res_x = det_x / det;
        double res_y = det_y / det;

        if (eqtoz(res_x)) {
            res_x = fabs(res_x);
        }
        if (eqtoz(res_y)) {
            res_y = fabs(res_y);
        }

        flag = INTERSEC;
        res = Point(res_x, res_y);
        return res;
    }
}

void get_points(void)
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Line l1(Point(x1, y1), Point(x2, y2)), l2(Point(x3, y3), Point(x4, y4));

    int flag{0};
    Point res = intersection(l1, l2, flag);

    std::cout << flag;
    if (flag == INTERSEC) {
        std::cout << ' ' << std::fixed << std::setprecision(PRECISION) << res.x() << ' ' << res.y() << std::endl;
    }
}

int main()
{
    get_points();
}
