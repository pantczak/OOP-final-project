//
// Created by student on 17.01.2020.
//

#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_INDIVIDUAL_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_INDIVIDUAL_HPP


#include "ClientType.hpp"

class Individual : public ClientType {
public:
    double discount(double totalValue, int totalRecentPurchase) final;

    virtual ~Individual();

    Individual();
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_INDIVIDUAL_HPP
