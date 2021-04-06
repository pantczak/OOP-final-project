#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_SERVICE_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_SERVICE_HPP


#include "Item.hpp"

class Service : public Item {
    int durationInDays;

protected:
    Service(double price, int durationInDays);

    ~Service() override;

public:
    int getDurationInDays() const;

    std::string itemInfo() override;

    double getPrice() const override;
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_SERVICE_HPP
