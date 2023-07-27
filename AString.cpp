#include "astring.hpp"
#include <cstring>

//default constructor
AString::AString() {
    this->length = 0;
    this->cap = 0;
    this->data = nullptr;
    this->tempReturn = nullptr;
}

//constructor with arguments for char*
AString::AString(const char* newData) {
    this->length = strlen(newData);
    this->cap = this->length + 1;
    this->data = new char[this->cap];
    this->tempReturn = nullptr;
    for (int i = 0; i < this->length; i++) {
        this->data[i] = newData[i];
    }
    this->data[length] = '\0';
}

//constructor with arguments for passing a string by reference
AString::AString(const AString& newData) {
    this->length = newData.length;
    this->cap = this->length + 1;
    this->data = new char[this->cap];
    this->tempReturn = nullptr;
    for (int i = 0; i < this->length; i++) {
        this->data[i] = newData.data[i];
    }
    this->data[length] = '\0';
}

//called with the = string reference
AString& AString::operator= (const AString& newData) {
    if (data != nullptr) {
        delete[] data;
    }

    this->length = newData.length;
    this->cap = newData.length + 1;
    this->data = new char[this->cap];
    for (int i = 0; i < this->length; i++) {
        data[i] = newData.data[i];
    }
    this->data[length] = '\0';

    return *this;
}

//called with the = char*
AString& AString::operator= (const char* newData) {
    if (this->data != newData) {
        if (this->data != nullptr) {
            delete[] data;
        }

        this->length = strlen(newData);
        this->cap = this->length + 1;
        this->data = new char[this->cap];
        for (int i = 0; i < this->length; i++) {
            data[i] = newData[i];
        }
        this->data[length] = '\0';
    }
    return *this;
}

//return two strings combined
AString AString::operator+ (const AString& newData) {
    if (tempReturn != nullptr)
        delete[] tempReturn;
    //initialize temp with enough space for both strings
    tempReturn = new char[this->length + newData.cap];
    //fill begining of temp with data
    strcpy(tempReturn, data);
    //starting where data ended, fill temp with newData
    strcat(tempReturn, newData.data);
    tempReturn[this->length + newData.length] = '\0';
    AString tempString(tempReturn);
    return tempString;
}

// == char*
bool AString::operator== (const char* newData) {
    //function that compares strings
    return  !strcmp(data, newData);
}

// == string reference
bool AString::operator== (const AString& newData) {
    return  !strcmp(data, newData.data);
}

bool AString::operator> (const AString& newData) const {
    bool greaterThan = true;
    int counter = 0;
    int dataLetter = 0;
    int newDataLetter = 0;
    if (newData.data != nullptr && data != nullptr) {
        //compare each letter of both Strings until they differ,
        while (dataLetter == newDataLetter && counter < this->length && counter < newData.length) {
            dataLetter = static_cast<int>(data[counter]);
            newDataLetter = static_cast<int>(newData.data[counter]);
            if (dataLetter > newDataLetter)
                greaterThan = true;
            else if (dataLetter < newDataLetter)
                greaterThan = false;
            counter++;
        }
    }
    else {
        greaterThan = false;
    }

    return greaterThan;
}

bool AString::operator< (const AString& newData) const {
    bool lessThan = true;
    int counter = 0;
    int dataLetter = 0;
    int newDataLetter = 0;

    //compare each letter of both Strings until they differ,
    if (newData.data != nullptr && data != nullptr) {
        while (dataLetter == newDataLetter && counter < this->length && counter < newData.length) {
            dataLetter = static_cast<int>(data[counter]);
            newDataLetter = static_cast<int>(newData.data[counter]);
            if (dataLetter < newDataLetter) {
                lessThan = true;
            }
            else if (dataLetter > newDataLetter) {
                lessThan = false;
            }
            counter++;
        }
    }
    else {
        lessThan = false;
    }

    return lessThan;
}


char& AString::operator[] (const int position) {
    int index = position;
    //check incase position is negative
    if (position < 0) {
        index = length + position;
    }

    return data[index];
}

//create a string of a part of a string
AString AString::substring(int position, int len) {
    AString tempString;
    //for typical both values positive (position can be zero)
    if (position >= 0 && len >= 0) {
        if (tempReturn != nullptr)
            delete[] tempReturn;
        tempReturn = new char[len + 1];
        for (int i = 0; i < len; i++) {
            tempReturn[i] = data[position + i];
        }
        tempReturn[len] = '\0';
        AString tmpStr(tempReturn);
        tempString = tmpStr;
    }
    //positive postition, but negative length given (length can be zero)
    if (position >= 0 && len < 0)
        tempString = substringNegLength(position, len);

    //Negative position and positive length
    if (position < 0 && len >= 0)
        tempString = substringNegPosition(position, len);

    //Negative position and negative length which can be zero.
    if (position < 0 && len <= 0)
        tempString = substringNegLengthAndPostition(position, len);
    return tempString;
}

AString AString::substringNegLength(int position, int len) {
    if (tempReturn != nullptr)
        delete[] tempReturn;
    int templen = this->cap + len;
    tempReturn = new char[templen + 1];
    for (int i = 0; i < templen; i++) {
        tempReturn[i] = data[position + i];
    }
    tempReturn[templen] = '\0';
    AString tempString(tempReturn);
    return tempString;
}

AString AString::substringNegPosition(int position, int len) {
    if (tempReturn != nullptr)
        delete[] tempReturn;
    int index = this->length + position;
    tempReturn = new char[len + 1];
    for (int i = 0; i < len; i++) {
        tempReturn[i] = data[index + i];
    }
    tempReturn[len] = '\0';
    AString tempString(tempReturn);
    return tempString;
}

AString AString::substringNegLengthAndPostition(int position, int len) {
    if (tempReturn != nullptr)
        delete[] tempReturn;
    int index = this->length + position - len;
    int templen = this->length - index;
    tempReturn = new char[templen + 1];
    for (int i = 0; i < templen; i++) {
        tempReturn[i] = data[index + i];
    }
    tempReturn[templen] = '\0';
    AString tempString(tempReturn);
    return tempString;
}

//convert string to all lowercase
void AString::lowerCase() {
    for (int i = 0; i < this->length; i++) {
        //converts char to int for easy check if capital or lowercase
        int value = static_cast<int>(data[i]);
        //if capital, convert the char to the lowercase
        if (value < 97 && value > 64 && value != 32) {
            value += 32;
        }
        data[i] = static_cast<char>(value);
    }
}

//convert string to first upperCase
void AString::upperCase() {
    //converts char to int for easy check if capital or lowercase
    int value = static_cast<int>(data[0]);
    //if capital, convert the char to the lowercase
    if (value >= 97 && value <= 122) {
        value -= 32;
    }
    data[0] = static_cast<char>(value);

}

//remove puncutation from a string
void AString::removePuncuation() {
    int noPunctLen = this->length;
    int tempInt = this->length;
    char* temp;
    for (int i = 0; i < this->length; i++) {
        int value = static_cast<int>(data[i]);
        //decimal numbers of all puncuation not including numbers and -
        if ((value >= 33 && value <= 44) ||
            (value >= 46 && value <= 47) ||
            (value >= 58 && value <= 64) ||
            (value >= 91 && value <= 96) ||
            (value >= 123 && value <= 126)) {
            //adjust length to not include puncuation
            noPunctLen--;
        }
    }
    //if there was puncuation
    if (this->length != noPunctLen) {
        temp = new char[cap];
        //copy original string
        for (int i = 0; i < this->length; i++) {
            temp[i] = this->data[i];
        }
        delete[] this->data;
        this->length = noPunctLen;
        this->cap = this->length + 1;
        this->data = new char[this->cap];
        int count = 0;
        int value;
        for (int i = 0; i < tempInt; i++) {
            //store string with no punct in data;
            value = static_cast<int>(temp[i]);
            //decimal numbers of all puncuation not including numbers and -
            if (!((value >= 33 && value <= 44) ||
                (value >= 46 && value <= 47) ||
                (value >= 58 && value <= 64) ||
                (value >= 91 && value <= 96) ||
                (value >= 123 && value <= 126))) {
                this->data[count] = temp[i];
                count++;
            }
        }
        this->data[this->length] = '\0';
        delete[] temp;
    }
}



int AString::stringInt() {
    //int num = std::stoi(data);
    int num = 0;
    int tempNum = 0;
    int adjuster = 1;
    for (int i = length - 1; i >= 0; i--) {
        tempNum = static_cast<int>(data[i]);
        if (tempNum >= 48 && tempNum <= 57) {
            tempNum = tempNum - 48;
            tempNum = tempNum * adjuster;
            num = num + tempNum;
        }
        adjuster *= 10;
    }
    return num;
}


//return capacity
int AString::capacity() {
    return this->cap;
}

//return length
int AString::size() {
    return this->length;
}

void AString::clear() {
    delete[] data;
    delete[] tempReturn;
    tempReturn = nullptr;
    data = nullptr;
    length = 0;
    cap = 0;
}

//insertion operator
std::ostream& operator <<(std::ostream& out, const AString& s) {
    out << s.data;
    return out;
}

//extraction operator
std::istream& operator >> (std::istream& in, const AString& s) {
    in >> s.data;
    return in;
}

AString::~AString() {
    if (tempReturn != nullptr)
        delete[] tempReturn;
    if (data != nullptr)
        delete[] data;
}
