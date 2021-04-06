#include <boost/test/unit_test.hpp>

#include <model/Laptop.hpp>
#include "ItemException.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteLaptopCorrect)

    BOOST_AUTO_TEST_CASE(LaptopGettersAndInfoTestCase) {
        Laptop tablet1(20.01, "Samsung", 1.2, 2048, 4000, true);
        BOOST_CHECK_NO_THROW(Laptop tablet2(20.01, "Samsung", 1.2, 2048, 4000, true));
        BOOST_CHECK_THROW(Laptop tablet2(-20.01, "Samsung", 1.2, 2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Laptop tablet2(20.01, "Samsung", -1.2, 2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Laptop tablet2(20.01, "Samsung", 1.2, -2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Laptop tablet2(20.01, "Samsung", 1.2, 2048, -4000, true), ItemException);
        BOOST_REQUIRE_EQUAL(tablet1.getHasACdReader(), true);
    }


BOOST_AUTO_TEST_SUITE_END()