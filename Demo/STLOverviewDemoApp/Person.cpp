#include "Person.h"


std::ostream& operator << (std::ostream& os, const Person& person)
{
	return person.PutToStream(os);
}

std::istream& operator >> (std::istream& is, Person& person)
{
	return person.GetFromStream(is);
}

std::ostream& operator << (std::ostream& os, const SalariedEmployee& salariedEmp) 
{
	return salariedEmp.PutToStream(os);
}

std::istream& operator >> (std::istream& is, SalariedEmployee& salariedEmp) 
{
	return salariedEmp.GetFromStream(is);
}

std::ostream& operator << (std::ostream& os, const HourlyPaidEmployee& hourlyEmp) 
{
	return hourlyEmp.PutToStream(os);
}

std::istream& operator >> (std::istream& is, HourlyPaidEmployee& hourlyEmp) 
{
	return hourlyEmp.GetFromStream(is);
}

// comparison operators
bool operator== (const Person& lhs, const Person& rhs)
{
	return lhs.IsEqual(rhs);
}

bool operator!= (const Person& lhs, const Person& rhs)
{
	return !(lhs == rhs);
}

bool operator== (const SalariedEmployee& lhs, const SalariedEmployee& rhs) 
{
	return lhs.IsEqual(rhs);
}

bool operator!= (const SalariedEmployee& lhs, const SalariedEmployee& rhs) 
{
	return !(lhs == rhs);
}

bool operator== (const HourlyPaidEmployee& lhs, const HourlyPaidEmployee& rhs) 
{
	return lhs.IsEqual(rhs);
}

bool operator!= (const HourlyPaidEmployee& lhs, const HourlyPaidEmployee& rhs)
{
	return !(lhs == rhs);
}

bool Person::IsEqual(const Person& src) const
{
	return	_firstName == src._firstName &&
			_lastName == src._lastName;

}

std::ostream& 	Person::PutToStream(std::ostream& os) const
{
	os << _firstName << " " << _lastName << " ";
	return os;
}

std::istream& 	Person::GetFromStream(std::istream& is)
{
	is >> _firstName >> _lastName;
	return is;
}


bool SalariedEmployee::IsEqual(const SalariedEmployee& src) const
{
	return	Person::IsEqual(src) &&
			_salary == src._salary;

}

std::ostream& SalariedEmployee::PutToStream(std::ostream& os) const
{
	Person::PutToStream(os);

	os << _salary << " ";
	
	return os;
}

std::istream& SalariedEmployee::GetFromStream(std::istream& is)
{
	Person::GetFromStream(is);

	is >> _salary;

	return is;
}

bool HourlyPaidEmployee::IsEqual(const HourlyPaidEmployee& src) const
{
	return	Person::IsEqual(src) &&
		_rate == src._rate;

}

std::ostream& HourlyPaidEmployee::PutToStream(std::ostream& os) const
{
	Person::PutToStream(os);

	os << _rate << " ";

	return os;
}

std::istream& HourlyPaidEmployee::GetFromStream(std::istream& is)
{
	Person::GetFromStream(is);

	is >> _rate;

	return is;
}
