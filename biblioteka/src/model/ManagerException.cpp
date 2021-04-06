#include "ManagerException.hpp"

ManagerException::ManagerException(const std::string &arg) : runtime_error(arg) {}

ManagerException::~ManagerException() = default;
