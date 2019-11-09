/*
 * Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение invalid_argument,
 * если знаменатель равен нулю. Кроме того, переделайте реализацию оператора деления для класса Rational так,
 * чтобы он выбрасывал исключение domain_error, если делитель равен нулю.
 */
#include <iostream>
#include <exception>
#include <stdexcept>
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
        if(denominator == 0){
            throw invalid_argument("");
        }
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
// Меньше
bool operator<(const Rational& lhs, const Rational& rhs){
    return lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator();
}
// Умножение
Rational operator*(const Rational& lhs, const Rational& rhs){
    return Rational{lhs.Numerator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator()};
}
// Деление
Rational operator/(const Rational& lhs, const Rational& rhs){
    if(rhs.Numerator() == 0){
        throw domain_error("");
    }
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}