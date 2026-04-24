#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

class ContentAnalyzer {
private:
    string inputFile;
    string reportFile;
    void createArticleFile() {
        ifstream check(inputFile);
        if (!check.is_open()) {
            ofstream newFile(inputFile);
            if (newFile.is_open()) {
                newFile << "Welcome to the world of programming!\n";
                newFile << "Programming is the art of problem solving.\n";
                newFile << "Every great software starts with a single line of code.\n";
                newFile << "C++ is one of the most powerful languages ever created.\n";
                newFile << "Object Oriented Programming changed how we write code.\n";
                newFile << "Classes, objects, and methods are the foundation of OOP.\n";
                newFile << "Encapsulation keeps your data safe and organized.\n";
                newFile << "Inheritance allows code reuse across classes.\n";
                newFile << "Polymorphism lets one interface serve many types.\n";
                newFile << "Abstraction hides complexity from the user.\n";
                newFile.close();
                cout << "✅ article.txt created automatically!\n";
            }
        }
    }

public:
    ContentAnalyzer(string input, string report) : inputFile(input), reportFile(report) {
        createArticleFile();
    }
    void analyze() {
        ifstream file(inputFile);
        if (!file.is_open()) {
            cout << "❌ Error: Could not open " << inputFile << "!\n";
            return;
        }

        int totalChars = 0;
        int totalWords = 0;
        int totalLines = 0;
        int totalPunctuation = 0;

        string line, word;

        while (getline(file, line)) {
            totalLines++;
            totalChars += line.length();
            for (char ch : line) {
                if (ispunct(ch)) {
                    totalPunctuation++;
                }
            }
            istringstream iss(line);
            while (iss >> word) {
                totalWords++;
            }
        }

        file.close();
        cout << "\n===== Quality Metrics =====\n";
        cout << "📄 Total Characters  : " << totalChars << "\n";
        cout << "🔤 Total Words       : " << totalWords << "\n";
        cout << "📋 Total Lines       : " << totalLines << "\n";
        cout << "❗ Punctuation Marks : " << totalPunctuation << "\n";
        ofstream report(reportFile);
        if (!report.is_open()) {
            cout << "❌ Error: Could not create " << reportFile << "!\n";
            return;
        }
        report << "       CONTENT QUALITY REPORT          \n";
        report << "Source File     : " << inputFile  << "\n";
        report << "Total Characters : " << totalChars       << "\n";
        report << "Total Words      : " << totalWords       << "\n";
        report << "Total Lines      : " << totalLines       << "\n";
        report << "Punctuation Marks: " << totalPunctuation << "\n";
        report << "Average Words per Line: ";

        if (totalLines > 0) {
            report << (float)totalWords / totalLines << "\n";
        } else {
            report << "N/A\n";
        }
        report.close();

        cout << "\n✅ Report saved to " << reportFile << " successfully!\n";
    }
};

int main() {
    ContentAnalyzer analyzer("article.txt", "report.txt");

    cout << " Content Management System";
    analyzer.analyze();

    return 0;
}
