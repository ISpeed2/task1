#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    std::string name;
    std::string description;
    int id;
    double price;

public:
    Product(std::string name, std::string description, int id, double price);

    std::string get_name() const;
    std::string get_description() const;
    int get_id() const;
    double get_price() const;
    void set_price(double price);

    void print_info() const;
};

#endif