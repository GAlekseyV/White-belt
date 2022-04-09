/*
 * Cчитайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt.
 * Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream input("input.txt");
    ofstream output("output.txt");
    if(input.is_open()){
        while(getline(input, line)){
            output << line << endl;
        }
    }
    return 0;
}