#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,y,z, ans;
	cin >> x >> y;
	z = y*100/x+1;

	if(z>=100)
	{
		printf("-1");
		return 0;
	}
	long long left = 1, right = 1000000000;
	
	while(left<=right)
	{
		long long mid = (left+right)/2;
		if(z<=(y+mid)*100/(x+mid))
		{
			right = mid-1;
			ans = mid;
		}
		else left = mid+1;
		
	}
	cout<< ans;
	
	
	return 0;
}
