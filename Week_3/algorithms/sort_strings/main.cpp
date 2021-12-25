#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n{0};
  string s;
  cin >> n;
  vector<string> v(n);
  for (string& s : v) {
    cin >> s;
  }

  sort(begin(v), end(v), [](const string& l, const string& r) {
    return lexicographical_compare(
        begin(l), end(l), begin(r), end(r),
        [](char cl, char cr) { return tolower(cl) < tolower(cr); });
  });

  for (const auto& word : v) {
    cout << word << " ";
  }
  cout << endl;
  return 0;
}
