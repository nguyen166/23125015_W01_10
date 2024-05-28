#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

const int HEADER_SIZE = 100000;

using namespace std;

struct Order {
    long long int orderNumber;
    float amount;
    char* itemList;
};

struct Customer {
    long long int customerId;
    char userName[21];
    char telephone[17];
    int numOfOrders;
    Order* orders;
};

void write(int n, int* pos, const char* filename, Customer* customersList);
bool searchID(const char* filename, long long int customerId, Customer* customer);