/*
 * Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения.
 * Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.
 * Формат ввода
 * Первая строка содержит одно целое число N от 0 до 10000 — число студентов.
 * Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов —
 * имя и фамилию очередного студента, и три целых числа от 0 до 1000000000 — день, месяц и год рождения.
 * Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.
 * Следующие M строк содержат строку длиной от 1 до 15 символов — запрос,
 * и целое число от 0 до 1000000000 — номер студента (нумерация начинается с 1).
 * Формат вывода
 * Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.
 * Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.
 * Для остальных запросов выведите bad request.
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string first_name;
    string last_name;
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int main() {
    vector<Student> students;
    unsigned int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        string first_name, last_name;
        unsigned int day, month, year;
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back({first_name, last_name, day, month, year});
    }

    // Запросы
    string op_code;
    unsigned int k, M;
    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> op_code >> k;
        bool in_range = k > 0 && k <= students.size();
        if(op_code == "name" && in_range){
            cout << students[k - 1].first_name << " " << students[k - 1].last_name << endl;
        }else if(op_code == "date" && in_range){
            cout << students[k - 1].day << "." << students[k - 1].month << "." << students[k - 1].year << endl;
        }else{
            cout << "bad request" << endl;
        }
    }
    return 0;
}