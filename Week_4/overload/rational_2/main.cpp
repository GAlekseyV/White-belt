/*
 * Реализуйте для класса Rational операторы ==, + и - так, чтобы операции с дробями можно было записывать
 * естественным образом
 */
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

bool operator==(const Rational& lhs, const Rational& rhs){
    return lhs.Numerator() == rhs.Numerator()
           && lhs.Denominator() == rhs.Denominator();
}

bool operator!=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
