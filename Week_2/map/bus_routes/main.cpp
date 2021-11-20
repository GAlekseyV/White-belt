/*
 * Cистема хранения автобусных маршрутов.
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int q;
  string operation_code;
  map<string, vector<string>> bus_to_stops;
  map<string, vector<string>> stop_to_busses;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    cin >> operation_code;
    if (operation_code == "NEW_BUS") {
      string bus, stop;
      int stop_count;
      cin >> bus >> stop_count;
      bus_to_stops[bus];
      for (int j = 0; j < stop_count; ++j) {
        cin >> stop;
        bus_to_stops[bus].push_back(stop);
        stop_to_busses[stop].push_back(bus);
      }

    } else if (operation_code == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      if (stop_to_busses.count(stop) > 0) {
        for (auto b : stop_to_busses[stop]) {
          cout << b << " ";
        }
        cout << endl;
      } else {
        cout << "No stop" << endl;
      }
    } else if (operation_code == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      if (bus_to_stops.count(bus) > 0) {  // Автобус существует
        for (auto stop : bus_to_stops[bus]) {
          cout << "Stop " << stop << ": ";
          if (stop_to_busses[stop].size() > 1) {
            for (auto b : stop_to_busses[stop]) {
              if (b != bus) {
                cout << b << " ";
              }
            }
          } else {
            cout << "no interchange";
          }
          cout << endl;
        }
      } else {
        cout << "No bus" << endl;
      }

    } else if (operation_code == "ALL_BUSES") {
      if (bus_to_stops.size() > 0) {
        for (auto b : bus_to_stops) {
          cout << "Bus " << b.first << ": ";
          for (auto stop : b.second) {
            cout << stop << " ";
          }
          cout << endl;
        }
      } else {
        cout << "No buses" << endl;
      }
    }
  }
  return 0;
}
