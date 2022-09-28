#include "DustbinContentError.h"

DustbinContentError::DustbinContentError(std::string errorMessage) {
    this->errorMessage = errorMessage;
}

const char* DustbinContentError::what() const noexcept {
    return errorMessage.c_str();
}
