#include "Book.h"
#include <string>

#ifndef A4_11153043_EBOOK_H
#define A4_11153043_EBOOK_H


class eBook: public Book {
protected:
    float fileSize;
    string eFormat;
public:
    void setfileSize(float fileSize);
    float getfileSize();
    void seteFormat(string eFormat);
    string geteFormat();

    EBook();
    EBook(string title, string author, string publisher, string isbn, float fileSize, string eFormat);
    ~EBook();
    void write();
    void lendingConditions();
};


#endif //A4_11153043_EBOOK_H
