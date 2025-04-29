#pragma once
#include "Vector.h"
#include "String.h"

template <typename K, typename V>
struct Pair {
    K key;
    V value;
};

template <typename K, typename V>
class Map {
private:
    Vector<Pair<K, V>> entries;

    void copyFrom(const Map& other);

public:
    Map() = default;

    Map(const Map& other);

    Map& operator=(const Map& other);

    Map& put(const K& key, const V& value);
    //void set(const K& key, const V& value);

    V& getValue(const K& key) const;
    void remove(const K& key);

    void sortByKey();
    void sortByValue();
    Map sortedByKey() const;
    Map sortedByValue() const;

    void filterKeys(bool(*predicate)(const K& value));
    Map filteredKeys(bool(*predicate)(const K& value));
    void filterValues(bool(*predicate)(const V& value));
    Map filteredValues(bool(*predicate)(const V& value));

    template <typename Func>
    void foreach(Func func) const;

    void clear();
    bool isEmpty() const;
    size_t size() const;

    bool operator==(const Map& other) const;
    bool operator!=(const Map& other) const;

    ~Map() = default;
};

#include "Map.cpp"