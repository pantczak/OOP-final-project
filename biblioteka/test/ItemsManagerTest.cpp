//
// Created by student on 18.01.2020.
//
#include "ItemsManager.hpp"
#include "ItemException.hpp"
#include "Phone.hpp"
#include "Item.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid.hpp>


BOOST_AUTO_TEST_SUITE(TestSuiteItemsManagerCorrect)

    BOOST_AUTO_TEST_CASE(ItemsManagerAddCase) {
        ItemsManager itemsManager;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        itemsManager.newItem(phone);
        BOOST_REQUIRE_EQUAL(itemsManager.getAllItems().size(), 1);
        std::shared_ptr<Phone> phone1(new Phone(200, "Lenovo", 2, 2048, 3200, true));
        itemsManager.newItem(phone1);
        BOOST_REQUIRE_EQUAL(itemsManager.getAllItems().size(), 2);
    }

    BOOST_AUTO_TEST_CASE(ItemsManagerDeleteCase) {
        ItemsManager itemsManager;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        std::shared_ptr<Phone> phone1(new Phone(200, "Sony", 2, 2048, 3200, true));
        itemsManager.newItem(phone);
        itemsManager.newItem(phone1);
        BOOST_REQUIRE_EQUAL(itemsManager.getAllItems().size(), 2);
        itemsManager.removeItem(phone);
        BOOST_REQUIRE_EQUAL(itemsManager.getAllItems().size(), 1);
        itemsManager.removeItem(phone1);
        BOOST_REQUIRE_EQUAL(itemsManager.getAllItems().size(), 0);
    }

    BOOST_AUTO_TEST_CASE(ItemsManagerUpdatePriceCase) {
        ItemsManager itemsManager;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        itemsManager.newItem(phone);
        itemsManager.updatePrice(phone->getId(), 400);
        BOOST_REQUIRE_EQUAL(itemsManager.findByID(phone->getId())->getPrice(), 400.00);
        itemsManager.updatePrice(phone->getId(), 10.004);
        BOOST_REQUIRE_EQUAL(itemsManager.findByID(phone->getId())->getPrice(), 10.00);
        BOOST_REQUIRE_THROW(itemsManager.updatePrice(phone->getId(), 0), ItemException);
    }

    BOOST_AUTO_TEST_CASE(ItemsManagerGetAllItemCase) {
        ItemsManager itemsManager;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        std::shared_ptr<Phone> phone1(new Phone(200, "Sony", 2, 2048, 3200, true));
        itemsManager.newItem(phone);
        itemsManager.newItem(phone1);
        BOOST_REQUIRE(itemsManager.getAllItems()[0]->getId() == phone->getId());
        BOOST_REQUIRE(itemsManager.getAllItems()[1]->getId() == phone1->getId());
    }


BOOST_AUTO_TEST_SUITE_END()