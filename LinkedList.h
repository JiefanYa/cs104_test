#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
    public:
        Node* next;
        int data;
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void add(int data);
        void InsertNth(int index, int data);
        int NthFromEnd(int n);
        int NthFromEndHelper(Node* node, int& n);
        Node* InsertNthHelper(Node* curr, int index, int data);
        Node* head;

};

#endif