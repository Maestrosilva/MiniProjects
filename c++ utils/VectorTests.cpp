//#include "Vector.h"
//#include <cassert>
//#include <iostream>
//
//void testConstructor() {
//    Vector<int> v1;
//    assert(v1.getLength() == 0);
//    assert(v1.getCapacity() == 10);
//
//    int arr[] = { 1, 2, 3 };
//    Vector<int> v2(arr, 3);
//    assert(v2.getLength() == 3);
//    assert(v2.getCapacity() == 6);
//}
//
//void testPushAndPop() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    assert(v.getLength() == 3);
//    assert(v.pop() == 3);
//    assert(v.getLength() == 2);
//}
//
//void testPeek() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    assert(v.peek() == 2);
//}
//
//void testAdd() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.add(3, 1);
//    assert(v.getLength() == 3);
//    assert(v.get(1) == 3);
//}
//
//void testRemove() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    assert(v.remove(2) == true);
//    assert(v.getLength() == 2);
//    assert(v.remove(5) == false);
//}
//
//void testRemoveAt() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    v.removeAt(1);
//    assert(v.getLength() == 2);
//    assert(v.get(1) == 3);
//}
//
//void testSetAt() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.setAt(1, 5);
//    assert(v.get(1) == 5);
//}
//
//void testIndexOf() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    assert(v.indexOf(2) == 1);
//    assert(v.indexOf(3) == -1);
//}
//
//void testContains() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    assert(v.contains(1) == true);
//    assert(v.contains(3) == false);
//}
//
//void testReverse() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    v.reverse();
//    assert(v.get(0) == 3);
//    assert(v.get(1) == 2);
//    assert(v.get(2) == 1);
//}
//
//void testSort() {
//    Vector<int> v;
//    v.push(3);
//    v.push(1);
//    v.push(2);
//    v.sort();
//    assert(v.get(0) == 1);
//    assert(v.get(1) == 2);
//    assert(v.get(2) == 3);
//}
//
//void testMap() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    v.map([](int& x) { x *= 2; });
//    assert(v.get(0) == 2);
//    assert(v.get(1) == 4);
//    assert(v.get(2) == 6);
//}
//
//void testForEach() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    int sum = 0;
//    v.foreach([&](const int& x) { sum += x; });
//    assert(sum == 6);
//}
//
//void testFilter() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    assert(v.filter([](int& x) { return x % 2 == 0; }).getLength() == 1);
//    assert(v.filter([](int& x) { return x % 2 == 0; }).filter([](int& x) { return x % 2 == 0; }).get(0) == 2);
//}
//
//void testShuffle() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    v.shuffle();
//    // Check that size remains same, but order may change
//    assert(v.getLength() == 3);
//    //v.out();
//}
//
//void testSubarray() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    Vector<int> sub = v.subarray(1, 2);
//    assert(sub.getLength() == 2);
//    assert(sub.get(0) == 2);
//    assert(sub.get(1) == 3);
//}
//
//void testIsSubArrOf() {
//    Vector<int> v1;
//    v1.push(1);
//    v1.push(2);
//    Vector<int> v2;
//    v2.push(1);
//    v2.push(2);
//    v2.push(3);
//    assert(v1.isSubArrOf(v2) == true);
//    v1.push(4);
//    assert(v1.isSubArrOf(v2) == false);
//}
//
//void testDistinct() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.push(2);
//    v.push(3);
//    Vector<int> distinctVec = v.distinct();
//    assert(distinctVec.getLength() == 3);
//    assert(distinctVec.get(0) == 1);
//    assert(distinctVec.get(1) == 2);
//    assert(distinctVec.get(2) == 3);
//}
//
//void testIsEmpty() {
//    Vector<int> v;
//    assert(v.isEmpty() == true);
//    v.push(1);
//    assert(v.isEmpty() == false);
//}
//
//void testClear() {
//    Vector<int> v;
//    v.push(1);
//    v.push(2);
//    v.clear();
//    assert(v.getLength() == 0);
//}
//
//void testEqualityOperator() {
//    Vector<int> v1;
//    v1.push(1);
//    v1.push(2);
//    Vector<int> v2;
//    v2.push(1);
//    v2.push(2);
//    assert(v1 == v2);
//    v2.push(3);
//    assert(v1 != v2);
//}
//
//void testMinAndMax() {
//    Vector<int> v;
//    v.push(3);
//    v.push(1);
//    v.push(2);
//    assert(v.min() == 1);
//    assert(v.max() == 3);
//}
//
//void runTests() {
//    testConstructor();
//    testPushAndPop();
//    testPeek();
//    testAdd();
//    testRemove();
//    testRemoveAt();
//    testSetAt();
//    testIndexOf();
//    testContains();
//    testReverse();
//    testSort();
//    testMap();
//    testForEach();
//    testFilter();
//    testShuffle();
//    testSubarray();
//    testIsSubArrOf();
//    testDistinct();
//    testIsEmpty();
//    testClear();
//    testEqualityOperator();
//    testMinAndMax();
//}
//
//int main() {
//    runTests();
//    std::cout << "All tests passed!" << std::endl;
//    return 0;
//}