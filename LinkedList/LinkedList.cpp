#include "LinkedList.h"             // 1) your own header first
#include <iostream>                 // 2) then what THIS file needs
using namespace std;

LinkedList::LinkedList()            // LinkedList:: = member of LinkedList
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    while (head != nullptr) {       // delete the nodes one by one
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtFront(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void LinkedList::display() const
{
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " -> ";
    cout << "NULL" << endl;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

// =============================== Week 3 ===============================

void LinkedList::insertAtEnd(int value)                     // Q2
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)                                    // empty list
    {
        head = newNode;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr)                            // stop AT the last node
        cur = cur->next;
    cur->next = newNode;
}

int LinkedList::length() const                              // Q2
{
    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        count++;
    return count;
}

void LinkedList::createFromArray(const int arr[], int n)    // Q2
{
    for (int i = 0; i < n; i++)
        insertAtEnd(arr[i]);
}

int LinkedList::search(int value) const                     // Q3
{
    int index = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next, index++)
        if (cur->data == value)
            return index;
    return -1;                                              // not found
}

int LinkedList::update(int oldValue, int newValue)          // Q4
{
    int changed = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        if (cur->data == oldValue)
        {
            cur->data = newValue;
            changed++;
        }
    return changed;
}

bool LinkedList::insertAt(int index, int value)             // Q5
{
    if (index < 0 || index > length())
        return false;

    if (index == 0)                                         // new first node
    {
        insertAtFront(value);
        return true;
    }

    Node* prev = head;                                      // node at index-1
    for (int i = 0; i < index - 1; i++)
        prev = prev->next;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = prev->next;                             // (3) successor first
    prev->next = newNode;                                   // (4) then predecessor
    return true;
}

bool LinkedList::deleteValue(int value)                     // Q6
{
    if (head == nullptr)                                    // empty list
        return false;

    if (head->data == value)                                // head node
    {
        Node* victim = head;
        head = head->next;
        delete victim;
        return true;
    }

    Node* prev = head;                                      // middle or last node
    while (prev->next != nullptr && prev->next->data != value)
        prev = prev->next;

    if (prev->next == nullptr)                              // not found
        return false;

    Node* victim = prev->next;
    prev->next = victim->next;
    delete victim;
    return true;
}

void LinkedList::merge(LinkedList& other)                   // Q7
{
    if (this == &other || other.head == nullptr)
        return;

    if (head == nullptr)
        head = other.head;
    else
    {
        Node* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = other.head;                             // move, not copy
    }
    other.head = nullptr;                                   // other no longer owns them
}
