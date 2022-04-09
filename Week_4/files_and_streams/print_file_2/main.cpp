/*
 * В файле input.txt записаны вещественные числа, по одному на строчку. На стандартный вывод напечатайте
 * эти числа в том же порядке, по одному на строке, но сделайте так, чтобы у каждого из них было ровно
 * три знака после десятичной точки (округление производится по стандартным правилам, т.е. 0.1234 округляется
 * до 0.123, а 0.1235 до 0.124).
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("input.txt");
    if(input.is_open()){
        cout << fixed << setprecision(3);
        for(double x; input >> x;){
            cout << x;
            if(!input.eof()){
                cout << endl;
            }
        }
    }
    return 0;
}