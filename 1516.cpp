#include<bits/stdc++.h>
using namespace std;
int a[501];
int b[501];
int de[501];
int main()
{
	int n;
	cin >> n;
	vector<int> adj[n+1];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=a[i];
		while(1)
		{
			int w;
			cin >> w;
			if(w==-1) break;
			adj[w].push_back(i);
			de[i]++;
		}	
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(de[i]==0)
		{
			q.push(i);
			b[i]=a[i];
		}
	}
	
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		for(int j=0;j<adj[i].size();j++)
		{
			b[adj[i][j]] = max(b[adj[i][j]], b[i]+a[adj[i][j]]);
			if(--de[adj[i][j]]==0)
			{
				q.push(adj[i][j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout << b[i] << endl;
	}
	
	return 0;
}
