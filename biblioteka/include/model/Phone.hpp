#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_PHONE_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_PHONE_HPP


#include "Device.hpp"

class Phone : public Device {
    bool is5G;

public:
    Phone(double price, const std::string &brand, double weight, int memorySizeInMb, int batteryCapacityInMAh,
          bool is5G);

    ~Phone() final;

    bool isCompatibleWith5G() const;

    std::string itemInfo() final;

};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_PHONE_HPP
