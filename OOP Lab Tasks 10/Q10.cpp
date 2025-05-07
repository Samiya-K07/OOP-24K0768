// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ofstream logOutput("entries.txt");
    
    if (!logOutput)
    {
        cerr << "Failed to create file" << endl;
        return 1;
    }

    logOutput << "Entry A\n";
    logOutput << "Entry B\n";
    logOutput << "Entry C\n";
    logOutput << "Entry D\n";
    logOutput.close();

    ifstream logInput("entries.txt");
    
    if (!logInput)
    {
        cerr << "Failed to open file for reading" << endl;
        return 1;
    }

    logInput.seekg(20, ios::beg);

    string line;
    getline(logInput, line);
    cout << "Line read after seek: " << line << endl;

    logInput.close();
    return 0;
}
