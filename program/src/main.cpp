#include <iostream>
#include <Client.hpp>
#include <ItemsManager.hpp>
#include <ClientsManager.hpp>
#include <OrdersManager.hpp>
#include "Phone.hpp"

using namespace std;

int main() {
    ItemsManager itemsManager;
    ClientsManager clientsManager;
    OrdersManager ordersManager;


    std::shared_ptr<Phone> phone(new Phone(2000, "Sony", 0.2, 256, 3200, true));
    cout << phone->itemInfo() << endl;

    itemsManager.newItem(phone);

    std::shared_ptr<Client> client(new Client("Adam", "Kula", "Dobra", "9a", "Jasna", "33"));
    cout << client->clientInfo();
    clientsManager.newClient(client);

    std::shared_ptr<Order> order(new Order(client, phone));
    cout << order->orderInfo() << endl;
    ordersManager.newOrder(order);

    cout << client->clientInfo();

    ordersManager.finishOrder(order);


    return 0;
}

