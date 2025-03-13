#include "Customer.h"
#include <stdexcept> // Для исключений
#include <iostream>

Customer::Customer(std::string name, double balance, int id) :
    name(name), balance(balance), id(id) {
    if (name.empty()) {
        throw std::invalid_argument("Имя покупателя не может быть пустым.");
    }
    if (balance < 0) {
        throw std::invalid_argument("Баланс покупателя не может быть отрицательным.");
    }
    if (id <= 0) {
        throw std::invalid_argument("ID покупателя должен быть положительным числом.");
    }
}

std::string Customer::get_name() const {
    return name;
}

int Customer::get_id() const {
    return id;
}

double Customer::get_balance() const {
    return balance;
}

void Customer::set_balance(double balance) {
    if (balance < 0) {
        throw std::invalid_argument("Баланс покупателя не может быть отрицательным.");
    }
    this->balance = balance;
}

void Customer::add_to_shopping_list(int product_id, int quantity) {
    if (product_id <= 0) {
        throw std::invalid_argument("ID товара должен быть положительным числом.");
    }
    if (quantity <= 0) {
        throw std::invalid_argument("Количество товара должно быть положительным числом.");
    }
    shopping_list[product_id] = quantity;
}

void Customer::remove_from_shopping_list(int product_id) {
    shopping_list.erase(product_id);
}

std::map<int, int> Customer::get_shopping_list() const {
    return shopping_list;
}

void Customer::make_purchase(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Сумма покупки должна быть положительной.");
    }
    if (balance < amount) {
        throw std::runtime_error("Недостаточно средств на балансе.");
    }
    balance -= amount;
}

void Customer::print_info() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Баланс: " << balance << std::endl;
}
