cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(SOURCE_FILES
        src/model/Item.cpp
        src/model/Client.cpp
        src/model/Address.cpp
        src/model/Order.cpp
        src/model/ClientType.cpp
        src/model/Company.cpp
        src/model/Device.cpp
        src/model/Individual.cpp
        src/model/Phone.cpp
        src/model/Laptop.cpp
        src/model/Tablet.cpp
        src/model/Service.cpp
        src/model/TechSupport.cpp
        src/model/Warranty.cpp
        src/model/ItemsManager.cpp
        src/model/OrdersManager.cpp
        src/model/ClientsManager.cpp
        src/model/RepositoryException.cpp
        src/model/ItemException.cpp
        src/model/ManagerException.cpp)
#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC
        include/model
        include
        )

enable_testing()

find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ItemTest.cpp
        test/AddressTest.cpp
        test/ClientTest.cpp
        test/OrderTest.cpp
        test/DeviceTest.cpp
        test/RepositoryTest.cpp
        test/IndividualTest.cpp
        test/CompanyTest.cpp
        test/PhoneTest.cpp
        test/LaptopTest.cpp
        test/TabletTest.cpp
        test/ItemsManagerTest.cpp
        test/ClientsManagerTest.cpp
        test/OrdersManagerTest.cpp
        test/WarrantyTest.cpp
        test/ServiceTest.cpp
        test/TechSupportTest.cpp)

add_executable(TestBibl ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries(TestBibl
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(TestBiblioteki1 TestBibl
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
