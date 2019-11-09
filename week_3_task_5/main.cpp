#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// если имя неизвестно, возвращает пустую строку
vector<string> FindAllNamesByYear(const map<int, string>& names, int year) {
  vector<string> all_names;  // изначально список имен пуст

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного и имени нет в списке, добавляем имя в список
    if (item.first <= year) {
        if(all_names.size() == 0){
            all_names.insert(all_names.begin(), item.second);
        }else if(all_names[0] != item.second){
            all_names.insert(all_names.begin(), item.second);
        }
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему илиэ
      // уже есть в списке
      break;
    }
  }
  return all_names;
}

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }

  return name;
}

// возвращает строку из вектора имен
string VectorToString(const vector<string>& names){
    string ans;
    ans += names[0];
    if(names.size() > 1){
        ans += " (";
        for(unsigned int i = 1; i < names.size(); ++i){
            ans += names[i];
            if(i != names.size() - 1){
                ans += ", ";
            }
        }
        ans += ")";
    }
    return ans;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";

    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";

    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }

  string GetFullNameWithHistory(int year){
      // получаем имена и фамилии по состоянию на год year
      const vector<string> first_names_by_year = FindAllNamesByYear(first_names, year);
      const vector<string> last_names_by_year = FindAllNamesByYear(last_names, year);

      // если и имя, и фамилия неизвестны
      if (first_names_by_year.empty() && last_names_by_year.empty()) {
        return "Incognito";

      // если неизвестно только имя
      } else if (first_names_by_year.empty()) {
        return VectorToString(last_names_by_year) + " with unknown first name";

      // если неизвестна только фамилия
      } else if (last_names_by_year.empty()) {
        return VectorToString(first_names_by_year) + " with unknown last name";

      // если известны и имя, и фамилия
      } else {

        return VectorToString(first_names_by_year) + " " + VectorToString(last_names_by_year);
      }

  }
private:
  map<int, string> first_names;
  map<int, string> last_names;
};


//int main()
//{
//    Person person;

//      person.ChangeFirstName(1900, "Eugene");
//      person.ChangeLastName(1900, "Sokolov");
//      person.ChangeLastName(1910, "Sokolov");
//      person.ChangeFirstName(1920, "Evgeny");
//      person.ChangeLastName(1930, "Sokolov");
//      cout << person.GetFullNameWithHistory(1940) << endl;

//      return 0;
//}
