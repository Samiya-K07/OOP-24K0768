//Samiya Khan
//24K-0768
//Task 03

#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 150;

class Library{

private:
    string bookList[MAX_BOOKS];
    string borrowedBooks[MAX_BOOKS];
    bool availableBooks[MAX_BOOKS];
    int total_books;
    int total_borrowed;

public:
    
    Library()
    {
        total_books = 0;
        total_borrowed = 0;
    }

    void add_book(string bookName)
    {
        if (total_books < MAX_BOOKS)
        {
            bookList[total_books] = bookName;
            availableBooks[total_books] = true;
            
            total_books++;
            cout << bookName << " book has been added succesfully!!" << endl;
        } 
        
        else
        {
            cout << "Error!! Cannot add more books!!" << endl;
        }
    }

    void display_books()
    {
        cout << "Available Books:\n" << endl;
        
        for (int i = 0; i < total_books; i++)
        {
            if (availableBooks[i])
            {
                cout << i + 1 << ". " << bookList[i] << endl;
            }
        }
    }

    void lend_book(string bookName)
    {
        for (int i = 0; i < total_books; i++)
        {
            if (bookList[i] == bookName && availableBooks[i])
            {
                availableBooks[i] = false;
                borrowedBooks[total_borrowed] = bookName;
                
                total_borrowed++;
                cout << bookName << " book has been borrowed!!" << endl;
                
                return;
            }
        }
        
        cout << bookName << " book is not available unfortunately!!" << endl;
    }

    void return_book(string bookName)
    {
        for (int i = 0; i < total_borrowed; i++)
        {
            if (borrowedBooks[i] == bookName)
            {
                borrowedBooks[i] = borrowedBooks[total_borrowed - 1];
                total_borrowed--;
                
                for (int j = 0; j < total_books; j++)
                {
                    if (bookList[j] == bookName)
                    {
                        availableBooks[j] = true;
                        break;
                    }
                }
               
                cout << bookName << " book has been returned successfully!!" << endl;
                
                return;
            }
        }
        
        cout << bookName << " book was not borrowed!!" << endl;
    }
};

int main() {
    Library library;

    library.add_book("A Good Girl's Guide To Murder");
    library.add_book("Pride and Prejudice");
    library.add_book("The Secret History");
    library.display_books();

    library.lend_book("Pride and Prejudice");
    library.lend_book("The Secret History");
    library.display_books();

    library.return_book("Pride and Prejudice");
    library.display_books();

    return 0;
}