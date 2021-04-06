#include <sstream>
#include "TechSupport.hpp"

TechSupport::TechSupport(double price, int durationInDays, bool doorToDoor, bool callAnyTime) : Service(price,
                                                                                                        durationInDays),
                                                                                                doorToDoor(doorToDoor),
                                                                                                callAnyTime(
                                                                                                        callAnyTime) {}

bool TechSupport::getDoorToDoor() const {
    return doorToDoor;
}

bool TechSupport::getCallAnyTime() const {
    return callAnyTime;
}

std::string TechSupport::itemInfo() {
    std::ostringstream stringStream;
    stringStream << ", door to door: " << (doorToDoor ? "yes" : "no") << ", call any time: "
                 << (callAnyTime ? "yes" : "no");
    return "TechSupport, " + Service::itemInfo() + stringStream.str();
}

TechSupport::~TechSupport() = default;
