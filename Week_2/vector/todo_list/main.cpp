#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const vector<unsigned int> MONTH_LENGTHS = {31, 28, 31, 30, 31, 30,
                                            31, 31, 30, 31, 30, 31};

int main() {
  unsigned int q;
  cin >> q;

  // Номер текущего месяца
  unsigned int month = 0;

  vector<vector<string>> jobs(MONTH_LENGTHS[month]);

  while (q > 0) {
    string operation_code, s;
    cin >> operation_code;
    if (operation_code == "NEXT") {
      unsigned int next_m = (month + 1) % 12;
      if (MONTH_LENGTHS[next_m] > MONTH_LENGTHS[month]) {
        jobs.resize(MONTH_LENGTHS[next_m]);
      } else if (MONTH_LENGTHS[next_m] < MONTH_LENGTHS[month]) {
        for (unsigned int i = MONTH_LENGTHS[next_m]; i < MONTH_LENGTHS[month];
             i++) {
          jobs[MONTH_LENGTHS[next_m] - 1].insert(
              end(jobs[MONTH_LENGTHS[next_m] - 1]), begin(jobs[i]),
              end(jobs[i]));
        }
        jobs.resize(MONTH_LENGTHS[next_m]);
      }
      month = next_m;

    } else if (operation_code == "DUMP") {
      unsigned int day;
      cin >> day;
      cout << jobs[day - 1].size() << " ";
      for (auto s : jobs[day - 1]) {
        cout << s << " ";
      }
      cout << endl;

    } else if (operation_code == "ADD") {
      unsigned int day;
      string concern;
      cin >> day >> concern;
      jobs[day - 1].push_back(concern);
    }
    q--;
  }

  return 0;
}
