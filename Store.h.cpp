#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <map>
#include "Product.h" // Подключаем Product.h

class Store {
private:
    std::string name;
    int id;
    std::string address;
    std::map<int, std::pair<Product, int>> inventory;

public:
    Store(std::string name, std::string address, int id);

    std::string get_name() const;
    int get_id() const;
    std::string get_address() const;

    void add_product(const Product& product, int quantity);
    void remove_product(int product_id, int quantity);
    double get_product_price(int product_id) const;
    int get_product_quantity(int product_id) const;
    void sell_product(int product_id, int quantity);

    void print_inventory() const;
    Product getProduct(int product_id) const;
};

#endif