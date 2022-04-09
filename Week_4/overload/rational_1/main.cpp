/*
 * В первой части вам надо реализовать класс Rational, который представляет собой рациональное число вида p/q,
 * где p целое, а q натуральное. Он должен иметь следующий интерфейс:
 * Класс Rational должен гарантировать, что p/q — это несократимая дробь.
 * Список требований, предъявляемых к реализации интерфейса класса Rational:
 * - Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
 * - При конструировании объека класса Rational с параметрами p и q должно выполняться сокращение дроби p/q
 *  (здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
 * - Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный
 *   знаменатель.
 * -  Если дробь p/q положительная, то объект Rational(p, q) должен иметь положительные числитель и знаменатель
 *   (обратите внимание на случай Rational(-2, -3)).
 * - Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
 * Гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет знаменателя,
 * равного нулю.
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
        int divider = gcd(numerator, denominator);
        _numerator = numerator / divider;
        _denominator = denominator / divider;
    }

    int Numerator() const {
        return _numerator;
    }

    int Denominator() const {
        return _denominator;
    }

private:
    int gcd(int a, int b) const {
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        return a + b;
    }

    int _numerator;
    int _denominator;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}