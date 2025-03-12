#include "Product.h"

Product::Product(std::string name, std::string description, int id, double price) :
    name(name), description(description), id(id), price(price) {}

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
    this->price = price;
}

void Product::print_info() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Описание: " << description << std::endl;
    std::cout << "Цена: " << price << std::endl;
}