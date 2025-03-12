#include "ShopManagementSystem.h"
#include <iostream>
#include <limits> // Для numeric_limits

void ShopManagementSystem::add_store(const Store& store) {
    stores.push_back(store);
}

void ShopManagementSystem::add_product(const Product& product) {
    products.push_back(product);
}

void ShopManagementSystem::add_customer(const Customer& customer) {
    customers.push_back(customer);
}

Store* ShopManagementSystem::find_store_with_lowest_price(int product_id) {
    Store* cheapest_store = nullptr;
    double lowest_price = std::numeric_limits<double>::infinity(); // Set to maximum possible value

    for (Store& store : stores) {
        try {
            double price = store.get_product_price(product_id);
            if (price < lowest_price) {
                lowest_price = price;
                cheapest_store = &store;
            }
        }
        catch (const std::runtime_error& error) {
            // Product not found in this store, ignore
        }
    }

    return cheapest_store;
}

void ShopManagementSystem::run_simulation() {
    // Implement your simulation logic here, using the added stores, products, and customers
}