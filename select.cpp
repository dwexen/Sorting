#include "sorting.hh"

template void Sortings<int, intintCompare>::select(int*, unsigned int);
template void Sortings<char*, strstrCompare>::select(char**, unsigned int);

template <class Elem, class Comp>
/*
*Pre-condition: an unsorted array and the amount of elements in the array that are to be sorted
*
*Post-condition: a sorted array
*/
void Sortings<Elem, Comp>::select(Elem *arr, unsigned int n)
{
	if(arr != NULL && n > 1) {
		int i = 0, j = 0, minIndex = 0;
		for(i = 0; i < n - 1; i++) { //outer loop puts the found min in the proper index
			minIndex = i;
			for(j = i +1; j < n; j++) //inner loop finds the min
				if(Comp::lt(arr[j],arr[minIndex]) == true) {
					minIndex = j;
				}
			swap(arr,i, minIndex);
	}

	}
}
