/*
    OOP Concepts Applied:
    -> C++ Access Specifiers
    -> C++ Encapsulation
    -> C++ Files
*/
// C++ libraries
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

const int maxrow = 100; // max array value

// class book
class BOOK
{
private: // private access spefiers
    string isbn, title, author, edition, publication;

public: // public access spefiers
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

// counter increament
int counter = 0;
BOOK books[maxrow] = {}; // class array

// method identifiers
void createBooks();     // choice 1
void updateBooks();     // choice 2
void deleteBooks();     // choice 3
void searchBooks();     // choice 4
void displayBooks();    // choice 5
void openBookFiles();   // open Book Files
void saveBookRecords(); // save Book Records

// main method
int main()
{
    int choice;
    openBookFiles(); // opem method file
    do
    {
        cout << "LIBRARY SYSTEM MANAGEMENT" << endl;
        cout << "1) Create Books\n2) Update Books\n3) Delete Books\n4) Search Books\n5) Display Books\n6) Exit\n\nEnter choice: ";
        cin >> choice;
        switch (choice) /* switch case choices */
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
            cout << endl;
            system("pause");
            break;
        default:
            break;
        }
    } while (choice != 6);

    cout << "LIBRARY SYSTEM MANAGEMENT... SYSTEM LOGOUT!!!" << endl;

    return 0;
}

/* create method to add books */
void createBooks() // choice 1
{
    cin.ignore();
    string isbn, title, author, edition, publication;
    cout << "CREATE BOOKS" << endl;
    // input data
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
            books[i].setISBN(isbn); // set the setter method from the input
            books[i].setTITLE(title);
            books[i].setAUTHOR(author);
            books[i].setEDITION(title);
            books[i].setPUBLICATION(publication);
            cout << "\nBOOK SUCCESSFULLY CREATED!!!" << endl;
            saveBookRecords();
            break;
        }
    }
} // end of create books method

/* update method to update book infomation */
void updateBooks()
{

    cin.ignore();
    string isbn, title, author, edition, publication, yn;
    cout << "BOOK UPDATE" << endl;
    // search book statement
    cout << "SEARCH BOOK BY ISBN: ";
    getline(cin, isbn);

    for (int i = 0; i < maxrow; i++)
    {
        // ask if the book isbn get method is empty   
        if (books[i].getISBN() == isbn)
        {
            counter++;

            // display books if found
            cout << "BOOK FOUND!!!" << endl;
            cout << "ISBN: " << books[i].getISBN() << endl; // display book getters
            cout << "TITLE: " << books[i].getTITLE() << endl;
            cout << "AUTHOR: " << books[i].getAUTHOR() << endl;
            cout << "EDITION: " << books[i].getEDITION() << endl;
            cout << "PUBLICATION: " << books[i].getPUBLICATION() << endl;

            // update statement
            cout << "Do you want to update is book?\n[Y - y] YES\n[N - n] NO" << endl;
            getline(cin, yn);

            // update condition
            if (yn == "y" || yn == "Y")
            {
                // update book infomation
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
                books[i].setTITLE(title); // update book setter
                books[i].setAUTHOR(author);
                books[i].setEDITION(title);
                books[i].setPUBLICATION(publication);
                cout << "\nBOOK SUCCESSFULLY UPDATED!!" << endl;
                saveBookRecords();
                break;
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

    // if the text file does not have item
    if (counter == 0)
    {
        cout << "BOOKS DOES NOT EXIST!!!" << endl;
    }

} // end of update books method

/* delete method to delete books */
void deleteBooks() // choice 3
{
    cin.ignore();
    string isbn, yn;
    cout << "DELETE BOOK" << endl;
    // delete books statemnts
    cout << "SEARCH BOOK BY ISBN: ";
    getline(cin, isbn);
    for (int i = 0; i < maxrow; i++)
    {
         // ask if the book isbn get method is empty
        if (books[i].getISBN() == isbn)
        {
            // increment
            counter++;

            // display book if was found
            cout << "BOOK FOUND!!!\n"
                 << endl;
            cout << "ISBN: " << books[i].getISBN() << endl;  // display books getters
            cout << "TITLE: " << books[i].getTITLE() << endl;
            cout << "AUTHOR: " << books[i].getAUTHOR() << endl;
            cout << "EDITION: " << books[i].getEDITION() << endl;
            cout << "PUBLICATION: " << books[i].getPUBLICATION() << endl;

            // delete books statement
            cout << "\nDo you want to delete this book?\n[Y - y] YES\n[N - n] NO" << endl;
            getline(cin, yn); 

            // delete books conditions
            if (yn == "y" || yn == "Y")
            {
                books[i].setISBN(""); // set setters to empty string if deleted
                books[i].setTITLE("");
                books[i].setAUTHOR("");
                books[i].setEDITION("");
                books[i].setPUBLICATION("");

                cout << "\nBOOK SUCCESSFULLY DELETED!!" << endl;
                // decrease the book
                counter--;
                saveBookRecords();
                break;
            }
            else if (yn == "n" || yn == "N")
            {
                cout << "\nBOOK NOT DELETED!!" << endl;
            }

            break;
        }
    }

    // if no books found
    if (counter == 0)
    {
        cout << "BOOKS DOES NOT EXIST!!!" << endl;
    }

} // end of delete books method

/* search method to search books*/
void searchBooks() // choice 4
{
    cin.ignore();
    string isbn;
    cout << "SEARCH BOOK" << endl;
    // search the books
    cout << "SEARCH BOOK BY ISBN: ";
    getline(cin, isbn);
    for (int i = 0; i < maxrow; i++)
    {
        // ask if the book isbn get method is empty
        if (books[i].getISBN() == isbn)
        {
            // increament
            counter++;

            // display books if found
            cout << "BOOK FOUND!!!\n"
                 << endl;
            cout << "ISBN: " << books[i].getISBN() << endl;
            cout << "TITLE: " << books[i].getTITLE() << endl;
            cout << "AUTHOR: " << books[i].getAUTHOR() << endl;
            cout << "EDITION: " << books[i].getEDITION() << endl;
            cout << "PUBLICATION: " << books[i].getPUBLICATION() << endl;
            cout << "\n";
        }
    }

    // if no books found
    if (counter == 0)
    {
        cout << "BOOKS DOES NOT EXIST!!!" << endl;
    }

} // end of search books method

/* display method to display books */
void displayBooks() // choice 5
{
    cout << "\nDISPLAY BOOKS" << endl;
    cout << "ISBN"
         << "\t\t"
         << "TITLE"
         << "\t\t"
         << "AUTHOR"
         << "\t\t"
         << "EDITION"
         << "\t\t"
         << "PUBLICATION" << endl;
    for (int i = 0; i < maxrow; i++)
    {
        // ask if the book isbn get method is empty
        if (books[i].getISBN() != "\0")
        {
            counter++; // increamnt
            // display books
            cout << books[i].getISBN() << "\t\t" << books[i].getTITLE() << "\t\t" << books[i].getAUTHOR() << "\t\t" << books[i].getEDITION() << "\t\t" << books[i].getPUBLICATION() << endl;
        }
    }

    // if no books found
    if (counter == 0)
    {
        cout << "No books record found!!!" << endl;
    }
} // end of display books method

/* open file method to open file save from text */
void openBookFiles()
{
    // read text tile line by line
    string textfile;
    int index; // increament the text file
    ifstream ReadBookRecord;
    // read the book record in array
    ReadBookRecord.open("Library_System_Management_Record_Book.txt", ios::in);
    if (ReadBookRecord.fail()) // if the file was not found
    {
        cout << "File was not found" << endl;
        system("pause");
        exit(1);
    }
    // read text file line by line
    getline(ReadBookRecord, textfile);
    index = 0;                                        // increment
    string isbn, title, author, edition, publication; // variable
    while (index < maxrow && ReadBookRecord >> isbn >> title >> author >> edition >> publication)
    {
        books[index].setISBN(isbn);
        books[index].setTITLE(title);
        books[index].setAUTHOR(author);
        books[index].setEDITION(edition);
        books[index].setPUBLICATION(publication);
        index++; // increment
    }

    // close file
    // ReadBookRecord.close();

} // end of open book files method

/* save file method to save file save from text */
void saveBookRecords()
{
    /* write file name */
    ofstream WriteRecordBooks;
    WriteRecordBooks.open("Library_System_Management_Record_Book.txt");
    for (int i = 0; i < maxrow; i++)
    {
        if (books[i].getISBN() == "\0") /* ask if the book isbn is empty*/
        {
            break;
        }
        else
        {
            /* write the input text to the text file */
            WriteRecordBooks << books[i].getISBN() + "\t" + books[i].getTITLE() + "\t" + books[i].getAUTHOR() + "\t" + books[i].getEDITION() + "\t" + books[i].getPUBLICATION() << endl;
        }
    }
    // close file
    WriteRecordBooks.close();
}