# Множество значений словаря

Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string> и возвращающую множество значений этого словаря:

```C++
set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}
```

## Пример

Код

```C++
set<string> values = BuildMapValuesSet({
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}
});

for (const string& value : values) {
  cout << value << endl;
}
```
