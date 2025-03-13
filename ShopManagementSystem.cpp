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
            return &store; // Возвращаем указатель на найденный магазин
        }
    }
    return nullptr; // Магазин не найден
}

std::vector<Store> ShopManagementSystem::get_all_stores() const {
    return stores;
}

void ShopManagementSystem::run_simulation() {
    std::cout << "Запуск симуляции работы магазинов..." << std::endl;

    // Создаем генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    // Проходим по всем магазинам и имитируем продажи
    for (auto& store : stores) {
        std::cout << "Симуляция для магазина \"" << store.get_name() << "\":" << std::endl;

        // Получаем inventory магазина
        std::map<int, std::pair<Product, int>>& inventory = store.get_inventory();

        // Если inventory пустой, пропускаем магазин
        if (inventory.empty()) {
            std::cout << "  В магазине нет товаров." << std::endl;
            continue;
        }

        // Имитируем несколько покупок (например, 5)
        for (int i = 0; i < 5; ++i) {
            // Выбираем случайный товар из inventory
            std::uniform_int_distribution<> distrib(0, inventory.size() - 1);
            int random_index = distrib(gen);

            // Получаем итератор на случайный элемент
            auto it = inventory.begin();
            std::advance(it, random_index);

            int product_id = it->first;
            Product product = it->second.first;
            int available_quantity = it->second.second;

            // Имитируем покупку 1 единицы товара (если он есть в наличии)
            if (available_quantity > 0) {
                std::cout << "  Покупка: " << product.get_name() << std::endl;
                inventory[product_id].second--; // Уменьшаем количество товара в inventory
            } else {
                std::cout << "  Попытка покупки: " << product.get_name() << " (нет в наличии)" << std::endl;
            }
        }
    }

    std::cout << "Симуляция завершена." << std::endl;
}
