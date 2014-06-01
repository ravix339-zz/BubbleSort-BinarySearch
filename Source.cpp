/*
 * Developed by: Ravi Sinha 2013
 * This program:
 * Sorts data in ascending order using Bubble sort algorithm
 * Performs binary search of a key entered at the keyboard
 */

#include <iostream>
#include <iomanip>

using namespace std;

void sortArray(int[], int);
int binarySearch(int[], int, int);

int main()
{
	const int arraySize = 500;
	int a[arraySize] = { 0 };
	int key;
	int i;

	cout << "Enter up to 500 numbers (-909983 to quit): " << endl;
	for (i = 0; i < arraySize; ++i)
	{
		cout << i + 1 << ": ";
		cin >> a[i];
		if (a[i] == -909983)
			break;
		else
			continue;
	}

	sortArray(a, i);
	cout << "\nData items in ascending order\n";

	for (int k = 0; k < i; k++)
		cout << setw(4) << ' ' << a[k];

	cout << "\nEnter Search KEY: ";
	cin >> key;

	int loc = binarySearch(a, i, key);
	if (loc != -1)
		cout << "FOUND at location: " << loc << endl;
	else
		cout << "NOT FOUND!\a\a\a\a\a" << endl;

	cout << endl;
	system("pause");
}

void sortArray(int a[], int i)
{
	int hold;

	for (int pass = 0; pass < i - 1; pass++) // passes
	{
		for (int j = 0; j < i - 1; j++)      // one pass
		{
			if (a[j] > a[j + 1])      // one comparison
			{
				hold = a[j];                 // one swap
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
	}

}

int binarySearch(int a[], int i, int key)
{
	sortArray(a, i);
	int first = 0;
	int last = i - 1;
	while (first <= last) 
	{
		int mid = (first + last) / 2;  // compute mid point.
		if (a[mid] == key)
			return mid;// found it. return position /////
		else if (key > a[mid])
			first = mid + 1;  // repeat search in top half.
		else if (key < a[mid])
			last = mid - 1; // repeat search in bottom half.
	}
	return -1;    // failed to find key
}
