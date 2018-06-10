#include <iostream>
using namespace std;

int partition(int *A, int start, int end);
void QuickSort(int *A, int start, int end);

int partition(int *A, int start, int end)
{
	//First select pivot
	int pivot = A[end];
	int pindex=start;

	for(int i=start;i<=end-1;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[pindex]);
			pindex++;
		}
	}
	swap(A[pindex], A[end]);
	return pindex;
}

void QuickSort(int *A, int start, int end)
{
	if(start<end)
	{
		int pindex = partition(A, start, end);
		QuickSort(A, start, pindex-1);
		QuickSort(A, pindex+1, end);
	}
}

int main()
{
	int A[]={7,2,5,45,32,67,1,0};
	QuickSort(A,0,7);

	for(int i=0;i<8;i++)
		cout << A[i] << " ";

	return 0;
}


