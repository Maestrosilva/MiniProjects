#include <cassert>
#include <iostream>
#include "String.h"

void testDefaultConstructor() {
    String str;
    assert(str.getSize() == 0);
    assert(str.getCapacity() == 10);
}

void testConstructorFromCStr() {
    String str("Hello");
    assert(str.getSize() == 5);
    assert(str.getChar(0) == 'H');
    assert(str.getChar(4) == 'o');
}

void testConstructorWithCapacity() {
    String str(20);
    assert(str.getSize() == 0);
    assert(str.getCapacity() == 20);
}

void testCopyConstructor() {
    String str1("Hello");
    String str2 = str1;
    assert(str2.getSize() == 5);
    assert(str2.getChar(0) == 'H');
    assert(str2.getChar(4) == 'o');
}

void testAssignmentOperator() {
    String str1("Hello");
    String str2;
    str2 = str1;
    assert(str2.getSize() == 5);
    assert(str2.getChar(0) == 'H');
    assert(str2.getChar(4) == 'o');
}

void testAppendString() {
    String str("Hello");
    str.append(" World");
    assert(str.getSize() == 11);
    assert(str.getChar(5) == ' ');
    assert(str.getChar(10) == 'd');
}

void testAppendChar() {
    String str("Hello");
    str.append('!');
    assert(str.getSize() == 6);
    assert(str.getChar(5) == '!');
}

void testInsertChar() {
    String str("Hello");
    str.insert('X', 2);
    assert(str.getSize() == 6);
    assert(str.getChar(2) == 'X');
}

void testInsertString() {
    String str("Hello");
    str.insert("ABC", 2);
    assert(str.getSize() == 8);
    assert(str.getChar(2) == 'A');
    assert(str.getChar(3) == 'B');
}

void testRemoveAt() {
    String str("Hello");
    str.removeAt(2);
    assert(str.getSize() == 4);
    assert(str.getChar(2) == 'l');
}

void testRemoveSubstring() {
    String str("Hello World");
    str.remove("World");
    assert(str.getSize() == 6);
    assert(str.getChar(0) == 'H');
}

void testIndexOf() {
    String str("Hello World");
    assert(str.indexOf("World") == 6);
    assert(str.indexOf("Test") == -1);
}

void testContains() {
    String str("Hello World");
    assert(str.contains("Hello"));
    assert(!str.contains("Test"));
}

void testSetCharAt() {
    String str("Hello");
    str.setCharAt('X', 1);
    assert(str.getChar(1) == 'X');
}

void testReplaceAll() {
    String str("Hello World");
    str.replaceAll("World", "Universe");
    assert(str.getSize() == 14);
    assert(str.getChar(6) == 'U');
}

void testReverse() {
    String str("Hello");
    str.reverse();
    assert(str.getChar(0) == 'o');
    assert(str.getChar(4) == 'H');
}

void testReversed() {
    String str("Hello");
    String r = str.reversed();
    assert(r.getChar(0) == 'o');
    assert(r.getChar(4) == 'H');
    assert(str.getChar(0) == 'H');  // original unchanged
}

void testStartsWith() {
    String str("Hello World");
    assert(str.startsWith("Hello"));
    assert(!str.startsWith("World"));
}

void testEndsWith() {
    String str("Hello World");
    assert(str.endsWith("World"));
    assert(!str.endsWith("Hello"));
}

void testToLower() {
    String str("HELLO");
    str.toLower();
    assert(str.getChar(0) == 'h');
    assert(str.getChar(4) == 'o');
}

void testLowered() {
    String str("HELLO");
    String r = str.lowered();
    assert(r.getChar(0) == 'h');
    assert(r.getChar(4) == 'o');
}

void testToUpper() {
    String str("hello");
    str.toUpper();
    assert(str.getChar(0) == 'H');
    assert(str.getChar(4) == 'O');
}

void testUppered() {
    String str("hello");
    String r = str.uppered();
    assert(r.getChar(0) == 'H');
    assert(r.getChar(4) == 'O');
}

void testSubstr() {
    String str("Hello World");
    String sub = str.substr(6, 5);
    assert(sub.getSize() == 5);
    assert(sub.getChar(0) == 'W');
    assert(sub.getChar(4) == 'd');
}

void testSubstrNegativeLen() {
    String str("Hello World");
    String sub = str.substr(6);
    assert(sub.getSize() == 5);
    assert(sub.getChar(0) == 'W');
}

void testPlusOperator() {
    String str1("Hello");
    String str2(" World");
    String result = str1 + str2;
    assert(result.getSize() == 11);
    assert(result.getChar(10) == 'd');
}

void testEqualsOperator() {
    String a("Test");
    String b("Test");
    String c("Wrong");
    assert(a == b);
    assert(a != c);
}

void testRelationalOperators() {
    String a("abc");
    String b("def");
    assert(a < b);
    assert(a <= b);
    assert(b > a);
    assert(b >= a);
}

void testClear() {
    String str("Data");
    str.clear();
    assert(str.getSize() == 0);
    assert(str.isEmpty());
}

int main() {
    testDefaultConstructor();
    testConstructorFromCStr();
    testConstructorWithCapacity();
    testCopyConstructor();
    testAssignmentOperator();
    testAppendString();
    testAppendChar();
    testInsertChar();
    testInsertString();
    testRemoveAt();
    testRemoveSubstring();
    testIndexOf();
    testContains();
    testSetCharAt();
    testReplaceAll();
    testReverse();
    testReversed();
    testStartsWith();
    testEndsWith();
    testToLower();
    testLowered();
    testToUpper();
    testUppered();
    testSubstr();
    testSubstrNegativeLen();
    testPlusOperator();
    testEqualsOperator();
    testRelationalOperators();
    testClear();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
