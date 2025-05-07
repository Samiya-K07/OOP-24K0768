// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ofstream writer("settings.txt");
    
    if (!writer)
    {
        cerr << "Failed to create the file" << endl;
        return 1;
    }
    writer << "AAAAABBBBBCCCCC";
    writer.close();

    fstream config("settings.txt", ios::in | ios::out);
    
    if (!config)
    {
        cerr << "Failed to open file for editing" << endl;
        return 1;
    }

    config.seekp(5);
    config << "XXXXX";
    config.close();

    ifstream reader("settings.txt");
    
    if (!reader)
    {
        cerr << "Failed to open file for reading" << endl;
        return 1;
    }

    string updatedText;
    getline(reader, updatedText);
    cout << "Final content in file: " << updatedText << endl;

    reader.close();

    return 0;
}
