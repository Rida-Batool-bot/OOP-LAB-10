#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SpellChecker {
private:
    string filename;
    void createDraftFile() {
        ifstream check(filename);
        if (!check.is_open()) {
            ofstream newFile(filename);
            if (newFile.is_open()) {
                newFile << "This is teh first draft of teh document.\n";
                newFile << "We need to fix teh typos carefully.\n";
                newFile << "Only teh first instance should be corrected.\n";
                newFile.close();
                cout << "✅ draft.txt created automatically!\n";
            }
        }
    }

public:
    SpellChecker(string file) : filename(file) {
        createDraftFile();
    }

    void displayFile(string label) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "❌ Error: Could not open " << filename << "!\n";
            return;
        }

        string line;
        cout << label  ;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }
void fixFirstTypo() {
        fstream file(filename, ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "❌ Error: Could not open " << filename << " for editing!\n";
            return;
        }

        string content, line;
        while (getline(file, line)) {
            content += line + "\n";
        }

        size_t pos = content.find("teh");

        if (pos == string::npos) {
            cout << "✅ No typo 'teh' found in the file.\n";
            file.close();
            return;
        }

        file.clear();
        file.seekp(pos, ios::beg);

        file.write("the", 3);

        cout << "🔍 Typo 'teh' found at byte position: " << pos << "\n";
        cout << "✅ Fixed: 'teh' → 'the' (first instance only)\n";

        file.close();
    }
};

int main() {
    SpellChecker checker("draft.txt");

    cout << "=== Spell Checker App ===\n";

    checker.displayFile("Before Fix");

    checker.fixFirstTypo();

    checker.displayFile("After Fix");

    return 0;
}
