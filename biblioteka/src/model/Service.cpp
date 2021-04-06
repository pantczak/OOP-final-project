#include <sstream>
#include "Service.hpp"
#include "ItemException.hpp"

Service::Service(double price, int durationInDays) : Item(price), durationInDays(durationInDays) {
    if (durationInDays < 0)
    {
        throw ItemException("Duration cannot be set to 0 or negative, provided: " + std::to_string(durationInDays));

    }
}

int Service::getDurationInDays() const {
    return durationInDays;
}

std::string Service::itemInfo() {
    std::ostringstream stringStream;
    stringStream << ", duration: " << durationInDays << " days";
    return Item::itemInfo() + stringStream.str();
}

double Service::getPrice() const {
    return Item::getPrice() * durationInDays;
}

Service::~Service() = default;
