#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    int id;
    float gpa;
};

class StudentManager {
private:
    string filename;

public:
    StudentManager(string file) : filename(file) {}

    void addStudents() {
        int n;
        cout << "Enter number of students: ";
        cin >> n;
        cin.ignore();

        ofstream file(filename, ios::binary | ios::app);
        if (!file.is_open()) {
            cout << "❌ Error: Could not open " << filename << " for writing!\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            Student s;
            cout << "\n--- Student " << i + 1 << " ---\n";

            cout << "Enter Name: ";
            cin.getline(s.name, 50);

            cout << "Enter ID: ";
            cin >> s.id;
            cin.ignore();

            cout << "Enter GPA: ";
            cin >> s.gpa;
            cin.ignore();

            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "✅ Student saved!\n";
        }

        file.close();
    }

    void displayStudents() {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cout << "❌ Error: Could not open " << filename << " for reading!\n";
            return;
        }

        Student s;
        int count = 1;

        cout << "\n===== Student GPA Records =====\n";
        while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            cout << "\nStudent " << count++ << ":\n";
            cout << "  Name : " << s.name << "\n";
            cout << "  ID   : " << s.id << "\n";
            cout << "  GPA  : " << s.gpa << "\n";
        }

        if (count == 1) {
            cout << "No student records found.\n";
        }

        file.close();
    }
};

int main() {
    StudentManager manager("students.dat");

    cout << "=== Student GPA Record System ===\n";

    manager.addStudents();
    manager.displayStudents();

    return 0;
}
