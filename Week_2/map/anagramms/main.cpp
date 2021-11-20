/*
 * Анаграммы
 */
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
  map<char, int> ans;
  for (auto c : word) {
    ans[c] += 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  string word1, word2;
  for (int i = 0; i < n; ++i) {
    cin >> word1 >> word2;
    if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
