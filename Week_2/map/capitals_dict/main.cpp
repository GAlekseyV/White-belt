/*
 * Cправочник столиц стран.
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

//  Вывод столиц всех стран.
void dump(const map<string, string>& m) {
  if (m.size() > 0) {
    for (auto item : m) {
      cout << item.first << "/" << item.second << " ";
    }
    cout << endl;
  } else {
    cout << "There are no countries in the world" << endl;
  }
}

// Вывод столицы страны country.
void about(map<string, string>& m, const string& country) {
  if (m.count(country) > 0) {
    cout << "Country " << country << " has capital " << m[country] << endl;
  } else {
    cout << "Country " << country << " doesn't exist" << endl;
  }
}

//  Переименование страны из old_country_name в new_country_name
void rename(map<string, string>& m, const string& o_c_name,
            const string& n_c_name) {
  if (o_c_name == n_c_name || m.count(o_c_name) < 1 || m.count(n_c_name) > 0) {
    cout << "Incorrect rename, skip" << endl;
  } else {
    string cap = m[o_c_name];
    cout << "Country " << o_c_name << " with capital " << cap
         << " has been renamed to " << n_c_name << endl;
    m.erase(o_c_name);
    m[n_c_name] = cap;
  }
}

//  Изменение столицы страны country на new_capital, либо добавление такой
//  страны с такой столицей, если раньше её не было.
void change_capital(map<string, string>& m, const string& country,
                    const string& cap) {
  if (m.count(country) == 0) {
    m[country] = cap;
    cout << "Introduce new country " << country << " with capital "
         << m[country] << endl;
  } else if (m[country] == cap) {
    cout << "Country " << country << " hasn't changed its capital" << endl;
  } else if (m[country] != cap) {
    cout << "Country " << country << " has changed its capital from "
         << m[country] << " to " << cap << endl;
    m[country] = cap;
  }
}

int main() {
  map<string, string> capBook;
  int q;
  cin >> q;
  string command, country, new_capital, old_country, new_coutnry;

  for (int i = 0; i < q; ++i) {
    cin >> command;
    if (command == "CHANGE_CAPITAL") {
      cin >> country >> new_capital;
      change_capital(capBook, country, new_capital);
    } else if (command == "RENAME") {
      cin >> old_country >> new_coutnry;
      rename(capBook, old_country, new_coutnry);
    } else if (command == "ABOUT") {
      cin >> country;
      about(capBook, country);
    } else if (command == "DUMP") {
      dump(capBook);
    }
  }

  return 0;
}
