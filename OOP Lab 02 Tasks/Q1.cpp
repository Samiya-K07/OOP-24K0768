//Samiya Khan
//24K-0768
//Task 01

#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    int yr;
};

int main() {
    
    int no_of_books;
    cout << "Enter the number of books: ";
    cin >> no_of_books;

    Book *books = new Book[no_of_books];

    for (int i = 1; i <= no_of_books; i++)
    {
        cout << "Enter the details for book " << i << ":" << endl;
        
        cout << "Title: ";
        cin >> books[i].title;
        
        cout << "Author: ";
        cin >> books[i].author;
        
        cout << "Year: ";
        cin >> books[i].yr;
    }

    int find_year;
    cout << "Enter the year to find the published books after that year: ";
    cin >> find_year;

    cout << "Books published after " << find_year << ":" << endl;
    bool found = false;
    
    for (int i = 0; i < no_of_books; i++)
    {
        if (books[i].yr > find_year)
        {
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Year: " << books[i].yr << endl;
            
            found = true;
        }
    }

    if (!found)
    {
        cout << "No books published after " << find_year << "!!" << endl;
    }

    delete[]books;
    
    return 0;
}
