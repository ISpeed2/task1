#include "Store.h"

Store::Store(std::string name, std::string address, int id) :
    name(name), address(address), id(id) {}

std::string Store::get_name() const {
    return name;
}

int Store::get_id() const {
    return id;
}

std::string Store::get_address() const {
    return address;
}

void Store::add_product(const Product& product, int quantity) {
    auto it = inventory.find(product.get_id());
    if (it != inventory.end()) {
        it->second.second += quantity; // Increase quantity if product exists
    }
    else {
        inventory[product.get_id()] = std::make_pair(product, quantity);
    }
}

void Store::remove_product(int product_id, int quantity) {
    auto it = inventory.find(product_id);
    if (it == inventory.end()) {
        throw std::runtime_error("Товар с ID " + std::to_string(product_id) + " отсутствует в магазине.");
    }

    if (it->second.second < quantity) {
        throw std::runtime_error("Недостаточно товара с ID " + std::to_string(product_id) + " в магазине для удаления.");
    }

    it->second.second -= quantity;
    if (it->second.second == 0) {
        inventory.erase(product_id); // Optionally remove the product if quantity becomes zero
    }
}

double Store::get_product_price(int product_id) const {
    auto it = inventory.find(product_id);
    if (it == inventory.end()) {
        throw std::runtime_error("Товар с ID " + std::to_string(product_id) + " отсутствует в магазине.");
    }
    return it->second.first.get_price();
}

int Store::get_product_quantity(int product_id) const {
    auto it = inventory.find(product_id);
    if (it == inventory.end()) {
        return 0; // Or throw an exception, depending on desired behavior
    }
    return it->second.second;
}

void Store::sell_product(int product_id, int quantity) {
    auto it = inventory.find(product_id);
    if (it == inventory.end()) {
        throw std::runtime_error("Товар с ID " + std::to_string(product_id) + " отсутствует в магазине.");
    }
    if (it->second.second < quantity) {
        throw std::runtime_error("Недостаточно товара с ID " + std::to_string(product_id) + " в магазине.");
    }
    it->second.second -= quantity;
}

void Store::print_inventory() const {
    std::cout << "Ассортимент магазина " << name << ":" << std::endl;
    for (const auto& item : inventory) {
        std::cout << "  Товар ID: " << item.first << ", Название: " << item.second.first.get_name()
            << ", Количество: " << item.second.second << ", Цена: " << item.second.first.get_price() << std::endl;
    }
}

Product Store::getProduct(int product_id) const {
    auto it = inventory.find(product_id);
    if (it == inventory.end()) {
        throw std::runtime_error("Товар с ID " + std::to_string(product_id) + " отсутствует в магазине.");
    }
    return it->second.first;
}
