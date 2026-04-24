#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BackupLogger {
private:
    string filename;

public:
    BackupLogger(string file) : filename(file) {}

    void startLogging() {
        string message;
        int entryNum = 1;

        cout << "\n📋 Enter log messages (type 'exit' to stop):\n";

        while (true) {
            cout << "\nEntry " << entryNum << ": ";
            getline(cin, message);

            if (message == "exit") {
                cout << "\n🛑 Logging stopped by user.\n";
                break;
            }
            ofstream file(filename, ios::app);
            if (!file.is_open()) {
                cout << "❌ Error: Could not open " << filename << "!\n";
                return;
            }

            file << "[Entry " << entryNum << "] " << message << "\n";

            file.seekp(0, ios::end);
            streampos fileSize = file.tellp();

            file.close();

            cout << "✅ Entry saved! | 📦 File size now: " << fileSize << " bytes\n";
            entryNum++;
        }
    }


    void displayLogs() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "⚠️  No backup log found.\n";
            return;
        }

        string line;
        cout << " Backup Log Contents ";
        while (getline(file, line)) {
            cout << line << "\n";
        }
      file.close();
    }
};

int main() {
    BackupLogger logger("backup_log.txt");

    cout << "=== Backup File Monitor ===\n";

    logger.startLogging();
    logger.displayLogs();

    return 0;
}
