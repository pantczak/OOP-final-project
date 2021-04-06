#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_ITEMEXCEPTION_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_ITEMEXCEPTION_HPP

#include "stdexcept"

class ItemException : virtual public std::runtime_error {

public:
    explicit ItemException(const std::string &arg);

    ~ItemException() override;
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_ITEMEXCEPTION_HPP
