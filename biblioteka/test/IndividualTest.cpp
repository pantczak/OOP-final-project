//
// Created by student on 17.01.2020.
//
#include "Individual.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteIndividualCorrect)

    BOOST_AUTO_TEST_CASE(IndividualTestCase) {
        Individual individual;
        BOOST_REQUIRE_EQUAL(individual.discount(4000, 3), 0);
        BOOST_REQUIRE_EQUAL(individual.discount(6000, 3), 0.05);
        BOOST_REQUIRE_EQUAL(individual.discount(6000, 6), 0.05);
        BOOST_REQUIRE_EQUAL(individual.discount(20000, 16), 0.1);
        BOOST_REQUIRE_EQUAL(individual.discount(20000, 6), 0.05);
    }


BOOST_AUTO_TEST_SUITE_END()
