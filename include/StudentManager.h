#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>

class StudentManager
{
    std ::vector<Student> studentList;

public:
    bool exists(int id) const;

    void addStudent(int id, const std ::string &name, int age, double marks);

    void displayAll() const;

    void searchStudent(int id);

    void deleteStudent(int id);

    void updateStudentInformation(int id, int choice);

    void saveToFile() const;

    void loadFromFile();
};

#endif