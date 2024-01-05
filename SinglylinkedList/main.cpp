#include <iostream>
#include "singlyLinkedList.h"



using namespace std;



int main()
{
    singlyList list1, list2;
    // inserting the nodes
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);
    list1.insert(8);

    // print the values
    list1.printNodes();

    cout << endl;
    list1.Reverse();
    list1.printNodes();





}