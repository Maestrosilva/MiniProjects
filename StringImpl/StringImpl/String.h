#include <iostream>

class String {
private:
    char* content;

public:
    // Default constructor: initializes the content with an empty string if no input is provided.
    String(const char* input = "") {
        content = nullptr;
        if (input) {
            strCopy(content, input);
        }
        else {
            std::cerr << "Nullpointer Exception\n";
        }
    }

    // Copy constructor: creates a copy of the provided String object.
    String(const String& other) {
        content = nullptr;
        if (other.isValid()) {
            strCopy(content, other.content);
        }
    }

    // Destructor: Frees the dynamically allocated memory when the object is destroyed
    ~String() {
        if (!content) {
            delete[] content;
        }
    }

    // Static helper method to copy a C-string to dynamically allocated memory
    static void strCopy(char*& destination, const char* str) {
        if (!str) {
            std::cerr << "Nullpointer Exception\n";
            return;
        }
        size_t size = getSize(str);
        delete[] destination;
        destination = new char[size + 1];
        if (!destination) {
            std::cerr << "Memory allocation failed\n";
            return;
        }
        for (size_t i = 0; i < size; i++) {
            destination[i] = str[i];
        }
        destination[size] = '\0';
    }

    // Static method to calculate the length of a C-string
    static size_t getSize(const char* str) {
        if (!str) {
            std::cerr << "Nullpointer Exception\n";
            return 0;
        }
        size_t size = 0;
        while (str[size]) size++;
        return size;
    }

    // Static method to get the size of the string content of a String object
    static size_t getSize(const String& str) {
        return getSize(str.content);
    }

    // Method to get the size of the string content
    size_t getSize() const {
        return getSize(content);
    }

    // Method to insert another string at a specified index in the current string
    void insertAt(size_t index, const String& toInsert) {
        if (!isValid() || !toInsert.isValid()) {
            return;
        }
        size_t sizeD = getSize();
        size_t sizeI = toInsert.getSize();
        if (index > sizeD) {
            index = sizeD;
        }
        char* newStr = new char[sizeD + sizeI + 1];
        if (!newStr) {
            std::cerr << "Memory allocation failed\n";
            return;
        }
        for (size_t i = 0; i < index; i++) {
            newStr[i] = content[i];
        }
        for (size_t i = 0; i < sizeI; i++) {
            newStr[i + index] = toInsert.content[i];
        }
        for (size_t i = index; i < sizeD; i++) {
            newStr[i + sizeI] = content[i];
        }
        newStr[sizeD + sizeI] = 0;
        delete[] content;
        content = newStr;
    }

    // Method to append another string at the end of the current string
    void append(const String& str) {
        insertAt(getSize(), str);
    }

    // Method to find the index of a substring starting from a given index
    int find(String toFind, size_t startIndex = 0) const {
        if (!isValid() || !toFind.isValid()) {
            return -1;
        }
        size_t strSize = getSize();
        size_t TFsize = toFind.getSize();
        if (TFsize > strSize || TFsize == 0) {
            return -1;
        }
        for (size_t i = startIndex; i <= strSize - TFsize; i++) {
            String subStr = substring(i, TFsize);
            if (!subStr.compare(toFind)) {
                return i;
            }
        }
        return -1;
    }

    // Method to get a substring from a given starting index and size
    String substring(size_t startIndex, size_t size) const {
        if (!isValid()) {
            return String("");
        }
        size_t strSize = getSize();
        if (startIndex >= strSize) {
            return String("");
        }
        if (startIndex + size > strSize) size = strSize - startIndex;
        char* temp = new char[size + 1];
        for (size_t i = 0; i < size; i++) {
            temp[i] = content[startIndex + i];
        }
        temp[size] = 0;
        String result(temp);
        delete[] temp;
        return result;
    }

    // Static method to split a string by a delimiter and return an array of substrings
    static String* split(const String& str, const String& delimiter, size_t& size) {
        if (str.isEmpty() || delimiter.isEmpty()) {
            std::cerr << "Empty String or Emptry Delimiter\n";
            size = 0;
            return nullptr;
        }
        if (!str.isValid() || !delimiter.isValid()) {
            size = 0;
            return nullptr;
        }
        const unsigned short MAX_ARR_SIZE = 1024;
        String* strs = new String[MAX_ARR_SIZE];
        if (!strs) {
            std::cerr << "Memory allocation failed\n";
            size = 0;
            return nullptr;
        }
        size_t delSize = delimiter.getSize();
        size = 0;
        size_t index = 0;
        while (true) {
            size_t start = str.find(delimiter, index);
            if (start == (size_t)-1) break;
            strs[size++] = str.substring(index, start - index);
            index = start + delSize;
        }
        strs[size++] = str.substring(index, str.getSize() - index);
        fix(strs, size);
        return strs;
    }

    // Static method to concatenate an array of strings into a single string
    static String concatenate(const String* strs, const size_t size) {
        if (!strs) {
            std::cerr << "Nullpointer Exception\n";
            return String("");
        }
        String result;
        for (size_t i = 0; i < size; i++) {
            if (!strs[i].isEmpty()) {
                result.append(strs[i]);
            }
        }
        return result;
    }

    // Static helper method to resize the string array after splitting
    static void fix(String*& strs, const size_t size) {
        if (!strs) {
            std::cerr << "Nullpointer Exception\n";
            return;
        }
        String* newStrs = new String[size];
        for (size_t i = 0; i < size; i++) {
            newStrs[i] = strs[i];
        }
        delete[] strs;
        strs = newStrs;
    }

    // Method to delete a range of characters from the string
    void deleteRange(size_t startIndex, size_t endIndex) {
        if (!isValid()) {
            return;
        }
        if (startIndex >= endIndex || endIndex > getSize()) {
            std::cerr << "Invalid indices for delete operation\n";
            return;
        }
        String parts[2] = { substring(0, startIndex), substring(endIndex, getSize()) };
        String newStr = concatenate(parts, 2);
        delete[] content;
        content = nullptr;
        strCopy(content, newStr.content);
    }

    // Method to compare two strings and return a result: 1 (greater), -1 (lesser), 0 (equal)
    short compare(const String& other) const {
        if (!isValid() || !other.isValid()) {
            return -2;
        }
        size_t size1 = getSize();
        size_t size2 = other.getSize();
        size_t minSize = (size1 < size2) ? size1 : size2;
        for (size_t i = 0; i < minSize; i++) {
            if (content[i] > other.content[i]) {
                return 1;
            }
            if (content[i] < other.content[i]) {
                return -1;
            }
        }
        if (size1 > size2) {
            return 1;
        }
        if (size1 < size2) {
            return -1;
        }
        return 0;
    }

    // Static method to compare two string objects
    static short compare(const String& str1, const String& str2) {
        return str1.compare(str2);
    }

    // Method to get a character at a specific index
    char charAt(size_t index) const {
        if (!isValid()) {
            return 0;
        }
        if (index >= getSize()) {
            std::cerr << "Index out of bounds\n";
            return 0;
        }
        return content[index];
    }

    // Method to convert all characters in the string to uppercase
    void toUpperCase() {
        if (!isValid()) {
            return;
        }
        size_t size = getSize();
        for (size_t i = 0; i < size; i++) {
            char& current = content[i];
            if (current >= 'a' && current <= 'z') {
                current -= ('a' - 'A');
            }
        }
    }

    // Method to convert all characters in the string to lowercase
    void toLowerCase() {
        if (!isValid()) {
            return;
        }
        size_t size = getSize();
        for (size_t i = 0; i <= size; i++) {
            char& current = content[i];
            if (current >= 'A' && current < 'Z') {
                current += ('a' - 'A');
            }
        }
    }

    // Method to replace occurrences of a substring with a new substring
    void replace(const String& oldStr, const String& newStr) {
        if (!isValid() || !oldStr.isValid() || !newStr.isValid()) {
            return;
        }
        size_t strSize = getSize();
        size_t oldSize = oldStr.getSize();
        size_t newSize = newStr.getSize();
        size_t index = 0;
        int currentIndex = 0;
        while ((currentIndex = find(oldStr, currentIndex)) != -1) {
            deleteRange(currentIndex, currentIndex + oldSize);
            insertAt(currentIndex, newStr);
            currentIndex += newSize;
        }
    }

    // Method to reverse the string content
    void reverse() {
        if (!isValid()) {
            return;
        }
        size_t size = getSize();
        for (size_t i = 0; i < size / 2; i++) {
            content[i] ^= content[size - i - 1];
            content[size - i - 1] ^= content[i];
            content[i] ^= content[size - i - 1];
        }
    }

    // Method to check if the string starts with a given prefix
    bool startsWith(const String& prefix) {
        if (!prefix.isValid()) {
            return false;
        }
        return !find(prefix);
    }

    // Method to check if the string ends with a given suffix
    bool endsWith(const String& suffix) {
        if (!suffix.isValid()) {
            return false;
        }
        if (suffix.getSize() > getSize()) {
            return false;
        }
        String subStr = substring(getSize() - suffix.getSize(), suffix.getSize());
        return subStr.compare(suffix) == 0;
    }

    // Method to check if the string is empty
    bool isEmpty() const {
        return !content || getSize() == 0;
    }

    // Method to check if the string contains only whitespace characters
    bool isBlank() const {
        if (!content) {
            return true;
        }
        String trimmed(this->content);
        trimmed.trim();
        int a = trimmed.getSize();
        return trimmed.isEmpty();
    }

    // Method to output the content of the string to the console
    void out() const {
        if (content) {
            std::cout << content;
            return;
        }
        isValid();
    }

    // Method to remove leading and trailing whitespace characters
    void trim() {
        if (!isValid()) {
            return;
        }
        size_t start = 0;
        size_t end = getSize();
        while (content[start++] == ' ');
        while (content[--end] == ' ');

        deleteRange(0, start - 1);
        deleteRange(end - 2, getSize());
    }

    //Method to check if String's content is a nullptr
    bool isValid() const {
        if (!content) {
            std::cerr << "Nullpointer Exception\n";
            return false;
        }
        return true;
    }
};