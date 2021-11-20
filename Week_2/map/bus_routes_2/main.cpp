/*
 * В этой задаче вам нужно присваивать номера автобусным маршрутам.
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int q, route_count = 0;
  cin >> q;

  map<vector<string>, int> stops_to_route;

  for (int i = 0; i < q; ++i) {
    string stop;
    int n;
    cin >> n;
    vector<string> stops;
    for (int j = 0; j < n; ++j) {
      cin >> stop;
      stops.push_back(stop);
    }
    if (stops_to_route.count(stops) > 0) {
      cout << "Already exists for " << stops_to_route[stops] << endl;
    } else {
      stops_to_route[stops] = ++route_count;
      cout << "New bus " << stops_to_route[stops] << endl;
    }
  }

  return 0;
}
