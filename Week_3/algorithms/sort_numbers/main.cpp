#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  long num;
  vector<int> nums;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    nums.push_back(num);
  }

  sort(begin(nums), end(nums), [](long i, long j) { return abs(i) < abs(j); });

  for (const auto num : nums) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
