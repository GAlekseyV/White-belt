/*
 * Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы
 * Reverse для переворота строки и ToString для получения строки.
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ReversibleString{
public:
    ReversibleString(){

    }
    ReversibleString(const string& str){
        s = str;
    }

    void Reverse(){
        reverse(begin(s), end(s));
    }

    string ToString() const {
        return s;
    }

private:
    string s;
};

//int main()
//{
//    ReversibleString s("live");
//    s.Reverse();
//    cout << s.ToString() << endl;

//    s.Reverse();
//    const ReversibleString& s_ref = s;
//    string tmp = s_ref.ToString();
//    cout << tmp << endl;

//    ReversibleString empty;
//    cout << '"' << empty.ToString() << '"' << endl;

//  return 0;
//}
