#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_WARRANTY_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_WARRANTY_HPP


#include "Service.hpp"

class Warranty : public Service {
    bool waterDamage;
    int maxCoverage;

public:
    Warranty(double price, int durationInDays, bool waterDamage, int maxCoverage);

    ~Warranty() override;

    bool getWaterDamage() const;

    int getMaxCoverage() const;

    std::string itemInfo() final;

};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_WARRANTY_HPP
