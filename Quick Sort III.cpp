#include <iostream>
#include <fstream>
using namespace std;

void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Divider(int arr[], int l, int h) {
	int pivot = arr[h];
	int i = (l - 1);
 
	for (int j = l; j < h; j++) {
		if (arr[j] < pivot) {
		swap(&arr[++i], &arr[j]);
		}
	}
 
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

int Median_Pivot(int arr[], int l, int h) {
	
	int pivot;
	int mid = (l + h) / 2;
	if (arr[mid] < arr[l]) 
		swap(&arr[mid], &arr[l]);
	if (arr[h] < arr[l])
		swap(&arr[h], &arr[l]);
	if (arr[h] < arr[mid])
		swap(&arr[h], &arr[mid]);
	swap(&arr[mid], &arr[h-1]);
	
	pivot = arr[h-1];
 
	return Divider(arr, l, h);
}
void QuickSort(int arr[], int l, int h) {	
	if (l < h) {
		int pi = Median_Pivot(arr, l, h);
 		QuickSort(arr, l, pi - 1);
 		QuickSort(arr, pi + 1, h);
	}
}


int main() {
   int elements = 1000, arr[elements];
    ifstream file("1000 Elements.txt");
	int count;
	count = 0;
    int read;

    while (count < elements and file >> read)
    {
    	arr[count++] = read;
	}
    cout << "\nArray read from File :-\n";
    for (int i = 0; i < count; i++)
    {
    	cout << arr[i] <<"	";
	}
    QuickSort(arr,0, elements-1);
    cout << "\n\n\nElements in Array after Sort :-\n";
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i] << "	";
    }
    cout<<endl;
    return 0;
}
