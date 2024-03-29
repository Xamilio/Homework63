#include <iostream>
#include <map>
#include <string>
using namespace std;

class Student {
public:
    Student(const string& name, float average_grade) : name(name), average_grade(average_grade) 
    {

    }
    string getName() const
    {
        return name; 
    }
    float getAverageGrade() const 
    {
        return average_grade; 
    }

    bool operator<(const Student& other) const {
        return name < other.name;
    }

    bool operator==(const Student& other) const {
        return name == other.name && average_grade == other.average_grade;
    }

private:
    string name;
    float average_grade;
};

int main() {
    map<Student, float> studentGrades;
    studentGrades.emplace(Student("Иван", 4.5), 85.5);
    studentGrades.emplace(Student("Мария", 4.2), 78.2);
    studentGrades.emplace(Student("Алексей", 4.7), 92.1);
    studentGrades.emplace(Student("Екатерина", 4.1), 76.8);
    studentGrades.emplace(Student("Дмитрий", 4.4), 83.7);
    for (const auto& pair : studentGrades) {
        if (pair.first.getName() == "Мария") {
            cout << "Имя студента: " << pair.first.getName() << endl;
            cout << "Средний балл: " << pair.second << endl;
            break;
        }
    }
}
