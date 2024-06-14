// -----------------------------------------------------------------------------------
// LinkedListTest.cpp : Test Program used for validating the doubly linked list class
// 
// Author: Jack Eubanks
// Date  : 6/14/2024
// -----------------------------------------------------------------------------------
#include <iostream>
#include "dlist.h"   // doubly-linked list definition



int main()
{
    // Create an instance of the Doubly-Linked List class
    DList<int> myList;

    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #1: Add a reference to application data"                          << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    int num1 = 20;
    myList.add(&num1);  
    std::cout << *myList.head() << std::endl << std::endl;  // Verify the results


    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #2: Modify the data & verify the change is reflected in the list" << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    num1 = 777;
    std::cout << *myList.head() << std::endl << std::endl;

    // Create some additional test data...
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    myList.add(&num2);
    myList.add(&num3);
    myList.add(&num4);


    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #3: Find an item at a specific location in the list"              << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    int* pnum = myList.find_at_index(3);
    if (pnum == nullptr) {
        std::cout << "ERROR: Invalid index" << std::endl;
    }
    else {
        std::cout << "List[3] = " << *pnum << std::endl;
    }
    std::cout << std::endl;


    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #4: Test for index out-of-bounds condition"                       << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    int idx = 7;
    pnum = myList.find_at_index(idx);
    if (pnum == nullptr) {
        std::cout << "Invalid index: " << idx << "  (Size of list is: " << myList.size() << ")" << std::endl;
    }
    else {
        std::cout << *pnum << std::endl;
    }
    std::cout << std::endl;


    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #5: Test Printing the entire list"                                << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "List currently contains: " << std::endl;
    for (int idx = 0; idx < myList.size(); idx++) {
        std::cout << "List[" << idx << "] = " << *myList.find_at_index(idx) << std::endl;
    }
    std::cout << std::endl;


    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #6: Test Removing an item from the list"                          << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    // Remove item containing reference to 'num3'
    std::cout << "Removed Item containing: " << *myList.remove(&num3) << std::endl << std::endl;

    // Verify it's no longer in the list
    std::cout << "List now contains: " << std::endl;
    for (int idx = 0; idx < myList.size(); idx++) {
        std::cout << "List[" << idx << "] = " << *myList.find_at_index(idx) << std::endl;
    }
    std::cout << std::endl;


    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #7: Test Removing an element that doesn't exist"                  << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    int num5 = 5;
    pnum = myList.remove(&num5);
    if (pnum == nullptr) {
        std::cout << "Entry not found." << std::endl << std::endl;
    }
    else {
        std::cout << *pnum << std::endl << std::endl << std::endl;
    }


    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Test #8: Test Removing an element from an empty list"                  << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    DList<int> myList2;
    if (myList2.remove(&num5) == nullptr) {
        std::cout << "Cannot remove item from empty list - (List size: " << myList2.size() << ")" << std::endl;
    }
    else {
        std::cout << "Test FAILED! An item was removed." << std::endl;
    }


    return 0;
}

