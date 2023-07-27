#include "testClasses.hpp"

testClasses::testClasses() {
    s[0] = AString("testString");
    s[1] = AString("a test string");
    s[2] = AString("");
    s[3] = AString("THIS IS AN UPPERCASE STRING");
    s[4] = AString("this is an uppercase string");
    s[5] = AString("\n");
    s[6] = AString("");
    s[7] = AString("  split  split  split  ");
    s[8] = AString("                          ");
    s[9] = AString("testString");

    longString = "Hello I am a really long  string of at least eighty characters to test if this class can handle really long strings";
    str = "Hello 2 You";
    strr = "Let's test!!!";

    t[0] = AString("Hello!!!");
    t[1] = AString("Yesterday my dog died :(");
    t[2] = AString(" !! ");
    t[3] = AString("2-3 tree!");
    t[4] = AString("H?llo");

    nums[0] = AString("0");
    nums[1] = AString("25");
    nums[2] = AString("4000000");


    intList.add(0);
    intList.add(1);
    intList.add(2);
    intList.add(3);
    intList.add(4);

    zero = AString("0");
    one = "1";
    two = "2";
    three = "3";
    four = "4";
    five = "5";
    six = "6";
    seven = "7";

    strList.add(zero);
    strList.add(one);
    strList.add(two);
    strList.add(three);
    strList.add(four);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

}

void testClasses::testStrings() {
    testStringPrint();
    testStringEquality();
    testStringAssign();
    testStringAddition();
    testStringGreaterThan();
    testStringLessThan();
    testStringArray();
    testStringSize();
    testStringSubstring();
    testStringLowerCase();
    testStringUpperCase();
    testStringRemovePunctuation();
    testStringToNumber();
}

void testClasses::testStringPrint() {
    std::cout << "Testing Printing String Array\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "	" << s[i] << "\n";
    }
}

void testClasses::testStringEquality() {
    //Testing Equality operators
    std::cout << "Equality Tests\n";
    if (s[0] == AString("testString")) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }

    if (s[0] == s[9]) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (s[2] == "") {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (s[1] == "a test string") {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (!(s[3] == s[4])) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
    if (longString == "Hello I am a really long  string of at least eighty characters to test if this class can handle really long strings") {
        std::cout << "  Test 6: passed\n";
    }
    else {
        std::cout << "  Test 6: failed\n";
    }
}

void testClasses::testStringAssign() {
    std::cout << "Assignment Operator Tests\n";
    AString str;
    str = "a test string";
    if (str == s[1]) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    str = AString("testString");
    if (str == s[0]) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    str = "";
    if (str == s[6]) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    str = AString("\n");
    if (str == s[5]) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }

}

void testClasses::testStringAddition() {
    std::cout << "Addition Operator Tests\n";
    if (AString("testStringtestString") == s[0] + s[9]) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (s[6] + s[6] == "") {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (s[5] + s[6] == AString("\n")) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (s[0] + s[1] + s[2] == "testStringa test string") {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (s[0] + longString == "testStringHello I am a really long  string of at least eighty characters to test if this class can handle really long strings") {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
    if (s[0] + longString + s[1] == "testStringHello I am a really long  string of at least eighty characters to test if this class can handle really long stringsa test string") {
        std::cout << "  Test 6: passed\n";
    }
    else {
        std::cout << "  Test 6: failed\n";
    }
    if (s[0] + s[0] + s[0] == "testStringtestStringtestString") {
        std::cout << "  Test 7: passed\n";
    }
    else {
        std::cout << "  Test 7: failed\n";
    }

}

void testClasses::testStringGreaterThan() {
    std::cout << "Greater than Operator Tests\n";
    //Comparing alphabetic order. Later in the alphabet = greater. Lowercase is greater than uppercase.
    if (s[0] > s[1]) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (s[4] > s[3]) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (s[9] > s[6]) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (s[7] > s[6]) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (!(longString > s[9])) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
}

void testClasses::testStringLessThan() {
    std::cout << "Less than Operator Tests\n";
    //Comparing alphabetic order. Later in the alphabet = greater. Lowercase is greater than uppercase.
    if (s[1] < s[0]) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (s[3] < s[4]) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (s[6] < s[9]) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (s[6] < s[7]) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (longString < s[9]) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
}

void testClasses::testStringArray() {
    std::cout << "Array Operator Tests\n";
    if (s[0][1] == 'e') {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (s[9][-1] == 'g') {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (s[3][-3] == 'I') {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (s[4][4] == ' ') {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (s[6][0] == 0) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
    if (longString[81] == 'a') {
        std::cout << "  Test 6: passed\n";
    }
    else {
        std::cout << "  Test 6: failed\n";
    }
}

void testClasses::testStringSize() {
    std::cout << "Size Tests\n";
    if (s[9].size() == 10) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (s[2].size() == 0) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (s[8].size() == 26) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (s[3].size() == 27) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (longString.size() == 115) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
}

void testClasses::testStringSubstring() {
    std::cout << "Substring Tests\n";
    if (s[0].substring(0, 5) == "testS") {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (s[1].substring(-6, -1) == "tring") {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (s[9].substring(0, -3) == "testStri") {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (s[1].substring(-6, 4) == "stri") {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (s[9].substring(0, -1) == s[9]) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
    if (s[4].substring(0, 4) == "this") {
        std::cout << "  Test 6: passed\n";
    }
    else {
        std::cout << "  Test 6: failed\n";
    }
    if (longString.substring(0, 21) == "Hello I am a really l") {
        std::cout << "  Test 7: passed\n";
    }
    else {
        std::cout << "  Test 7: failed\n";
    }
}

void testClasses::testStringLowerCase() {
    s[3].lowerCase();
    str.lowerCase();
    strr.lowerCase();
    std::cout << "Lowercase Tests\n";
    if (s[3] == s[4]) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (str == AString("hello 2 you")) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (strr == AString("let's test!!!")) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
}

void testClasses::testStringUpperCase() {
    s[3].upperCase();
    str.upperCase();
    strr.upperCase();
    std::cout << "Uppercase Tests\n";
    if (s[3] == AString("This is an uppercase string")) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (str == AString("Hello 2 you")) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (strr == AString("Let's test!!!")) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
}

void testClasses::testStringRemovePunctuation() {
    for (int i = 0; i < 5; i++) {
        t[i].removePuncuation();
    }
    std::cout << "Remove Punctuation Tests\n";
    if (t[0] == "Hello") {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (t[1] == "Yesterday my dog died ") {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (t[2] == "  ") {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (t[3] == "2-3 tree") {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (t[4] == "Hllo") {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
}

void testClasses::testStringToNumber() {
    num[0] = nums[0].stringInt();
    num[1] = nums[1].stringInt();
    num[2] = nums[2].stringInt();
    std::cout << "Convert String Numerals to Numbers Tests\n";
    if (num[0] == 0) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (num[1] == 25) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (num[2] == 4000000) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
}

void testClasses::testDataStructures() {
    testDSPrintAddGet();
    testDSGetNextGetPrevious();
    testDSInList();
    testDSDelete();
    testDSGetSize();
    testDSPushPeek();
    testDSPop();
    testDSIsEmpty();
}

void testClasses::testDSPrintAddGet() {
    std::cout << "Testing Printing Int Linked List Created Using Add Function\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "  " << intList.get(i) << "\n";
    }
    std::cout << "Testing Printing String Linked List Created Using Add Function\n";
    for (int i = 0; i < strList.getSize(); i++) {
        std::cout << "  " << strList.get(i) << "\n";
    }
    std::cout << "Testing Get Functions with Int Linked List\n";
    if (intList.get(0) == 0) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (intList.get(1) == 1) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (intList.get(2) == 2) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (intList.get(3) == 3) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (intList.get(4) == 4) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }

    std::cout << "Testing Add and Get Functions with String Linked List\n";
    if (strList.get(0) == zero) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (strList.get(1) == one) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (strList.get(2) == two) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (strList.get(3) == three) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (strList.get(4) == four) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
}

void testClasses::testDSGetNextGetPrevious() {
    std::cout << "Testing GetNext and GetPrevious Functions\n";
    if (intList.getPrevious(1) == 0) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (intList.getNext(1) == 2) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (strList.getPrevious(one) == zero) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (strList.getNext(one) == two) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
}

void testClasses::testDSInList() {
    std::cout << "Testing inList Functions\n";
    if (intList.inList(0) == true) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (intList.inList(7) == false) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (strList.inList(zero) == true) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (strList.inList(AString("notHere")) == false) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
}

void testClasses::testDSDelete() {
    //Adding to intList to become-> 0,1,2,3,4,6,7,5
    //Use deleteByData to make intList-> 0,1,2,3,4,6,5
    //Use deleteByIndex to make intList->0,1,2,3,4,5
    intList.add(6);
    intList.add(7);
    intList.add(5);
    intList.deleteByData(7);
    intList.deleteByIndex(5);

    strList.add(six);
    strList.add(seven);
    strList.add(five);
    strList.deleteByData(seven);
    strList.deleteByIndex(5);

    std::cout << "Testing Delete by Data & Delete by Index with Int Linked List\n";
    if (intList.get(0) == 0 && intList.get(1) == 1 && intList.get(2) == 2 && intList.get(3) == 3 && intList.get(4) == 4 && intList.get(5) == 5) {
        std::cout << "  Test: passed\n";
    }
    else {
        std::cout << "  Test: failed\n";
        std::cout << "      Predicted Array: 0, 1, 2, 3, 4, 5\n";
        std::cout << "      Actual Array:";
        for (int i = 0; i < intList.getSize(); i++) {
            std::cout << intList.get(i);
            if (i != intList.getSize() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "Testing Delete by Data & Delete by Index with String Linked List\n";
    if (strList.get(0) == zero && strList.get(1) == one && strList.get(2) == two && strList.get(3) == three && strList.get(4) == four && strList.get(5) == five) {
        std::cout << "  Test: passed\n";
    }
    else {
        std::cout << "  Test: failed\n";
        std::cout << "      Predicted Array: 0, 1, 2, 3, 4, 5\n";
        std::cout << "      Actual Array:";
        for (int i = 0; i < strList.getSize(); i++) {
            std::cout << strList.get(i);
            if (i != strList.getSize() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
}

void testClasses::testDSGetSize() {
    std::cout << "Testing getSize Function\n";
    if (intList.getSize() == 6) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (strList.getSize() == 6) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
}

void testClasses::testDSPushPeek() {
    
    
    std::cout << "Testing Push & Peek Functions from Stack\n";
    if (intStack.peek() == 3) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
}

void testClasses::testDSPop() {
    std::cout << "Testing Pop & Peek Functions from Stack\n";
    if (intStack.pop() == 3) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (intStack.peek() == 2) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }
    if (intStack.pop() == 2) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (intStack.peek() == 1) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (intStack.pop() == 1) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
}

void testClasses::testDSIsEmpty() {
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Testing Pop & isEmpty Functions from Stack\n";
    if (intStack.isEmpty() == false) {
        std::cout << "  Test 1: passed\n";
    }
    else {
        std::cout << "  Test 1: failed\n";
    }
    if (intStack.pop() == 3) {
        std::cout << "  Test 2: passed\n";
    }
    else {
        std::cout << "  Test 2: failed\n";
    }

    if (intStack.pop() == 2) {
        std::cout << "  Test 3: passed\n";
    }
    else {
        std::cout << "  Test 3: failed\n";
    }
    if (intStack.pop() == 1) {
        std::cout << "  Test 4: passed\n";
    }
    else {
        std::cout << "  Test 4: failed\n";
    }
    if (intStack.isEmpty() == true) {
        std::cout << "  Test 5: passed\n";
    }
    else {
        std::cout << "  Test 5: failed\n";
    }
}


