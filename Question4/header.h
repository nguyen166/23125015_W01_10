#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void push(Node*& head, int data);
void pop(Node*& head);
void destroy(Node*& head);
void print(Node* head);
void partitions(int N, int prev, Node* head);
