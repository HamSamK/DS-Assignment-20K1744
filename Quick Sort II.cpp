#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Divider(int arr[], int l, int h) {
    
  int pivot = arr[h], i = (l - 1);
  
  for (int j = l; j < h; j++) 
  {
    if (arr[j] <= pivot) 
	{
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[h]);
  return (i + 1);
}
int Random_Pivot(int arr[], int l, int h)
{
	srand(time(NULL));
	int random = l + rand() % (h - l);
	swap(arr[random], arr[h]);
	return Divider(arr, l, h);
}

void QuickSort(int arr[], int l, int h) 
{
  if (l < h) 
  {
    int pi = Random_Pivot(arr, l, h);
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
