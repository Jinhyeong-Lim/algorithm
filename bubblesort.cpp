#include<bits/stdc++.h>
using namespace std;
int a[21];

bubblesort(int a[], int n)
{
	for(int i=n-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
		
	}
	
}


int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%10000;
		printf ("%d ", a[i]);
	}
	printf("\n");
	
	bubblesort(a, n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;	
}
