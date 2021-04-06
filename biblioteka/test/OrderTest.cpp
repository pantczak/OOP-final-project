//
// Created by student on 16.01.2020.
//
#include <boost/test/unit_test.hpp>
#include <model/Phone.hpp>
#include "Client.hpp"
#include "Address.hpp"
#include "Order.hpp"
#include "Item.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteOrderCorrect)

    BOOST_AUTO_TEST_CASE(OrderCreationCase) {
        ClientSPtr clientSPtr(new Client("SampleName", "SampleSurname", "SampleStreet", "22a", "Rest Street", "21g"));
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        Order order(clientSPtr, phone);
        BOOST_REQUIRE_EQUAL(order.getClient(), clientSPtr);
        BOOST_REQUIRE_EQUAL(order.getItem(), phone);
    }

    BOOST_AUTO_TEST_CASE(OrderPriceCase) {
        ClientSPtr client(new Client("SampleName", "SampleSurname", "SampleStreet", "22a", "Rest Street", "21g"));
        std::shared_ptr<Phone> phone(new Phone(2000, "Huawei", 2, 2048, 3200, true));
        OrderSPtr order(new Order(client, phone));
        OrderSPtr order1(new Order(client, phone));
        OrderSPtr order2(new Order(client, phone));
        client->addOrder(order);
        client->addOrder(order1);
        client->addOrder(order2);
        OrderSPtr order3(new Order(client, phone));

        client->addOrder(order3);
        BOOST_REQUIRE_EQUAL(order3->getFinalPrice(), 1900);
    }

BOOST_AUTO_TEST_SUITE_END()
