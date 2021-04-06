#include <cmath>
#include <sstream>
#include <iomanip>
#include <ItemException.hpp>
#include "Device.hpp"


Device::Device(double price, const std::string &brand, double weightInKg, int memorySizeInMB, int batteryCapacityInMAh)
        : Item(
        price), brand(brand) {
    weightInKg = roundDoubleToPowerOfTen(weightInKg, -1);
    if (weightInKg <= 0)
        throw ItemException("Weight cannot be set to 0.0 or negative, provided: " + std::to_string(weightInKg));
    else if (memorySizeInMB <= 0)
        throw ItemException("Memory size cannot be set to 0 or negative, provided: " + std::to_string(memorySizeInMB));
    else if (batteryCapacityInMAh <= 0)
        throw ItemException(
                "Battery capacity cannot be set to 0 or negative, provided: " + std::to_string(batteryCapacityInMAh));
    else
    {
        this->weightInKg = weightInKg;
        this->memorySizeInMB = memorySizeInMB;
        this->batteryCapacityInMAh = batteryCapacityInMAh;
    }
}

Device::~Device() = default;

double Device::getWeight() const {
    return weightInKg;
}

int Device::getMemorySizeInMb() const {
    return memorySizeInMB;
}

std::string Device::itemInfo() {
    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(1);
    stringStream << ", brand: " << brand << ", weight: " << weightInKg << " kg, memory size: " << memorySizeInMB
                 << " MB, battery capacity: " << batteryCapacityInMAh << " mAh";
    return Item::itemInfo() + stringStream.str();
}

int Device::getBatteryCapacity() const {
    return batteryCapacityInMAh;
}

const std::string &Device::getBrand() const {
    return brand;
}
