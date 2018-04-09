// test cool qsort
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "qsort.h"

using epicyclism::qsort;

template<typename C> void Dump(C const& c)
{
	for (auto& e : c)
		std::cout << e << " ";
	std::cout << "\n";
}

template<typename C> void SortAndDump(C& c)
{
	std::cout << "   ";
	Dump(c);
	std::cout << "-> ";
	qsort(std::begin(c), std::end(c));
	Dump(c);
	std::cout << "\n";
}

int main()
{
	std::array<int, 10> a1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::array<int, 10> a2{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	std::array<int, 10> a3{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::array<int, 10> a4{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
	std::vector<int> v1;
	std::vector<int> v2{ 1 };
	std::vector<std::string> vs{ "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten" };

	SortAndDump(a1);
	SortAndDump(a2);
	SortAndDump(a3);
	SortAndDump(a4);
	SortAndDump(v1);
	SortAndDump(v2);
	SortAndDump(vs);

	return 0;
}


