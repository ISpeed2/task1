#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    std::string description;
    double price;

public:
    Product(std::string name, std::string description, double price);

    std::string get_name() const;
    std::string get_description() const;
    double get_price() const;
};

#endif
