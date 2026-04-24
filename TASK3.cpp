#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class WorkshopRegistration {
private:
    string filename;

public:
    // Constructor
    WorkshopRegistration(string file) {
        filename = file;
    }

    void registerUser() {
        string name, email;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Email: ";
        getline(cin, email);

        
        ofstream file(filename, ios::app);

        if (file.is_open()) {
            file << "Name: " << name << ", Email: " << email << endl;
            file.close();
            cout << "✅ " << name << " has been successfully registered!\n" << endl;
        } else {
            cout << "❌ Error: Could not open file!\n";
        }
    }

    void displayRegistrations() {
        ifstream file(filename);
        string line;

        cout << "Registered Uers ";
        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "No registrations found.\n";
        }
        
    }
};

int main() {
    WorkshopRegistration reg("signup.txt");
    int choice;

    cout << "=== University Workshop Registration ===\n";

    while (true) {
        cout << "\n1. Register a User";
        cout << "\n2. View All Registrations";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            reg.registerUser();
        } else if (choice == 2) {
            reg.displayRegistrations();
        } else if (choice == 3) {
            cout << "Exiting... Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}