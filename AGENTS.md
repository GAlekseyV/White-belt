# Agent Guidelines for White-belt C++ Repository

This repository contains solutions for Yandex's "White Belt C++ course" (Основы разработки на С++: белый пояс).

## Build Commands

**Full build:**
```bash
cmake -S . -B build
cd build && make
```

**Build single task:**
```bash
cd build && make Week_5_final_task
```
Executables follow naming convention: `Week_{N}_{task_path}` (slashes replaced with underscores)

**Run a task:**
```bash
cd build && ./Week_5_final_task
# OR
cd build && echo "Add 2017-01-01 holiday" | ./Week_5_final_task
```

**Clean build:**
```bash
cd build && make clean
```

## Project Structure

- `Week_N/` - weekly tasks organized by folder
- Each task folder contains `main.cpp` and `Task.md` (Russian problem statement)
- CMakeLists.txt auto-discovers and builds all tasks
- C++17 standard is required

## Code Style Guidelines

### Imports & Headers
- System headers first (e.g., `<iostream>`, `<vector>`, `<map>`)
- Group related headers together (streams, containers, algorithms)
- No header guard issues - this is a single-file-per-task repository
- `using namespace std;` is used consistently in main.cpp files

### Naming Conventions
- **Classes/Structs**: PascalCase (Date, Rational, Student, Database)
- **Functions**: camelCase (GetYear, Numerator, BuildCharCounters)
- **Variables**: snake_case (year, month, day, num, n)
- **Private members**: leading underscore (_numerator, _denominator, _year)
- **Constants**: UPPER_SNAKE_CASE (rarely used)

### Type & Formatting
- **Indentation**: 2 spaces
- **Braces**: Opening brace on new line for class definitions, same line for control structures
- Use `class` for encapsulated types with private members
- Use `struct` for POD types with public members (Student)
- Const correctness: mark member functions `const` when they don't modify state
- Pass strings/containers by `const string&` or `const vector<T>&` when not modifying

### Operator Overloading
- Implement as free functions when both operands are values (e.g., `operator+(const Rational& lhs, const Rational& rhs)`)
- Implement as member functions when one operand is `*this` (e.g., `Rational::Numerator() const`)
- Stream operators (`<<`, `>>`) return the stream reference (e.g., `ostream& operator<<(...)`)

### Error Handling
- Use `runtime_error` for validation errors with descriptive messages
- Use `try-catch` blocks when parsing user input
- Validate input and throw exceptions immediately (see Date class constructor)
- Print error messages to `cout` for user feedback

### I/O Patterns
- Read from stdin using `cin >>`
- Write to stdout using `cout <<`
- Use `endl` for line breaks (flushes buffer)
- Empty input lines should be ignored (see Week_5_final_task main loop)
- Use `stringstream` for parsing command lines

### Container Usage
- Prefer `vector` for dynamic arrays
- Use `map` for key-value pairs requiring ordered access
- Use `set` for unique collections requiring ordered access
- Use range-based for loops: `for (const auto& item : collection)`
- Use `begin()`/`end()` or `begin(x)`/`end(x)` with algorithms

### Lambda Functions
- Use `[]` capture when no variables needed
- Use `[&]` when capturing all by reference
- Use `auto` for loop variables in lambdas when appropriate

## Task Development Workflow

1. Locate the appropriate `Week_N/category/task_name/` folder
2. Read `Task.md` for problem requirements (in Russian)
3. Implement solution in `main.cpp`
4. Build: `cd build && make Week_N_category_task_name`
5. Test manually with sample inputs from `Task.md`

## Important Notes

- All code is educational/solution code - not production software
- Comments may be in Russian (course language)
- Tasks are self-contained - don't create header files unless necessary
- Focus on correctness and clarity over optimization
- Use STL containers and algorithms rather than manual implementations
- Follow patterns seen in existing solutions (operator overloading style, I/O patterns)