#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,m;
	cin >> n >> m;
	long long left = 1, right = m; 
 	long long ans;
    while (left <= right)
	 {
        long long mid = (left + right)/2; 
        long long sum = 0; 
        for (int i = 1; i <= n; i++)
            sum += min(n, mid/i); 
        if (sum >= m)
        {
            right = mid - 1;
			ans = mid;
        }
        else
		{
            left = mid + 1; 	
		}
    }
    cout << ans; 
	
	return 0;
}
