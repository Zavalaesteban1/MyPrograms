
#include "stack.h"

Stack :: Stack()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

void Stack :: push(string str)
{
    // create a new Node
    Node* p = new Node;
    // fill the data memebers of the node
    p->s = str;
    // head == nullptr when first node is pushed
    p->next = head;
    // point head to the new node 
    head = p;
    // if the count is 0 set tail to the first node thats created 
    if (count == 0)
        tail = p;
    // increment count
    ++count;
}

void Stack::pop()
{
    // if head is empty theres no nodes
    if (head == nullptr)
        return;
    // create aux pointer and point it to the head of the node or in this case the top of the stack
    Node* dead_node = head;
    // set head to head next to point the next node
    head = head->next;
    // delete the top of stack
    delete dead_node;
    // increment count
    --count;
    // if the the count is zero head will be nullptr therefore tail has to be set to nullptrw
    if (count == 0)
        tail = nullptr;
}

string Stack::top()
{
    if (count > 0)
        return head->s;             // Same: return (*head).s;
    return "";
}

int Stack::size()
{
    return count;
}

Stack::~Stack()
{
    cout << "Stack count before destroying the linked list: " << count << endl;
    int all = count;
    for (int i = 0; i < all; ++i)
        pop();
    cout << "Stack count after destroying the linked list: " << count << endl;
}

