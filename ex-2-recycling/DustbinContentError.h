#pragma once
#include <stdexcept>

class DustbinContentError : public std::exception{
public:
	DustbinContentError(std::string errorMessage);
	virtual const char* what() const noexcept override;

private:
	std::string errorMessage;
};

