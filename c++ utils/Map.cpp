#pragma once
#include "Map.h"

template <typename K, typename V>
void Map<K, V>::copyFrom(const Map& other) {
    for (size_t i = 0; i < other.size(); i++) {
        this->entries.push(other.entries[i]);
    }
}

template <typename K, typename V>
Map<K, V>::Map(const Map& other) {
    copyFrom(other);
}

template <typename K, typename V>
Map<K, V>& Map<K, V>::operator=(const Map& other) {
    if (this != &other) {
        copyFrom(other);
    }
    return &this;
}

template <typename K, typename V>
Map<K, V>& Map<K, V>::put(const K& key, const V& value) {
    try {
        getValue(key);
        remove(key);
    }
    catch (const std::invalid_argument e) {}
    Pair<K, V> p = { key, value };
    this->entries.push(p);
    return *this;
}

template <typename K, typename V>
V& Map<K, V>::getValue(const K& key) const {
    for (size_t i = 0; i < this->size(); i++) {
        if (this->entries[i].key == key) {
            return entries[i].value;
        }
    }
    throw std::invalid_argument("Key not found!");
}

template <typename K, typename V>
void Map<K, V>::remove(const K& key) {
    for (size_t i = 0; i < this->size(); i++) {
        if (this->entries[i].key == key) {
            this->entries.removeAt(i);
            return;
        }
    }
    throw std::invalid_argument("Key not found!");
}

template <typename K, typename V>
void Map<K, V>::sortByKey() {
    for (size_t i = 0; i < this->size(); i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < this->size(); j++) {
            if (this->entries[minIndex].key > this->entries[j].key) {
                minIndex = j;
            }
        }
        std::swap(this->entries[i], this->entries[minIndex]);
    }
}

template <typename K, typename V>
void Map<K, V>::sortByValue() {
    for (size_t i = 0; i < this->size(); i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < this->size(); j++) {
            if (this->entries[minIndex].value > this->entries[j].value) {
                minIndex = j;
            }
        }
        std::swap(this->entries[i], this->entries[minIndex]);
    }
}

template <typename K, typename V>
Map<K, V> Map<K, V>::sortedByKey() const{
    Map toReturn(*this);
    toReturn.sortByKey();
    return toReturn;
}

template <typename K, typename V>
Map<K, V> Map<K, V>::sortedByValue() const{
    Map toReturn(*this);
    toReturn.sortByValue();
    return toReturn;
}

template <typename K, typename V>
void Map<K, V>::filterKeys(bool(*predicate)(const K& value)) {
    for (size_t i = 0; i < this->size(); i++) {
        if (!predicate(entries[i].key)) {
            remove(this->entries[i].key);
            i--;
        }
    }
}

template <typename K, typename V>
Map<K, V> Map<K, V>::filteredKeys(bool(*predicate)(const K& value)) {
    Map toReturn(*this);
    toReturn.filterKeys(predicate);
    return toReturn;
}

template <typename K, typename V>
void Map<K, V>::filterValues(bool(*predicate)(const V& value)) {
    for (size_t i = 0; i < this->size(); i++) {
        if (!predicate(entries[i].value)) {
            remove(this->entries[i].key);
            i--;
        }
    }
}

template <typename K, typename V>
Map<K, V> Map<K, V>::filteredValues(bool(*predicate)(const V& value)) {
    Map toReturn(*this);
    toReturn.filterValues(predicate);
    return toReturn;
}

template <typename K, typename V>
template <typename Func>
void Map<K, V>::foreach(Func func) const {
    for (size_t i = 0; i < this->size(); i++) {
        func(this->entries[i].key, this->entries[i].value);
    }
}

template <typename K, typename V>
void Map<K, V>::clear() {
    this->entries.clear();
}

template <typename K, typename V>
bool Map<K, V>::isEmpty() const {
    return this->size() == 0;
}

template <typename K, typename V>
size_t Map<K, V>::size() const {
    return this->entries.getLength();
}

template <typename K, typename V>
bool Map<K, V>::operator==(const Map& other) const {
    Map<K, V> sorted1 = this->sortedByValue();
    Map<K, V> sorted2 = other.sortedByValue();
    for (size_t i = 0; i < this->size(); i++) {
        if (sorted1.entries[i].key != sorted2.entries[i].key
            || sorted1.entries[i].value != sorted2.entries[i].value) {
            return false;
        }
    }
    return true;
}

template <typename K, typename V>
bool Map<K, V>::operator!=(const Map& other) const {
    return !(*this == other);
}