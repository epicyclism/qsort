# qsort
Modest generic implementation of Quick Sort

There is no optimisation for mostly sorted sets. This seems a reasonable limitation since there is an excellent implementation of sort for most purposes in the STL. (But it might be interesting to take another step).

This qsort is 'constexpr' which means it can be run at compile time. The associated sample program shows this working. This won't be available from std::sort until C++ 20. The demonstration seems unnecessarilyy convoluted, perhaps this will evolve.

The build is Windows, but the meat is header only and the test program is trivial.

No warranty, but I think this is correct within its constraints.
