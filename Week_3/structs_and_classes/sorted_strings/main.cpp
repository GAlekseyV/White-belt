#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SortedStrings {
 public:
  void AddString(const string& s) { _s.push_back(s); }
  vector<string> GetSortedStrings() {
    sort(begin(_s), end(_s));
    return _s;
  }

 private:
  vector<string> _s;
};
