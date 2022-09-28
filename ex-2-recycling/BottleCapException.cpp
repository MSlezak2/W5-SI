#include "BottleCapException.h"

BottleCapException::BottleCapException(std::string errorMessage) {
    this->errorMessage = errorMessage;
}

const char* BottleCapException::what() const noexcept {
    return errorMessage.c_str();
}
