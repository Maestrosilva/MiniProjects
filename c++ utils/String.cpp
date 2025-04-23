#include "String.h"

void String::free() {
    delete[] this->data;
    this->data = nullptr;
    this->capacity = 0;
    this->size = 0;
}

void String::copyFrom(const String& other) {
    this->size = other.getSize();
    this->capacity = other.getCapacity();
    this->data = new char[this->capacity];
    strcpy(this->data, other.data);
}

void String::resize(char ch) {
    switch (ch) {
    case '+':
        this->capacity *= RESIZE_FACTOR;
        break;
    case '-':
        if (this->capacity > this->size) {
            this->capacity /= RESIZE_FACTOR;
        }
        break;
    default:
        throw std::invalid_argument("Invalid resize argument!");
    }

    char* newData = new char[this->capacity];
    strcpy(newData, this->data);
    delete[] this->data;
    this->data = newData;
}

String::String(const char* data) {
    this->size = strlen(data);
    this->capacity = (this->size + 1) * RESIZE_FACTOR;
    this->data = new char[this->capacity];
    strcpy(this->data, data);
}

String::String(size_t capacity) : capacity(capacity) {
    if (capacity == 0) {
        throw std::invalid_argument("Capacity cannot be 0!");
    }
    this->size = 0;
    this->data = new char[capacity];
    this->data[0] = '\0';
}

String::String(const String& other) {
    copyFrom(other);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

size_t String::getSize() const {
    return this->size;
}

size_t String::getCapacity() const {
    return this->capacity;
}

char String::getChar(size_t index) const {
    if (index >= this->size) {
        throw std::out_of_range("Index out of bounds!");
    }
    return this->data[index];
}

void String::out(std::ostream& direction) const {
    direction << (this->data ? this->data : "");
}

void String::insert(char ch, size_t index) {
    if (index > this->size) {
        throw std::out_of_range("Index out of bounds!");
    }
    if (this->size + 1 >= this->capacity) {
        resize('+');
    }
    for (size_t i = this->size; i > index; --i) {
        this->data[i] = this->data[i - 1];
    }
    this->data[index] = ch;
    this->size++;
    this->data[this->size] = '\0';
}

void String::insert(const String& str, size_t index) {
    for (size_t i = 0; i < str.getSize(); ++i) {
        this->insert(str.getChar(i), index + i);
    }
}

String& String::append(const String& str) {
    this->insert(str, this->size);
    return *this;
}

String& String::append(char ch) {
    this->insert(ch, this->size);
    return *this;
}

void String::removeAt(size_t index) {
    if (index >= this->size) {
        throw std::out_of_range("Index out of bounds!");
    }
    for (size_t i = index; i < this->size - 1; ++i) {
        this->data[i] = this->data[i + 1];
    }
    this->size--;
    this->data[this->size] = '\0';
    if (this->size * SHRINK_THRESHOLD < this->capacity) {
        resize('-');
    }
}

String& String::remove(const String& substr) {
    short from = indexOf(substr);
    if (from == -1) return *this;
    for (size_t i = 0; i < substr.getSize(); ++i) {
        removeAt(from);
    }
    return *this;
}

short String::indexOf(const String& str) const {
    if (str.getSize() > this->size) return -1;
    if (str.getSize() == 0) return 0;
    for (size_t i = 0; i <= this->size - str.getSize(); ++i) {
        bool isSubstr = true;
        for (size_t j = 0; j < str.getSize(); ++j) {
            if (this->data[i + j] != str.data[j]) {
                isSubstr = false;
                break;
            }
        }
        if (isSubstr) return i;
    }
    return -1;
}

bool String::contains(const String& str) const {
    return indexOf(str) >= 0;
}

void String::setCharAt(char ch, size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds!");
    }
    this->data[index] = ch;
}

void String::replaceAll(const String& oldStr, const String& newStr) {
    short index = indexOf(oldStr);
    while (index != -1) {
        remove(oldStr);
        insert(newStr, index);
        index = indexOf(oldStr);
    }
}

void String::reverse() {
    for (size_t i = 0; i < this->size / 2; ++i) {
        std::swap(this->data[i], this->data[this->size - i - 1]);
    }
    this->data[this->size] = '\0';
}

String String::reversed() const{
    String toReturn = *this;
    toReturn.reverse();
    return toReturn;
}

bool String::startsWith(const String& prefix) const {
    return indexOf(prefix) == 0;
}

bool String::endsWith(const String& suffix) const {
    return this->reversed().indexOf(suffix.reversed()) == 0;
}

void String::toUpper() {
    for (size_t i = 0; i < this->size; ++i) {
        if (this->data[i] >= 'a' && this->data[i] <= 'z') {
            this->data[i] -= ('a' - 'A');
        }
    }
}

String String::uppered() const {
    String toReturn = *this;
    toReturn.toUpper();
    return toReturn;
}

void String::toLower() {
    for (size_t i = 0; i < this->size; ++i) {
        if (this->data[i] >= 'A' && this->data[i] <= 'Z') {
            this->data[i] += ('a' - 'A');
        }
    }
}

String String::lowered() const {
    String toReturn = *this;
    toReturn.toLower();
    return toReturn;
}

String String::substr(size_t start, short len) const {
    if (len == -1) {
        len = this->size - start;
    }
    if (start + len > this->size) {
        throw std::out_of_range("Substring range out of bounds");
    }
    String toReturn;
    for (size_t i = start; i < start + len; ++i) {
        toReturn.append(this->getChar(i));
    }
    return toReturn;
}

bool String::isEmpty() const {
    return this->size == 0;
}

void String::clear() {
    free();
    this->capacity = DEFAULT_CAPACITY;
    this->data = new char[this->capacity];
    this->data[0] = '\0';
    this->size = 0;
}

String String::operator+=(const String& other) {
    append(other);
    return *this;
}

bool String::operator<(const String& other) {
    return strcmp(this->data, other.data) < 0;
}
bool String::operator<=(const String& other) {
    return strcmp(this->data, other.data) <= 0;
}
bool String::operator>(const String& other) {
    return strcmp(this->data, other.data) > 0;
}
bool String::operator>=(const String& other) {
    return strcmp(this->data, other.data) >= 0;
}
bool String::operator==(const String& other) {
    return strcmp(this->data, other.data) == 0;
}
bool String::operator!=(const String& other) {
    return strcmp(this->data, other.data) != 0;
}

char& String::operator[](size_t index) const {
    if (index >= this->size) {
        throw std::out_of_range("Index out of bounds!");
    }
    return this->data[index];
}

void operator<<(std::ostream& direction, const String& str) {
    str.out(direction);
}

String operator+(const String& str1, const String& str2) {
    String result(str1);
    result;
    return result.append(str2);
}

String::~String() {
    free();
}
