#include<bits/stdc++.h>
using namespace std;
pair< pair<int, int> , int> p[100001];
int parent[1001];
bool cmp(pair< pair<int, int> , int> a, pair< pair<int, int> , int> b)
{
	return a.second < b.second;
}

int find(int x)
{
	if(parent[x]<0) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return;
	parent[y]=x;
}

int main()
{
	int n,m;
	cin >> n >> m;
	fill(parent, parent+n+1,-1);
	for(int i=0;i<m;i++)
	{
		cin >>p[i].first.first >> p[i].first.second >> p[i].second;
	}
	
	sort(p,p+m,cmp);
	int cnt=0, sum=0;
	for(int i=0;i<m;i++)
	{
		//cout << p[i].first.first <<" "<< p[i].first.second <<" "<< p[i].second;
		if(cnt==n-1) break;
		if(find(p[i].first.first) == find(p[i].first.second )) continue;
		merge(p[i].first.first, p[i].first.second);
		sum+=p[i].second;
		cnt++;
	}
	cout << sum;
	
	
	return 0;
}
