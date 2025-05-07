// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct ProductRecord
{
    int productCode;
    char productLabel[20];
};

int main()
{
    ProductRecord recordOut;
    recordOut.productCode = 101;
    strcpy(recordOut.productLabel, "Wireless Mouse");

    ofstream outputFile("inventory.dat", ios::binary);
    
    if (!outputFile)
    {
        cout << "Failed to open file for writing." << endl;
        return 1;
    }
    outputFile.write(reinterpret_cast<char *>(&recordOut), sizeof(recordOut));
    outputFile.close();

    ProductRecord recordIn;
    ifstream inputFile("inventory.dat", ios::binary);
    
    if (!inputFile)
    {
        cout << "Failed to open file for reading." << endl;
        return 1;
    }
    inputFile.read(reinterpret_cast<char *>(&recordIn), sizeof(recordIn));
    inputFile.close();

    cout << "Retrieved Product Code: " << recordIn.productCode << endl;
    cout << "Retrieved Product Label: " << recordIn.productLabel << endl;

    return 0;
}
