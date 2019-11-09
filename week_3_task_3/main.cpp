/*
 * Реализуйте класс, поддерживающий набор строк в отсортированном порядке.
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SortedStrings{
public:
    void AddString(const string& s){
        // добавить строку s в набор
        _s.push_back(s);
    }
    vector<string> GetSortedStrings(){
        // получить набор из всех добавленных строк в отсортированном порядке
        sort(begin(_s), end(_s));
        return _s;
    }
private:
    vector<string> _s;
};

//void PrintSortedStrings(SortedStrings& strings){
//    for(const string& s : strings.GetSortedStrings()){
//        cout << s << " ";
//    }
//    cout << endl;
//}

//int main()
//{
//    SortedStrings strings;

//    strings.AddString("first");
//    strings.AddString("third");
//    strings.AddString("second");
//    PrintSortedStrings(strings);

//    strings.AddString("second");
//    PrintSortedStrings(strings);
//    return 0;
//}
