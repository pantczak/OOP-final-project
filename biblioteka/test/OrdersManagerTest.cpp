#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid.hpp>
#include <model/OrdersManager.hpp>
#include <model/Phone.hpp>
#include "Order.hpp"
#include "Client.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteOrdersManagerCorrect)


    BOOST_AUTO_TEST_CASE(ItemsManagerNewRemoveGetCase) {
        OrdersManager ordersManager;
        ItemSPtr phone = std::make_shared<Phone>(200, "Huawei", 2, 2048, 3200, true);
        ClientSPtr client = std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A");

        OrderSPtr order = std::make_shared<Order>(client, phone);
        ordersManager.newOrder(order);
        BOOST_REQUIRE_EQUAL(ordersManager.getArchiveOrders().size(), 0);
        BOOST_REQUIRE_EQUAL(ordersManager.getCurrentOrders().size(), 1);

        ordersManager.finishOrder(order);

        BOOST_REQUIRE_EQUAL(ordersManager.getArchiveOrders().size(), 1);
        BOOST_REQUIRE_EQUAL(ordersManager.getCurrentOrders().size(), 0);
    }

    BOOST_AUTO_TEST_CASE(ItemsManagerGetByIdCase) {
        OrdersManager ordersManager;
        ItemSPtr phone = std::make_shared<Phone>(200, "Huawei", 2, 2048, 3200, true);
        ClientSPtr client = std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A");

        OrderSPtr order = std::make_shared<Order>(client, phone);
        ordersManager.newOrder(order);


        BOOST_REQUIRE(
                ordersManager.findByID(order->getId())->getClient().operator*() == order->getClient().operator*());

    }


BOOST_AUTO_TEST_SUITE_END()