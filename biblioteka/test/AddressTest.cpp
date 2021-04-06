//
// Created by student on 16.01.2020.
//
#include <boost/test/unit_test.hpp>
#include "Address.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteAddressCorrect)

    BOOST_AUTO_TEST_CASE(AddressCreationCase) {
        Address address("Test Street", "22a");
        BOOST_REQUIRE_EQUAL(address.getStreet(), "Test Street");
        BOOST_REQUIRE_EQUAL(address.getNumber(), "22a");
    }

    BOOST_AUTO_TEST_CASE(AddressChangeCase) {
        Address address("Test Street", "22a");
        BOOST_REQUIRE_EQUAL(address.getStreet(), "Test Street");
        BOOST_REQUIRE_EQUAL(address.getNumber(), "22a");
        address.setNumber("30f");
        address.setStreet("New Street");
        BOOST_REQUIRE_EQUAL(address.getStreet(), "New Street");
        BOOST_REQUIRE_EQUAL(address.getNumber(), "30f");
    }


BOOST_AUTO_TEST_SUITE_END()
