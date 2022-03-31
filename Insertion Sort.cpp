#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
}

int main()
{
    int elements = 50, arr[elements];
    ifstream file("50 Elements.txt");
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
    InsertionSort(arr, elements);
    cout << "\n\n\nElements in Array after Sort :-\n";
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i] << "	";
    }
    cout<<endl;
    return 0;
}


