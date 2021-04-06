//
// Created by student on 18.01.2020.
//

#include "ItemsManager.hpp"

#include <utility>
#include "Item.hpp"

void ItemsManager::newItem(ItemSPtr item) {
    items.create(std::move(item));
}

void ItemsManager::removeItem(ItemSPtr item) {
    items.remove(std::move(item));
}

ItemsManager::ItemsManager() = default;

ItemsManager::~ItemsManager() = default;

void ItemsManager::updatePrice(boost::uuids::uuid id, double newPrice) {
    items.get(id)->setPrice(newPrice);
}

ItemSPtr ItemsManager::findByID(boost::uuids::uuid id) {
    return items.get(id);
}

const std::vector<ItemSPtr> &ItemsManager::getAllItems() {
    return items.getAll();
}
