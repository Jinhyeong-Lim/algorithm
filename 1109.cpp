#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	int m,n;
	cin >> m >> n;
	
	vector<int> bot,top;
	 
	for(int i=0;i<m;i++)
	{
		int b;
		cin >> b;
		if(i%2==0) bot.push_back(b);
		else top.push_back(b);
	}
	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());
	int cnt=987654321, sum=1;
	for(int i=1;i<=n;i++)
	{
		int tmp=bot.size()-(lower_bound(bot.begin(), bot.end(), i)-bot.begin());
		tmp+=top.size()-(upper_bound(top.begin(), top.end(), n-i)-top.begin());
		
		
		if(cnt==tmp)
		{
			sum++;
		}
		else if(cnt>tmp)
		{
			sum=1;
			cnt=tmp;
		}
	}
	printf("%d %d", cnt, sum);
	
	return 0;
}
