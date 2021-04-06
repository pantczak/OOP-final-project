#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_LAPTOP_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_LAPTOP_HPP


#include "Device.hpp"

class Laptop : public Device {
    bool hasACdReader;

public:
    Laptop(double price, const std::string &brand, double weight, int memorySizeInMb, int batteryCapacityInMAh,
           bool hasACdReader);

    ~Laptop() final;

    bool getHasACdReader() const;

    std::string itemInfo() final;
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_LAPTOP_HPP
