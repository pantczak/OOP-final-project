//
// Created by student on 18.01.2020.
//
#include "ClientsManager.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid.hpp>
#include <memory>


BOOST_AUTO_TEST_SUITE(TestSuiteClientManagerCorrect)

    BOOST_AUTO_TEST_CASE(ClientManagerAddCase) {
        ClientsManager clientsManager;
        clientsManager.newClient(std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A"));
        BOOST_REQUIRE_EQUAL(clientsManager.getAllClients().size(), 1);
        clientsManager.newClient(std::make_shared<Client>("Edward", "Nowak", "Fajna", "22A", "Woronicza", "22A"));
        BOOST_REQUIRE_EQUAL(clientsManager.getAllClients().size(), 2);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerDeleteCase) {
        ClientsManager clientsManager;
        ClientSPtr client1 = std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A");
        clientsManager.newClient(client1);
        ClientSPtr client2 = std::make_shared<Client>("Edward", "Nowak", "Fajna", "22A", "Woronicza", "22A");
        clientsManager.newClient(client2);
        BOOST_REQUIRE_EQUAL(clientsManager.getAllClients().size(), 2);
        clientsManager.removeClient(client2);
        BOOST_REQUIRE_EQUAL(clientsManager.getAllClients().size(), 1);
        clientsManager.removeClient(client1);
        BOOST_REQUIRE_EQUAL(clientsManager.getAllClients().size(), 0);

    }

    BOOST_AUTO_TEST_CASE(ClientManagerDulpicateCase) {
        ClientsManager clientsManager;
        clientsManager.newClient(std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A"));
        BOOST_REQUIRE_THROW(clientsManager.newClient(
                std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A")), ManagerException);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerUpdateCase) {
        ClientsManager clientsManager;
        ClientSPtr client1 = std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A");
        clientsManager.newClient(client1);
        ClientSPtr client2 = std::make_shared<Client>("Edward", "Nowak", "Fajna", "22A", "Woronicza", "22A");
        clientsManager.updateClient(client1->getId(), client2);
        BOOST_REQUIRE(clientsManager.findByID(client1->getId()).operator*() == client2.operator*());
    }

    BOOST_AUTO_TEST_CASE(ClientManagerFindByIdCase) {
        ClientsManager clientsManager;
        ClientSPtr client1 = std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A");
        clientsManager.newClient(client1);
        BOOST_REQUIRE(clientsManager.findByID(client1->getId()).operator*() == client1.operator*());
    }

    BOOST_AUTO_TEST_CASE(ClientManagerGetAllCase) {
        ClientsManager clientsManager;
        ClientSPtr client1 = std::make_shared<Client>("Jan", "Kowalski", "Woronicza", "22A", "Woronicza", "22A");
        ClientSPtr client2 = std::make_shared<Client>("Edward", "Nowak", "Fajna", "22A", "Woronicza", "22A");
        clientsManager.newClient(client1);
        clientsManager.newClient(client2);
        BOOST_REQUIRE(clientsManager.getAllClients()[0].operator*() == client1.operator*()
                      && clientsManager.getAllClients()[1].operator*() == client2.operator*());
    }

BOOST_AUTO_TEST_SUITE_END()