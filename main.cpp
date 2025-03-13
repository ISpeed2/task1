#include <iostream>
#include "ShopManagementSystem.h"
#include "Store.h"
#include "Product.h"
#include "Customer.h"

int main() {
    ShopManagementSystem system;

    // Create some products
    Product milk("Milk", "Fresh milk", 10.0);
    Product apple("Apple", "Red apple", 1.0);

    // Create some stores
    Store store1("Store A", 1, "Address 1");
    store1.add_product(1, milk, 10);
    store1.add_product(3, apple, 20);

    Store store2("Store B", 2, "Address 2");
    store2.add_product(1, milk, 8.0);
    store2.add_product(3, apple, 15);

    system.add_store(store1);
    system.add_store(store2);

    // Create a customer
    Customer customer1("John", 100.0);

    // Add some items to the shopping list
    customer1.add_to_shopping_list(3, 1);

    // Find store with lowest price for milk
    Store* cheapest_store = system.find_store_with_lowest_price(1);

    if (cheapest_store != nullptr) {
        std::cout << "Cheapest store for milk: " << cheapest_store->get_name() << std::endl;
    } else {
        std::cout << "Milk not found in any store." << std::endl;
    }

    return 0;
}
