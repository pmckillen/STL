#ifndef __PEOPLE_HEADER__
#define __PEOPLE_HEADER__

// STL Headers
#include <string>
#include <iosfwd>

// Forward Declarations
class Passenger;


// Input / Output operators
std::ostream& operator << (std::ostream& os, const Passenger& p);
std::istream& operator >> (std::istream& is, Passenger& p);

// comparison operators
bool operator== (const Passenger& lhs, const Passenger& rhs);
bool operator!= (const Passenger& lhs, const Passenger& rhs);
bool operator<  (const Passenger& lhs, const Passenger& rhs);
bool operator>  (const Passenger& lhs, const Passenger& rhs);
bool operator<= (const Passenger& lhs, const Passenger& rhs);
bool operator>= (const Passenger& lhs, const Passenger& rhs);


// By default the underlying type for scoped enums is int
// No need to write concersion functions for these.
enum class PassengerType { FIRST_CLASS, SECOND_CLASS, THIRD_CLASS};
enum class GenderType    { FEMALE, MALE}
;
class Passenger
{
public:


	friend std::ostream& operator << (std::ostream& os, const Passenger& p);
	friend std::istream& operator >> (std::istream& is, Passenger& p);
	friend bool operator== (const Passenger& lhs, const Passenger& rhs);
	friend bool operator<  (const Passenger& lhs, const Passenger& rhs);


	Passenger(std::string firstName, std::string lastName, PassengerType type, GenderType gender) :
		_firstName(firstName),
		_lastName(lastName),
		_passengerType(type),
		_gender(gender) {}

	virtual ~Passenger() {}

	std::string		GetFirstName()		const { return _firstName; }
	std::string		GetLastName()		const { return _lastName; }
	PassengerType	GetPassengerType()	const { return _passengerType; }
	GenderType		GetGenderType()		const { return _gender; }

	void SetFirstName(std::string val)			{ _firstName = val; }
	void SetLastName(std::string val)			{ _lastName = val; }
	void SetPassengerType(PassengerType val)	{ _passengerType = val; }
	void SetGenderType(GenderType val)			{ _gender = val; }

protected:
	bool IsEqual(const Passenger& src) const;

	bool IsLessThan(const Passenger& src) const;

	std::ostream& PutToStream(std::ostream& os) const;

	std::istream& GetFromStream(std::istream& is);

private:

	// Helpers
	std::string PassengerTypeAsString() const;
	std::string GenderAsString() const;

	PassengerType	PassengerTypeFromString(std::string s) const;
	GenderType		GenderFromString(std::string s) const;

	std::string		_firstName;
	std::string		_lastName;
	PassengerType	_passengerType;
	GenderType		_gender;

}; // class Passenger

#endif // __PEOPLE_HEADER__
