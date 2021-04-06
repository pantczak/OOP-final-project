#include <sstream>
#include "Tablet.hpp"

Tablet::Tablet(double price, const std::string &brand, double weight, int memorySizeInMb, int batteryCapacityInMAh,
               bool hasAStylus) : Device(price, brand, weight, memorySizeInMb, batteryCapacityInMAh),
                                  hasAStylus(hasAStylus) {}

bool Tablet::getHasAStylus() const {
    return hasAStylus;
}

std::string Tablet::itemInfo() {
    std::ostringstream stringStream;
    stringStream << ", stylus: " << (hasAStylus ? "yes" : "no");
    return "Tablet, " + Device::itemInfo() + stringStream.str();
}

Tablet::~Tablet() = default;


