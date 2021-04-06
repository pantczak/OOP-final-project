#include "RepositoryException.hpp"

RepositoryException::RepositoryException(const std::string &message) : std::runtime_error(message) {}

RepositoryException::~RepositoryException() = default;
