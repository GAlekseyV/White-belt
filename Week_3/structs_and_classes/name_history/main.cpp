#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
 public:
  void ChangeFirstName(int year, const string& first_name) {
    year_to_firstname[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    year_to_lastname[year] = last_name;
  }
  string GetFullName(int year) {
    if (isIncognito(year)) {
      return "Incognito";
    } else if (isNoChangeFirstName(year)) {
      return GetLastName(year) + " with unknown first name";
    } else if (isNoChangeLastName(year)) {
      return GetFirstName(year) + " with unknown last name";
    } else {
      return GetFirstName(year) + " " + GetLastName(year);
    }
  }

 private:
  string GetFirstName(int year) {
    int lastChangeYear = year;
    for (const auto& i : year_to_firstname) {
      if (i.first <= year) {
        lastChangeYear = i.first;
      } else {
        break;
      }
    }
    return year_to_firstname[lastChangeYear];
  }
  string GetLastName(int year) {
    int lastChangeYear = year;
    for (const auto& i : year_to_lastname) {
      if (i.first <= year) {
        lastChangeYear = i.first;
      } else {
        break;
      }
    }
    return year_to_lastname[lastChangeYear];
  }

  bool isIncognito(int year) {
    return isNoChangeFirstName(year) && isNoChangeLastName(year);
  }

  bool isNoChangeFirstName(int year) {
    int count = 0;
    for (const auto& i : year_to_firstname) {
      if (i.first <= year) {
        count++;
      }
    }
    return count == 0;
  }

  bool isNoChangeLastName(int year) {
    int count = 0;
    for (const auto& i : year_to_lastname) {
      if (i.first <= year) {
        count++;
      }
    }
    return count == 0;
  }

  map<int, string> year_to_firstname;
  map<int, string> year_to_lastname;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  return 0;
}
