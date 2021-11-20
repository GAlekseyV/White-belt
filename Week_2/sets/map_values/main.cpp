/*
 * Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int,
 * string> и возвращающую множество значений этого словаря.
 */
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> ans;
  for (auto item : m) {
    ans.insert(item.second);
  }
  return ans;
}
