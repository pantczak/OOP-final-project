//
// Created by student on 18.01.2020.
//
#include <boost/test/unit_test.hpp>
#include <model/Client.hpp>
#include <model/Phone.hpp>
#include "Repository.hpp"
#include "Order.hpp"

BOOST_AUTO_TEST_SUITE(TestSuiteRepositoryCorrect)

    BOOST_AUTO_TEST_CASE(RepoCreationCase) {
        BOOST_CHECK_NO_THROW(Repository<Phone> phones);
    }

    BOOST_AUTO_TEST_CASE(RepoAddExcceptionCase) {
        Repository<Phone> phones;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        phones.create(phone);
        //TODO check exception
    }

    BOOST_AUTO_TEST_CASE(RepoRemoveCase) {
        Repository<Phone> phones;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        phones.create(phone);
        BOOST_CHECK_NO_THROW(phones.remove(phone));
        BOOST_CHECK_THROW(phones.remove(phone), RepositoryException);

    }

    BOOST_AUTO_TEST_CASE(RepoFindCase) {
        Repository<Phone> phones;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        phones.create(phone);
        boost::uuids::uuid ID = phone->getId();
        BOOST_CHECK_EQUAL(phones.find(ID), phone);

    }

    BOOST_AUTO_TEST_CASE(RepoGetAllCase) {
        Repository<Phone> phones;
        std::shared_ptr<Phone> phone(new Phone(200, "Huawei", 2, 2048, 3200, true));
        phones.create(phone);
        BOOST_CHECK_EQUAL(phones.getAll().size(), 1);
    }

BOOST_AUTO_TEST_SUITE_END()