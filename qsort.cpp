// test cool qsort
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
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

template<typename C, typename F> void SortAndDumpF(C& c, F f)
{
	std::cout << "   ";
	Dump(c);
	std::cout << "-> ";
	qsort(std::begin(c), std::end(c), f);
	Dump(c);
	std::cout << "\n";
}

template<typename I1, typename O1, typename F> constexpr O1 ctransform(I1 b, I1 e, O1 o, F f)
{
	while (b != e)
	{
		*o = f(*b);
		++b;
		++o;
	}
	return o;
}

template<typename C, int sz> constexpr auto CompileTimeSortedString( C const* s) -> std::array<C, sz>
{
	std::array<C, sz> rv{};
	ctransform(s, s + sz, std::begin(rv), [](auto c) { return c; });
	qsort(std::begin(rv), std::end(rv));

	return rv;
}

template<typename C, int sz> constexpr auto CompileTimeReverseSortedString( C const* s) -> std::array<C, sz>
{
	std::array<C, sz> rv{};
	ctransform(s, s + sz, std::begin(rv), [](auto c) { return c; });
	qsort(std::begin(rv), std::end(rv), [](auto l, auto r) { return l > r; });

	return rv;
}

constexpr std::array<char, 26> alpha = CompileTimeSortedString<char, 26>("FKQHTLXOCBJSPDZRAMEWNIUYGV");
constexpr std::array<char, 26> alphar = CompileTimeReverseSortedString<char, 26>("FKQHTLXOCBJSPDZRAMEWNIUYGV");

int main()
{
	std::cout << "Testing default ordering\n";
	std::array<int, 10> a1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::array<int, 10> a2{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	std::array<int, 10> a3{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::array<int, 10> a4{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
	std::vector<int> v1;
	std::vector<int> v2{ 1 };
	std::vector<std::string> vs{ "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
	std::array<int, 10> a5{ 9, 8, 7, 6, 7, 4, 3, 2, 1, 0 };
	std::array<int, 10> a6{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::array<int, 10> a7{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
	std::vector<std::string> vs2{ "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };

	std::cout << "In order\n";
	SortAndDump(a1);
	std::cout << "Reverse order\n";
	SortAndDump(a2);
	std::cout << "All same\n";
	SortAndDump(a3);
	std::cout << "Pseudo random\n";
	SortAndDump(a4);
	std::cout << "Empty vector\n";
	SortAndDump(v1);
	std::cout << "Vector with single item\n";
	SortAndDump(v2);
	std::cout << "Vector with strings\n";
	SortAndDump(vs);
	std::cout << "In order with reverse predicate\n";
	SortAndDumpF(a5, [](auto l, auto r) { return l < r; });
	std::cout << "Out of order with reverse predicate\n";
	SortAndDumpF(a6, [](auto l, auto r) { return l > r; });
	std::cout << "Pseudo random with reverse predicate\n";
	SortAndDumpF(a7, [](auto l, auto r) { return l > r; });
	std::cout << "Vector with strings with reverse predicate\n";
	SortAndDumpF(vs2, [](auto l, auto r) { return l > r; });

	std::cout << "Sorted default at compile time\n";
	Dump(alpha);
	std::cout << "\nReverse sorted default at compile time\n";
	Dump(alphar);

	return 0;
}


