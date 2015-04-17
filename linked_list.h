#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "node.h"

class LinkedList{
	friend std::ostream &operator<< (std::ostream &os, const LinkedList &link){
		Node *a = link.head;
		Node *b = a->next;
		while(b != a){
			os << "[" << b->data << "] ";
			b = b->next;
		}
		os << std::endl;
		return os;
	}

	private :
		Node *head, *iterator;
		EType size;
	public :
		LinkedList(): head(new Node), size(0) {head->next = head; head->prev = head;}
		void insert(Node *p, const EType &val);
		EType remove(Node *&p);
		bool remove(const EType &val);
		void pushFront(const EType &val);
		void pushBack(const EType &val);
		EType popFront();
		EType popBack();
		int getSize();
		Node *getIterator();
		bool empty();
};

#endif 
