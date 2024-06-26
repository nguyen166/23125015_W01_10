#include "header.h"

void write(int n, int* pos, const char* filename, Customer* customersList) {
    ofstream fout(filename, ios::binary);
    fout.write((char*)&n, sizeof(n));
    fout.seekp(sizeof(int) + HEADER_SIZE * sizeof(int));
    for (int i = 0; i < n; i++) {
        pos[i] = fout.tellp();
        fout.write((char*)&customersList[i].customerId, sizeof(customersList[i].customerId));
        fout.write(customersList[i].userName, sizeof(customersList[i].userName));
        fout.write(customersList[i].telephone, sizeof(customersList[i].telephone));
        fout.write((char*)&customersList[i].numOfOrders, sizeof(customersList[i].numOfOrders));
        for (int j = 0; j < customersList[i].numOfOrders; j++) {
            fout.write((char*)&customersList[i].orders[j].orderNumber, sizeof(customersList[i].orders[j].orderNumber));
            fout.write((char*)&customersList[i].orders[j].amount, sizeof(customersList[i].orders[j].amount));
            int len = strlen(customersList[i].orders[j].itemList);
            fout.write((char*)&len, sizeof(len));
            fout.write(customersList[i].orders[j].itemList, len);
        }
    }
    fout.seekp(sizeof(int));
    fout.write((char*)pos, n * sizeof(int));
    fout.close();
}

bool searchID(const char* filename, long long int customerId, Customer* customer) {
    ifstream fin(filename, ios::binary);
    int n;
    fin.read((char*)&n, sizeof(n));
    int* pos = new int[n];
    fin.read((char*)pos, n * sizeof(int));
    bool found = false;
    for (int i = 0; i < n; i++) {
        fin.seekg(pos[i]);
        fin.read((char*)&customer->customerId, sizeof(customer->customerId));
        if (customer->customerId == customerId) {
            found = true;
            fin.read(customer->userName, sizeof(customer->userName));
            fin.read(customer->telephone, sizeof(customer->telephone));
            fin.read((char*)&customer->numOfOrders, sizeof(customer->numOfOrders));
            customer->orders = new Order[customer->numOfOrders];
            for (int j = 0; j < customer->numOfOrders; j++) {
                fin.read((char*)&customer->orders[j].orderNumber, sizeof(customer->orders[j].orderNumber));
                fin.read((char*)&customer->orders[j].amount, sizeof(customer->orders[j].amount));
                int len;
                fin.read((char*)&len, sizeof(len));
                customer->orders[j].itemList = new char[len + 1];
                fin.read(customer->orders[j].itemList, len);
                customer->orders[j].itemList[len] = '\0';
            }
            break;
        }
    }
    return found;
}