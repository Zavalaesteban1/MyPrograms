#include "singlyLinkedList.h"
#include <iostream>



singlyList::singlyList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}
void singlyList::insert(int num)
{
    // create a new node
    Node *p = new Node;
    // fill the data member of the node
    p->number = num;
    // store in next the nullptr
    p->next = nullptr;
    // if the count is zero that means the list is empty and we're going to point head to the new node being created
    if(count == 0)
    {
        // point head to first node being created
        head = p;
    }
    // if it isnt the first node created point tail-> next to the next node to link them together
    else
    {
        tail->next = p;
    }
    // set tail to point to the node being created
    tail = p;
    // increment the count
    count++;

}
void singlyList::earse()
{
    // if the head is empty theres no nodes
    if(head == nullptr)
    {
        return;
    }
    // create a temp pointer pointing to head
    Node* rip = head;
    // move head to the next node
    head = head->next;
    // delete the node
    delete rip;
    // decrement the coount
    count--;
    // the count is zero set tail pointer to nulllptr
    if(count == 0)
    {
        tail = nullptr;
    }
}
void singlyList::printNodes()
{
    // point curr to the head
   Node* cur = head;

    // if the list is empty return 
   if(head == nullptr)
   {
        return;
   }
   // traverse through the linked list printing the values
   while(cur != nullptr)
   {
        // print the value
        cout << cur->number << ' ';
        // update the curr to the next node
        cur = cur->next;
    }
}

void singlyList::Reverse()
{
    Node *cur = head, *prev = NULL, *next = NULL;


    if(head == nullptr)
    {
        return;
    }

    while(cur != nullptr)
    {
        // set next to point to the next node
        next = cur->next;
        // set cur->next to prev
        cur->next = prev;
        // set prev to what cur is pointing to
        prev = cur;
        // move cur to what next is pointing to 
        cur = next;
    }
    head = prev;

}


int singlyList::size()
{
    return count;
}
singlyList::~singlyList()
{
    int all = count;

    for(int i = 0; i < count; i++)
    {
        earse();
    }
}