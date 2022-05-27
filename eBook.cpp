#include "eBook.h"
#include <iostream>

using namespace std;

eBook::EBook(): Book(), fileSize(-1), eFormat("")   //Dies ist der Default Konstruktor von der Unterfunktion e
{
}

eBook::EBook(string title, string author, string publisher, string isbn, float fileSize, string eFormat):       //Dies ist der Initialisierungskonstruktor von der Tochterklasse EBook
        Book(title, author, publisher, isbn), fileSize(fileSize), eFormat(eFormat)
{cout << "Das eBook mit dem Titel: "<< title << " wurde erstellt \n";
}

void eBook::write() {                                                            //Diese Methode sorgt für die Ausgabe eines E-Books
    Book::write();
    cout << "Dateigroesse: "<< fileSize << "\neBook-Format: "<< eFormat << endl;
}

eBook::~EBook() {                               //Destruktor von EBook
    cout << "Das eBook mit dem Titel: "<< title << " wurde geloescht \n";

}

void eBook::lendingConditions() {           //Methode in der Tochterfunktion
    cout << "Ausleihfrist 3 Wochen, Ausleihe per Download Link.\n\n";
}

void eBook::setfileSize(float fileSize) {               //Getter und Setter von EBook
    this->fileSize=fileSize;
}

float eBook::getfileSize() {
    return fileSize;
}

void eBook::seteFormat(string eFormat) {
    this->eFormat=eFormat;
}

string eBook::geteFormat() {
    return eFormat;
}