/*
 * ¬ стандартном потоке дана одна строка, состо€ща€ из числа N и следующих за ним N строк S.
 * ћежду собой число и строки разделены пробелом.
 * ќтсортируйте строки S в лексикографическом пор€дке по возрастанию, игнориру€ регистр букв,
 * и выведите их в стандартный поток вывода.
 * ќграничени€
 * 0 <= N <= 1000
 * 1 <= |S| <= 15
 *  ажда€ строка S[i] может состо€ть из следующих символов: [0-9,a-z,A-Z]
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool comp(string i, string j){
    for(unsigned int k = 0; k < i.size(); ++k){
        i[k] = tolower(i[k]);
    }
    for(unsigned int k = 0; k < j.size(); ++k){
        j[k] = tolower(j[k]);
    }
    return i < j;
}

int main()
{
    int n;
    string s;
    vector<string> words;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s;
        words.push_back(s);
    }

    sort(begin(words), end(words), comp);

    for(const auto& word : words){
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
