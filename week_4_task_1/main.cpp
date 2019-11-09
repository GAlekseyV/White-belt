/*
 * Структура LectureTitle
 */
#include <iostream>
using namespace std;

struct Specialization{
    string specialization;
    explicit Specialization(const string& new_specialization){
        specialization = new_specialization;
    }
};

struct Course{
    string course;
    explicit Course(const string& new_course){
        course = new_course;
    }
};

struct Week{
    string week;
    explicit Week(const string& new_week){
        week = new_week;
    }
};

struct LectureTitle{
    string specialization;
    string course;
    string week;
    LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week){
        specialization = new_specialization.specialization;
        course = new_course.course;
        week = new_week.week;
    }
};

//int main() {
//    LectureTitle title(
//            Specialization("C++"),
//            Course("White belt"),
//            Week("4th")
//    );
//
//    LectureTitle title("C++", "White belt", "4th");
//
//    LectureTitle title(string("C++"), string("White belt"), string("4th"));
//
//    LectureTitle title = {"C++", "White belt", "4th"};
//
//    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
//
//    LectureTitle title(
//            Course("White belt"),
//            Specialization("C++"),
//            Week("4th")
//    );
//
//    LectureTitle title(
//            Specialization("C++"),
//            Week("4th"),
//            Course("White belt")
//    );
//    return 0;
//}