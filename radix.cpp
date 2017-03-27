#include "sorting.hh"

template void Sortings<int, intuival>::radix(int*, unsigned int);
template <class Elem, class Comp>
/*
*Pre-condition: An unsorted array and the amount of elements that will be sorted
* 
*Post-condition: A sorted array
*/
void Sortings<Elem, Comp>::radix(Elem *arr, unsigned int n)
{
	if(arr != NULL && n > 1) {


		int count[RADIX]; 
		int b[n];
		int exp, max, i;
		for(i = 1, max = arr[0]; i < n; i++){ //finds the maximum value in the array and also checks for negative numbers
			arr[i] = Comp::uintVal(arr[i]);
			if(arr[i] > max) {
				max = arr[i];
			}
		}
	
	
	
		for(exp = 1; max/exp > 0; exp *= RADIX) {
			for(i = 0; i < RADIX; i++) { //clears each bucket every iteration
				count[i] = 0;
			}
			for(i = 0; i < n; i++) { //counting the size of each bucket
				count[(arr[i] / exp) % RADIX]++;
			}
			for(i = 1; i < RADIX; i++) { //makes count represent bucket indexes
				count[i] += count[i - 1];
			}
			for(i = n - 1; i >= 0; i--) { //moves the unsorted items into the proper buckets
				b[--count[(arr[i]/exp) % RADIX]]=arr[i];
			}
			for(i = 0; i < n; i++) { //moving the items back into the array
				arr[i] = b[i];
			}
		}
	}
}
