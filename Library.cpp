#include <iostream>
#include "Date.h"
#include "Book.h"
#include "eBook.h"
#include "PaperBook.h"
#include "AudioBook.h"
#include "Member.h"

using namespace std;

int main()
{
    Date d1(9, 4, 2022);
    Date d2(11, 5, 2022);
    Date d3;

    // Die folgende Anweisung erlaubt deutsche Umlaute und Monatsangaben (in Date)
    // muss evtl. in CodeBlocks auskommentiert werden.
    locale::global(locale("de_DE.utf-8"));

    eBook b1("Bornholmer Flucht", "Peters, Katharina", "Aufbau Digital", "9783841229120", 813, "ePub");
    PaperBook b2("Die Enkelin", "Schlink, Bernhard", "Diogenes", "9783257071818", 368, "Gebundene Ausgabe");
    AudioBook b3("Was der Himmel uns erzählt", "Kiel, Gertrude", "cbj audio", "9783837159493", 500, "Rohrbeck, Oliver");
    PaperBook b4("Müll", "Haas, Wolf", "Hoffmann und Campe", "9783455014303", 288, "Taschenbuch");
    PaperBook b5("Das Mädchen mit dem Drachen", "Colombani, Laetitia", "S.Fischer", "9783103974904", 272, "Taschenbuch");
    PaperBook b6("Serge", "Reza, Yasmina", "Hanser", "9783446272927", 208, "Gebundene Ausgabe");

    Member m1("Ellen Leseratte");
    Member m2("Klaus Bücherwurm");


    //Test ob das direkt in git aktualisiert123


    m1.lendBook(&b3, d3);
    m1.lendBook(&b1, d3);

    m2.lendBook(&b1, d1);
    m2.lendBook(&b2, d1);
    m2.lendBook(&b4, d1);
    m2.returnBook(&b2, d2);
    m2.returnBook(&b3, d2);

    m1.print();
    m2.print();
}

