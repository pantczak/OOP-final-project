//
// Created by student on 20.01.2020.
//

#include <boost/test/unit_test.hpp>
#include "Warranty.hpp"
#include "ItemException.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteWarrarntyCorrect)

    BOOST_AUTO_TEST_CASE(TechSuportCreationCase) {
        Warranty warranty(2000, 15, true, 15);
        BOOST_CHECK_NO_THROW(Warranty warranty1(2000, 15, true, 15));
        BOOST_CHECK_THROW(Warranty warranty1(-5, 15, true, true), ItemException);
        BOOST_CHECK_THROW(Warranty warranty1(5, -15, true, true), ItemException);
        BOOST_CHECK_THROW(Warranty warranty1(5, -15, true, -15), ItemException);
        BOOST_REQUIRE_EQUAL(warranty.getWaterDamage(), true);
        BOOST_REQUIRE_EQUAL(warranty.getMaxCoverage(), 15);
        BOOST_REQUIRE_EQUAL(warranty.getPrice(), 30000);
        BOOST_REQUIRE_EQUAL(warranty.getDurationInDays(), 15);
    }

    BOOST_AUTO_TEST_CASE(WarrantySetCaseCase) {
        Warranty warranty(10, 2, true, true);
        BOOST_CHECK_NO_THROW(warranty.setPrice(5));
        BOOST_CHECK_THROW(warranty.setPrice(-5), ItemException);
        warranty.setPrice(5);
        BOOST_REQUIRE_EQUAL(warranty.getPrice(), 10);
    }


BOOST_AUTO_TEST_SUITE_END()