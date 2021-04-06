#include <boost/test/unit_test.hpp>
#include <model/Tablet.hpp>
#include "ItemException.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteTabletCorrect)

    BOOST_AUTO_TEST_CASE(TabletGettersAndTestCase) {
        Tablet tablet1(20.01, "Samsung", 1.2, 2048, 4000, true);
        BOOST_CHECK_NO_THROW(Tablet tablet2(20.01, "Samsung", 1.2, 2048, 4000, true));
        BOOST_CHECK_THROW(Tablet tablet2(-20.01, "Samsung", 1.2, 2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Tablet tablet2(20.01, "Samsung", -1.2, 2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Tablet tablet2(20.01, "Samsung", 1.2, -2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Tablet tablet2(20.01, "Samsung", 1.2, 2048, -4000, true), ItemException);
        BOOST_REQUIRE_EQUAL(tablet1.getHasAStylus(), true);
    }

BOOST_AUTO_TEST_SUITE_END()