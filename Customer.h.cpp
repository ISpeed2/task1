#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <map>

class Customer {
private:
    std::string name;
    double balance;
    std::map<int, int> shopping_list;

public:
    Customer(std::string name, double balance); // Изменен конструктор!

    std::string get_name() const;
    double get_balance() const;
    void set_balance(double balance);
    std::map<int, int> get_shopping_list() const;

    void add_to_shopping_list(int product_id, int quantity);
    void remove_from_shopping_list(int product_id);
    void make_purchase(double amount);

    void print_info() const; // Функция для вывода информации
};

#endif
