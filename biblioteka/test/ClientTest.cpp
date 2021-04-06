//
// Created by student on 16.01.2020.
//
#include <boost/test/unit_test.hpp>
#include <model/Phone.hpp>
#include "Client.hpp"
#include "Address.hpp"
#include "Order.hpp"
#include "Item.hpp"
#include "Device.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteClientCorrect)

    BOOST_AUTO_TEST_CASE(ClientCreationCase) {
        Client klient("SampleName", "SampleSurname", "SampleStreet", "22a", "Rest Street", "21g");
        BOOST_REQUIRE_EQUAL(klient.getLastName(), "SampleSurname");
        BOOST_REQUIRE_EQUAL(klient.getFirstName(), "SampleName");
        klient.setFirstName("Adam");
        klient.setLastName("Dobry");
        BOOST_REQUIRE_EQUAL(klient.getFirstName(), "Adam");
        BOOST_REQUIRE_EQUAL(klient.getLastName(), "Dobry");
        BOOST_REQUIRE_EQUAL(klient.getAddress().getStreet(), "SampleStreet");
        BOOST_REQUIRE_EQUAL(klient.getRegisteredAddress().getStreet(), "Rest Street");
        BOOST_REQUIRE_EQUAL(klient.getAddress().getNumber(), "22a");
        BOOST_REQUIRE_EQUAL(klient.getRegisteredAddress().getNumber(), "21g");

    }

    BOOST_AUTO_TEST_CASE(ClientAddressChangeCase) {
        Client klient("SampleName", "SampleSurname", "SampleStreet", "22a", "Rest Street", "21g");
        klient.setAddress("Super Street", "73");
        klient.setRegisteredAddress("ULTRA Street", "12");
        BOOST_REQUIRE_EQUAL(klient.getAddress().getStreet(), "Super Street");
        BOOST_REQUIRE_EQUAL(klient.getRegisteredAddress().getStreet(), "ULTRA Street");
        BOOST_REQUIRE_EQUAL(klient.getAddress().getNumber(), "73");
        BOOST_REQUIRE_EQUAL(klient.getRegisteredAddress().getNumber(), "12");
    }

    BOOST_AUTO_TEST_CASE(ClientOrderAddDeleteCase) {
        ClientSPtr clientSPtr(new Client("SampleName", "SampleSurname", "SampleStreet", "22a", "Rest Street", "21g"));
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        OrderSPtr order(new Order(clientSPtr, phone));
        clientSPtr->addOrder(order);
        BOOST_REQUIRE_EQUAL(clientSPtr->numberOfOrders(), 1);
        clientSPtr->removeOrder(order);
        BOOST_REQUIRE_EQUAL(clientSPtr->numberOfOrders(), 0);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeTestCase) {
        ClientSPtr client(new Client("SampleName", "SampleSurname", "SampleStreet", "22a", "Rest Street", "21g"));
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        OrderSPtr order(new Order(client, phone));
        client->addOrder(order);
        BOOST_REQUIRE_EQUAL(order->getFinalPrice(), 200);
        BOOST_REQUIRE_EQUAL(client->calculateDiscount(20000, 5), 0.05);

        client->setClientType(100);
        OrderSPtr order1(new Order(client, phone));
        client->addOrder(order1);
        BOOST_REQUIRE_EQUAL(order1->getFinalPrice(), 190);
        BOOST_REQUIRE_EQUAL(client->calculateDiscount(20000, 6), 0.15);

    }

BOOST_AUTO_TEST_SUITE_END()
