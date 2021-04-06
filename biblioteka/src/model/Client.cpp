//
// Created by student on 16.01.2020.
//

#include <sstream>
#include "Client.hpp"
#include "Order.hpp"
#include "Individual.hpp"
#include "Company.hpp"

//Client::Client(const std::string &firstName, const std::string &lastName, const std::string &id, Address address,
//               const Address &registeredAddress) : firstName(firstName), lastName(lastName), ID(id), address(address),
//                                                   registeredAddress(registeredAddress) {}

Client::~Client() {

}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

void Client::setFirstName(const std::string &newFirstName) {
    Client::firstName = newFirstName;
}

void Client::setLastName(const std::string &newLastName) {
    Client::lastName = newLastName;

}

std::string Client::clientInfo(bool Cinfo) {
    std::stringstream str;

    if (Cinfo)
        str << "Client: " << firstName << " " << lastName << " " << ID << ", "
            << "Registered address: " << registeredAddress.getStreet() << " " << registeredAddress.getNumber()
            << ", Address: " << address.getStreet() << " " << address.getNumber() << "\n ";

    if (Cinfo)
    {
        if (orders.empty()) str << "   Client has no orders" << "\n";
        else {
            for (const auto &it: orders)
            {
                str << "   " << it->orderInfo() << "\n";
            }
        }
    }
    return str.str() + "\n";
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &addressStreet,
               const std::string &addressNumber,
               const std::string &registeredAddressStreet,
               const std::string &registeredAddressNumber) : firstName(firstName), lastName(lastName),
                                                             ID(boost::uuids::random_generator()()),
                                                             address(addressStreet, addressNumber),
                                                             registeredAddress(registeredAddressStreet,
                                                                               registeredAddressNumber) {
    clientType = ClientTypeSPtr(new Individual);
}

const Address &Client::getAddress() const {
    return address;
}

const Address &Client::getRegisteredAddress() const {
    return registeredAddress;
}

void Client::setAddress(const std::string &street, const std::string &number) {
    address.setStreet(street);
    address.setNumber(number);
}

void Client::setRegisteredAddress(const std::string &street, const std::string &number) {
    registeredAddress.setStreet(street);
    registeredAddress.setNumber(number);
}

void Client::addOrder(const OrderSPtr &order) {
    orders.push_back(order);
}

void Client::removeOrder(const OrderSPtr &orderToRemove) {
    for (std::size_t i = 0; i < orders.size(); i++)
    {
        if (orderToRemove == orders[i])
        {
            orders.erase(orders.begin() + i);
        }

    }
}

double Client::calculateDiscount(double price, int numberOfOrders) {
    return clientType->discount(price, numberOfOrders);
}

const boost::uuids::uuid &Client::getId() const {
    return ID;
}

int Client::numberOfOrders() {
    return orders.size();
}

void Client::setClientType(int numOfOrders) {

    if (numOfOrders <= 5) clientType = ClientTypeSPtr(new Individual);
    else clientType = ClientTypeSPtr(new Company);
}

std::vector<OrderSPtr> &Client::getOrders() {
    return orders;
}

Client &Client::operator=(const Client &rhs) {
    firstName = rhs.getFirstName();
    lastName = rhs.getLastName();
    address = rhs.getAddress();
    registeredAddress = rhs.getRegisteredAddress();

    return *this;
}

bool operator==(const Client &lhs, const Client &rhs) {
    return (lhs.getFirstName() == rhs.getFirstName() && lhs.getLastName() == rhs.getLastName() &&
            lhs.getAddress() == rhs.getAddress() && lhs.getRegisteredAddress() == rhs.getRegisteredAddress());
}









