#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
    int id;
    std ::string name;
    int age;
    double marks;

public:
    Student(int id, const std ::string &name, int age, double marks);

    std ::string getName() const;
    int getId() const;
    int getAge() const;
    double getMarks() const;

    void setAge(int age);
    void setMarks(double marks);

    void display() const;
};

#endif