// Samiya Khan
// 24K-0768

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseException : public exception
{
public:
    
    const char *what() const noexcept override
    {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException
{
};

class QueryTimeoutException : public DatabaseException
{
};

template <typename T>
class DatabaseConnector
{
private:
    string dbName;

public:
    DatabaseConnector(string name) : dbName(name) {}

    void connect()
    {
        if (dbName == "invalid_db")
        {
            throw ConnectionFailedException();
        }
        
        else if (dbName == "slow_db")
        {
            throw QueryTimeoutException();
        }
        
        else
        {
            cout << "Successfully connected to: " << dbName << endl;
        }
    }
};

int main()
{
    try
    {
        cout << "Attempting to connect to invalid_db..." << endl;
        DatabaseConnector<int> db1("invalid_db");
        db1.connect();
    }
    catch (const ConnectionFailedException &e)
    {
        cout << "Caught ConnectionFailedException" << endl;
        cout << "what(): " << e.what() << endl;
    }

    try
    {
        cout << "Attempting to connect to slow_db..." << endl;
        DatabaseConnector<int> db2("slow_db");
        db2.connect();
    }
    catch (const DatabaseException &e)
    {
        cout << "Caught a general DatabaseException" << endl;
        cout << "what(): " << e.what() << endl;
    }

    return 0;
}
