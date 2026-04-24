#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

class SystemLogger {
private:
    string filename;

    string getCurrentTime() {
        time_t now = time(0);
        string timestamp = ctime(&now);
        if (!timestamp.empty() && timestamp.back() == '\n') {
            timestamp.pop_back();
        }
        return timestamp;
    }

public:
    SystemLogger(string file) : filename(file) {}

    void logStartup() {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << "System started at: " << getCurrentTime() << endl;
            file.close();
            cout << "Startup logged successfully!\n";
        } else {
            cout << "Error: Could not open log file!\n";
        }
    }

    void displayLogs() {
        ifstream file(filename);
        string line;
        cout << "System Logs ";
        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "No logs found.\n";
        }
    }
};

int main() {
    SystemLogger logger("system_log.txt");

    cout << "System Startup Logger ";

    logger.logStartup();

    logger.displayLogs();

    return 0;
}