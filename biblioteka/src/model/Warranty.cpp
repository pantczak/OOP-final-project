#include <sstream>
#include <ItemException.hpp>
#include "Warranty.hpp"

Warranty::Warranty(double price, int durationInDays, bool waterDamage, int maxCoverage) : Service(
        price, durationInDays), waterDamage(waterDamage), maxCoverage(maxCoverage) {
    if (maxCoverage < 0)
    {
        throw ItemException("maxCoverage cannot be set to 0 or negative, provided: " + std::to_string(maxCoverage));
    }
}


bool Warranty::getWaterDamage() const {
    return waterDamage;
}

int Warranty::getMaxCoverage() const {
    return maxCoverage;
}

std::string Warranty::itemInfo() {
    std::ostringstream stringStream;
    stringStream << ", water damage: " << (waterDamage ? "yes" : "no") << ", max coverage: "
                 << maxCoverage << " PLN";
    return "Warranty, " + Service::itemInfo() + stringStream.str();
}

Warranty::~Warranty() = default;

