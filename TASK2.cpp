#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Diary {
private:
    ofstream diaryFile;

public:
   
    Diary() {
        diaryFile.open("diary.txt", ios::app); 
                if (!diaryFile) {
            cerr << "Error opening diary file.\n";
        }
    }

    void writeEntries() {
        if (!diaryFile) return;

        string entry;
        cout << "Start typing your diary entries (type 'exit' to stop):\n";

        while (true) {
            getline(cin, entry);
            if (entry == "exit") break;
            diaryFile << entry << endl;  
        }
    }

    ~Diary() {
        if (diaryFile.is_open()) {
            diaryFile.close();
            cout << "Diary entries saved successfully.\n";
        }
    }
};

int main() {
    Diary myDiary;
    myDiary.writeEntries();
    return 0;
}
