#include <utility>
#include <cassert>
#include "ll.h"
#include<stdio.h>
#include<stdlib.h>

using namespace cs126linkedlist;

// This is the default constructor which should construct an empty linked list.
template<typename ElementType>
LinkedList<ElementType>::LinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
}

// This constructor will create a linked list containing in order the elements from the value vector.
template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
    for (ElementType element: values) {
        push_back(element);
    }
    LinkedListNode *current = head_;
    while (current) {
        if (!current->next) {
            tail_ = current;
        }
        current = current->next;
    }
    
}

//This function will create a new linked list that is a deep copy of the source.
// Copy constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
    LinkedListNode *currentNode = source.head_;
    if (!currentNode) {
        return;
    }
    head_ = nullptr;
    tail_ = nullptr;
    while (currentNode) {
        push_back(currentNode->data);
        if (!currentNode->next) {
            tail_ = currentNode;
        }
        currentNode = currentNode->next;
    }
}

// This function will implement a move constructor that will make a new linked list using the already allocated elements from the source.
// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
    head_ = source.head_;
    source.head_ = nullptr;
    tail_ = source.tail_;
    source.tail_ = nullptr;
}

// This destructor function will delete all the allocated data in the linked list class.
// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {
    clear();
    delete head_;
}

//This function is the copy assignment operator which should make a deep copy from the source deallocating all data from the old location. Remember to handle the case where the both sides are the same list.
// Copy assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (const LinkedList<ElementType>& source) {
    
}

// This function will copy the data from the source reusing the allocated data from the source and deleting any data that was allocated. Remember to handle the case where the both sides are the same list
// Move assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (LinkedList<ElementType>&& source) noexcept {
    
}

// This function will add a new element to the linked list at the front of the list.
template<typename ElementType>
void LinkedList<ElementType>::push_front(ElementType value) {
    LinkedListNode *new_head = new LinkedListNode(value);
    if (head_ == nullptr) {
        head_ = new_head;
    } else {
        new_head->next = head_;
        head_ = new_head;
    }
}

// This function will add a new element to the linked list at the back of the list.
template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
    LinkedListNode *new_tail = new LinkedListNode(value);
    if (head_ == nullptr) {
        head_ = new_tail;
    } else {
        LinkedListNode *temp = new LinkedListNode(value);
        temp = head_;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_tail;
    }
}

// Return a copy of the ElementType element stored in the first node of the list. This does not remove any items from the list. If the list is empty you should crash to an assert ElementType.
template<typename ElementType>
ElementType LinkedList<ElementType>::front() const{
    if (empty()) {
        return NULL;
    }
    return head_->data;
    
}

// Return a copy of the ElementType element stored in the last node of the list. This does  not remove any items from the list. If the list is empty you should crash to an assert ElementType.
template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {
    if (empty()) {
        return NULL;
    } else {
        LinkedListNode *current = head_;
        while (current->next != NULL) {
            current = current->next;
        }
        return current->data;
    }
}

// This will remove the front element from the linked list and delete the allocated data. If the list is empty it will do nothing.
template<typename ElementType>
void LinkedList<ElementType>::pop_front() {
    if (empty()) {
        return;
    }
    LinkedListNode *first = head_;
    head_ = first->next;
    delete first;
    
}

// This will remove the back element from the linked list and delete the allocated data. If the list is empty it will do nothing
template<typename ElementType>
void LinkedList<ElementType>::pop_back() {
    if (empty()) {
        return;
    }
    if (size() == 1) {
        delete head_;
        head_ = nullptr;
    }
    LinkedListNode *node_to_delete = head_;
    LinkedListNode *new_tail;
    
    while (node_to_delete->next != nullptr) {
        new_tail = node_to_delete;
        node_to_delete = node_to_delete->next;
    }
    new_tail->next = nullptr;
    delete node_to_delete;
    
}

// Return the number of elements in the list.
template<typename ElementType>
int LinkedList<ElementType>::size() const {
    int count = 0;
    LinkedListNode *current = head_;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// This function returns true if the list is empty otherwise returns false
template<typename ElementType>
bool LinkedList<ElementType>::empty() const {
    if (head_ == NULL) {
        return true;
    }
    return false;
}

//  Delete all data in the linked list returning the list to the same state as the default constructor.
template<typename ElementType>
void LinkedList<ElementType>::clear() {
    if (empty()) {
        return;
    }
    LinkedListNode *current = head_;
    LinkedListNode *next_node;
    
    while (current != nullptr) {
        next_node = current->next;
        delete current;
        current = next_node;
    }
    
    head_ = nullptr;
    
    
    
}

// This should print the ElementType elements stored in the list using the « operator from the ElementType class to print the list with a comma and a space separating each element for example "3, 2" when there are elements that would print as 3 and 2 respectively
template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {
    
}

// Remove all the odd elements from the list. Remember that the list is zero indexed so the first element in the list is even. This should be implemented without directly calling any functions in this class.
template<typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
    if (head_ == nullptr) {
        return;
    }
    LinkedListNode *first = head_;
    LinkedListNode *node = head_->next;
    
    while (first != nullptr && node != nullptr) {
        first->next = node->next;
        first = first->next;
        
        delete(node);
        
        if (first != NULL) {
            node = first->next;
        }
    }
}

// This function will compare the list element by element returning true if they are all equal otherwise it will return false
template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
    if (head_ == nullptr && rhs.head_ == nullptr) {
        return true;
    }
    if (size() != rhs.size()) {
        return false;
    }
    LinkedListNode* current_first = head_;
    LinkedListNode* current_second = rhs.head_;
    
    while (current_first->next != NULL) {
        if (current_first->data != current_second->data) {
            return false;
        }
        current_first = current_first->next;
        current_second = current_second->next;
    }
    return true;
}

//  This function will compare the list element by element returning false if they are all equal otherwise it will return true.
template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {
    return !(lhs == rhs);
}


// this should let the iterator go through the nodes of a list
template<typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::operator++() {
    if (current_) {
        current_ = current_->next;
    }
    return *this;
}

// retrieves data of current node
template<typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {
    current_ = current_->data;
    return current_;
}

// not equal operator
template<typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator& other) const {
    if (other.current_ != current_) {
        return true;
    }
    return false;
}

// return iterator that points to beginning of list
template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
    return iterator(head_);
}

// return iterator that points to end of list.
template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
    return iterator(NULL);
}

//
template<typename ElementType>
typename LinkedList<ElementType>::const_iterator& LinkedList<ElementType>::const_iterator::operator++() {
    if (current_) {
        current_ = current_->next;
    }
    return *this;
    
}

//
template<typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
    return current_->data;
    
}

// not equal operator
template<typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator& other) const {
    if (other.current_ != current_) {
        return true;
    }
    return false;
}

// These functions return an iterator and a const iterator respectively that points to the start of the list.
template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
    return const_iterator(head_);
    
}

// These functions return an iterator and a const iterator respectively that points to the past the end of the list
template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
    return const_iterator(NULL);
    
}
