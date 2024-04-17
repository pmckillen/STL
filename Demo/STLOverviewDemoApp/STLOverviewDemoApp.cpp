#include "STLOverviewDemoApp.h"
#include <fstream>
#include <iterator>

int main()
{
	DemoPeople();

    return 0;
}

void DemoPeople()
{
	People beatles;

	BuildPeople(beatles);

	DumpPeopleToFile(beatles);

	LoadPeopleFromFile(beatles);

}

void BuildPeople(People& people)
{
	people.clear();

	people.emplace_back("John", "Lennon");
	people.emplace_back("Paul", "McCartney");
	people.emplace_back("George", "Harrison");
	people.emplace_back("Ringo", "Starr");
}

void DumpPeopleToFile(const People& people)
{
	std::ofstream store("beatles.txt", std::ofstream::out);

	for (const auto& person : people)
		store << person << std::endl;

	store.close();
}

void LoadPeopleFromFile(People& people)
{
	people.clear();

	std::ifstream store("beatles.txt", std::ios::in);

	std::copy(	std::istream_iterator<Person>(store),
				std::istream_iterator<Person>(),
				std::back_insert_iterator<People>(people)	);

	store.close();
}

