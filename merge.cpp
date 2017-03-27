#include "sorting.hh"

template void Sortings<int, intintCompare>::merge(int*, unsigned int);
template void Sortings<int, intintCompare>::mergeRecurse(int*, int[], unsigned int, unsigned int);
template void Sortings<char*, strstrCompare>::merge(char**, unsigned int);
template void Sortings<char*, strstrCompare>::mergeRecurse(char**, char*[], unsigned int, unsigned int);

template <class Elem, class Comp>
/*
*Pre-condition: an unsorted array and the amount of elements in the array that are to be sorted
*
*Post-condition: a sorted array
*/
void Sortings<Elem, Comp>::merge(Elem *arr, unsigned int n)
{
	if(arr != NULL && n > 1) {

		if(n < 5) { //if the array is small enough a non comparison based sort is called
			select(arr, n);
		}
		else {
			Elem temp[n]; 
			mergeRecurse(arr, temp, 0, (n - 1));
		}
	}

}
/*
*Pre-condition: An unsorted array, a temporary array of the same size, the lowest index and the highest index
*
*Post-condition: a sorted array 
*/
template <class Elem, class Comp>
void Sortings<Elem, Comp>::mergeRecurse(Elem *arr, Elem tmp[], unsigned int low, unsigned int high)
{
	int mid, i, j, k;

	if(high > low) {
		mid = low + ((high - low)/2);
		
		if((high - low) < THRESHOLD){
			select(arr, high + 1);
		}
		else {

			mergeRecurse(arr,tmp, low, mid); //recursive call for the left side of the array
			mergeRecurse(arr,tmp, mid + 1, high); //recursive call for the right side of the array
			for(i = low; i <= mid; i++) {
				tmp[i] = arr[i];
			}
			cout << "Past first loop" << endl;
			for(j = mid + 1; j <= high; i++, j++) {
				tmp[i] = arr[j];
			}
			cout << "Past second loop" << endl;
			for(i = low, j = mid + 1, k = low; k <= high; k++) { //iterates over the entire given array and compares the values and puts them in order back into the original array
				cout << i << " " << j << " " << k << endl;
				if(i <= mid && (j > high || Comp::lt(tmp[i],tmp[j]) || Comp::eq(tmp[i], tmp[j]))) {
					cout << "i before: " << i << endl;
					arr[k] = tmp[i++];
					cout << "i after: " << i << endl;
				}
				else {
					cout << "j before: " << j << endl;
					arr[k] = tmp[j++];
					cout << "j after: " << j << endl;
				}
			}
			cout << "Past third loop" << endl;
		}
	}

 cout << "Done " << low << ", " << high << endl;
}

