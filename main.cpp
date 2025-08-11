#include <iostream>
#include <vector>
#include <limits> // for numeric_limits
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "\nEnter Roll No: ";
    cin >> s.rollNo;

    // Clear input buffer before getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    cout << "✅ Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\n⚠️ No students found.\n";
        return;
    }
    cout << "\n📋 Student List:\n";
    for (const auto& s : students) {
        cout << "Roll No: " << s.rollNo
             << ", Name: " << s.name
             << ", Marks: " << s.marks << "\n";
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll No to search: ";
    cin >> roll;
    bool found = false;
    for (const auto& s : students) {
        if (s.rollNo == roll) {
            cout << "🎯 Found: " << s.name << " with " << s.marks << " marks.\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "❌ Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n====== Student Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "👋 Exiting...\n"; break;
            default: cout << "⚠️ Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
