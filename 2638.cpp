#include<bits/stdc++.h>
using namespace std;
int a[101][101];
bool check[101][101];
int const dx[]={1, -1, 0, 0};
int const dy[]={0, 0, 1, -1};
int sum=0, n, m;
void dfs(int x, int y)
{
	int cnt=0;
	check[y][x]=true;
		for(int i=0;i<4;i++)
			{
				int nx=x+dx[i], ny=y+dy[i];
				if(nx>=0&&ny>=0&&nx<m&&ny<n)
				{
					if(a[ny][nx]==0) cnt++;
				}
			}
			
			if(cnt>=2)
			{
				a[y][x]=-1;
				sum--;
			}
			
			
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i], ny=y+dy[i];
				if(nx>=0&&ny>=0&&nx<m&&ny<n&&!check[ny][nx]&&a[ny][nx]==1)
				{
					
					dfs(nx, ny);
				}
			}
}


int main()
{
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
			if(a[i][j]==1) sum++;
		}
	}
	int ans=0;
	//printf("%d\n", sum);
	
	while(1)
	{
		ans++;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]==1&&check[i][j]==false)
				{
					
					dfs(j,i);
					if(sum==0)
					{
						printf("%d\n", ans);
						return 0;
					}
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				check[i][j]=false;
				if(a[i][j]==-1) a[i][j]=0;
				//printf("%d ", a[i][j]);
			}
		//	printf("\n");
		}
	//	printf("%d\n", sum);
		
	}
	
	
	return 0;
}
