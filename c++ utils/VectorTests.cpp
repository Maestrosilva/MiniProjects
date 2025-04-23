#include <cassert>
#include "Vector.h"

void testConstructorAndBasicInfo() {
    Vector<int> v;
    assert(v.getLength() == 0);
    assert(v.isEmpty());
}

void testPushPopPeek() {
    Vector<int> v;
    v.push(10).push(20).push(30);
    assert(v.getLength() == 3);
    assert(v.peek() == 30);
    assert(v.pop() == 30);
    assert(v.getLength() == 2);
}

void testAddAndAccess() {
    Vector<int> v;
    v.push(10).push(20);
    v.add(15, 1);
    assert(v[1] == 15);
    assert(v.getLength() == 3);
}

void testReverse() {
    Vector<int> v;
    v.push(1).push(2).push(3);
    Vector<int> rev = v.reversed();
    assert(rev[0] == 3 && rev[2] == 1);
    v.reverse();
    assert(v[0] == 3 && v[2] == 1);
}

void testSort() {
    Vector<int> v;
    v.push(5).push(3).push(4);
    v.sort();
    assert(v[0] <= v[1] && v[1] <= v[2]);

    Vector<int> sorted = v.sorted();
    assert(sorted[0] <= sorted[1] && sorted[1] <= sorted[2]);
}

void testClear() {
    Vector<int> v;
    v.push(1).push(2).clear();
    assert(v.isEmpty());
}

void testMapAndMapped() {
    Vector<int> v;
    v.push(1).push(2).push(3);
    v.map([](int& x) { x *= 2; });
    assert(v[0] == 2 && v[1] == 4 && v[2] == 6);

    Vector<int> mapped = v.mapped([](int& x) { x += 1; });
    assert(mapped[0] == 3 && mapped[1] == 5 && mapped[2] == 7);
}

void testFilterAndFiltered() {
    Vector<int> v;
    v.push(1).push(2).push(3).push(4);
    v.filter([](int& x) { return x % 2 == 0; });
    for (size_t i = 0; i < v.getLength(); i++) assert(v[i] % 2 == 0);

    Vector<int> mapped;
    mapped.push(1).push(2).push(3).push(4);
    Vector<int> filtered = mapped.filtered([](int& x) { return x % 2 == 0; });
    for (size_t i = 0; i < filtered.getLength(); i++) assert(filtered[i] % 2 == 0);
}

void testDistinct() {
    Vector<int> v;
    v.push(1).push(2).push(1).push(3).push(2);
    Vector<int> d = v.distinct();
    assert(d.getLength() <= v.getLength());
}

void testSubarray() {
    Vector<int> v;
    v.push(10).push(20).push(30).push(40);
    Vector<int> sub = v.subarray(1, 2);
    assert(sub.getLength() == 2);
    assert(sub[0] == 20 && sub[1] == 30);
}

void testSubsetAndSubarr() {
    Vector<int> v1;
    v1.push(1).push(2).push(3);

    Vector<int> v2;
    v2.push(2).push(3);

    assert(v2.isSubSetOf(v1));
    assert(v2.isSubArrOf(v1.subarray(1, 2)));
}

void testContainsIndexOf() {
    Vector<int> v;
    v.push(5).push(10).push(15);
    assert(v.contains(10));
    assert(v.indexOf(10) == 1);
    assert(!v.contains(999));
}

void testShuffle() {
    Vector<int> v;
    v.push(1).push(2).push(3).push(4).push(5);
    Vector<int> before = v;
    v.shuffle();
    assert(v.getLength() == before.getLength());
    assert(v.shuffled().sorted() == v.sorted());
    assert(v.shuffled().sorted() == v.shuffled().sorted());
}

void testEqualityOperators() {
    Vector<int> v1;
    v1.push(1).push(2);

    Vector<int> v2 = v1;
    assert(v1 == v2);
    v2.push(3);
    assert(v1 != v2);
}

void testSetAt() {
    Vector<int> v;
    v.push(1).push(2);
    v.setAt(0, 999);
    assert(v[0] == 999);
}

void testMinMax() {
    Vector<int> v;
    v.push(10).push(20).push(5);
    assert(v.min() <= v.max());
    assert(v.max() == 20);
    assert(v.min() == 5);
}

void testRemoveAtAndRemove() {
    Vector<int> v;
    v.push(1).push(2).push(3);
    v.removeAt(1);
    assert(v.getLength() == 2 && v[0] == 1 && v[1] == 3);

    v.remove(1);
    assert(!v.contains(1));
}

void testForeach() {
    Vector<int> v;
    v.push(1).push(2).push(3);
    int sum = 0;
    v.foreach([&sum](int x) { sum += x; });
    assert(sum == 6);
}

int main() {
    testConstructorAndBasicInfo();
    testPushPopPeek();
    testAddAndAccess();
    testReverse();
    testSort();
    testClear();
    testMapAndMapped();
    testFilterAndFiltered();
    testDistinct();
    testSubarray();
    testSubsetAndSubarr();
    testContainsIndexOf();
    testShuffle();
    testEqualityOperators();
    testSetAt();
    testMinMax();
    testRemoveAtAndRemove();
    testForeach();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
