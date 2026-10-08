#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
    DNode* cur = head;
    while (cur != nullptr)
    {
        DNode* next = cur->next;
        delete cur;
        cur = next;
    }
}

void DoublyLinkedList::insertAtFront(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;
    else
        tail = newNode;                         // empty list: also the last node
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr)
        tail->next = newNode;
    else
        head = newNode;                         // empty list: also the first node
    tail = newNode;
}

void DoublyLinkedList::displayForward() const
{
    cout << "Forward:  ";
    for (DNode* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

void DoublyLinkedList::displayBackward() const
{
    cout << "Backward: ";
    for (DNode* cur = tail; cur != nullptr; cur = cur->prev)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

bool DoublyLinkedList::deleteValue(int value)
{
    DNode* victim = head;
    while (victim != nullptr && victim->data != value)
        victim = victim->next;

    if (victim == nullptr)                      // not found (or empty list)
        return false;

    if (victim->prev != nullptr)
        victim->prev->next = victim->next;
    else
        head = victim->next;                    // victim was the head

    if (victim->next != nullptr)
        victim->next->prev = victim->prev;
    else
        tail = victim->prev;                    // victim was the tail

    delete victim;
    return true;
}
