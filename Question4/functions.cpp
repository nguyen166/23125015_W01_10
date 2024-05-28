#include "header.h"

void push(Node*& head, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void pop(Node*& head) {
	if (head == nullptr) {
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
}

void destroy(Node*& head) {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void print(Node* head) {
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void partitions(int N, int prev, Node* head) {
	if (N == 0) {
		print(head);
		return;
	}
	for (int i = N; i >= prev; i--) {
		push(head, i);
		partitions(N - i, i, head);
		pop(head);
	}
}