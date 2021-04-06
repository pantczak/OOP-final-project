#include "ClientsManager.hpp"

ClientsManager::ClientsManager() = default;

ClientsManager::~ClientsManager() = default;

void ClientsManager::newClient(ClientSPtr client) {
    if (isDuplicate(client))
        throw ManagerException("Trying to add duplicate client to repository.");
    else
        clients.create(client);
}

void ClientsManager::removeClient(ClientSPtr client) {
    clients.remove(client);
}

ClientSPtr ClientsManager::findByID(boost::uuids::uuid id) {
    return clients.get(id);
}

void ClientsManager::updateClient(boost::uuids::uuid id, ClientSPtr updatedClient) {
    clients.get(id).operator*() = updatedClient.operator*();
}

const std::vector<ClientSPtr> &ClientsManager::getAllClients() {
    return clients.getAll();
}

bool ClientsManager::isDuplicate(const ClientSPtr &client) {
    std::vector<ClientSPtr> cl = getAllClients();
    for (const auto &it : cl)
    {
        if (it.operator*() == client.operator*()) return true;
    }
    return false;
}


