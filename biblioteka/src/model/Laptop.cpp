#include <sstream>
#include "Laptop.hpp"

Laptop::Laptop(double price, const std::string &brand, double weight, int memorySizeInMb, int batteryCapacityInMAh,
               bool hasACdReader) : Device(price, brand, weight, memorySizeInMb, batteryCapacityInMAh),
                                    hasACdReader(hasACdReader) {}

bool Laptop::getHasACdReader() const {
    return hasACdReader;
}

std::string Laptop::itemInfo() {
    std::ostringstream stringStream;
    stringStream << ", cd reader: " << (hasACdReader ? "yes" : "no");
    return "Laptop, " + Device::itemInfo() + stringStream.str();
}

Laptop::~Laptop() = default;
