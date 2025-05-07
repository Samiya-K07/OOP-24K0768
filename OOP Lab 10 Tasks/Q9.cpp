// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ofstream logFile("system_log.txt");
    
    if (!logFile)
    {
        cerr << "Unable to create the file" << endl;
        return 1;
    }

    logFile << "This is the beginning of the log." << endl;
    logFile << "This continues with more log info." << endl;
    logFile << "This finishes the recorded entry." << endl;
    logFile.close();

    ifstream inputLog("system_log.txt");
    
    if (!inputLog)
    {
        cerr << "Unable to open the file for input" << endl;
        return 1;
    }

    char segment[11];
    segment[10] = '\0';

    inputLog.read(segment, 10);
    cout << "Initial 10 characters: " << segment << endl;
    cout << "Stream position after first chunk: " << inputLog.tellg() << endl;

    inputLog.read(segment, 10);
    cout << "Following 10 characters: " << segment << endl;
    cout << "Stream position after second chunk: " << inputLog.tellg() << endl;

    inputLog.close();
    return 0;
}
