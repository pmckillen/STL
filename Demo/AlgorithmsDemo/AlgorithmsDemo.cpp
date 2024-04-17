#include "AlgorithmsDemo.h"

#include <iostream>
#include <algorithm>


int main()
{
	std::cout << "***** DemoForEach *****" << std::endl;
	DemoForEach();

	std::cout << "***** DemoFill *****" << std::endl;
	DemoFill();

	std::cout << "***** DemoGenerate *****" << std::endl;
	DemoGenerate();

	std::cout << "***** DemoCopy *****" << std::endl;
	DemoCopy();

	std::cout << "***** DemoReplace *****" << std::endl;
	DemoReplace();

	std::cout << "***** DemoRemove *****" << std::endl;	
	DemoRemove();

	std::cout << "***** DemoRemoveIf *****" << std::endl;
	DemoRemoveIf();

	std::cout << "***** DemoUnique *****" << std::endl;
	DemoUnique();

	std::cout << "***** DemoUniquePred *****" << std::endl;
	 DemoUniquePred();

	std::cout << "***** DemoReverse *****" << std::endl;
	DemoReverse();

	std::cout << "***** DemoRotate *****" << std::endl;
	DemoRotate();

	std::cout << "***** DemoFind *****" << std::endl;
	DemoFind();

	std::cout << "***** DemoAdjacentFind *****" << std::endl;
	DemoAdjacentFind();

	std::cout << "***** DemoFindFirstOf *****" << std::endl;
	DemoFindFirstOf();

	std::cout << "***** DemoMinMaxElements *****" << std::endl;
	DemoMinMaxElements();

	std::cout << "***** DemoBinarySearch *****" << std::endl;
	DemoBinarySearch();

	std::cout << "***** DemoStableSort *****" << std::endl;
	 DemoStableSort();

	std::cout << "***** DemoPartialSort *****" << std::endl;
	DemoPartialSort();

	std::cout << "***** DemoPartition *****" << std::endl;
	DemoPartition();

    return 0;
}

void PrintCollection(const std::vector<int>& collection)
{
	for (const auto& c : collection) std::cout << ' ' << c;
	std::cout << std::endl;
}

void PrintCollection(const std::list<int>& collection)
{
	for (const auto& c : collection) std::cout << ' ' << c;
	std::cout << std::endl;
}

void PrintCollection(const std::vector<Item>& collection)
{
	for (const auto& c : collection) 
			std::cout << ' ' << c.id << "\t" 
					  << c.desc << std::endl;
}


void DemoForEach()
{
	std::vector<int> collection{ 1,2,3,4,5,6,7,8,9 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::for_each(collection.begin(), collection.end(), [](int& n) { n = n*n; });

	std::cout << "After Lambda" << std::endl;

	PrintCollection(collection);

	Total t = std::for_each(collection.begin(), collection.end(), Total());

	std::cout << "Collection Total " << t.total << std::endl;
}

void DemoFill()
{
	std::vector<int> collection{ 1,2,3,4,5,6,7,8,9 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::fill(collection.begin(), collection.begin() + 2, 5);

	std::cout << "After fill" << std::endl; 
	
	PrintCollection(collection);

	std::fill_n(collection.begin(), collection.size(), 42);

	std::cout << "After fill_n" << std::endl; 
	
	PrintCollection(collection);
}

void DemoGenerate()
{
	std::vector<int> collection{ 1,2,3,4,5,6,7,8,9 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::generate(collection.begin(), collection.begin() + 5, Generator());

	std::cout << "After generate" << std::endl;

	PrintCollection(collection);

	std::generate_n(collection.begin() + 5, 4, Generator());

	std::cout << "After generate_n" << std::endl;

	PrintCollection(collection);
}

void DemoCopy()
{
	std::vector<int> collection{ 1,2,3,4,5,6,7,8,9 };

	std::list<int> destination(collection.size());

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::copy(collection.begin(), collection.end(), destination.begin());

	std::cout << "Destination Series" << std::endl;

	PrintCollection(destination);

	std::fill(collection.begin() + 5, collection.end(), 42);

	std::copy_backward(collection.begin(), collection.begin() + 5, destination.end());

	std::cout << "After copy backwards - Destination Series" << std::endl;

	PrintCollection(destination);
}

void DemoReplace()
{
	std::vector<int> collection{ 1,6,3,6,5,6,7,6,9 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::replace(collection.begin(), collection.end(), 6, 66);

	std::cout << "After replace" << std::endl;

	PrintCollection(collection);

	std::list<int> destination(collection.size());

	std::replace_copy(collection.begin(), collection.end(), destination.begin(), 9, 99);

	std::cout << "After replace_copy" << std::endl;
	PrintCollection(collection);
	PrintCollection(destination);
}

void DemoRemove()
{
	std::vector<int> collection{ 1,2,1,2,1,2,1,3,1 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::remove(collection.begin(), collection.end(), 1);

	std::cout << "After remove" << std::endl;

	PrintCollection(collection);

	std::list<int> destination(collection.size());

	std::remove_copy(collection.begin(), collection.end(), destination.begin(), 3);

	std::cout << "After remove copy" << std::endl;

	PrintCollection(destination);
}

void DemoRemoveIf()
{
	std::vector<int> collection{ 1,2,1,2,1,2,1,3,1 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::remove_if(collection.begin(), collection.end(), 
					[](int n) { return (n%2) == 1; });

	std::cout << "After remove_if" << std::endl;

	PrintCollection(collection);

	std::list<int> destination(collection.size());

	std::remove_copy_if(collection.begin(), collection.end(), 
						destination.begin(), 
						[](int n) { return (n%2) == 1; });

	std::cout << "After remove_copy_if" << std::endl;

	PrintCollection(destination);
}

void DemoUnique()
{
	std::vector<int> collection{ 1,2,2,3,3,3,4,4,4,4,3,3,3,2,2,1 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::vector<int>::iterator it;
	it = std::unique(collection.begin(), collection.end());

	collection.resize(std::distance(collection.begin(), it));

	std::cout << "After unique" << std::endl;

	PrintCollection(collection);

	std::list<int> destination(collection.size());

	collection = { 1,2,2,3,3,3,4,4,4,4,3,3,3,2,2,1 };

	std::unique_copy(collection.begin(), collection.end(), destination.begin());

	std::cout << "After unique_copy" << std::endl;

	PrintCollection(destination);
}

void DemoUniquePred()
{
	std::vector<int> collection{ 1,2,2,3,3,3,4,4,4,4,3,3,3,2,2,1 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::vector<int>::iterator it;
	it = std::unique(collection.begin(), collection.end(), IsEqual());

	collection.resize(std::distance(collection.begin(), it));

	std::cout << "After unique (with predicate)" << std::endl;

	PrintCollection(collection);

	collection = { 1,2,2,3,3,3,4,4,4,4,3,3,3,2,2,1 };

	std::cout << "Before unique_copy (with predicate)" << std::endl;

	PrintCollection(collection);

	it = std::unique_copy(collection.begin(), collection.end(), 
						 collection.begin(), IsEquiDivisible());
	
	collection.resize(std::distance(collection.begin(), it));

	std::cout << "After unique_copy (with predicate)" << std::endl;

	PrintCollection(collection);
}

void DemoReverse()
{
	std::vector<int> collection{ 0,1,1,2,3,5,8,13,21};

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);
	
	std::reverse(collection.begin(), collection.end());

	std::cout << "After Reverse" << std::endl;

	PrintCollection(collection);

	std::list<int> destination(collection.size());

	std::reverse_copy(collection.begin(), collection.end(), destination.begin());

	std::cout << "After Reverse_copy" << std::endl;

	PrintCollection(destination);
}

void DemoRotate()
{
	std::vector<int> collection{ 0,1,1,2,3,5,8,13,21,34,55 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::rotate(collection.begin(), collection.begin() + 6, collection.end());

	std::cout << "After rotate" << std::endl;

	PrintCollection(collection);

	std::list<int> destination(collection.size());

	std::rotate_copy(collection.begin(), collection.begin() + 3, collection.end(), destination.begin());

	std::cout << "After rotate_copy" << std::endl;

	PrintCollection(destination);
}

void DemoFind()
{
	std::vector<int> collection{ 0,1,1,2,3,5,8,13,21,34,55 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::vector<int>::iterator it;
	
	it = std::find(begin(collection), end(collection), 21);
	if (it != end(collection))
		std::cout << "Found " << *it << std::endl;
	else std::cout << "Not Found " << std::endl;

	it = std::find(begin(collection), end(collection), 32);
	if (it != end(collection))
		std::cout << "Found " << *it << std::endl;
	else std::cout << "Not Found " << std::endl;
}

void DemoAdjacentFind()
{
	std::vector<int> collection{ 0,1,1,2,3,5,5,5,8,13,21 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(collection);

	std::vector<int>::iterator it;

	it = std::adjacent_find(begin(collection), end(collection));
	if (it != end(collection))
		std::cout << "First pair of adjacent items are " << *it << std::endl;

	it = std::adjacent_find(++it, end(collection));
	if (it != end(collection))
		std::cout << "Next pair of adjacent items are " << *it << std::endl;

	it = std::adjacent_find(++it, end(collection));
	if (it != end(collection))
		std::cout << "Next pair of adjacent items are " << *it << std::endl;
}

void DemoFindFirstOf()
{
	std::vector<int> squares{ 1,4,9,16,25,36,49,64,81,100 };

	std::vector<int> cubes{ 1,8,27,64,125,216,343,512,729,1000 };

	std::vector<int>::iterator it;

	it = std::find_first_of(begin(squares), end(squares), begin(cubes), end(cubes));

	if (it != end(squares))
		std::cout << "The first cube that is also a square is " << *it << std::endl;

	it = std::find_first_of(++it, end(squares), begin(cubes), end(cubes));

	if (it != end(squares))
		std::cout << "The next cube that is also a square is " << *it << std::endl;
}

void DemoMinMaxElements()
{
	std::vector<int> squares{ 36,49,64,81,100,1,4,9,16,25 };

	std::vector<int>::iterator it;

	PrintCollection(squares);

	it = std::min_element(begin(squares), end(squares));
	if (it != end(squares))
		std::cout << "The minimum element of squares is " << *it << std::endl;

	it = std::max_element(begin(squares), end(squares));
	if (it != end(squares))
		std::cout << "The maximum element of squares is " << *it << std::endl;
}

void DemoBinarySearch()
{
	std::vector<int> squares{ 16,25,36,49,64,81,100,36,49,9,16,64,81,100,1,4,9,16,25 };

	std::sort(begin(squares), end(squares));

	bool found = std::binary_search(squares.begin(), squares.end(), 36);

	if (found == true) std::cout << "Found 36" << std::endl;
	else std::cout << "Not Found 36" << std::endl;

	std::vector<int>::iterator lower, upper;

	lower = std::lower_bound(squares.begin(), squares.end(), 16);
	upper = std::upper_bound(squares.begin(), squares.end(), 81);

	std::list<int> bounded(lower, upper);

	std::cout << "Numbers between lower and upper" << std::endl;

	PrintCollection(bounded);
}

void DemoStableSort() {

	std::vector<Item> masterList = {
		Item(3.23, "Windows Lap Top"),
		Item(2.62, "Mouse"),
		Item(123, "Screen"),
		Item(3.02, "MacBook"),
		Item(3.99, "Second Windows Lap Top"),
		Item(1.31, "External Hard Drive"),
	};

	std::vector<Item> items(cbegin(masterList), cend(masterList));

	std::cout << "Initial Series" << std::endl;

	PrintCollection(items);

	std::sort(begin(items), end(items), CompareAsDouble);

	std::cout << "After sort" << std::endl;

	PrintCollection(items);

	items = masterList;

	std::cout << "Reset Series" << std::endl;

	PrintCollection(items);

	std::stable_sort(begin(items), end(items), CompareAsInt);

	std::cout << "After sort" << std::endl;

	PrintCollection(items);
}

void DemoPartialSort() {

	std::vector<int> squares{ 16,25,36,49,64,81,100,36,49,9,16,64,81,100,1,4,9,16,25 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(squares);

	std::partial_sort(begin(squares), squares.begin() + 10, end(squares));

	std::cout << "After Partial Sort" << std::endl;

	PrintCollection(squares);
}

void DemoPartition()
{
	std::vector<int> squares{ 16,25,36,49,64,81,100,36,49,9,16,64,81,100,1,4,9,16,25 };

	std::cout << "Initial Series" << std::endl;

	PrintCollection(squares);

	std::partition(begin(squares), end(squares), IsOdd());

	std::cout << "After Partition (IsOdd) " << std::endl;

	PrintCollection(squares);
}
