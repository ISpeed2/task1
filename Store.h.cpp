#ifndef STORE_H
#define STORE_H

#include <string>
#include <map>
#include "StockItem.h" // Включаем StockItem!

class Store {
private:
    std::string name;
    int id;
    std::string address;
    std::map<int, StockItem> inventory; // Используем StockItem!

public:
    Store(std::string name, int id, std::string address);
    std::string get_name() const;
    int get_id() const;
    std::string get_address() const;

    std::map<int, StockItem>& get_inventory(); // Возвращаем ссылку!

    void add_product(int product_id, const Product& product, int quantity);
    void remove_product(int product_id);
};

#endif
