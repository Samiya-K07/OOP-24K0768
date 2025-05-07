// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    ifstream inputStream("vehicles.txt");
    
    if (!inputStream.is_open())
    {
        cout << "Could not open the file" << endl;
        return 1;
    }

    string dataRow;
    while (getline(inputStream, dataRow))
    {
        if (dataRow.empty())
        {
            continue;
        }
        
        if (dataRow[0] == '#')
        {
            continue;
        }

        istringstream parser(dataRow);

        string category, code, model, yearText, miscInfo, approvalTag;

        getline(parser, category, ',');
        getline(parser, code, ',');
        getline(parser, model, ',');
        getline(parser, yearText, ',');
        getline(parser, miscInfo, ',');
        getline(parser, approvalTag, ',');

        if (!yearText.empty())
        {
            yearText.erase(0, yearText.find_first_not_of(" \t"));
            yearText.erase(yearText.find_last_not_of(" \t") + 1);

            int numericYear = stoi(yearText);

            cout << "Category: " << category << endl;
            cout << "Code: " << code << endl;
            cout << "Model: " << model << endl;
            cout << "Year (as number): " << numericYear << endl;
            cout << "Misc Info: (" << miscInfo << " )" << endl;
            cout << "Approval Tag: " << approvalTag << endl;
            cout << endl;
        }
        
        else
        {
            cout << "Missing year value for entry: " << dataRow << endl;
        }
    }

    inputStream.close();
    return 0;
}
