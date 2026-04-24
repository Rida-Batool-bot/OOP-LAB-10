#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class VocabularyApp {
private:
    string filename;

public:
    VocabularyApp(string file) : filename(file) {}

    void printWords() {
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "❌ Error: Could not open " << filename << "!\n";
            return;
        }

        string line, word;
        cout << "\n===== Vocabulary Words =====\n";

        while (getline(file, line)) {
            istringstream iss(line);
            while (iss >> word) {
                cout << word << "\n";
            }
        }

        file.close();
    }
};

int main() {
    VocabularyApp app("story.txt");

    cout << "=== E-Learning Vocabulary App ===\n";
    app.printWords();

    return 0;
}