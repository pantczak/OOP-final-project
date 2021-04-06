//
// Created by student on 17.01.2020.
//

#include "Company.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteCompanyCorrect)

    BOOST_AUTO_TEST_CASE(ComapnyTestCase) {
        Company company;
        BOOST_REQUIRE_EQUAL(company.discount(2000, 1), 0.05);
        BOOST_REQUIRE_EQUAL(company.discount(5000, 3), 0.05);
        BOOST_REQUIRE_EQUAL(company.discount(5000, 6), 0.15);
        BOOST_REQUIRE_EQUAL(company.discount(9000, 6), 0.15);
        BOOST_REQUIRE_EQUAL(company.discount(9000, 11), 0.2);
    }


BOOST_AUTO_TEST_SUITE_END()