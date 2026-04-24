#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BlogReader {
private:
    string filename;

    void createArticleFile() {
        ifstream check(filename);
        if (!check.is_open()) {
            ofstream newFile(filename);
            if (newFile.is_open()) {
                newFile << "Line 1:  Welcome to the world of programming.\n";
                newFile << "Line 2:  Programming is the art of problem solving.\n";
                newFile << "Line 3:  Every great software starts with a single line of code.\n";
                newFile << "Line 4:  C++ is one of the most powerful languages ever created.\n";
                newFile << "Line 5:  Object Oriented Programming changed how we write code.\n";
                newFile << "Line 6:  Classes and objects are the foundation of OOP.\n";
                newFile << "Line 7:  Encapsulation keeps your data safe and organized.\n";
                newFile << "Line 8:  Inheritance allows code reuse across classes.\n";
                newFile << "Line 9:  Polymorphism lets one interface serve many types.\n";
                newFile << "Line 10: Abstraction hides complexity from the user.\n";
                newFile << "Line 11: File handling lets programs store data permanently.\n";
                newFile << "Line 12: Binary files store data in raw memory format.\n";
                newFile << "Line 13: Text files store data in human-readable format.\n";
                newFile << "Line 14: seekg() lets you jump anywhere inside a file.\n";
                newFile << "Line 15: tellg() tells you the current position in a file.\n";
                newFile << "Line 16: getline() reads an entire line at once.\n";
                newFile << "Line 17: istringstream helps parse words from a string.\n";
                newFile << "Line 18: Always close your files after using them.\n";
                newFile << "Line 19: Good programmers write clean and readable code.\n";
                newFile << "Line 20: Keep learning and never stop improving your skills.\n";
                newFile.close();
                cout << "✅ article.txt created automatically!\n";
            }
        }
    }

public:
    // Constructor with initializer list
    BlogReader(string file) : filename(file) {
        createArticleFile();
    }

    void previewMiddle() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "❌ Error: Could not open " << filename << "!\n";
            return;
        }

        file.seekg(0, ios::end);
        streampos fileSize = file.tellg();

        file.seekg(fileSize / 2, ios::beg);

        string line;
        getline(file, line);

        cout << " Blog Article Preview (Middle) ";
        cout << "📄 File size: " << fileSize << " bytes | Starting from byte: " << fileSize / 2 << "\n\n";

        int lineCount = 0;
        while (lineCount < 10 && getline(file, line)) {
            cout << line << "\n";
            lineCount++;
        }

        if (lineCount == 0) {
            cout << "⚠️  No lines found from the midpoint.\n";
        }

        file.close();
    }
};

int main() {
    BlogReader reader("article.txt");

    cout << "Blog Reader App ";
    reader.previewMiddle();

    return 0;
}
