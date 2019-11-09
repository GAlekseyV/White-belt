/*
 * Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
 * Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного
 * изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого
 * человека, поэтому года? в последовательных вызовах методов ChangeLastName и ChangeFirstName не
 * обязаны возрастать.
 * Гарантируется, что все имена и фамилии непусты.
 * Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя
 * и фамилию человека по состоянию на конец данного года.
 * Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
 * Если к данному году случилось изменение фамилии, но не было ни одного изменения имени,
 * верните "last_name with unknown first name".
 * Если к данному году случилось изменение имени, но не было ни одного изменения фамилии,
 * верните "first_name with unknown last name".
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
      year_to_firstname[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
      year_to_lastname[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
      if(isIncognito(year)){
          return "Incognito";
      }else if(isNoChangeFirstName(year)){
          return GetLastName(year) + " with unknown first name";
      }else if(isNoChangeLastName(year)){
          return GetFirstName(year) + " with unknown last name";
      }else{
          return GetFirstName(year) + " " + GetLastName(year);
      }
  }
private:
  // приватные поля
  string GetFirstName(int year){
      // ищу год последнего изменения
      int lastChangeYear = year;
      for(const auto& i : year_to_firstname){
          if(i.first <= year){
              lastChangeYear = i.first;
          }else{
              break;
          }
      }
      return year_to_firstname[lastChangeYear];
  }
  string GetLastName(int year){
      // ищу год последнего изменения
      int lastChangeYear = year;
      for(const auto& i : year_to_lastname){
          if(i.first <= year){
              lastChangeYear = i.first;
          }else{
              break;
          }
      }
      return year_to_lastname[lastChangeYear];
  }

  bool isIncognito(int year){
      return isNoChangeFirstName(year) && isNoChangeLastName(year);
  }

  bool isNoChangeFirstName(int year){
      int count = 0;
      for(const auto& i : year_to_firstname){
          if(i.first <= year){
              count++;
          }
      }
      return count == 0;
  }

  bool isNoChangeLastName(int year){
      int count = 0;
      for(const auto& i : year_to_lastname){
          if(i.first <= year){
              count++;
          }
      }
      return count == 0;
  }



  map<int, string> year_to_firstname;
  map<int, string> year_to_lastname;
};


int main()
{
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
