/*
 * Реализуйте справочник столиц стран.
 * На вход программе поступают следующие запросы:
   - CHANGE_CAPITAL country new_capital — изменение столицы страны country на
 new_capital, либо добавление такой страны с такой столицей, если раньше её не
 было.
   - RENAME old_country_name new_country_name — переименование страны из
 old_country_name в new_country_name.
   - ABOUT country — вывод столицы страны country.
   - DUMP — вывод столиц всех стран.
   Формат ввода
   В первой строке содержится количество запросов Q, в следующих Q строках —
 описания запросов. Все названия стран и столиц состоят лишь из латинских букв,
 цифр и символов подчёркивания. Формат вывода Выведите результат обработки
 каждого запроса: В ответ на запрос CHANGE_CAPITAL country new_capital выведите
   - Introduce new country country with capital new_capital, если страны country
 раньше не существовало;
   - Country country hasn't changed its capital, если страна country до текущего
 момента имела столицу new_capital;
   - Country country has changed its capital from old_capital to new_capital,
 если страна country до текущего момента имела столицу old_capital, название
 которой не совпадает с названием new_capital. В ответ на запрос RENAME
 old_country_name new_country_name выведите
   - Incorrect rename, skip, если новое название страны совпадает со старым,
   страна old_country_name не существует или страна new_country_name уже
 существует;
   - Country old_country_name with capital capital has been renamed to
 new_country_name, если запрос корректен и страна имеет столицу capital. В ответ
 на запрос ABOUT country выведите
   - Country country doesn't exist, если страны с названием country не
 существует;
   - Country country has capital capital, если страна country существует и имеет
 столицу capital. В ответ на запрос DUMP выведите
   - There are no countries in the world, если пока не было добавлено ни одной
 страны; разделённые пробелами пары country/capital, описывающие столицы всех
 стран и упорядоченные по названию страны, если в мире уже есть хотя бы одна
 страна.
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
