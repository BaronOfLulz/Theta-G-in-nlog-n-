#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>


struct Interval
{
	double sp;
	double ep;
	int cliq_color;
}typedef Interval;


Interval_pswap(Interval *i1, Interval *i2) 
{
	Interval temp = *i1;
	*i1 = *i2;
	*i2 = temp;


}
cocktail_shaker_sort_Interval(Interval *arr, int k)/*I know that Cocktail shaker is n^2 but I wrote it here to save space.
                                                    Just replace it with mergesort and you have a program that runs in nlogn*/
{
	int p, i;
	for (p = 1; p <= k / 2; p++)
	{
		for (i = p - 1; i < k - p; i++)
			if ((arr + i)->sp > (arr + i + 1)->sp)
				Interval_pswap((arr + i), (arr + i + 1));
		for (i = k - p - 1; i >= p; i--)
			if ((arr + i)->sp < (arr + i - 1)->sp)
				Interval_pswap((arr + i), (arr + i - 1));
	}

}


void GreedyPartition()
{
	int k, i, j = 0;
	printf("Please input k \n");
	scanf("%d", &k);
	Interval *array = (Interval*)malloc(sizeof(Interval)*k);
	for (i = 0;i < k;i++)
	{
		printf("Enter Interval %d : \n", i + 1);
		printf("Enter start point: \n");
		scanf("%lf", &(array + i)->sp);
		printf("Enter end point: \n");
		scanf("%lf", &(array + i)->ep);
		printf("\n");
		(array + i)->cliq_color = -1;
	}
    cocktail_shaker_sort_Interval(array, k);

	for (i = 0; i < k;i++)
		printf(" (%.2f,%.2f) ", (array + i)->sp, (array + i)->ep);
	printf("\n");
	int clique_up_bound = 1;
	int smallest = 0;
	(array)->cliq_color = 1; 
	for (i = 1;i < k;i++)
	{
		if ((array + i)->sp >= (array + smallest)->ep)
		{
			smallest = i; 
			clique_up_bound++; 
			(array + i)->cliq_color = clique_up_bound; 
		}
		else
		{
			(array + i)->cliq_color = clique_up_bound;
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
