#include "Product.h"
#include <stdexcept>  // Для исключений

Product::Product(std::string name, std::string description, int id, double price) :
    name(name), description(description), id(id), price(price) {
    if (name.empty()) {
        throw std::invalid_argument("Название товара не может быть пустым.");
    }
    if (description.empty()) {
         throw std::invalid_argument("Описание товара не может быть пустым.");
    }
    if (id <= 0) {
        throw std::invalid_argument("ID товара должен быть положительным числом.");
    }
    if (price < 0) {
        throw std::invalid_argument("Цена товара не может быть отрицательной.");
    }
}

std::string Product::get_name() const {
    return name;
}

std::string Product::get_description() const {
    return description;
}

int Product::get_id() const {
    return id;
}

double Product::get_price() const {
    return price;
}

void Product::set_price(double price) {
    if (price < 0) {
        throw std::invalid_argument("Цена товара не может быть отрицательной.");
    }
    this->price = price;
}

void Product::print_info() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Описание: " << description << std::endl;
    std::cout << "Цена: " << price << std::endl;
}
