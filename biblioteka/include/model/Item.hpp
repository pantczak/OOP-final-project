#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_ITEM_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_ITEM_HPP


#include <string>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

class Item {
    double price; //For Service-deriving classes it is PER DAY price
    boost::uuids::uuid ID;

protected:

    double roundDoubleToPowerOfTen(double value, int exponent);

    explicit Item(double price);

    virtual ~Item();

public:

    virtual double getPrice() const;

    void setPrice(double newPrice);

    virtual std::string itemInfo() = 0;

    const boost::uuids::uuid &getId() const;

};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_ITEM_HPP
