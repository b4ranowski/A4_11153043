#include "Book.h"
#include <string>

#ifndef A4_11153043_PAPERBOOK_H
#define A4_11153043_PAPERBOOK_H


class PaperBook: public Book {
private:
    int numPages;
    string pFormat;
public:
    void setnumPages(int numPages);
    int getnumPages();
    void setpFormat(string pFormat);
    string getpFormat();

    PaperBook();
    PaperBook(string title, string author, string publisher, string isbn, int numPages, string pFormat);
    ~PaperBook();
    void write();
    void lendingConditions();
};


#endif //A4_11153043_PAPERBOOK_H
