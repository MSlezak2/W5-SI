#pragma once
#include <stdexcept>

class BottleCapException : public std::exception {
public:
	BottleCapException(std::string errorMessage);
	virtual const char* what() const noexcept override;

private:
	std::string errorMessage;
};

