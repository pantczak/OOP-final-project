//
// Created by student on 16.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_ORDER_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_ORDER_HPP


#include <string>
#include <vector>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

class Client;

typedef std::shared_ptr<Client> ClientSPtr;

class Item;

typedef std::shared_ptr<Item> ItemSPtr;

class Order {
    ClientSPtr client;
    ItemSPtr item;
    boost::uuids::uuid ID;
    double finalPrice = calculateFinalPrice();
    boost::local_time::local_date_time order_date_time;

    double calculateFinalPrice();

public:
    Order(const ClientSPtr &client, const ItemSPtr &item);

    virtual ~Order();

    std::string orderInfo();

    ClientSPtr getClient();

    ItemSPtr getItem();

    double getFinalPrice() const;

    const boost::uuids::uuid &getId() const;


};

bool operator==(const Order &lhs, const Order &rhs);

#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_ORDER_HPP
