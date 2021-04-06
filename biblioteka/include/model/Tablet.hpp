#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_TABLET_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_TABLET_HPP


#include "Device.hpp"

class Tablet : public Device {
    bool hasAStylus;

public:
    Tablet(double price, const std::string &brand, double weight, int memorySizeInMb, int batteryCapacityInMAh,
           bool hasAStylus);

    ~Tablet() final;

    bool getHasAStylus() const;

    std::string itemInfo() final;
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_TABLET_HPP
