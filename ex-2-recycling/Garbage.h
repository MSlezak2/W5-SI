#pragma once
#include <string>


class Garbage {
public:
	virtual ~Garbage() = default;

protected:
	std::string name;
};

