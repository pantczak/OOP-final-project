#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_TECHSUPPORT_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_TECHSUPPORT_HPP


#include "Service.hpp"

class TechSupport : public Service {
    bool doorToDoor, callAnyTime;

public:
    TechSupport(double price, int durationInDays, bool doorToDoor, bool callAnyTime);

    ~TechSupport() final;

    bool getDoorToDoor() const;

    bool getCallAnyTime() const;

    std::string itemInfo() final;
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_TECHSUPPORT_HPP
