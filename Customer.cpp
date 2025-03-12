#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name, double balance, int id) :
    name(name), balance(balance), id(id) {}

std::string Customer::get_name() const {
    return name;
}

int Customer::get_id() const {
    return id;
}

double Customer::get_balance() const {
    return balance;
}

void Customer::add_to_shopping_list(int product_id, int quantity) {
    shopping_list[product_id] = quantity;
}

void Customer::remove_from_shopping_list(int product_id) {
    shopping_list.erase(product_id);
}

bool Customer::buy_products(Store& store) {
    double total_cost = 0.0;
    std::map<int, int> bought_items; // For tracking successfully bought items

    // Calculate total cost and check availability
    for (const auto& item : shopping_list) {
        int product_id = item.first;
        int quantity = item.second;

        try {
            double product_price = store.get_product_price(product_id);
            int available_quantity = store.get_product_quantity(product_id);

            if (available_quantity < quantity) {
                std::cout << "Недостаточно товара с ID " << product_id << " в магазине " << store.get_name() << std::endl;
                return false; // Abort if not enough quantity
            }

            total_cost += product_price * quantity;
        }
        catch (const std::runtime_error& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            return false; // Abort if product not found
        }
    }

    // Check if enough balance
    if (balance < total_cost) {
        std::cout << "Недостаточно средств на балансе. Требуется: " << total_cost << ", Доступно: " << balance << std::endl;
        return false;
    }

    // Perform the purchase
    try {
        for (const auto& item : shopping_list) {
            int product_id = item.first;
            int quantity = item.second;
            store.sell_product(product_id, quantity);
            bought_items[product_id] = quantity; // Track successfully bought items
        }

        balance -= total_cost;
        std::cout << "Покупка прошла успешно на сумму: " << total_cost << std::endl;
        shopping_list.clear(); // Clear the shopping list after successful purchase
        return true;

    }
    catch (const std::runtime_error& error) {
        std::cerr << "Ошибка во время покупки: " << error.what() << std::endl;

        // Attempt to revert the sale (compensating transaction)
        for (const auto& item : bought_items) {
            store.add_product(store.getProduct(item.first), item.second); // Refund products back to the store
        }
        return false;
    }
}

void Customer::deposit(double amount) {
    balance += amount;
}

void Customer::withdraw(double amount) {
    if (balance < amount) {
        throw std::runtime_error("Недостаточно средств на балансе.");
    }
    balance -= amount;
}

void Customer::print_shopping_list() const {
    std::cout << "Список покупок покупателя " << name << ":" << std::endl;
    for (const auto& item : shopping_list) {
        std::cout << "  Товар ID: " << item.first << ", Количество: " << item.second << std::endl;
    }
}
