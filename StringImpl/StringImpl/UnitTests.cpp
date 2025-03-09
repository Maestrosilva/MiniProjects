#include <iostream>
#include <cassert>
#include "String.h"

// Test default constructor and getSize()
void testConstructors() {
    String str1("Hello");
    assert(str1.getSize() == 5);
    String str2;
    assert(str2.getSize() == 0);
    String str3(str1);
    assert(str3.getSize() == 5);
    std::cout << "testConstructors passed!\n";
}

// Test append() and find()
void testAppend() {
    String str1("Hello");
    String str2("World");
    str1.append(" ");
    str1.append(str2);
    assert(str1.getSize() == 11);
    assert(str1.find("World") == 6);
    std::cout << "testAppend passed!\n";
}

// Test insertAt()
void testInsertAt() {
    String str1("Hello");
    String str2("World");
    str1.insertAt(3, str2);
    assert(str1.getSize() == 10);
    assert(str1.find("World") == 3);
    std::cout << "testInsertAt passed!\n";
}

// Test find()
void testFind() {
    String str1("Hello World");
    assert(str1.find("World") == 6);
    assert(str1.find("Hello") == 0);
    assert(str1.find("NotFound") == -1);
    std::cout << "testFind passed!\n";
}

// Test substring()
void testSubstring() {
    String str1("Hello World");
    String sub = str1.substring(6, 5);
    assert(sub.getSize() == 5);
    assert(sub.find("World") == 0);
    std::cout << "testSubstring passed!\n";
}

// Test split()
void testSplit() {
    String str1("Hello World");
    size_t size;
    String* parts = String::split(str1, " ", size);
    assert(size == 2);
    assert(parts[0].getSize() == 5);
    assert(parts[1].getSize() == 5);
    delete[] parts;
    std::cout << "testSplit passed!\n";
}

// Test concatenate()
void testConcatenate() {
    String strs[2] = { String("Hello"), String(" World") };
    String result = String::concatenate(strs, 2);
    assert(result.getSize() == 11);
    assert(result.find("Hello World") == 0);
    std::cout << "testConcatenate passed!\n";
}

// Test compare()
void testCompare() {
    String str1("Hello");
    String str2("Hello");
    String str3("World");
    assert(str1.compare(str2) == 0);
    assert(str1.compare(str3) == -1);
    assert(str3.compare(str1) == 1);
    std::cout << "testCompare passed!\n";
}

// Test charAt()
void testCharAt() {
    String str1("Hello");
    assert(str1.charAt(0) == 'H');
    assert(str1.charAt(4) == 'o');
    std::cout << "testCharAt passed!\n";
}

// Test isEmpty()
void testIsEmpty() {
    String str1;
    assert(str1.isEmpty() == true);
    String str2("Not Empty");
    assert(str2.isEmpty() == false);
    std::cout << "testIsEmpty passed!\n";
}

// Test out()
void testOut() {
    String str1("Hello");
    std::cout << "Expected: Hello\nActual: ";
    str1.out();
    std::cout << "\ntestOut passed!\n";
}

// Test deleteRange()
void testDeleteRange() {
    String str1("Hello World");
    str1.deleteRange(5, 11);
    assert(str1.getSize() == 5);
    assert(str1.find("World") == -1);
    std::cout << "testDeleteRange passed!\n";
}

// Test toUpperCase() and toLowerCase()
void testCaseConversion() {
    String str1("Hello");
    str1.toUpperCase();
    assert(str1.find("HELLO") == 0);
    str1.toLowerCase();
    assert(str1.find("hello") == 0);
    std::cout << "testCaseConversion passed!\n";
}

// Test replace()
void testReplace() {
    String str1("Hello World");
    String oldStr("World");
    String newStr("Everyone");
    str1.replace(oldStr, newStr);
    assert(str1.find("Everyone") == 6);
    assert(str1.getSize() == 14);
    std::cout << "testReplace passed!\n";
}

// Test reverse()
void testReverse() {
    String str1("Hello");
    str1.reverse();
    assert(str1.find("olleH") == 0);
    std::cout << "testReverse passed!\n";
}

// Test startsWith() and endsWith()
void testStartsEndsWith() {
    String str1("Hello World");
    assert(str1.startsWith("Hello"));
    assert(str1.endsWith("World"));
    std::cout << "testStartsEndsWith passed!\n";
}

// Test isBlank()
void testIsBlank() {
    String str1("   ");
    assert(str1.isBlank() == true);
    String str2("Not Blank");
    assert(str2.isBlank() == false);
    std::cout << "testIsBlank passed!\n";
}

// Test trim()
void testTrim() {
    String str1("   Hello World   ");
    str1.trim();
    assert(str1.find("Hello World") == 0);
    assert(str1.getSize() == 11);
    std::cout << "testTrim passed!\n";
}

int main() {
    testConstructors();
    testAppend();
    testInsertAt();
    testFind();
    testSubstring();
    testSplit();
    testConcatenate();
    testCompare();
    testCharAt();
    testIsEmpty();
    testOut();
    testDeleteRange();
    testCaseConversion();
    testReplace();
    testReverse();
    testStartsEndsWith();
    testIsBlank();
    testTrim();

    return 0;
}
