#ifndef SERWIS_SPRZETU_KOMPUTEROWEGO_REPOSITORYEXCEPTION_HPP
#define SERWIS_SPRZETU_KOMPUTEROWEGO_REPOSITORYEXCEPTION_HPP


#include <stdexcept>

class RepositoryException : public std::runtime_error {
public:
    explicit RepositoryException(const std::string &message);

    ~RepositoryException() override;
};


#endif //SERWIS_SPRZETU_KOMPUTEROWEGO_REPOSITORYEXCEPTION_HPP
