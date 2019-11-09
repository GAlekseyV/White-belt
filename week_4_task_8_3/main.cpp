#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        _numerator = 0;
        _denominator = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if(numerator < 0 && denominator < 0){
            numerator = -numerator;
            denominator = - denominator;
        }else if(denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
        _numerator = numerator;
        _denominator = denominator;
        reduce(_numerator, _denominator);
    }

    int Numerator() const {
        return _numerator;
    }

    int Denominator() const {
        return _denominator;
    }

private:
    int gcd(int n, int d) const {
        if(n < 0) n = -n;
        if(d < 0) d = -d;
        while (n > 0 && d > 0) {
            if (n > d) {
                n %= d;
            } else {
                d %= n;
            }
        }
        return n + d;
    }
    // Сократить
    void reduce(int& n, int& d){
        int divider = gcd(n, d);
        n = n / divider;
        d = d / divider;
    }

    int _numerator;
    int _denominator;
};

// Унарный +
Rational operator+(const Rational& rhs){
    return rhs;
}
// Бинарный +
Rational operator+(const Rational& lhs, const Rational& rhs){
    return Rational{lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator()};
}
// Унарный -
Rational operator-(const Rational& rhs){
    return Rational{-rhs.Numerator(), rhs.Denominator()};
}
// Бинарный -
Rational operator-(const Rational& lhs, const Rational& rhs){
    return Rational{lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
                    lhs.Denominator() * rhs.Denominator()};
}
// Равно
bool operator==(const Rational& lhs, const Rational& rhs){
    return lhs.Numerator() == rhs.Numerator()
           && lhs.Denominator() == rhs.Denominator();
}
// Не равно
bool operator!=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}
// Умножение
Rational operator*(const Rational& lhs, const Rational& rhs){
    return Rational{lhs.Numerator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator()};
}

// Деление
Rational operator/(const Rational& lhs, const Rational& rhs){
    return Rational{lhs.Numerator() * rhs.Denominator(),
                    lhs.Denominator() * rhs.Numerator()};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
