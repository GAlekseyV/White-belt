/*
 * Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений.
 * Гарантируется, что содержимое файла input.txt заканчивается переводом строки.
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    ifstream input("input.txt");
    if(input.is_open()){
        while(getline(input, line)){
            cout << line << endl;
        }
    }
    return 0;
}