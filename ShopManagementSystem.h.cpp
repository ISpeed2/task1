#ifndef SHOPMANAGEMENTSYSTEM_H
#define SHOPMANAGEMENTSYSTEM_H

#include <vector>
#include "Store.h"

class ShopManagementSystem {
private:
    std::vector<Store> stores;

public:
    ShopManagementSystem() = default;

    void add_store(const Store& store);
    void remove_store(int store_id);
    Store* get_store(int store_id);
    std::vector<Store> get_all_stores() const;

    Store* find_store_with_lowest_price(int product_id);

    void run_simulation();
};

#endif
