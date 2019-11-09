#include <iostream>
#include <sstream>
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
// Ввод из потока
istream& operator>>(istream& stream, Rational& rational){
    int n = rational.Numerator(), d = rational.Denominator();
    if(stream){
        stream >> n;
        stream.ignore(1);
        stream >> d;
    }
        rational = Rational{n, d};
    return stream;
}

// Вывод в поток
ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
