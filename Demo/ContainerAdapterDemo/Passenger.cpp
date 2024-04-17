#include "Passenger.h"
#include <iostream>


std::ostream& operator << (std::ostream& os, const Passenger& p)
{
	return p.PutToStream(os);
}

std::istream& operator >> (std::istream& is, Passenger& p)
{
	return p.GetFromStream(is);
}

// comparison operators
bool operator== (const Passenger& lhs, const Passenger& rhs)
{
	return lhs.IsEqual(rhs);
}

bool operator!= (const Passenger& lhs, const Passenger& rhs)
{
	return !(lhs == rhs);
}

bool operator<  (const Passenger& lhs, const Passenger& rhs)
{
	return lhs.IsLessThan(rhs);
}

bool operator>  (const Passenger& lhs, const Passenger& rhs)
{
	return (lhs != rhs) && (lhs < rhs);
}

bool operator<= (const Passenger& lhs, const Passenger& rhs)
{
	return (lhs < rhs) || (lhs == rhs);
}

bool operator>= (const Passenger& lhs, const Passenger& rhs)
{
	return!(lhs < rhs);
}

bool Passenger::IsEqual(const Passenger& src) const
{
	return	_firstName == src._firstName &&
		_lastName == src._lastName &&
		_passengerType == src._passengerType &&
		_gender == src._gender;

}

bool Passenger::IsLessThan(const Passenger& src) const
{
	return (
				(_gender > src._gender) || 
				((_gender == src._gender) && (_passengerType > src._passengerType))
			);
}

std::ostream& 	Passenger::PutToStream(std::ostream& os) const
{
	os << _firstName << " " << _lastName << " " << PassengerTypeAsString() << " " << GenderAsString();
	
	return os;
}

std::istream& 	Passenger::GetFromStream(std::istream& is)
{
	std::string passType, gender;

	is >> _firstName >> _lastName >> passType >> gender;

	_passengerType = PassengerTypeFromString(passType);
	_gender = GenderFromString(gender);

	return is;
}

std::string Passenger::PassengerTypeAsString() const
{
	std::string ret;

	switch (_passengerType) {
	case PassengerType::FIRST_CLASS:
		ret = "FIRST";
		break;
	case PassengerType::SECOND_CLASS:
		ret = "SECOND";
		break;
	default:
		ret = "THIRD";
		break;
	}

	return ret;
}

std::string Passenger::GenderAsString() const
{
	std::string ret;

	switch (_gender) {
	case GenderType::FEMALE:
		ret = "Female";
		break;
	default:
		ret = "Male";
		break;	
	}

	return ret;
}

PassengerType	Passenger::PassengerTypeFromString(std::string s) const
{
	PassengerType ret;

	if (s == "FIRST")
		ret = PassengerType::FIRST_CLASS;
	else if (s == "SECOND")
		ret = PassengerType::SECOND_CLASS;
	else
		ret = PassengerType::THIRD_CLASS;


	return ret;
}

GenderType		Passenger::GenderFromString(std::string s) const
{
	GenderType ret;

	if (s == "Female")
		ret = GenderType::FEMALE;
	else
		ret = GenderType::MALE;

	return ret;
}


