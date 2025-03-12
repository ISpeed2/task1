#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <map>
#include "Store.h" // Подключаем Store.h

class Customer {
private:
    std::string name;
    int id;
    double balance;
    std::map<int, int> shopping_list;

public:
    Customer(std::string name, double balance, int id);

    std::string get_name() const;
    int get_id() const;
    double get_balance() const;

    void add_to_shopping_list(int product_id, int quantity);
    void remove_from_shopping_list(int product_id);
    bool buy_products(Store& store);
    void deposit(double amount);
    void withdraw(double amount);

    void print_shopping_list() const;
};

#endif
