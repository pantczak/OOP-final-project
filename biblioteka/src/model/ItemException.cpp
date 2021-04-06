#include "ItemException.hpp"

ItemException::~ItemException() = default;

ItemException::ItemException(const std::string &arg) : runtime_error(arg) {}