#include <iostream>
#include "functions.h"

int main() {
    
    // --- Test the functions ---

    Customer testCustomers[3];
    for (int i = 0; i < 3; i++) {
        testCustomers[i].customerId = 123456789 + i;
        strcpy(testCustomers[i].userName, ("TestUser" + to_string(i)).c_str());
        strcpy(testCustomers[i].telephone, ("123-456-789" + to_string(i)).c_str());
        testCustomers[i].numOfOrders = 1;
        testCustomers[i].orders = new Order[1];
        testCustomers[i].orders[0].orderNumber = 1 + i;
        testCustomers[i].orders[0].amount = 99.99 + (float) i;
        testCustomers[i].orders[0].itemList = new char[10];
        strcpy(testCustomers[i].orders[0].itemList, ("item" + to_string(i+1)).c_str());
    }

    // create a customer list and position array
    int n = 3;
    Customer* customersList = new Customer[n];
    for (int i = 0; i < n; i++) {
        customersList[i] = testCustomers[i];
    }
    int* pos = new int[n];
    for (int i = 0; i < n; i++) {
        pos[i] = 0;
    }

    // write the customers to a file
    writeCustomers(n, pos, "test.dat", customersList);

    // create a new customer list to read into
    Customer* readCustomersList = new Customer[n];

    // read the customers from the file
    readCustomers("test.dat", readCustomersList);

    // print the read customer data to verify it was read correctly
    for (int i = 0; i < n; i++) {
        cout << "Customer ID: " << readCustomersList[i].customerId << endl;
        cout << "User Name: " << readCustomersList[i].userName << endl;
        cout << "Telephone: " << readCustomersList[i].telephone << endl;
        cout << "Number of Orders: " << readCustomersList[i].numOfOrders << endl;
        cout << endl;

        for(int j = 0; j < readCustomersList[i].numOfOrders; j++){
            cout << "Order Number: " << readCustomersList[i].orders[j].orderNumber << endl;
            cout << "Order Amount: " << readCustomersList[i].orders[j].amount << endl;
            cout << "Item List: " << readCustomersList[i].orders[j].itemList << endl;
            cout << endl;
        }
    }

    Customer* testCustomer = new Customer();

    cout << "---- Finding customer with ID 123456789 ----" << endl;

    bool found = findCustomer("test.dat", 123456789, testCustomer);

    if(found){
        cout << "Customer found" << endl;
        cout << "Customer ID: " << testCustomer->customerId << endl;
        cout << "User Name: " << testCustomer->userName << endl;
        cout << "Telephone: " << testCustomer->telephone << endl;
        cout << "Number of Orders: " << testCustomer->numOfOrders << endl;
        cout << endl;

        for(int j = 0; j < testCustomer->numOfOrders; j++){
            cout << "Order Number: " << testCustomer->orders[j].orderNumber << endl;
            cout << "Order Amount: " << testCustomer->orders[j].amount << endl;
            cout << "Item List: " << testCustomer->orders[j].itemList << endl;
            cout << endl;
        }
    } else {
        cout << "Customer not found" << endl;
    }

    // clean up
    for (int i = 0; i < n; i++) {
        delete[] customersList[i].orders[0].itemList;
        delete[] customersList[i].orders;
        for(int j = 0; j < readCustomersList[i].numOfOrders; j++){
            delete[] readCustomersList[i].orders[j].itemList;
        }
        delete[] readCustomersList[i].orders;
    }
    delete[] customersList;
    delete[] readCustomersList;
    delete[] pos;
    delete testCustomer;

    cout << "Test completed" << endl;

    return 0;
}
