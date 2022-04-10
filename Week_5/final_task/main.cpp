/*
 * Простая БД. Программа общается с пользователем через стандартный ввод и вывод
 * (потоки stdin и stdout). В БД  храняться пары вида: дата, событие. Определим
 * дату как строку вида Год-Месяц-День, где Год, Месяц и День — целые числа.
 * Событие определим как строку из произвольных печатных символов без
 * разделителей внутри (пробелов, табуляций и пр.). Событие не может быть пустой
 * строкой. В одну и ту же дату может произойти много разных событий, БД должна
 * суметь их все сохранить. Одинаковые события, произошедшие в один и тот же
 * день, сохранять не нужно: достаточно сохранить только одно из них. БД должна
 * понимать определённые команды, чтобы с ней можно было взаимодействовать:
 * - добавление события:                        Add Дата Событие
 * - удаление события:                          Del Дата Событие
 * - удаление всех событий за конкретную дату:  Del Дата
 * - поиск событий за конкретную дату:          Find Дата
 * - печать всех событий за все даты:           Print
 * Все команды, даты и события при вводе разделены пробелами. Команды
 * считываются из стандартного ввода. В одной строке может быть ровно одна
 * команда, но можно ввести несколько команд в несколько строк. На вход также
 * могут поступать пустые строки — их следует игнорировать и продолжать
 * обработку новых команд в последующих строках.
 */
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

class Date {
 public:
  Date() {
    year = 0;
    month = 0;
    day = 0;
  }

  explicit Date(const string& new_date) {  // Дата в формате Год-Месяц-День
    stringstream input(new_date);
    int new_year = 0, new_month = 0, new_day = 0;
    const int days_in_months = 31;
    const int month_in_year = 12;
    if (input) {
      input >> new_year;
      CheckDelimiter(input, new_date);
      input >> new_month;
      CheckMonth(new_month);
      CheckDelimiter(input, new_date);
      input >> new_day;
      CheckDay(new_day);
      string end;
      input >> end;
      if (!end.empty()) {
        throw runtime_error("Wrong date format: " + new_date);
      }
    }
    year = new_year;
    month = new_month;
    day = new_day;
  }
  int GetYear() const { return year; }
  int GetMonth() const { return month; }
  int GetDay() const { return day; }

 private:
  void CheckDelimiter(istream& input, const string& new_date) const {
    int c = input.get();
    if (c != '-') {
      throw runtime_error("Wrong date format: " + new_date);
    }
    c = input.get();
    if (!isdigit(c) || c == '-') {
      if (!isdigit(input.peek())) {
        throw runtime_error("Wrong date format: " + new_date);
      }
    }
    input.putback(char(c));
  }

  void CheckMonth(int month) const {
    if (month < 1 || month > 12) {
      throw runtime_error("Month value is invalid: " + to_string(month));
    }
  }

  void CheckDay(int day) const {
    if (day < 1 || day > 31) {
      throw runtime_error("Day value is invalid: " + to_string(day));
    }
  }

  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() != rhs.GetYear()) {
    return lhs.GetYear() < rhs.GetYear();
  } else if (lhs.GetMonth() != rhs.GetMonth()) {
    return lhs.GetMonth() < rhs.GetMonth();
  } else {
    return lhs.GetDay() < rhs.GetDay();
  }
}

ostream& operator<<(ostream& stream, const Date& date) {
  cout << setfill('0') << setw(4) << date.GetYear() << '-' << setw(2)
       << date.GetMonth() << '-' << setw(2) << date.GetDay();
  return stream;
}

class Database {
 public:
  void AddEvent(const Date& date, const string& event) {
    db[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
    if (db.count(date) > 0) {
      if (!db.at(date).empty() && db.at(date).count(event) > 0) {
        db.at(date).erase(event);
        return true;
      }
    }
    return false;
  }

  int DeleteDate(const Date& date) {
    unsigned int event_num = 0;
    if (db.count(date) > 0) {
      event_num = db.at(date).size();
      db.at(date).clear();
    }
    return event_num;
  }

  set<string> Find(const Date& date) const {
    if (db.count(date)) {
      return db.at(date);
    }
    return {};
  }

  void Print() const {
    for (const auto& date : db) {
      for (const auto& event : date.second) {
        cout << date.first << " ";
        cout << event << endl;
      }
    }
  }

 private:
  map<Date, set<string>> db;
};

string ReadOpCode(istream& input) {
  string command;
  input >> command;
  return command;
}

Date ReadDate(istream& input) {
  string new_date;
  input >> new_date;
  return Date{new_date};
}

string ReadEvent(istream& input) {
  string new_event;
  input >> new_event;
  return new_event;
}

void PrintEvents(const set<string>& events) {
  for (auto& event : events) {
    cout << event << endl;
  }
}

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
    if (!command.empty()) {  // Пустая строка
      stringstream input(command);
      string op_code = ReadOpCode(input);
      if (op_code == "Add") {
        Date d;
        try {
          d = ReadDate(input);
        } catch (exception& ex) {
          cout << ex.what() << endl;
          continue;
        }
        db.AddEvent(d, ReadEvent(input));
      } else if (op_code == "Del") {
        Date d;
        try {
          d = ReadDate(input);
        } catch (exception& ex) {
          cout << ex.what() << endl;
          continue;
        }
        string event = ReadEvent(input);
        if (!event.empty()) {
          if (db.DeleteEvent(d, event)) {
            cout << "Deleted successfully" << endl;
          } else {
            cout << "Event not found" << endl;
          }
        } else {
          cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
        }
      } else if (op_code == "Find") {
        Date d;
        try {
          d = ReadDate(input);
        } catch (exception& ex) {
          cout << ex.what() << endl;
          continue;
        }
        PrintEvents(db.Find(d));
      } else if (op_code == "Print") {
        db.Print();
      } else {
        cout << "Unknown command: " << op_code << endl;
      }
    }
  }

  return 0;
}
