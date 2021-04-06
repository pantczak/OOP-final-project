#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENTSMANAGER_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENTSMANAGER_HPP


#include <memory>
#include "Repository.hpp"
#include "Order.hpp"
#include "Client.hpp"
#include "RepositoryException.hpp"
#include "ManagerException.hpp"


typedef std::shared_ptr<Client> ClientSPtr;
typedef std::shared_ptr<Order> OrderSPtr;

class ClientsManager {
    Repository<Client> clients;

    bool isDuplicate(const ClientSPtr &client);

public:
    void newClient(ClientSPtr client);

    void removeClient(ClientSPtr client);

    void updateClient(boost::uuids::uuid id, ClientSPtr updatedClient);

    ClientSPtr findByID(boost::uuids::uuid id);

    ClientsManager();

    virtual ~ClientsManager();

    const std::vector<ClientSPtr> &getAllClients();

};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENTSMANAGER_HPP
