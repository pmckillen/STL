#ifndef __PEOPLE_HEADER__
#define __PEOPLE_HEADER__

// STL Headers
#include <string>
#include <iosfwd>

// Forward Declarations
class Person;
class SalariedEmployee;
class HourlyPaidEmployee;

// Input / Output operators
std::ostream& operator << (std::ostream& os, const Person& person);
std::istream& operator >> (std::istream& is, Person& person);
std::ostream& operator << (std::ostream& os, const SalariedEmployee& salariedEmp);
std::istream& operator >> (std::istream& is, SalariedEmployee& salariedEmp);
std::ostream& operator << (std::ostream& os, const HourlyPaidEmployee& hourlyEmp);
std::istream& operator >> (std::istream& is, HourlyPaidEmployee& hourlyEmp);

// comparison operators
bool operator== (const Person& lhs, const Person& rhs);
bool operator!= (const Person& lhs, const Person& rhs);
bool operator== (const SalariedEmployee& lhs, const SalariedEmployee& rhs);
bool operator!= (const SalariedEmployee& lhs, const SalariedEmployee& rhs);
bool operator== (const HourlyPaidEmployee& lhs, const HourlyPaidEmployee& rhs);
bool operator!= (const HourlyPaidEmployee& lhs, const HourlyPaidEmployee& rhs);

class Person
{
public:
	friend std::ostream& operator << (std::ostream& os, const Person& person);
	friend std::istream& operator >> (std::istream& is, Person& person);
	friend bool operator== (const Person& lhs, const Person& rhs);
	

	Person(std::string firstName = "Not Set", std::string lastName = "Not Set") :
		_firstName(firstName),
		_lastName(lastName) {}

	virtual ~Person() {}

	std::string GetFirstNane() const { return _firstName; }
	std::string GetLastNane()  const { return _lastName; }

	void SetFirstName(std::string val) { _firstName = val; }
	void SetLastName(std::string val)  { _lastName  = val; }

protected:
	bool IsEqual(const Person& src) const;

	std::ostream& PutToStream(std::ostream& os) const;

	std::istream& GetFromStream(std::istream& is);

private:
	std::string _firstName;
	std::string _lastName;

}; // class Person

class SalariedEmployee : public Person
{
public:
	friend std::ostream& operator << (std::ostream& os, const SalariedEmployee& salariedEmp);
	friend std::istream& operator >> (std::istream& is, SalariedEmployee& salariedEmp);
	friend bool operator== (const SalariedEmployee& lhs, const SalariedEmployee& rhs);

	SalariedEmployee(std::string firstName, std::string lastName, int salary) :
		Person(firstName, lastName),
		_salary(salary) {}

protected:
	bool IsEqual(const SalariedEmployee& src) const;

	std::ostream& PutToStream(std::ostream& os) const;

	std::istream& GetFromStream(std::istream& is);

private:
	int _salary;

}; // class SalariedEmployee

class HourlyPaidEmployee : public Person
{
public:
	friend std::ostream& operator << (std::ostream& os, const HourlyPaidEmployee& hourlyEmp);
	friend std::istream& operator >> (std::istream& is, HourlyPaidEmployee& hourlyEmp);
	friend bool operator== (const HourlyPaidEmployee& lhs, const HourlyPaidEmployee& rhs);

	HourlyPaidEmployee(std::string firstName, std::string lastName, double rate) :
		Person(firstName, lastName),
		_rate(rate) {}

protected:
	bool IsEqual(const HourlyPaidEmployee& src) const;

	std::ostream& PutToStream(std::ostream& os) const;

	std::istream& GetFromStream(std::istream& is);

private:
	double _rate;

}; // class HourlyPaidEmployee

#endif // __PEOPLE_HEADER__