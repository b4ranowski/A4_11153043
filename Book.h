#ifndef BOOK_BOOK_H
#define BOOK_BOOK_H
#include <string>

using namespace std;

class Book {
protected:
    string title;
    string author;
    string publisher;
    string isbn;
    string testisbn;
    string testpub;
public:
    void setTitle(string title);                //Zeile 17-26 alles Setter und Getter Methoden
    string getTitle();
    void setAuthor(string author);
    string getAuthor();
    void setPublisher(string publisher);
    string getPublisher();
    void setIsbn(string isbn);
    string getIsbn();

    Book();         //Defaultkonstruktor
    Book(string title, string author, string publisher /*int numPages*/);      // Initialisierungskonstruktor ohne ISBN, da es durch isbnGen eine ISBN erhält
    Book(string title, string author, string publisher, string isbn /*int numPages*/);         //Initialisierungskonstruktor
    bool read(ifstream& in);    //Lesen der Textdatei
    virtual void write();       //Ausgabe in der Konsole
    ~Book();         // Dies ist der Destruktor
    Book(Book &book);   //Kopierkonstruktor
    string isbnGen();      //ISBN-Generator
    bool validISBN();       //ISBN-Überprüfer
    static bool validISBN(string &s);       //statischer ISBN-Überprüfer
    virtual void lendingConditions()=0;
};
#endif //BOOK_BOOK_H

