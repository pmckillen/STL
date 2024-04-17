#include "ContainerAdapterDemo.h"

#include <queue>
#include <stack>
#include <iostream>


int main()
{

//	DemoStack();

//	DemoQueue();

	DemoPriorityQueue();

    return 0;
}

void DemoStack()
{
	using BealtesStack = std::stack<Passenger>;
	BealtesStack beatles;

	Passengers passengers = CreatePassengers();

	for (const auto& p : passengers)
		beatles.push(p);

	std::cout << "TOP  OF STACK =====> " << beatles.top() << std::endl;
	std::cout << "SIZE  OF QUEUE =====> " << beatles.size() << std::endl;


	while (!beatles.empty())
	{
		std::cout << beatles.top() << std::endl;
		
		beatles.pop();
	}
}

void DemoQueue()
{
	using BealtesQueue = std::queue<Passenger>;
	BealtesQueue beatles;

	Passengers passengers = CreatePassengers();

	for (const auto& p : passengers)
		beatles.push(p);
	
	std::cout << "FRONT OF QUEUE =====> " << beatles.front() << std::endl;
	std::cout << "BACK  OF QUEUE =====> " << beatles.back() << std::endl;
	std::cout << "SIZE  OF QUEUE =====> " << beatles.size() << std::endl;

	while (!beatles.empty())
	{
		std::cout << beatles.front() << std::endl;

		beatles.pop();
	}
}

void DemoPriorityQueue()
{
	using BealtesPriorityQueue = std::priority_queue<Passenger>;
	BealtesPriorityQueue beatles;

	Passengers passengers = CreatePassengers();

	for (const auto& p : passengers)
		beatles.push(p);

	std::cout << "TOP OF PRIORITY QUEUE =====> " << beatles.top() << std::endl;
	std::cout << "SIZE  OF PRIORITY QUEUE =====> " << beatles.size() << std::endl;

	while (!beatles.empty())
	{
		std::cout << beatles.top() << std::endl;

		beatles.pop();
	}

}

Passengers CreatePassengers()
{
	Passengers passengers;
	
	passengers.emplace_back("John", "Lennon", PassengerType::FIRST_CLASS, GenderType::MALE);	
	passengers.emplace_back("Yoko", "Ono", PassengerType::FIRST_CLASS, GenderType::FEMALE);
	passengers.emplace_back("Julian", "Lennon", PassengerType::FIRST_CLASS, GenderType::MALE);

	passengers.emplace_back("Paul", "McCartney", PassengerType::SECOND_CLASS, GenderType::MALE);
	passengers.emplace_back("Lynda", "McCartney", PassengerType::SECOND_CLASS, GenderType::FEMALE);
	passengers.emplace_back("Stella", "McCartney", PassengerType::SECOND_CLASS, GenderType::FEMALE);

	passengers.emplace_back("George", "Harrison", PassengerType::THIRD_CLASS, GenderType::MALE);
	passengers.emplace_back("Patti", "Boyd", PassengerType::THIRD_CLASS, GenderType::FEMALE);
	passengers.emplace_back("Dhani", "Harrison", PassengerType::THIRD_CLASS, GenderType::MALE);
	passengers.emplace_back("Olivia", "Harrison", PassengerType::THIRD_CLASS, GenderType::FEMALE);
	
	passengers.emplace_back("Ringo", "Starr", PassengerType::SECOND_CLASS, GenderType::MALE);

	return passengers;
}

