//
// Created by student on 17.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_COMPANY_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_COMPANY_HPP


#include "ClientType.hpp"

class Company : public ClientType {
public:
    double discount(double totalValue, int totalRecentPurchase) final;


    Company();

    virtual ~Company();
};

#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_COMPANY_HPP
