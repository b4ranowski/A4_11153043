#include "AudioBook.h"
#include <iostream>

using namespace std;

AudioBook::AudioBook(): Book(), duration(-1), speaker("")            //Dies ist der Default Konstruktor von der Tochterklasse AudioBook
{
}

AudioBook::AudioBook(string title, string author, string publisher, string isbn, int duration, string speaker):     //Dies ist der Initialisierungskonstruktor von der Tochterklasse AudioBook
        Book(title, author, publisher, isbn), duration(duration), speaker(speaker)
{cout << "Das AudioBook mit dem Titel: "<< title << " wurde erstellt \n";
}

void AudioBook::write() {                       //Diese Methode sorgt für die Ausgabe eines AudioBook
    Book::write();
    cout << "Dauer in Minuten: "<<duration << "\n" << "Sprecher: "<<speaker << endl;
}

AudioBook::~AudioBook() {                   //Destruktor von Audiobook
    cout << "Das AudioBook mit dem Titel: "<< title << " wurde geloescht \n";
}

void AudioBook::lendingConditions() {       //Methode in der Tochterfunktion
    cout << "Ausleihfrist: 2 Wochen, Ausleihe per Download Link.\n\n";
}

int AudioBook::getduration() {              //Getter und Setter Methoden von Audiobook
    return duration;
}

void AudioBook::setduration(int duration) {
    this->duration=duration;
}

void AudioBook::setspeaker(string speaker) {
    this->speaker=speaker;
}

string AudioBook::getspeaker() {
    return speaker;
}

