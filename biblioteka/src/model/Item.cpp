#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Item.hpp"
#include "ItemException.hpp"

Item::Item(double price) : ID(boost::uuids::random_generator()()) {
    setPrice(price);
}


Item::~Item() = default;

double Item::getPrice() const {
    return price;
}

void Item::setPrice(double newPrice) {
    newPrice = roundDoubleToPowerOfTen(newPrice, -2);
    if (newPrice <= 0.00)
        throw ItemException("Price cannot be set to 0.00 or negative, provided: " + std::to_string(newPrice));
    else
        price = newPrice;
}

std::string Item::itemInfo() {
    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(2);
    //stringStream << "ID: " << getId() << ", ";
    stringStream << "price: " << price << " PLN";
    return stringStream.str();
}

double Item::roundDoubleToPowerOfTen(double value, int exponent) {
    double helper = std::pow(10, exponent * -1);
    return floor(value * helper + 0.5) / helper;
}

const boost::uuids::uuid &Item::getId() const {
    return ID;
}

