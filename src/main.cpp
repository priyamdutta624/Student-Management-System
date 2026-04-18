#include <iostream>
#include "StudentManager.h"

int main()
{
    StudentManager sm;
    sm.loadFromFile();

    int choice;
    do {
        std::cout << "\n===== Student Management System =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Delete Student\n";
        std::cout << "5. Update Student Information\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id, age;
                std::string name;
                double marks;

                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std :: cin.ignore();
                std:: getline(std :: cin, name);
                std::cout << "Enter Age: ";
                std::cin >> age;
                std::cout << "Enter Marks: ";
                std::cin >> marks;

                sm.addStudent(id, name, age, marks);
                break;
            }

            case 2: {
                sm.displayAll();
                break;
            }

            case 3: {
                int id;
                std::cout << "Enter ID to search: ";
                std::cin >> id;
                sm.searchStudent(id);
                break;
            }

            case 4: {
                int id;
                std::cout << "Enter ID to delete: ";
                std::cin >> id;
                sm.deleteStudent(id);
                break;
            }

            case 5: {
                int id, ch;

                std::cout << "Enter ID: ";
                std::cin >> id;

                std::cout << "1. Update Age\n2. Update Marks\n";
                std::cout << "Enter choice: ";
                std::cin >> ch;

                sm.updateStudentInformation(id, ch);
                break;
            }

            case 6: {
                std::cout << "Exiting...\n";
                break;
            }

            default: {
                std::cout << "Invalid choice!\n";
            }
        }
    } while (choice != 6);

    return 0;
}
