#include "header.h"

int main() {
	Node* head = nullptr;
	int n;
	cout << "Enter a positive integer to print out all partitions of it: ";
	cin >> n;
	partitions(n, 1, head);
	destroy(head);
	return 0;
}