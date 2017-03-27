#include "sorting.hh"

template void Sortings<int, intintCompare>::swap(int*, unsigned int, unsigned int);
template void Sortings<char*, strstrCompare>::swap(char**, unsigned int, unsigned int);

template <class Elem, class Comp>
/*
*Pre-condition: an array and the two indices containing the values to be swapped
*Post-condition: the two values in the array will be properly swapped
*/
void Sortings<Elem, Comp>::swap(Elem* arr, unsigned int x, unsigned int y)
{
	Elem temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
