//
// Created by student on 18.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_ITEMSMANAGER_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_ITEMSMANAGER_HPP

#include "Repository.hpp"
#include <memory>

class Item;

class Phone;

class Tablet;

class Laptop;

class TechSupport;

class Warranty;

typedef std::shared_ptr<Item> ItemSPtr;

class ItemsManager {
    Repository<Item> items;

public:
    ItemsManager();

    virtual ~ItemsManager();

    void newItem(ItemSPtr item);

    void removeItem(ItemSPtr item);

    void updatePrice(boost::uuids::uuid id, double newPrice);

    ItemSPtr findByID(boost::uuids::uuid id);

    const std::vector<ItemSPtr> &getAllItems();

};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_ITEMSMANAGER_HPP
