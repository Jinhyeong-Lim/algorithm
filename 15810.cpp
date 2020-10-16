#include<bits/stdc++.h>
using namespace std;
long long int a[1000001];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);		
	long long left=0LL, right=a[0]*m;
	long long mid;
	long long ans;
	while (left <= right)
    {
        mid = (left + right) / 2;
        long long total = 0LL;
        for (int i = 0; i < n; i++)
                total += mid/a[i];
 
        if (total >= m)
        {
            //printf("%d %d\n", left, right);
            right = mid - 1;
            ans = mid;
        }
        

        else
        {
            left=mid+1;
        }
 		//printf("%d %d %d %d \n", mid, left, right, total);
    }
    printf("%lld", ans);
	
	return 0;
}
