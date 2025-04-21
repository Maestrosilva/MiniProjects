#pragma once
#include <iostream>
#include <stdexcept>

#pragma warning (disable: 4996)

class String {
private:
    char* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    static const size_t DEFAULT_CAPACITY = 10;
    static const size_t RESIZE_FACTOR = 2;
    static const size_t SHRINK_THRESHOLD = 3;

    void free();
    void copyFrom(const String& other);
    void resize(char ch);

public:
    String(const char* data);
    String(size_t capacity = DEFAULT_CAPACITY);
    String(const String& other);

    String& operator=(const String& other);

    size_t getSize() const;
    size_t getCapacity() const;
    char getChar(size_t index) const;

    void out(std::ostream& direction = std::cout) const;
    void append(const String& str);
    void append(char ch);
    void insert(char ch, size_t index);
    void insert(const String& str, size_t index);
    void removeAt(size_t index);
    bool remove(const String& substr);
    short indexOf(const String& str) const;
    bool contains(const String& str) const;
    void replaceAll(const String& oldStr, const String& newStr);
    void reverse();
    bool startsWith(const String& prefix) const;
    bool endsWith(const String& suffix) const;
    void toLower();
    void toUpper();
    String substr(size_t start, short len = -1) const;
    bool isEmpty() const;
    void clear();

    String operator+=(const String& other);
    bool operator<(const String& other);
    bool operator<=(const String& other);
    bool operator>(const String& other);
    bool operator>=(const String& other);
    bool operator==(const String& other);
    bool operator!=(const String& other);
    char& operator[](size_t index) const;

   void friend operator<<(std::ostream& direction, const String& str);

   String friend operator+(const String& str1, const String& str2);

    ~String();
};