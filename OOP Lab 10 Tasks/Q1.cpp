// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream inputFile("vehicles.txt");
    
    if (!inputFile.is_open())
    {
        cout << "Unable to open the file" << endl;
        return 1;
    }

    string contentLine;
    while (getline(inputFile, contentLine))
    {
        if (contentLine.empty())
        {
            continue;
        }
       
        if (contentLine[0] == '#')
        {
            continue;
        }
        cout << contentLine << endl;
    }

    inputFile.close();
    return 0;
}
