#ifndef __ALGORITHMS_DEMO_HEADER__
#define __ALGORITHMS_DEMO_HEADER__

#include <vector>
#include <list>
#include <string>

void PrintCollection(const std::vector<int>& v);
void PrintCollection(const std::list<int>& v);

void DemoForEach();
void DemoFill();
void DemoGenerate();
void DemoCopy();
void DemoReplace();
void DemoRemove();
void DemoRemoveIf();
void DemoUnique();
void DemoUniquePred();
void DemoReverse();
void DemoRotate();
void DemoFind();
void DemoAdjacentFind();
void DemoFindFirstOf();
void DemoMinMaxElements();
void DemoBinarySearch();
void DemoStableSort();
void DemoPartialSort();
void DemoPartition();

struct Total {
	int total;

	Total() { total = 0; }
	void operator() (int n) { 
		total += n; 
	}
};

struct Generator {
	int value;

	Generator() { value = 1000; }
	int operator() () { 
		return ++value; 
	}
};

struct IsEquiDivisible {
	bool operator()(int x, int y) {
		return (x % y == 0);
	}
};

struct IsOdd {
	bool operator()(int x) {
		return (x % 2 == 1);
	}
};

struct IsEven {
	bool operator()(int x) {
		return (x % 2 == 0);
	}
};

struct IsEqual {
	bool operator()(int x, int y) {
		return (x == y);
	}
};

struct Item {
	Item(double id, std::string desc) : id(id), desc(desc) {}
	double id;
	std::string desc;
};

bool CompareAsInt(const Item& x, const Item& y)
{
	return static_cast<int>(x.id) <
		static_cast<int>(y.id);
}

bool CompareAsDouble(const Item& x, const Item& y)
{
	return x.id < y.id;
}



#endif // __ALGORITHMS_DEMO_HEADER__
