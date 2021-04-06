//
// Created by student on 16.01.2020.
//

#include "Address.hpp"

Address::Address(const std::string &street, const std::string &number) : street(street), number(number) {}

const std::string &Address::getStreet() const {
    return street;
}

const std::string &Address::getNumber() const {
    return number;
}

void Address::setStreet(const std::string &newStreet) {
    Address::street = newStreet;
}

void Address::setNumber(const std::string &newNumber) {
    Address::number = newNumber;
}

Address::~Address() {

}

Address &Address::operator=(const Address &rhs) {
    street = rhs.getStreet();
    number = rhs.getNumber();

    return *this;
}

bool operator==(const Address &lhs, const Address &rhs) {
    return (lhs.getStreet() == rhs.getStreet() && lhs.getNumber() == rhs.getNumber());
}
