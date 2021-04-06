#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_MANAGEREXCEPTION_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_MANAGEREXCEPTION_HPP

#include <stdexcept>

class ManagerException : public std::runtime_error {
public:
    explicit ManagerException(const std::string &arg);

    ~ManagerException() override;

};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_MANAGEREXCEPTION_HPP
