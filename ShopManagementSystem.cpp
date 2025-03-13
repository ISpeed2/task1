#include "ShopManagementSystem.h"
#include <iostream>
#include <random>

void ShopManagementSystem::add_store(const Store& store) {
    stores.push_back(store);
}

void ShopManagementSystem::remove_store(int store_id) {
    stores.erase(std::remove_if(stores.begin(), stores.end(),
                                 [store_id](const Store& s) { return s.get_id() == store_id; }),
                 stores.end());
}

Store* ShopManagementSystem::get_store(int store_id) {
    for (auto& store : stores) {
        if (store.get_id() == store_id) {
            return &store;
        }
    }
    return nullptr;
}

std::vector<Store> ShopManagementSystem::get_all_stores() const {
    return stores;
}

Store* ShopManagementSystem::find_store_with_lowest_price(int product_id) {
    Store* cheapest_store = nullptr;
    double lowest_price = -1.0;

    for (auto& store : stores) {
        std::map<int, StockItem>& inventory = store.get_inventory();
        auto it = inventory.find(product_id);
        if (it != inventory.end()) {
            Product product = it->second.get_product();
            double price = product.get_price();

            if (cheapest_store == nullptr || price < lowest_price) {
                cheapest_store = &store;
                lowest_price = price;
            }
        }
    }

    return cheapest_store;
}

void ShopManagementSystem::run_simulation() {
    std::cout << "Запуск симуляции работы магазинов..." << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());

    for (auto& store : stores) {
        std::cout << "Симуляция для магазина \"" << store.get_name() << "\":" << std::endl;

        std::map<int, StockItem>& inventory = store.get_inventory();

        if (inventory.empty()) {
            std::cout << "  В магазине нет товаров." << std::endl;
            continue;
        }

        for (int i = 0; i < 5; ++i) {
            std::uniform_int_distribution<> distrib(0, inventory.size() - 1);
            int random_index = distrib(gen);

            auto it = inventory.begin();
            std::advance(it, random_index);

            int product_id = it->first;
            StockItem& item = it->second;
            Product product = item.get_product();
            int available_quantity = item.get_quantity();

            if (available_quantity > 0) {
                std::cout << "  Покупка: " << product.get_name() << std::endl;
                item.set_quantity(available_quantity - 1); // Correctly update quantity
            } else {
                std::cout << "  Попытка покупки: " << product.get_name() << " (нет в наличии)" << std::endl;
            }
        }
    }

    std::cout << "Симуляция завершена." << std::endl;
}
