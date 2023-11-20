#include <iostream>

using namespace std;

bool CheckSorted(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	// 오른쪽으로 하나씩 밀기 (삽입 정렬의 중간 단계)
	{
		int arr[] = { 1, 2, 4, 5, 3, 6 };
		int n = sizeof(arr) / sizeof(arr[0]);

		
	}

	//int arr[] = { 8, 3, 2, 5, 1, 2 };
	//int arr[] = { 6, 5, 4, 3, 2, 1 }; // Worst
	int arr[] = { 1, 2, 3, 4, 5, 6 }; // Best
	int n = sizeof(arr) / sizeof(arr[0]);

	// Insertion Sort
	{
		Print(arr, n);
		int i, key, j;

		for (i = 1; i < n; i++)
		{
			key = arr[i];

			for (j = i; j > 0 && arr[j - 1] > key; j--)
			{
				arr[j] = arr[j - 1];

				Print(arr, n);
			}
			arr[j] = key;
			Print(arr, n);
		}

		cout << endl;
	}

	// Stability
}
