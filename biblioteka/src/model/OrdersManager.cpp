//
// Created by student on 18.01.2020.
//

#include "OrdersManager.hpp"
#include "Order.hpp"
#include "Client.hpp"

void OrdersManager::finishOrder(const OrderSPtr &order) {
    currentOrders.remove(order);
    archiveOrders.create(order);
}

void OrdersManager::newOrder(const OrderSPtr &order) {
    currentOrders.create(order);
    order->getClient()->addOrder(order);
}

OrdersManager::OrdersManager() = default;

OrdersManager::~OrdersManager() = default;

OrderSPtr OrdersManager::findByID(boost::uuids::uuid id) {
    OrderSPtr order = currentOrders.find(id);
    if (order != nullptr)
        return order;
    else
        return archiveOrders.find(id);
}

const std::vector<OrderSPtr> &OrdersManager::getCurrentOrders() {
    return currentOrders.getAll();
}

const std::vector<OrderSPtr> &OrdersManager::getArchiveOrders() {
    return archiveOrders.getAll();
}

