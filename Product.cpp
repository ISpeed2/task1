#include "Product.h"

Product::Product(std::string name, std::string description, double price) :
    name(name), description(description), price(price) {}

std::string Product::get_name() const {
    return name;
}

std::string Product::get_description() const {
    return description;
}

double Product::get_price() const {
    return price;
}
