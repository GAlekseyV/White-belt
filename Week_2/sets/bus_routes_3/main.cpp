/*
 * Для каждого марштрута, заданного множеством названий оснатовок, нужно либо
 * выдать новый номер (первому маршруту - 1, второму - 2 и т.д.), либо вернуть
 * номер существующего маршрута, которому соответствует такое множество
 * остановок. В отличие от задачи "Автобусные остановки - 2", наборы остановок,
 * которые можно получить друг из друга перестановкой элементов или
 * добавлением/удалением повторяющихся, следует считать одиннаковыми.
 */
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
  int q, route_count = 0;
  cin >> q;

  map<set<string>, int> stops_to_route;

  for (int i = 0; i < q; ++i) {
    string stop;
    int n;
    cin >> n;
    set<string> stops;
    for (int j = 0; j < n; ++j) {
      cin >> stop;
      stops.insert(stop);
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
