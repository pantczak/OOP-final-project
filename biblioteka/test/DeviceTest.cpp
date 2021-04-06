#include <boost/test/unit_test.hpp>
#include <Device.hpp>
#include "ItemException.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteDeviceCorrect)

    class DeviceTesting : public Device {
    public:
        DeviceTesting(double price, const std::string &brand, double weight, int memorySizeInMb, int batteryCapacity)
                : Device(price, brand, weight, memorySizeInMb, batteryCapacity) {}

        ~DeviceTesting() final = default;

        std::string itemInfo() final {
            return Device::itemInfo();
        }
    };

    double tolerance = 0.000001;

    BOOST_AUTO_TEST_CASE(DiviceGettersTestCase) {
        DeviceTesting device1(20.01, "Samsung", 1.2, 2048, 4000);
        BOOST_CHECK_NO_THROW(DeviceTesting device2(20.01, "Samsung", 1.2, 2048, 4000));
        BOOST_CHECK_THROW(DeviceTesting device2(-20.01, "Samsung", 1.2, 2048, 4000), ItemException);
        BOOST_CHECK_THROW(DeviceTesting device2(20.01, "Samsung", -1.2, 2048, 4000), ItemException);
        BOOST_CHECK_THROW(DeviceTesting device2(20.01, "Samsung", 1.2, 2048, -4000), ItemException);
        BOOST_CHECK_THROW(DeviceTesting device2(20.01, "Samsung", 1.2, -2048, 4000), ItemException);

        BOOST_REQUIRE_EQUAL(device1.getBrand(), "Samsung");
        BOOST_REQUIRE_CLOSE(device1.getWeight(), 1.2, tolerance);
        BOOST_REQUIRE_EQUAL(device1.getMemorySizeInMb(), 2048);
        BOOST_REQUIRE_EQUAL(device1.getBatteryCapacity(), 4000);

        DeviceTesting device2(20.11, "Lenovo", 1.295, 512, 2100);
        BOOST_REQUIRE_EQUAL(device2.getBrand(), "Lenovo");
        BOOST_REQUIRE_CLOSE(device2.getWeight(), 1.3, tolerance);
        BOOST_REQUIRE_EQUAL(device2.getMemorySizeInMb(), 512);
        BOOST_REQUIRE_EQUAL(device2.getBatteryCapacity(), 2100);

        DeviceTesting device3(20.01, "Xiaomi", 0.05, 1512, 2122);
        BOOST_REQUIRE_EQUAL(device3.getBrand(), "Xiaomi");
        BOOST_REQUIRE_CLOSE(device3.getWeight(), 0.1, tolerance);
        BOOST_REQUIRE_EQUAL(device3.getMemorySizeInMb(), 1512);
        BOOST_REQUIRE_EQUAL(device3.getBatteryCapacity(), 2122);

        DeviceTesting device4(20.01, "Samsung", 10.0002, 1000, 1000);
        BOOST_REQUIRE_EQUAL(device4.getBrand(), "Samsung");
        BOOST_REQUIRE_CLOSE(device4.getWeight(), 10.0, tolerance);
        BOOST_REQUIRE_EQUAL(device4.getMemorySizeInMb(), 1000);
        BOOST_REQUIRE_EQUAL(device4.getBatteryCapacity(), 1000);

    }

BOOST_AUTO_TEST_SUITE_END()