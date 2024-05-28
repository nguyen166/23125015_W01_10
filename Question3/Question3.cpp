#include "header.h"

int main() {
    Customer Customers[10];
    for (int i = 0; i < 10; i++) {
        Customers[i].customerId = 123456789 + i;
        strcpy(Customers[i].userName, ("Customer" + to_string(i)).c_str());
        strcpy(Customers[i].telephone, ("000000000" + to_string(i)).c_str());
        Customers[i].numOfOrders = 1;
        Customers[i].orders = new Order[1];
        Customers[i].orders[0].orderNumber = 1 + i;
        Customers[i].orders[0].amount = 99.99 + (float)i;
        Customers[i].orders[0].itemList = new char[10];
        strcpy(Customers[i].orders[0].itemList, ("item" + to_string(i + 1)).c_str());
    }

    int n = 10;
    int* pos = new int[n];
    for (int i = 0; i < n; i++) {
        pos[i] = 0;
    }

    write(n, pos, "test.dat", Customers);

    cout << "Finding customer with ID 123456789" << endl;

    Customer test = Customers[0];

    bool found = searchID("test.dat", 123456789, Customers);

    if (found) {
        cout << "User Name: " << test.userName << endl;
        cout << "Telephone: " << test.telephone << endl;
        cout << "Number of Orders: " << test.numOfOrders << endl;
        cout << endl;

        for (int j = 0; j < test.numOfOrders; j++) {
            cout << "Order Number: " << test.orders[j].orderNumber << endl;
            cout << "Order Amount: " << test.orders[j].amount << endl;
            cout << "Item List: " << test.orders[j].itemList << endl;
            cout << endl;
        }
    }
    else {
        cout << "Customer not found" << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] Customers[i].orders[0].itemList;
        delete[] Customers[i].orders;
    }
    delete[] pos;

    return 0;
}
