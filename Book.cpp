#include "Book.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#define DELIM ';'
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

Book::Book():title(""), author(""), publisher(""), isbn("")   //Dies ist der Default Konstruktor
{
}

Book::Book(string title, string author, string publisher)             //Hierbei übernimmt die neue Methode Book::Book alles bis auf die ISBN
{
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->isbn = isbnGen();
}

Book::Book(string title, string author, string publisher, string isbn):       //Dies ist der Initialisierungskonstruktor
        title(title), author(author), publisher(publisher), isbn(isbn)
{cout << "Das Book mit dem Titel: "<< title << " wurde erstellt \n";
}

void Book::setTitle(string title) {                     //Die folgenden Zeilen sind die Getter und Setter Methoden der Attribute von Book
    this->title=title;
}

string Book::getTitle() {
    return title;
}

void Book::setAuthor(string author) {
    this->author=author;
}

string Book::getAuthor() {
    return author;
}

void Book::setPublisher(string publisher) {
    this->publisher=publisher;
}

string Book::getPublisher() {
    return publisher;
}

void Book::setIsbn(string isbn) {
    this->isbn=isbn;
}

string Book::getIsbn() {
    return isbn;
}

bool Book::read(ifstream &in) {
    string astring;
    if (in.eof())                                   //solange man nicht "End-of-line" ist wird das Dokument "durchgegangen"
        return false;

    getline(in,title, DELIM);
    getline(in,author, DELIM);
    getline(in,publisher, DELIM);
    getline(in,isbn, DELIM);
    return true;
}

void Book::write() {                                                            //Diese Methode sorgt für die Ausgabe eines Buches
    cout << "Titel: " <<title << '\n' << "Autor: "<<author << '\n' << "Verlag: " << publisher << '\n' << "ISBN: "<<isbn;
    if (validISBN(isbn))                    //je nachdem ob es eine gültige oder ungültige ISBN ist, wird dies angepasst
        cout << " (gueltig)"<< endl;
    else
        cout << " (ungueltig)"<< endl;
}

Book::~Book() {
    cout << "Das Book mit dem Titel: "<< title << " wurde geloescht \n";
}

Book::Book(Book &book)                      //In dieser Methode wird ein Buch kopiert
{
    title = book.title;
    author = book.author;
    publisher = book.publisher;
    isbn = book.isbn;
    cout << "\nDas Buch mit dem Titel: "<< title << " wurde kopiert \n";
}



string Book::isbnGen() {            //Dies ist der ISBN Generator
    int rdm[13]={9,7,8,3};          //Die ersten 4 Ziffern sind statisch
    int g = 0, u= 0;
    stringstream s;

    for (int i=4;i<13;i++)                          //In dieser for-Schleife werden die Ziffern 5 bis 12 zufällig generiert
    {
        rdm[i] = (rand() % 10);                     //bsp. rand()=423       423Modulo10 = 3
    }
    for(int i=0;i<12;i=i+2)
    {
        u+=rdm[i];                                  //Alle Ziffern an ungeraden Stellen im Array werden addiert
        g+=rdm[i+1];                                //Alle Ziffern an geraden Stellen im Array werden addiert
    }
    rdm[12]=(10-((u+3*(g))%10))%10;                 //vorgegebene Formel
    for(int i = 0; i<13;i++)
    {
        s <<rdm[i];                                 //mit stringstream wird das array zusammengesetzt
    }
    return s.str();
}

bool Book::validISBN(string &s) {                   //Diese statische Methode überprüft, ob eine ISBN gültig ist

    int u=0, g=0;

    if (s.size()==13)                        //ISBN muss genau 13 Zeichen besitzen
    {
        for(int i=0;i<13;i=i+2)
        {
            u+=(int)s[i];               //Alle Ziffern an ungeraden Stellen im Array werden addiert
            g+=(int)s[i+1];             //Alle Ziffern an geraden Stellen im Array werden addiert
        }

        if(((u+3*g)%10)==0)             //Wenn diese Funktion zutrifft, gibt diese Methode true zurück
            return true;
    }
    return false;
}

bool Book::validISBN() {            //Diese Methode hat dieselbe Funktion wie die vorherige mit dem Unterschied, dass dies Objektorientiert ist, also ein Objekt aus der Klasse Book zum Ausführen benötigt

    int u = 0, g = 0;

    if (isbn.size() == 13) {
        for (int i = 0; i < 13; i = i + 2) {
            u += (int) isbn[i];
            g += (int) isbn[i + 1];
        }

        if (((u + 3 * g) % 10) == 0)
            return true;
    }
    return false;
}
