#include "header.h"

void splitEvenOdd(Node* pHead, Node*& pHeadOdd) {
	if (!pHead) {
		pHeadOdd = nullptr;
		return;
	}
	Node* cur = pHead;
	pHeadOdd = pHead->next;
	Node* curOdd = pHeadOdd;
	int index = 2;
	while (cur && cur->next) {
		if (index % 2 == 0) {
			cur->next = curOdd->next;
			cur = cur->next;
		}
		else {
			curOdd->next = cur->next;
			curOdd = curOdd->next;
		}
		index++;
	}
	if (curOdd && curOdd->next) {
		curOdd->next = nullptr;
	}
}

void merge(Node*& pHead, Node*& pHeadOdd) {
	Node* cur = pHead;
	if (!pHead) {
		pHead = pHeadOdd;
		pHeadOdd = nullptr;
		return;
	}
	Node* curOdd = pHeadOdd;
	while (curOdd && cur->next) {
		Node* tmp = cur->next;
		cur->next = curOdd;
		curOdd = curOdd->next;
		cur->next->next = tmp;
		cur = tmp;
	}
	if (!cur->next) {
		cur->next = curOdd;
	}
	pHeadOdd = nullptr;
}