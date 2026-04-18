#include <iostream>
#include <fstream>
#include <sstream>
#include "StudentManager.h"

enum class Choice {
    Age = 1,
    Marks = 2
};

bool StudentManager :: exists(int id) const {
    for (const auto &i : studentList) {
        if (i.getId() == id) return true;
    }

    return false;
}

void StudentManager :: addStudent(int id, const std ::string &name, int age, double marks) {
    if (exists(id)) {
        std :: cout << "ID already exists" << std :: endl;
        return;
    }
    studentList.emplace_back(id, name, age, marks);
    saveToFile();
    std :: cout << "Student added" << std :: endl;
}

void StudentManager :: displayAll() const {
    for (const auto &i : studentList) {
        i.display();
    }
}

void StudentManager :: searchStudent(int id) {
    for (const auto &i : studentList) {
        if ( i.getId() == id) {
            i.display();
            return;
        }
    }

    std :: cout << "Student not found!" << std :: endl;
}

void StudentManager :: deleteStudent (int id) {
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it -> getId() == id) {
            studentList.erase(it);
            saveToFile();
            std :: cout << "Student Information Deleted" << std :: endl;
            return;
        }
    }
}

void StudentManager :: updateStudentInformation(int id, int choice) {
    switch (static_cast<Choice>(choice)) {
        case Choice :: Age : {
            for (auto &i : studentList) {
                if (i.getId() == id) {
                    int age;
                    std :: cout << "Enter the new age : ";
                    std :: cin >> age;
                    i.setAge(age);
                    saveToFile();
                    std ::cout << "Age of the Student is updated" << std ::endl;
                    return;
                }
            }

            std ::cout << "Student not found!" << std ::endl;
            break;
        }
        
        case Choice :: Marks : {
            for (auto &i : studentList) {
                if (i.getId() == id) {
                    int marks;
                    std ::cout << "Enter the new marks : ";
                    std :: cin >> marks;
                    i.setMarks(marks);
                    saveToFile();
                    std ::cout << "Marks of the Student is updated" << std ::endl;
                    return;
                }
            }

            std ::cout << "Student not found!" << std ::endl;
            break;
        }
    }
}

void StudentManager :: saveToFile() const {
    std :: ofstream file("data/Students.txt");

    for (const auto &i : studentList) {
        file << i.getId() << ","
             << i.getName() << ","
             << i.getAge() << ","
             << i.getMarks() << " \n";
    }
}

void StudentManager :: loadFromFile() {
    studentList.clear();

    std :: ifstream file("data/Students.txt");
    if (!file) return;

    std :: string line;

    while(getline(file, line)) {
        std :: stringstream ss(line);

        std :: string idStr, name, ageStr, marksStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, marksStr, ',');

        int id = stoi(idStr);
        int age = stoi(ageStr);
        double marks = stod(marksStr);

        studentList.emplace_back(id, name, age, marks);
    }
}