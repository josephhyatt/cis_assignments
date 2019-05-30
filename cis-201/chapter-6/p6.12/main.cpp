#include <iostream>
#include <vector>

using namespace std;

string name_of_best_customer(vector<double> sales, vector<string> customer) {
    double maxSale = 0.0;
    double maxSaleIndex = 0;
    for (int i = 0; i < sales.size(); i++) {
        if (maxSale <= sales[i]) {
            maxSale = sales[i];
            maxSaleIndex = i;
        }
    }
    return customer[maxSaleIndex];
}

int main() {
    string customer;
    double sale;
    int num = 1;

    cout << "Enter 1 to enter customer details and 0 to exit." << endl;
    cin >> num;

    vector<string> customers;
    vector<double> sales;

    while (num == 1) {
        cout << "Customer First Name: ";
        cin >> customer;

        cout << "Sale: ";
        cin >> sale;

        if (sale < 0) {
            sale = 0;
        }

        customers.push_back(customer);
        sales.push_back(sale);

        cout << "Enter 1 to enter next customer details and 0 to exit." << endl;
        cin >> num;
    }
    if (customers.size() == 0) {
        cout << "No customer data present, no best customer" << endl;
        return 0;
    }

    cout << "Best customer is " << name_of_best_customer(sales, customers) << endl;

    return 0;
}
