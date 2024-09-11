#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        deleteFront();
    }
}

void LinkedList::insertFront(int item) {
    Node* newNode = new Node(item, head);
    head = newNode;
}

void LinkedList::deleteFront() {
    if (head != nullptr) {
        Node* oldHead = head;
        head = head->link;
        delete oldHead;
    }
}

void LinkedList::printList() {
    Node* currNode = head;
    while (currNode != nullptr) {
        std::cout << currNode->data << " ";
        currNode = currNode->link;
    }
}

bool LinkedList::swap(int pos1, int pos2) {
    if (pos1 < 0 || pos2 < 0 || pos1 == pos2) return false;

    Node *node1 = nullptr, *node2 = nullptr;
    Node *current = head;
    int index = 0;

    // Traverse the list to find nodes at pos1 and pos2
    while (current != nullptr) {
        if (index == pos1) node1 = current;
        if (index == pos2) node2 = current;
        current = current->link;
        index++;
    }

    if (node1 == nullptr || node2 == nullptr) return false;

    // Swap the data between node1 and node2
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;

    return true;
}

bool LinkedList::find_and_delete(int target) {
    Node *current = head, *prev = nullptr;

    // Traverse the list to find the target
    while (current != nullptr) {
        if (current->data == target) {
            if (prev == nullptr) {
                head = current->link;
            } else {
                prev->link = current->link;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->link;
    }

    return false;
}
