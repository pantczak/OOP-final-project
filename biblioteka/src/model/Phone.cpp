#include <sstream>
#include "Phone.hpp"

Phone::Phone(double price, const std::string &brand, double weight, int memorySizeInMb, int batteryCapacityInMAh,
             bool is5G)
        : Device(price, brand, weight, memorySizeInMb, batteryCapacityInMAh), is5G(is5G) {}

bool Phone::isCompatibleWith5G() const {
    return is5G;
}

std::string Phone::itemInfo() {
    std::ostringstream stringStream;
    stringStream << ", compatible with 5G: " << (is5G ? "yes" : "no");
    return "Phone, " + Device::itemInfo() + stringStream.str() + "\n";
}

Phone::~Phone() = default;
