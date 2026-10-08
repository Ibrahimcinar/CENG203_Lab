#include "CircularList.h"
#include <iostream>
using namespace std;

CircularList::CircularList() : head(nullptr) {}

CircularList::~CircularList()
{
    if (head == nullptr)
        return;

    Node* cur = head->next;                     // break the ring: delete from head->next
    while (cur != head)
    {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    delete head;                                // back at head: delete it last
}

void CircularList::append(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr)                        // only node points to itself
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* last = head;
    while (last->next != head)
        last = last->next;
    last->next = newNode;
    newNode->next = head;                       // close the ring
}

void CircularList::display() const
{
    if (head == nullptr)
    {
        cout << "(empty)" << endl;
        return;
    }

    Node* cur = head;
    do
    {
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);
    cout << "(back to " << head->data << ")" << endl;
}

int CircularList::length() const
{
    if (head == nullptr)
        return 0;

    int count = 0;
    Node* cur = head;
    do
    {
        count++;
        cur = cur->next;
    } while (cur != head);
    return count;
}
