#include "PaperBook.h"
#include <iostream>

using namespace std;

PaperBook::PaperBook(): Book(), numPages(-1), pFormat("")           //Dies ist der Default Konstruktor von der Tochterklasse Paperbook
{
}

PaperBook::PaperBook(string title, string author, string publisher, string isbn, int numPages, string pFormat):     //Dies ist der Initialisierungskonstruktor von der Tochterklasse Paperbook
        Book(title, author, publisher, isbn), numPages(numPages), pFormat(pFormat)
{cout << "Das PaperBook mit dem Titel: "<< title << " wurde erstellt \n";
}

void PaperBook::write() {                           //Diese Methode sorgt für die Ausgabe eines Paperbooks
    Book::write();
    cout << "Seitenanzahl: "<< numPages << "\nBuchformat: "<< pFormat << endl;
}

PaperBook::~PaperBook() {
    cout << "Das PaperBook mit dem Titel: "<< title << " wurde geloescht \n";
}

void PaperBook::lendingConditions() {               //Methode in der Tochterfunktion
    cout << "Ausleihfrist: 4 Wochen, Ausleihe per Abholung.\n\n";
}

int PaperBook::getnumPages() {              //Setter und Getter Methoden von Paperbook
    return numPages;
}

void PaperBook::setnumPages(int numPages) {
    this->numPages=numPages;
}

void PaperBook::setpFormat(string pFormat) {
    this->pFormat=pFormat;
}

string PaperBook::getpFormat() {
    return pFormat;
}
