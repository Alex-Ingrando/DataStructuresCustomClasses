#ifndef ASTRING
#define ASTRING

#include <iostream>
#include <cstring>
#include <vector>

class AString {

private:
    int length;
    int cap;
    char* data;
    char* tempReturn;

    AString substringNegLength(int, int);
    AString substringNegPosition(int, int);
    AString substringNegLengthAndPostition(int, int);

public:

    AString();
    AString(const char*);
    AString(const AString&);

    AString& operator= (const char*);
    AString& operator= (const AString&);
    AString operator+ (const AString&);
    bool operator== (const char*);
    bool operator== (const AString&);
    bool operator> (const AString&) const;
    bool operator< (const AString&) const;

    char& operator[] (const int);

    void lowerCase();
    void upperCase();
    void removePuncuation();
    int stringInt();


    int size();
    int capacity();
    AString substring(int, int);
    void clear();


    friend std::ostream& operator<< (std::ostream&, const AString&);
    friend std::istream& operator>> (std::istream&, const AString&);

    ~AString();

};


#endif
