#include <iostream>
#include "Student.h"

Student :: Student(int id, const std :: string &name, int age, double marks) {
    this -> id = id;
    this -> name = name;
    this -> age = age;
    this -> marks = marks;
}

std :: string Student :: getName() const { return name; }
int Student :: getId() const { return id; }
int Student :: getAge() const { return age; }
double Student :: getMarks() const { return marks; }

void Student :: setAge(int age) { this -> age = age; }
void Student :: setMarks(double marks) { this -> marks = marks; }

void Student :: display() const {
    std :: cout << " | Name: "<< name 
                << " | id: " << id 
                << " | age: " <<  age 
                << " | marks obtained: "<< marks
                << " | " << std :: endl;
}