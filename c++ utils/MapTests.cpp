#include <cassert>
#include "Map.h"

void testConstructor() {
    Map<int, int> m;
    assert(m.isEmpty());
    assert(m.size() == 0);
}

void testAddAndAccess() {
    Map<int, int> m;
    m.put(1, 100);
    assert(!m.isEmpty());
    assert(m.size() == 1);
    assert(m.getValue(1) == 100);
}

void testAddUpdates() {
    Map<int, int> m;
    m.put(1, 100);
    m.put(1, 200);
    assert(m.size() == 1);
    assert(m.getValue(1) == 200);
}

void testGetMissingThrows() {
    Map<int, int> m;
    bool thrown = false;
    try {
        m.getValue(42);
    }
    catch (...) {
        thrown = true;
    }
    assert(thrown);
}

void testRemoveExisting() {
    Map<int, int> m;
    m.put(1, 10);
    m.remove(1);
    assert(m.isEmpty());
}

void testRemoveNonExisting() {
    Map<int, int> m;
    try {
        m.remove(999);
    }
    catch (std::invalid_argument e) {
        assert(m.isEmpty());
    }
}

void testSortByKey() {
    Map<int, int> m;
    m.put(3, 30);
    m.put(1, 10);
    m.put(2, 20);
    m.sortByKey();
    assert(m.getValue(1) == 10);
    assert(m.getValue(2) == 20);
    assert(m.getValue(3) == 30);
}

void testSortByValue() {
    Map<int, int> m;
    m.put(1, 300);
    m.put(2, 100);
    m.put(3, 200);
    m.sortByValue();
    assert(m.getValue(2) == 100);
    assert(m.getValue(3) == 200);
    assert(m.getValue(1) == 300);
}

void testSortedByKey() {
    Map<int, int> m;
    m.put(3, 30);
    m.put(1, 10);
    Map<int, int> sorted = m.sortedByKey();
    assert(sorted.getValue(1) == 10);
    assert(sorted.getValue(3) == 30);
}

void testSortedByValue() {
    Map<int, int> m;
    m.put(1, 300);
    m.put(2, 100);
    Map<int, int> sorted = m.sortedByValue();
    assert(sorted.getValue(2) == 100);
    assert(sorted.getValue(1) == 300);
}

void testFilterKeys() {
    Map<int, int> m;
    m.put(1, 10);
    m.put(2, 20);
    m.put(3, 30);
    m.filterKeys([](const int& key) { return key % 2 == 1; });
    assert(m.size() == 2);
    assert(m.getValue(1) == 10);
    assert(m.getValue(3) == 30);
}

void testFilteredKeys() {
    Map<int, int> m;
    m.put(1, 10);
    m.put(2, 20);
    Map<int, int> filtered = m.filteredKeys([](const int& key) { return key == 2; });
    assert(filtered.size() == 1);
    assert(filtered.getValue(2) == 20);
}

void testFilterValues() {
    Map<int, int> m;
    m.put(1, 10);
    m.put(2, 25);
    m.put(3, 30);
    m.filterValues([](const int& value) { return value >= 20; });
    assert(m.size() == 2);
    assert(m.getValue(2) == 25);
    assert(m.getValue(3) == 30);
}

void testFilteredValues() {
    Map<int, int> m;
    m.put(1, 10);
    m.put(2, 20);
    Map<int, int> filtered = m.filteredValues([](const int& value) { return value == 20; });
    assert(filtered.size() == 1);
    assert(filtered.getValue(2) == 20);
}

void testForeach() {
    Map<int, int> m;
    m.put(1, 10);
    m.put(2, 20);
    int sum = 0;
    m.foreach([&sum](int key, int value) {
        sum += value;
        });
    assert(sum == 30);
}

void testClear() {
    Map<int, int> m;
    m.put(1, 10);
    m.put(2, 20);
    m.clear();
    assert(m.isEmpty());
    assert(m.size() == 0);
}

void testEqualOperator() {
    Map<int, int> m1;
    Map<int, int> m2;
    m1.put(1, 10);
    m2.put(1, 10);
    assert(m1 == m2);
}

void testNotEqualOperator() {
    Map<int, int> m1;
    Map<int, int> m2;
    m1.put(1, 10);
    m2.put(2, 20);
    assert(m1 != m2);
}

void testCopyConstructor() {
    Map<int, int> m1;
    m1.put(1, 10);
    Map<int, int> m2(m1);
    assert(m1 == m2);
}

int main() {
    testConstructor();
    testAddAndAccess();
    testAddUpdates();
    testGetMissingThrows();
    testRemoveExisting();
    testRemoveNonExisting();
    testSortByKey();
    testSortByValue();
    testSortedByKey();
    testSortedByValue();
    testFilterKeys();
    testFilteredKeys();
    testFilterValues();
    testFilteredValues();
    testForeach();
    testClear();
    testEqualOperator();
    testNotEqualOperator();
    testCopyConstructor();

    std::cout << "All tests passed!" << std::endl;
}