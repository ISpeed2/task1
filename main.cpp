#include <iostream>
#include "ShopManagementSystem.h"

int main() {
    ShopManagementSystem system;

    // Create products
    Product product1("Молоко", "Свежее молоко 1л", 1, 90.0);
    Product product2("Хлеб", "Белый хлеб", 2, 45.0);
    Product product3("Яблоки", "Красные яблоки", 3, 120.0);

    system.add_product(product1);
    system.add_product(product2);
    system.add_product(product3);

    // Create stores
    Store store1("Магазин у дома", "ул. Ленина, 1", 101);
    Store store2("Супермаркет", "ул. Гагарина, 5", 102);

    // Add products to stores
    store1.add_product(product1, 10);
    store1.add_product(product2, 5);
    store2.add_product(product1, 15);
    store2.add_product(product2, 10);
    store2.add_product(product3, 20);

    // Change price in store
    store2.getProduct(1).set_price(85.0); // Lower milk price in Супермаркет

    system.add_store(store1);
    system.add_store(store2);

    // Create customer
    Customer customer1("Иван", 500.0, 201);
    system.add_customer(customer1);

    // Add products to shopping list
    customer1.add_to_shopping_list(1, 2); // 2 milk
    customer1.add_to_shopping_list(3, 1); // 1 apple

    // Find store with lowest price for milk
    Store* cheapest_store = system.find_store_with_lowest_price(1); // ID of milk is 1
    if (cheapest_store != nullptr) {
        std::cout << "Самая низкая цена на молоко в магазине: " << cheapest_store->get_name() << std::endl;
    }
    else {
        std::cout << "Молоко не продается ни в одном магазине." << std::endl;
    }

    // Buy products
    try {
        bool success = customer1.buy_products(*cheapest_store); // Buy from the cheapest store
        if (success) {
            std::cout << "Покупка прошла успешно!" << std::endl;
        }
        else {
            std::cout << "Не удалось совершить покупку." << std::endl;
        }
    }
    catch (const std::runtime_error& error) {
        std::cerr << "Ошибка при покупке: " << error.what() << std::endl;
    }

    // Print customer's balance after purchase
    std::cout << "Баланс покупателя: " << customer1.get_balance() << std::endl;

    return 0;
}
