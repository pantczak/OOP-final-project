//
// Created by student on 17.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENTTYPE_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENTTYPE_HPP


class ClientType {
public:
    virtual double discount(double totalValue, int totalRecentPurchase) = 0;

    ClientType();

    virtual ~ClientType();
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_CLIENTTYPE_HPP
