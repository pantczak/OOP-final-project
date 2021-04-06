#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_DEVICE_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_DEVICE_HPP


#include "Item.hpp"

class Device : public Item {
    double weightInKg;
    int memorySizeInMB, batteryCapacityInMAh;
    std::string brand;

protected:
    Device(double price, const std::string &brand, double weightInKg, int memorySizeInMB, int batteryCapacityInMAh);

    ~Device() override;

    std::string itemInfo() override;


public:
    double getWeight() const;

    int getMemorySizeInMb() const;

    int getBatteryCapacity() const;

    const std::string &getBrand() const;
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_DEVICE_HPP
