/*
    C++ libraries
    OOP Concepts Applied:
    -> C++ Access Specifiers
    -> C++ Encapsulation
*/
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

class BOOK
{
private:
    string isbn, title, author, edition, publication;

public:
    // Setter
    void setISBN(string _isbn) { isbn = _isbn; }
    void setTITLE(string _title) { title = _title; }
    void setAUTHOR(string _author) { author = _author; }
    void setEDITION(string _edition) { edition = _edition; }
    void setPUBLICATION(string _publication) { publication = _publication; }

    // Getter
    string getISBN() { return isbn; }
    string getTITLE() { return title; }
    string getAUTHOR() { return author; }
    string getEDITION() { return edition; }
    string getPUBLICATION() { return publication; }
};

void createBooks();     // choice 1
void updateBooks();     // choice 2
void deleteBooks();     // choice 3
void searchBooks();     // choice 4
void displayBooks();    // choice 5
void openBookFiles();   // open Book Files
void saveBookRecords(); // save Book Records
const int maxrow = 100;
int counter = 0;
BOOK books[maxrow] = {};

int main()
{
    int choice;
    openBookFiles();
    do
    {
        cout << "LIBRARY SYSTEM MANAGEMENT" << endl;
        cout << "1) Create Books\n2) Update Books\n3) Delete Books\n4) Search Books\n5) Display Books\n6) Exit\n\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            createBooks();
            system("pause");
            break;
        case 2:
            updateBooks();
            system("pause");
            break;
        case 3:
            deleteBooks();
            system("pause");
            break;
        case 4:
            searchBooks();
            system("pause");
            break;
        case 5:
            displayBooks();
            system("pause");
            break;
        default:
            break;
        }
    } while (choice != 6);

    cout << "LIBRARY SYSTEM MANAGEMENT... SYSTEM LOGOUT!!!" << endl;

    return 0;
}

void createBooks() // choice 1
{
    cin.ignore();
    string isbn, title, author, edition, publication;
    cout << "CREATE BOOKS" << endl;
    cout << "ISBN: ";
    getline(cin, isbn);
    cout << "TITLE: ";
    getline(cin, title);
    cout << "AUTHOR: ";
    getline(cin, author);
    cout << "EDITION: ";
    getline(cin, edition);
    cout << "PUBLICATION: ";
    getline(cin, publication);

    for (int i = 0; i < maxrow; i++)
    {
        if (books[i].getISBN() == "\0")
        {
            books[i].setISBN(isbn);
            books[i].setTITLE(title);
            books[i].setAUTHOR(author);
            books[i].setEDITION(title);
            books[i].setPUBLICATION(publication);
            saveBookRecords();
            break;
        }
    }
} // end of create books method

void updateBooks()
{

    cin.ignore();
    string isbn, title, author, edition, publication, yn;
    cout << "BOOK UPDATE" << endl;
    cout << "SEARCH BOOK BY ISBN: ";
    getline(cin, isbn);

    for (int i = 0; i < maxrow; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            counter++;
            cout << "BOOK FOUND!!!" << endl;
            cout << "ISBN: " << books[i].getISBN() << endl;
            cout << "TITLE: " << books[i].getTITLE() << endl;
            cout << "AUTHOR: " << books[i].getAUTHOR() << endl;
            cout << "EDITION: " << books[i].getEDITION() << endl;
            cout << "PUBLICATION: " << books[i].getPUBLICATION() << endl;

            cout << "Do you want to update is book?\n[Y - y] YES\n[N - n] NO" << endl;
            getline(cin, yn);

            if (yn == "y" || yn == "Y")
            {
                cout << "\nUPDATE BOOK INFOMATION: " << endl;
                cout << "CREATE BOOKS" << endl;
                cout << "TITLE: ";
                getline(cin, title);
                cout << "AUTHOR: ";
                getline(cin, author);
                cout << "EDITION: ";
                getline(cin, edition);
                cout << "PUBLICATION: ";
                getline(cin, publication);
                books[i].setTITLE(title);
                books[i].setAUTHOR(author);
                books[i].setEDITION(title);
                books[i].setPUBLICATION(publication);

                cout << "\nBOOK SUCCESSFULLY UPDATED!!" << endl;
            }
            else if (yn == "n" || yn == "N")
            {
                cout << "\nBOOK NOT UPDATED!!" << endl;
            }

            break;
        }
        else
        {
            break;
        }
    }

    if (counter == 0)
    {
        cout << "BOOKS DOES NOT EXIST!!!" << endl;
    }

} // end of update books method

void deleteBooks() // choice 3
{
    cin.ignore();
    string isbn, yn;
    cout << "DELETE BOOK" << endl;
    cout << "SEARCH BOOK BY ISBN: ";
    getline(cin, isbn);
    for (int i = 0; i < maxrow; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            counter++;
            cout << "BOOK FOUND!!!" << endl;
            cout << "ISBN: " << books[i].getISBN() << endl;
            cout << "TITLE: " << books[i].getTITLE() << endl;
            cout << "AUTHOR: " << books[i].getAUTHOR() << endl;
            cout << "EDITION: " << books[i].getEDITION() << endl;
            cout << "PUBLICATION: " << books[i].getPUBLICATION() << endl;

            cout << "\nDo you want to delete this book?\n[Y - y] YES\n[N - n] NO" << endl;
            getline(cin, yn);

            if (yn == "y" || yn == "Y")
            {
                books[i].setISBN("");
                books[i].setTITLE("");
                books[i].setAUTHOR("");
                books[i].setEDITION("");
                books[i].setPUBLICATION("");

                cout << "\nBOOK SUCCESSFULLY DELETED!!" << endl;
            }
            else if (yn == "n" || yn == "N")
            {
                cout << "\nBOOK NOT DELETED!!" << endl;
            }

            break;
        }
    }

    if (counter == 0)
    {
        cout << "BOOKS DOES NOT EXIST!!!" << endl;
    }

} // end of delete books method

void searchBooks() // choice 4
{
    cin.ignore();
    string isbn;
    cout << "SEARCH BOOK" << endl;
    cout << "SEARCH BOOK BY ISBN: ";
    getline(cin, isbn);
    for (int i = 0; i < maxrow; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            counter++;
            cout << "BOOK FOUND!!!" << endl;
            cout << "ISBN: " << books[i].getISBN() << endl;
            cout << "TITLE: " << books[i].getTITLE() << endl;
            cout << "AUTHOR: " << books[i].getAUTHOR() << endl;
            cout << "EDITION: " << books[i].getEDITION() << endl;
            cout << "PUBLICATION: " << books[i].getPUBLICATION() << endl;
        }
    }

    if (counter == 0)
    {
        cout << "BOOKS DOES NOT EXIST!!!" << endl;
    }

} // end of search books method

void displayBooks() // choice 5
{
    cout << "DISPLAY BOOKS" << endl;
    for (int i = 0; i < maxrow; i++)
    {
        if (books[i].getISBN() != "\0")
        {
            counter++;
            cout << "ISBN: " << books[i].getISBN() << endl;
            cout << "TITLE: " << books[i].getTITLE() << endl;
            cout << "AUTHOR: " << books[i].getAUTHOR() << endl;
            cout << "EDITION: " << books[i].getEDITION() << endl;
            cout << "PUBLICATION: " << books[i].getPUBLICATION() << endl;
        }
    }

    if (counter == 0)
    {
        cout << "No books record found!!!" << endl;
    }
} // end of display books method

void openBookFiles()
{
    // read line by line
    string readLine_ifStream_textFile;
    // read file
    ifstream ReadFile("Library_System_Management_Record_Book.txt");

    // ask if the file is open
    if (ReadFile.is_open())
    {
        // if the text file has text
        int dataTextFile = 0;
        // fetch the text and read it line by line using while loop
        while (getline(ReadFile, readLine_ifStream_textFile))
        {
            int textLength = readLine_ifStream_textFile.length();
            books[dataTextFile].getISBN() = readLine_ifStream_textFile.substr(0, 5);
            books[dataTextFile].getTITLE() = readLine_ifStream_textFile.substr(4, textLength - 4);
            books[dataTextFile].getAUTHOR() = readLine_ifStream_textFile.substr(4, textLength - 4);
            books[dataTextFile].getEDITION() = readLine_ifStream_textFile.substr(4, textLength - 4);
            books[dataTextFile].getPUBLICATION() = readLine_ifStream_textFile.substr(4, textLength - 4);
            dataTextFile++;
        }
    }
    else
    {
        cout << "Unable to open the file!!!" << endl;
    }

    // close the file
    ReadFile.close();

} // end of open book files method

void saveBookRecords()
{
    ofstream RecordBooks;
    RecordBooks.open("Library_System_Management_Record_Book.txt");
    for (int i = 0; i < maxrow; i++)
    {
        if (books[i].getISBN() == "\0")
        {
            break;
        }
        else
        {
            RecordBooks << books[i].getISBN() + "," + books[i].getTITLE() + "," + books[i].getAUTHOR() + "," + books[i].getEDITION() + "," +
                               books[i].getPUBLICATION()
                        << endl;
        }
    }
    // close file
    RecordBooks.close();
}