//
// Created by student on 20.01.2020.
//
//
// Created by student on 20.01.2020.
//

#include <boost/test/unit_test.hpp>
#include "Service.hpp"
#include "ItemException.hpp"


BOOST_AUTO_TEST_SUITE(TestSuiteServiceCorrect)


    class ServiceTesting : public Service {
    public:
        explicit ServiceTesting(double price, int durationInDays) : Service(price, durationInDays) {};

        ~ServiceTesting() final = default;


    };

    BOOST_AUTO_TEST_CASE(ServiceCreationCase) {
        ServiceTesting serviceTesting(2000, 15);
        BOOST_CHECK_NO_THROW(ServiceTesting serviceTesting1(2000, 15));
        BOOST_CHECK_THROW(ServiceTesting serviceTesting2(-5, 15), ItemException);
        BOOST_CHECK_THROW(ServiceTesting serviceTesting2(5, -15), ItemException);
        BOOST_REQUIRE_EQUAL(serviceTesting.getPrice(), 30000);
        BOOST_REQUIRE_EQUAL(serviceTesting.getDurationInDays(), 15);
    }

    BOOST_AUTO_TEST_CASE(ServiceSetCaseCase) {
        ServiceTesting serviceTesting(10, 2);
        BOOST_CHECK_NO_THROW(serviceTesting.setPrice(5));
        BOOST_CHECK_THROW(serviceTesting.setPrice(-5), ItemException);
        serviceTesting.setPrice(5);
        BOOST_REQUIRE_EQUAL(serviceTesting.getPrice(), 10);

    }

BOOST_AUTO_TEST_SUITE_END()
