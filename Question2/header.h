#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void splitEvenOdd(Node* pHead, Node*& pHeadOdd);
void merge(Node*& pHead, Node*& pHeadOdd);