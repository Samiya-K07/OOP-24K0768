// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream dataLog("log_data.txt");
    
    if (!dataLog)
    {
        cerr << "Unable to open file for writing" << endl;
        return 1;
    }

    dataLog << "Log Entry One ";
    streampos mark1 = dataLog.tellp();
    cout << "File position after first entry: " << mark1 << endl;

    dataLog << "Log Entry Two";
    streampos mark2 = dataLog.tellp();
    cout << "File position after second entry: " << mark2 << endl;

    dataLog.close();

    return 0;
}
