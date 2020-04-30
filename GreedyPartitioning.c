#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>


struct Interval
{
	double sp;
	double ep;

}typedef Interval;


void merge(Interval* arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	
	Interval* L = (Interval*)malloc(sizeof(Interval) * n1);
	Interval* R = (Interval*)malloc(sizeof(Interval) * n2);
	for (i = 0; i < n1; i++)
		*(L + i) = *(arr + l + i);
	for (j = 0; j < n2; j++)
		*(R + j) = *(arr + m + 1 + j);

	
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if ((L + i)->sp <= (R + j)->sp)
		{
			*(arr + k) = *(L + i);
			i++;
		}
		else
		{
			*(arr + k) = *(R + j);
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		*(arr+k) = *(L+i);
		i++;
		k++;
	}

	
	while (j < n2)
	{
		*(arr+k) = *(R+j);
		j++;
		k++;
	}
}

void mergeSort(Interval *arr, int l, int r)
{
	if (l < r)
	{
		
		int m = l + (r - l) / 2;

		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



void GreedyPartition()
{
	int k, i, j = 0;
	printf("Please input k \n");
	scanf("%d", &k);
	Interval* array = (Interval*)malloc(sizeof(Interval) * k);
	for (i = 0;i < k;i++)
	{
		printf("Enter Interval %d : \n", i + 1);
		printf("Enter start point: \n");
		scanf("%lf", &(array + i)->sp);
		printf("Enter end point: \n");
		scanf("%lf", &(array + i)->ep);
		printf("\n");

	}
	mergeSort(array, 0, k-1);
	for (i = 0; i < k;i++)
		printf(" (%.2f,%.2f) ", (array + i)->sp, (array + i)->ep);
	printf("\n");
	int clique_up_bound = 1;
	int smallest = 0;

	for (i = 1;i < k;i++)
	{
		if ((array + i)->sp >= (array + smallest)->ep)
		{
			smallest = i;
			clique_up_bound++;

		}
		else
		{
			if ((array + i)->ep < (array + smallest)->ep)
				smallest = i;
		}
	}
	printf("  Theta(G) = %d = Alpha(G)", clique_up_bound);
	printf("\n");


}

int main()
{
	GreedyPartition();
	system("pause");
	return 0;
}
