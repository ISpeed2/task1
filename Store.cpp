#include "Store.h"

Store::Store(std::string name, int id, std::string address) : name(name), id(id), address(address) {}

std::string Store::get_name() const {
    return name;
}

int Store::get_id() const {
    return id;
}

std::string Store::get_address() const {
    return address;
}

std::map<int, StockItem>& Store::get_inventory() {
    return inventory;
}

void Store::add_product(int product_id, const Product& product, int quantity) {
    inventory[product_id] = StockItem(product, quantity);
}

void Store::remove_product(int product_id) {
    inventory.erase(product_id);
}
