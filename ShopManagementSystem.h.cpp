#ifndef SHOPMANAGEMENTSYSTEM_H
#define SHOPMANAGEMENTSYSTEM_H

#include <vector>
#include "Store.h" // Убедитесь, что путь к файлу Store.h правильный

class ShopManagementSystem {
private:
    std::vector<Store> stores;

public:
    ShopManagementSystem() = default; // Конструктор по умолчанию

    // Методы для управления магазинами
    void add_store(const Store& store);
    void remove_store(int store_id);
    Store* get_store(int store_id); // Возвращает указатель на магазин
    std::vector<Store> get_all_stores() const;

    // Симуляция
    void run_simulation();
};

#endif
