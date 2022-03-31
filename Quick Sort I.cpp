#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

void swap(int *a, int *b) 
{
  int x = *a;
  *a = *b;
  *b = x;
}

void QuickSort(int arr[], int le, int ri) {

      int i = le;
	  int j = ri;
      int x;
      int pivot = arr[(le + ri) / 2];

      while (i <= j) 
	  {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) 
			{
                  x = arr[i];
                  arr[i] = arr[j];
                  arr[j] = x;
                  i++;
                  j--;
            }
      };
      if (le < j)
      {
      	QuickSort(arr, le, j);
	  }
            
      if (i < ri)
      {
      	QuickSort(arr, i, ri);
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
