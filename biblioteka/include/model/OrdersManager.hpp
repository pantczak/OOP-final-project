//
// Created by student on 18.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_ORDERSMANAGER_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_ORDERSMANAGER_HPP

#include <memory>
#include "Repository.hpp"

class Order;

typedef std::shared_ptr<Order> OrderSPtr;

class OrdersManager {
    Repository<Order> currentOrders;
    Repository<Order> archiveOrders;
public:
    void newOrder(const OrderSPtr &order);

    void finishOrder(const OrderSPtr &order);

    OrdersManager();

    virtual ~OrdersManager();

    OrderSPtr findByID(boost::uuids::uuid id);

    const std::vector<OrderSPtr> &getCurrentOrders();

    const std::vector<OrderSPtr> &getArchiveOrders();


};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_ORDERSMANAGER_HPP
