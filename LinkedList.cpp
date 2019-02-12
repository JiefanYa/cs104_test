#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::~LinkedList() {
    // iterative approach
    Node* curr = this->head;
    while(curr != nullptr){
    	Node* temp = curr->next;
    	delete curr;
    	curr = temp;
    }
}

void LinkedList::add(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
}

void LinkedList::InsertNth(int index, int data) {
	// recursive approach
	if(index<0) return;
	this->head = InsertNthHelper(this->head,index,data);
}

Node* LinkedList::InsertNthHelper(Node* curr, int index, int data){
	if(index==0) {
		Node* node = new Node;
		node->data = data;
		node->next = curr;
		return node;
	}
	if(curr==nullptr) return nullptr;
	curr->next = InsertNthHelper(curr->next,index-1,data);
}

/*
void LinkedList::InsertNth(int index, int data) {
    // iterative approach
    if(index<0) return;
    if(index==0){
    	add(data);
    	return;
    }
    Node* curr = this->head;
    for(int i=0;i<index-1;++i){
    	curr = curr->next;
    	if(curr==nullptr) return;
    }
    Node* nth = new Node;
    nth->data = data;
    nth->next = curr->next;
    curr->next = nth;
}
*/

int LinkedList::NthFromEndHelper(Node* node, int& n){
	if(node==nullptr) return -1;
	int result = NthFromEndHelper(node->next,n);
	if(n-- == 0) return node->data;
	return result;
}

int LinkedList::NthFromEnd(int n) {
	// recursive approach
	return NthFromEndHelper(this->head, n);
}

/*
int LinkedList::NthFromEnd(int n) {
    // iterative approach 1
    if(n<0) return -1;
    Node* curr = this->head;
    int l = 0;
    if(curr==nullptr) return -1;
    while(curr->next!=nullptr){
    	curr = curr->next;
    	l++;
    }
    if(n>l) return -1;
    if(n==0) return curr->data;
    int index = l-n;
    int i=0;
    Node* head = this->head;
    while(i<index){
    	head = head->next;
    	i++;
    }
    return head->data;
}
*/

/*
int LinkedList::NthFromEnd(int n) {
	// iterative approach 2 (better)
	if(n<0) return -1;
	Node* fast = this->head;
	for(int i =0;i<=n;++i){
		if(fast==nullptr) return -1;
		fast = fast->next;
	}
	Node* slow = this->head;
	while(fast!=nullptr){
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}
*/