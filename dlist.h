// ----------------------------------------------------------------------------
// dlist.h :  Template class implementing a doubly linked list
// Author  :  Jack Eubanks
// Date    :  6/14/2024
// ----------------------------------------------------------------------------
#ifndef _DLIST_H_
#define _DLIST_H_

template<class T>
class Node {
public:
    Node* next;
    Node* prev;
    T* data;
    Node(T* t = nullptr) : data(t), next(nullptr), prev(nullptr) {}
    virtual ~Node() {}
};


template<class T>
class DList {
private:
    int m_size;
    Node<T>* m_head;
    Node<T>* m_tail;

public:
    DList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    // DList::~DList() - Delete all nodes in the list
    virtual ~DList() {
        while (m_head != nullptr) {
            if (m_head->next != nullptr) {
                m_head = m_head->next;
                delete m_head->prev;
            }
            else {
                // We're at the tail now...
                delete m_head;
                m_head = nullptr;
            }
        }
    }

    T* head()  { return m_head->data; }  // Get object stored in head node
    T* tail()  { return m_tail->data; }  // Get object stored in tail node
    int size() { return m_size; }        // Return size of list

    // DList::add() - Add a new item to the list
    void add(T* new_node) {
        if (m_head == nullptr) {
            // Handle case of empty list
            m_head = new Node<T>(new_node);
            m_tail = m_head;
            m_size = m_size + 1;
        }
        else {
            // Handle normal case 
            m_tail->next = new Node<T>(new_node);
            m_tail->next->prev = m_tail;
            m_tail = m_tail->next;
            m_tail->next = nullptr;
            m_size = m_size + 1;
        }
    }


    // DList::find_at_index() - Find & return item at the specified position
    T* find_at_index(int idx) {
        if (idx < 0 || idx >= m_size)
            return nullptr;
        Node<T>* curr = m_head;
        for (int i = 0; i < idx; i++) {
            if (curr->next == nullptr)
                return nullptr;
            curr = curr->next;
        }
        // Node found, so return its data
        return curr->data;
    }


    // DList::remove() - Find & remove item from list (return item if found)
    T* remove(T* t) {    
        // Check for null pointer or empty list
        if (t == nullptr || m_size == 0) {
            return nullptr;
        }
        Node<T>* curr = m_head;

        // Handle case of only 1 item in List:
        if (curr->next == nullptr) {
            if (curr->data == t) {
                // Item was found at the head node
                delete curr;
                m_size = 0;
                m_tail = m_head = nullptr;
                return t;  
            }
        }     
        // Handle normal case
        while (curr->next != nullptr) {
            if (curr->data == t) {
                if (curr == m_head) {
                    // Handle case: Remove head node
                    m_head = curr->next;
                    m_head->prev = nullptr;
                    delete curr;
                    m_size--;
                    return t;
                }
                else {
                    // Handle case: Remove node in middle
                    curr->next->prev = curr->prev;
                    curr->prev->next = curr->next;
                    delete curr;
                    m_size--;
                    return t;
                }
            }
            curr = curr->next; // Item not found yet, so keep traversing...
        }
        if (curr == m_tail && curr->data == t) {
            // Handle case: Remove tail node
            m_tail = m_tail->prev;
            m_tail->next = nullptr;
            delete curr;
            m_size--;
            return t;
        }
        // Item not found in List
        return nullptr;
    }

};

#endif //_DLIST_H_
