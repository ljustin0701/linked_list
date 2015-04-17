#ifndef NODE_H
#define NODE_H

typedef int EType;

struct Node{
	Node(const EType &d = 0, Node *n = NULL, Node*p = NULL) : data(d), next(n), prev(p) {}
	Node *next, *prev;
	EType data;
};

#endif
