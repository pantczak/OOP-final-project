//
// Created by student on 16.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_ADDRESS_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_ADDRESS_HPP


#include <string>

class Address {
    std::string street;
    std::string number;
public:
    Address(const std::string &street, const std::string &number);

    virtual ~Address();

    const std::string &getStreet() const;

    const std::string &getNumber() const;

    void setStreet(const std::string &newStreet);

    void setNumber(const std::string &newNumber);

    Address &operator=(const Address &rhs);
};

bool operator==(const Address &lhs, const Address &rhs);


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_ADDRESS_HPP
