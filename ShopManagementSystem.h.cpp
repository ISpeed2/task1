#ifndef SHOPMANAGEMENTSYSTEM_H
#define SHOPMANAGEMENTSYSTEM_H

#include <vector>
#include "Store.h"
#include "Product.h"
#include "Customer.h"

class ShopManagementSystem {
private:
    std::vector<Store> stores;
    std::vector<Product> products;
    std::vector<Customer> customers;

public:
    void add_store(const Store& store);
    void add_product(const Product& product);
    void add_customer(const Customer& customer);
    Store* find_store_with_lowest_price(int product_id);

    void run_simulation(); // Optional: for demonstration purposes
};

#endif