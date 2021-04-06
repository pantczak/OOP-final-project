#include <boost/test/unit_test.hpp>
#include <Item.hpp>
#include <boost/uuid/uuid_serialize.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteItemCorrect)

    class ItemTesting : public Item {
    public:
        explicit ItemTesting(double price) : Item(price) {};

        ~ItemTesting() final = default;

        std::string itemInfo() final {
            return Item::itemInfo();
        }
    };

    double tolerance = 0.000001;

    BOOST_AUTO_TEST_CASE(ItemPriceTestCase) {
        ItemTesting item1(20.005);
        ItemTesting item2(20.000001);
        ItemTesting item3(20.551);
        ItemTesting item4(20.991);
        ItemTesting item5(20.0949999);

        BOOST_REQUIRE_CLOSE(item1.getPrice(), 20.01, tolerance);
        BOOST_REQUIRE_CLOSE(item2.getPrice(), 20.00, tolerance);
        BOOST_REQUIRE_CLOSE(item3.getPrice(), 20.55, tolerance);
        BOOST_REQUIRE_CLOSE(item4.getPrice(), 20.99, tolerance);
        BOOST_REQUIRE_CLOSE(item5.getPrice(), 20.09, tolerance);

        item1.setPrice(30.001);
        item2.setPrice(30.21);
        item3.setPrice(100.1);
        item4.setPrice(30);
        item5.setPrice(24.99999);

        BOOST_REQUIRE_CLOSE(item1.getPrice(), 30.00, tolerance);
        BOOST_REQUIRE_CLOSE(item2.getPrice(), 30.21, tolerance);
        BOOST_REQUIRE_CLOSE(item3.getPrice(), 100.10, tolerance);
        BOOST_REQUIRE_CLOSE(item4.getPrice(), 30.00, tolerance);
        BOOST_REQUIRE_CLOSE(item5.getPrice(), 25.00, tolerance);
    }

BOOST_AUTO_TEST_SUITE_END()