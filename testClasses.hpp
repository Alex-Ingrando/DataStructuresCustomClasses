#include "AString.hpp"
#include "AStack.hpp"
#include "AVector.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

class testClasses {
private:
	AString s[10];
	AString longString;
	AString str;
	AString strr;
	AString t[5];
	AString nums[3];
	int num[3];

	AList<int> intList;
	AList<AString> strList;
	AString zero;
	AString one;
	AString two;
	AString three;
	AString four;
	AString five;
	AString six;
	AString seven;
	AStack<int> intStack;

public:
	testClasses();
	void testStrings();
	void testStringPrint();
	void testStringEquality();
	void testStringAssign();
	void testStringAddition();
	void testStringGreaterThan();
	void testStringLessThan();
	void testStringArray();
	void testStringSize();
	void testStringSubstring();
	void testStringLowerCase();
	void testStringUpperCase();
	void testStringRemovePunctuation();
	void testStringToNumber();

	void testDataStructures();
	void testDSPrintAddGet();
	void testDSGetNextGetPrevious();
	void testDSInList();
	void testDSDelete();
	void testDSGetSize();
	void testDSPushPeek();
	void testDSPop();
	void testDSIsEmpty();
};