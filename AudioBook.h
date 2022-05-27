#include "Book.h"
#include <string>

#ifndef A4_11153043_AUDIOBOOK_H
#define A4_11153043_AUDIOBOOK_H


class AudioBook: public Book {
private:
    int duration;
    string speaker;
public:
    void setduration(int duration);
    int getduration();
    void setspeaker(string speaker);
    string getspeaker();

    AudioBook();
    AudioBook(string title, string author, string publisher, string isbn, int duration, string speaker);
    ~AudioBook();
    void write();
    void lendingConditions();
};


#endif //A4_11153043_AUDIOBOOK_H
