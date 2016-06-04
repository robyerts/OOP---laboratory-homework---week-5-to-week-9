#include "TutorialValidator.h"

using namespace std;

ValidationException::ValidationException(std::string _message) : message{ _message }
{
}

std::string ValidationException::getMessage() const
{
	return this->message;
}

void TutorialValidator::validate( Tutorial & s)
{
	string errors;
	if (s.getTitle().size() < 3)
		errors += string("The Tutorial name cannot be less than 2 characters!\n");
	if (s.getArtist().size() < 3)
		errors += string("The presenter's name cannot be less than 2 characters!\n");
	if (s.getSource().size()<5)
		errors += string("The source link cannot be less than 4 characters!\n");
	if (s.getDuration().getMinutes() <0 || s.getDuration().getSeconds()<0)
		errors += string("no negative numbers for duration!\n");
	if (s.getDuration().getMinutes()==0&&s.getDuration().getSeconds()<5)
		errors += string("there can't be tutorials with less than 5 seconds!\n");
	if (s.getDuration().getSeconds()>59)
		errors += string("no more than 59 seconds!\n");
	if (s.getLikes()<0)
		errors += string("no negative likes, please!\n");

	if (errors.size() > 0)
		throw ValidationException(errors);

	/*if (errors.size() > 0)
	throw ValidationExceptionInherited(errors);*/
}

