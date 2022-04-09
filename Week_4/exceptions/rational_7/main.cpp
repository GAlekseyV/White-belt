/*
 * Cчитывает из стандартного ввода одну строку в формате ДРОБЬ_1 операция ДРОБЬ_2.
 * ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое, а Y — целое неотрицательное число,
 * операция — это один из символов '+', '-', '*', '/'.
 * Если ДРОБЬ_1 или ДРОБЬ_2 является некорректной обыкновенной дробью, ваша программа должна
 * вывести в стандартный вывод сообщение "Invalid argument". Если считанная операция — это деление на ноль,
 * выведите в стандартный вывод сообщение "Division by zero". В противном случае выведите результат операции.
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
            throw invalid_argument("Invalid argument");
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
        throw domain_error("Division by zero");
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

Rational ReadRational(istream& stream){
    int n, d;
    cin >> n;
    if(cin.peek() != '/'){
        throw runtime_error("Invalid argument");
    }
    cin.ignore(1);
    cin >> d;
    return Rational(n, d);
}

int main(){
    Rational r1;
    Rational r2;
    string operation_code;

    try{
        r1 = ReadRational(cin);
        cin >> operation_code;
        r2 = ReadRational(cin);

        if(operation_code == "+"){
            cout << r1 + r2;
        }else if(operation_code == "-"){
            cout << r1 - r2;
        }else if(operation_code == "*"){
            cout << r1 * r2;
        }else if(operation_code == "/"){
            cout << r1 / r2;
        }else{
            cout << "Undefined operation";
        }
    }catch(exception& ex){
        cout << ex.what();
    }
    return 0;
}