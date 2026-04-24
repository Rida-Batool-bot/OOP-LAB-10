#include <iostream>
#include <fstream>
using namespace std;

class FileDebugger {
private:
    string fileName;

public:
    FileDebugger(string name) : fileName(name) {}

    void inspect() {
        ifstream file(fileName);

        if (!file.is_open()) {
            cout << "Error opening file!\n";
            return;
        }

        long offset;
        cout << "Enter byte offset: ";
        cin >> offset;

        cout << "Pointer before seek: " << file.tellg() << endl;

        file.seekg(offset, ios::beg);

        cout << "Pointer after seek: " << file.tellg() << endl;

        char buffer[101]; 
        file.read(buffer, 100);

        int bytesRead = file.gcount();
        buffer[bytesRead] = '\0';

        cout << "\nNext " << bytesRead << " characters:\n";
        cout << buffer << endl;

        file.close();
    }
};

int main() {
    FileDebugger debugger("article.txt");
    debugger.inspect();
    return 0;
}
