#include <iostream>
#include <fstream>
using namespace std;

void Merge_Array(int arr[], int p, int q, int r) 
{

  int num1 = q - p + 1, num2 = r - q;

  int L[num1], Mid[num2];

  for (int i = 0; i < num1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < num2; j++)
    Mid[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < num1 && j < num2) {
    if (L[i] <= Mid[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = Mid[j];
      j++;
    }
    k++;
  }

  while (i < num1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < num2) {
    arr[k] = Mid[j];
    j++;
    k++;
  }
}

void MergeSort(int arr[], int l, int r) 
{
  if (l < r) 
  {
    int m = l + (r - l) / 2;
	MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge_Array(arr, l, m, r);
  }
}


int main() 
{
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
    MergeSort(arr,0, elements);
    cout << "\n\n\nElements in Array after Sort :-\n";
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i] << "	";
    }
    cout<<endl;
    return 0;
}

