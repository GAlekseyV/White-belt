/*
 * Синонимы
 */
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<string, set<string>> m;

  string operation_code, word1, word2;
  for (int i = 0; i < q; ++i) {
    cin >> operation_code;
    if (operation_code == "COUNT") {
      cin >> word1;
      unsigned int count = m[word1].size();
      cout << count << endl;
    } else if (operation_code == "ADD") {
      cin >> word1 >> word2;
      m[word1].insert(word2);
      m[word2].insert(word1);
    } else if (operation_code == "CHECK") {
      cin >> word1 >> word2;
      if (m[word1].count(word2) > 0 || m[word2].count(word1) > 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
