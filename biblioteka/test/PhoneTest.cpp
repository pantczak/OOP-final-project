#include <boost/test/unit_test.hpp>
#include <Phone.hpp>
#include "ItemException.hpp"

BOOST_AUTO_TEST_SUITE(TestSuitePhoneCorrect)

    BOOST_AUTO_TEST_CASE(PhoneGettersAndInfoCase) {
        Phone phone1(20.01, "Samsung", 1.2, 2048, 4000, true);
        BOOST_CHECK_NO_THROW(Phone phone2(20.01, "Samsung", 1.2, 2048, 4000, true));
        BOOST_CHECK_THROW(Phone phone2(-20.01, "Samsung", 1.2, 2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Phone phone2(20.01, "Samsung", 1.2, -2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Phone phone2(20.01, "Samsung", -1.2, 2048, 4000, true), ItemException);
        BOOST_CHECK_THROW(Phone phone2(20.01, "Samsung", 1.2, 2048, -4000, true), ItemException);
        BOOST_REQUIRE_EQUAL(phone1.isCompatibleWith5G(), true);
    }


BOOST_AUTO_TEST_SUITE_END()