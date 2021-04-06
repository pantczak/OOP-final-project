//
// Created by student on 20.01.2020.
//

#include <boost/test/unit_test.hpp>
#include "TechSupport.hpp"
#include "ItemException.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteTechSupportCorrect)


    BOOST_AUTO_TEST_CASE(TechSupportCase) {
        TechSupport techSupport(2000, 15, true, true);
        BOOST_CHECK_NO_THROW(TechSupport techSupport1(2000, 15, true, true));
        BOOST_CHECK_THROW(TechSupport techSupport2(-5, 15, true, true), ItemException);
        BOOST_CHECK_THROW(TechSupport techSupport2(5, -15, true, true), ItemException);
        BOOST_REQUIRE_EQUAL(techSupport.getDoorToDoor(), true);
        BOOST_REQUIRE_EQUAL(techSupport.getCallAnyTime(), true);
        BOOST_REQUIRE_EQUAL(techSupport.getPrice(), 30000);
        BOOST_REQUIRE_EQUAL(techSupport.getDurationInDays(), 15);
    }

    BOOST_AUTO_TEST_CASE(TechSupportSetCaseCase) {
        TechSupport techSupport(2000, 15, true, true);
        BOOST_CHECK_NO_THROW(techSupport.setPrice(5));
        BOOST_CHECK_THROW(techSupport.setPrice(-5), ItemException);
        techSupport.setPrice(5);
        BOOST_REQUIRE_EQUAL(techSupport.getPrice(), 75);
    }

BOOST_AUTO_TEST_SUITE_END()