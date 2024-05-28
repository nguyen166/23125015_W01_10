#ifndef HEADER_FUNCTIONS_H
#define HEADER_FUNCTIONS_H

#include <fstream>
#include <vector>
#include <cstring>

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

void readCustomers(const char* filename, Customer* customersList);
void writeCustomers(int n, int* pos,  const char* filename, Customer* customersList);
bool findCustomer(const char* filename, long long int customerId, Customer* customer);

#endif