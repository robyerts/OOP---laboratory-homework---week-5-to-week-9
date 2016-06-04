#pragma once
#include <string>
#include "Tutorial.h"

class ValidationException
{
private:
	std::string message;

public:
	ValidationException(std::string _message);
	std::string getMessage() const;
};

class TutorialValidator
{
public:
	static void validate(Tutorial& s);
};