#ifndef __STL_VOERVIEW_DEMO_APP_HEADER__
#define __STL_VOERVIEW_DEMO_APP_HEADER__

// STL Headers
#include <vector>

// Application Headers
#include "Person.h"

// Aliases
using People = std::vector<Person>;

// Function Prototypes
void DemoPeople();
void BuildPeople(People& people);
void DumpPeopleToFile(const People& people);
void LoadPeopleFromFile(People& people);

#endif // __STL_VOERVIEW_DEMO_APP_HEADER__