#include <cassert>
#include "String.h"

void testDefaultConstructor() {
    String str;
    assert(str.getSize() == 0);
    assert(str.getCapacity() == 10);
}

void testCharConstructor() {
    String str("Hello");
    assert(str.getSize() == 5);
    assert(str.getChar(0) == 'H');
}

void testCopyConstructor() {
    String str1("Copy");
    String str2(str1);
    assert(str2.getSize() == str1.getSize());
    assert(str2.getChar(0) == 'C');
}

void testAssignmentOperator() {
    String str1("Assign");
    String str2;
    str2 = str1;
    assert(str2.getSize() == str1.getSize());
    assert(str2.getChar(0) == 'A');
}

void testAppendChar() {
    String str("Append");
    str.append('!');
    assert(str.getSize() == 7);
    assert(str.getChar(6) == '!');
}

void testAppendString() {
    String str1("Hello");
    String str2(" World");
    str1.append(str2);
    assert(str1.getSize() == 11);
    assert(str1.contains(String(" World")));
}

void testInsertChar() {
    String str("Insert");
    str.insert('X', 3);
    assert(str.getChar(3) == 'X');
}

void testInsertString() {
    String str1("Insert");
    String str2(" Here");
    str1.insert(str2, 6);
    assert(str1.contains(String("Insert Here")));
}

void testRemoveAt() {
    String str("Remove");
    str.removeAt(1);
    assert(str.getSize() == 5);
    assert(str.getChar(1) == 'm');
}

void testFind() {
    String str("Find me");
    assert(str.indexOf(String("me")) == 5);
}

void testContains() {
    String str("Contains substring");
    assert(str.contains(String("substring")));
}

void testReplaceAll() {
    String str("Replace all");
    str.replaceAll(String("all"), String("everything"));
    assert(str.contains(String("Replace everything")));
}

void testReverse() {
    String str("Reverse");
    str.reverse();
    assert(str.getChar(0) == 'e');
}

void testStartsWith() {
    String str("Starts");
    assert(str.startsWith(String("Start")));
}

void testEndsWith() {
    String str("Ends");
    assert(str.endsWith(String("s")));
}

void testToLower() {
    String str("TO LOWER");
    str.toLower();
    assert(str.getChar(0) == 't');
}

void testToUpper() {
    String str("to upper");
    str.toUpper();
    assert(str.getChar(0) == 'T');
}

void testSubstr() {
    String str("Substring test");
    String substr = str.substr(0, 9);
    assert(substr == String("Substring"));
}

void testIsEmpty() {
    String str;
    assert(str.isEmpty());
}

void testClear() {
    String str("Clear");
    str.clear();
    assert(str.getSize() == 0);
}

void testOperators() {
    String str1("Operator");
    String str2(" Overload");
    str1 += str2;
    assert(str1.contains(String("Operator Overload")));
}

void testComparisonOperators() {
    String str1("Comparison");
    String str2("Comparison");
    assert(str1 == str2);
    assert(!(str1 != str2));
}

void testConcatenationOperator() {
    String str1("Hello");
    String str2(" World");
    String str3 = str1 + str2;
    assert(str3 == String("Hello World"));
}

int main() {
    testDefaultConstructor();
    testCharConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testAppendChar();
    testAppendString();
    testInsertChar();
    testInsertString();
    testRemoveAt();
    testFind();
    testContains();
    testReplaceAll();
    testReverse();
    testStartsWith();
    testEndsWith();
    testToLower();
    testToUpper();
    testSubstr();
    testIsEmpty();
    testClear();
    testOperators();
    testComparisonOperators();
    testConcatenationOperator();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}