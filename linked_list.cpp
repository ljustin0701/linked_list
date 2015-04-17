#include <iostream>
#include "node.h"
#include "linked_list.h"

int LinkedList::getSize(){return size;}

bool LinkedList::empty(){return size == 0 ? true:false;}

Node * LinkedList::getIterator(){iterator = head->next; return iterator;}

void LinkedList::insert(Node *p, const EType &val){
	if(!p){
		std::cerr << "Null Pointer Exception." << std::endl;
		return;
	}
	Node *b = p->prev;
	Node *nodeP = new Node(val, p, b);
	b->next = nodeP;
	p->prev = nodeP;
	size++;
}

EType LinkedList::remove(Node *&p){
	if(!p){
		std::cerr << "Null Pointer Exception." << std::endl;
		return -10000;
	}
	if(p == head){
		std::cerr << "Attempting to remove header node." << std::endl;
		return -20000;
	}
	if(size == 0){
		std::cerr << "Removing from empty list." << std::endl;
		return -30000;
	}
	Node *temp = p;
	EType tempdata = p->data;
	p = p->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
	size--;
	return tempdata;
}

bool LinkedList::remove(const EType &val){
	if(size == 0){
		std::cerr << "Removing from empty list." << std::endl;
		return false;
	}
	Node *p = head->next;
	while(p->data != val && p != head){
		p = p->next;
	}
	if(p == head){
		return false;
	} else {
		remove(p);
		return true;
	}
}

void LinkedList::pushFront(const EType &val){
	Node *p = new Node(val, head->next, head);
	head->next->prev = p;
	head->next = p;	
	size++;
}

void LinkedList::pushBack(const EType &val){
	Node *p = new Node(val, head, head->prev);
	head->prev->next = p;
	head->prev = p;
	size++;
}

EType LinkedList::popFront(){
	if(size == 0){
		std::cerr << "Removing from empty list." << std::endl;
		return -10000;
	}
	Node *temp = head->next;
	EType hold = temp->data;
	head->next = temp->next;
	temp->next->prev = head;
	delete temp;
	size--;
	return hold;
}

EType LinkedList::popBack(){
	if(size == 0){
		std::cerr << "Removing from empty list." << std::endl;
		return -10000;
	}
	Node *temp = head->prev;
	EType hold = temp->data;
	head->prev = temp->prev;
	temp->prev->next = head;
	delete temp;
	size--;
	return hold;
}
