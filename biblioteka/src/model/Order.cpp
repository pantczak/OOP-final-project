//
// Created by student on 16.01.2020.
//

#include "Order.hpp"
#include "Client.hpp"
#include "Item.hpp"

Order::Order(const ClientSPtr &client, const ItemSPtr &item)
        : client(client), item(item), ID(boost::uuids::random_generator()()),
          order_date_time(boost::posix_time::second_clock::local_time(),
                          boost::local_time::time_zone_ptr(new boost::local_time::posix_time_zone("CET+1"))) {
}

Order::~Order() {

}

std::string Order::orderInfo() {
    std::stringstream str;
    str << "Order ID: " << boost::uuids::to_string(ID) << ", order price: " << finalPrice
        << ", order date: " << order_date_time.date()
        << "    " << client->clientInfo(false) << "    " << item->itemInfo();
    return str.str();
}

ClientSPtr Order::getClient() {
    return client;
}

ItemSPtr Order::getItem() {
    return item;
}

const boost::uuids::uuid &Order::getId() const {
    return ID;
}

double Order::calculateFinalPrice() {
    double tmp = 0;
    for (auto it : client->getOrders())
    {
        tmp += it->getItem()->getPrice();
    }
    return (item->getPrice() - (item->getPrice() * client->calculateDiscount(tmp, client->numberOfOrders())));
}

double Order::getFinalPrice() const {
    return finalPrice;
}

bool operator==(const Order &lhs, const Order &rhs) {
    return (lhs.getId() == rhs.getId());
}
