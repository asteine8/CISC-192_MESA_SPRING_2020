#ifndef LLIST_H
#define LLIST_H

template <typename T>
struct Node {
    Node* prevNode;
    Node* nextNode;
    T value;
};

template <typename T>
class LList {
    public:
        Node head;
        Node tail;

        LList() {
            head = NULL;
            tail = NULL;
        }

        LList(T x) {
            head
        }
};

#endif