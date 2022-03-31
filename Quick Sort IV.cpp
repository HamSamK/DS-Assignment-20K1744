#include <iostream>
#include <fstream>
using namespace std;

void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void InsertionSort(int arr[], int size)
{
    int min;
    int i;
	int j;
    for (i = 0; i < size; i++)
    {
        min = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > min)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = min ;
    }
    swap(&arr[size],&arr[size-1]);
}
int Divider(int arr[],int low,int high)
{
	int pivot = arr[(low + high)/2];
	int i = low;
	for(int j = low; j<=high ; j++)
	{
		if(arr[j]< pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void QuickSort(int arr[],int low,int high)
{
	int N = 50;
	if((high-low)<N)
	{
		InsertionSort(arr,high);
	}
	else if(low<high)
	{
		int pi = Divider(arr,low,high);
		QuickSort(arr,low,pi);
		QuickSort(arr,pi,high);
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
