//
// Created by student on 16.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENT_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENT_HPP


#include <string>
#include <memory>
#include <vector>
#include "Address.hpp"
#include <boost/uuid/uuid.hpp>

class Order;

typedef std::shared_ptr<Order> OrderSPtr;

class ClientType;

typedef std::shared_ptr<ClientType> ClientTypeSPtr;

class Client {
    std::string firstName;
    std::string lastName;
    boost::uuids::uuid ID;
    Address address;
    Address registeredAddress;
    std::vector<OrderSPtr> orders;
    ClientTypeSPtr clientType;

public:
    Client(const std::string &firstName, const std::string &lastName,
           const std::string &addressStreet, const std::string &addressNumber,
           const std::string &registeredAddressStreet, const std::string &registeredAddressNumber);

    virtual ~Client();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const boost::uuids::uuid &getId() const;

    void setFirstName(const std::string &newFirstName);

    void setLastName(const std::string &newLastName);

    void setAddress(const std::string &street, const std::string &number);

    void setRegisteredAddress(const std::string &street, const std::string &number);

    std::string clientInfo(bool isClient = true);

    const Address &getAddress() const;

    const Address &getRegisteredAddress() const;

    void addOrder(const OrderSPtr &order);

    void removeOrder(const OrderSPtr &orderToRemove);

    void setClientType(int numOfOrders);

    double calculateDiscount(double price, int numberOfOrders);

    int numberOfOrders();

    std::vector<OrderSPtr> &getOrders();


    Client &operator=(const Client &rhs);

};


bool operator==(const Client &lhs, const Client &rhs);


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENT_HPP
