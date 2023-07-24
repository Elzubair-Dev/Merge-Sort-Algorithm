using namespace std;
#include<iostream>
void merge(int arr[],int l, int m,int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++)L[i] = arr[l + i];
	for (j = 0; j < n2; j++)R[j] = arr[m + 1 + j];
	j = i = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = R[j];
			k++;
			j++;
		}
	}
	while (i < n1)
	{
		arr[k] = L[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		k++;
		j++;
	}
}
void M_Sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		M_Sort(arr, l, m);
		M_Sort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}
void print(int arr[], int n)
{
	cout << "[ ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]\n\n";
}
int main()
{
	int z[] = { 20,10,40,30,50 };
	int b = sizeof(z) / sizeof(z[0]);
	print(z, b);
	cout << "---------after Merge Sort-------------------\n\n";
	M_Sort(z, 0, b - 1);
	print(z, b);
}