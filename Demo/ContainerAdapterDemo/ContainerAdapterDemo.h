#ifndef __CONTAINER_ADAPTER_DEMO_HEADER__
#define __CONTAINER_ADAPTER_DEMO_HEADER__

#include <vector>

#include "Passenger.h"
using Passengers = std::vector<Passenger>;

void DemoStack();
void DemoQueue();
void DemoPriorityQueue();
Passengers CreatePassengers();

/*
// STL Headers
#include <string>
#include <iosfwd>

// Forward Declarations
class Passenger;

// comparison operators
bool operator<  (const Passenger& lhs, const Passenger& rhs);
bool operator== (const Passenger& lhs, const Passenger& rhs);

enum class PassengerType { FIRST_CLASS, SECOND_CLASS, THIRD_CLASS};
enum class GenderType    { FEMALE, MALE}
;
class Passenger
{
public:
friend bool operator<  (const Passenger& lhs, const Passenger& rhs);
/// .....
}; // class Passenger

*/






#endif // __CONTAINER_ADAPTER_DEMO_HEADER__