#include <iostream>
using namespace std;

void MergeSort(int* A, int n);
void Merge(int *left, int *right, int *A, int mid, int);

void MergeSort(int *A, int n)
{

	if(n<2)
		return;

	int mid=n/2;
	int left[mid], right[n-mid], i;

	//fill up the sub-arrays
	for(i=0;i<=mid-1;i++)
		left[i]=A[i];
	for(i=mid;i<=n-1;i++)
		right[i-mid]=A[i];

	MergeSort(left, mid);
	MergeSort(right, n-mid);
	Merge(left, right, A, mid, n-mid);

}

void Merge(int *L, int *R, int *A, int nL, int nR)
{

	int i=0,j=0,k=0;

	while(i<nL && j<nR)
	{
		if(L[i]<R[j])
		{
			A[k]=L[i];
			k++;
			i++;
		}
		else
		{
			A[k]=R[j];
			k++;
			j++;
		}
	}

	while(i<nL)
	{
		A[k]=L[i];
		k++;
		i++;
	}
	while(j<nR)
	{
		A[k]=R[j];
		k++;
		j++;
	}

}

int main()
{
	int A[]= {2,3,87,1,46,8,3};
	int n=sizeof(A)/sizeof(A[0]);


	MergeSort(A, n);

	cout << "The merge sorted elements are: " << endl;

	for(int i=0;i<n;i++)
		cout << A[i] << endl;

	return 0;
}








