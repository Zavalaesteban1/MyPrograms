#include <iostream>


using namespace std;

struct Node
{
    int number;
    Node* next;
};

void Reverse(Node *head);
void printList(Node* head);



int main()
{
    Node* head;
    Node* tail;
    int count = 0;
    Node* n;


    n = new Node;
    n->number = 1;
    n->next = nullptr;
    if(count == 0)
    {
        head = n;
    }
    tail = n;
    count++;

    n = new Node;
    n->number = 2;
    n->next = nullptr;
    tail->next = n;
    tail = n;
    count++;

    n = new Node;
    n->number = 3;
    n->next = nullptr;
    tail->next = n;
    tail = n;
    count++;

    n = new Node;
    n->number = 4;
    n->next = nullptr;
    tail->next = n;
    tail = n;
    count++;


    cout << "There is " << count << " nodes in the list" << endl << endl;
    printList(head);
    cout << endl;

    Reverse(head);


}
void printList(Node* head)
{
    Node* cur = head;
    if(head == nullptr)
    {
        return;
    }


    while(cur != nullptr)
    {
        cout << cur->number << ' ';
        cur = cur->next;
    }
}


void Reverse(Node* head)
{
    Node* cur = head;
    Node* prev = nullptr;
    Node* next = nullptr;

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

    printList(head);

}

