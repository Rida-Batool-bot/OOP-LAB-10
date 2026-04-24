#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class GreetingCard {
private:
    string recipientName;
    string message;

public:
    // Method to take user input
    void getInput() {
        cout << "Enter recipient's name: ";
        getline(cin, recipientName);
        cout << "Enter your message: ";
        getline(cin, message);
    }

    void writeToFile() {
        ofstream outFile("greeting.txt");
        if (!outFile) {
            cerr << "Error opening file for writing.\n";
            return;
        }
        outFile << "Dear " << recipientName << ",\n"
                << message << "\n"
                << "Best Regards!";
        outFile.close();
        cout << "Greeting written to greeting.txt successfully.\n";
    }
};

int main() {
    GreetingCard card;
    card.getInput();
    card.writeToFile();
    return 0;
}
