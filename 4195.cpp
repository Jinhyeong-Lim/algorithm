#include<bits/stdc++.h>
using namespace std;
int parent[2000001];
int counter[2000001];

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
 
//두 집합을 합치는 함수
int merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u != v){//같은 집합에 있지 않다면
        parent[v] = u;//두 집합을 연결
        counter[u] += counter[v];//v개수를 u에 더해줌
        counter[v] = 1;//v가 나중에 다른 곳에서 쓰일 수 있으니 1로 초기화 시켜줌
    }
    return counter[u];
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	 int T;
    cin >> T;
    for(int i = 0; i < T; i++)
	{
        int F;
        cin >> F;

        for(int j = 1; j <= 2*F; j++)
		{
            parent[j] = j;
            counter[j] = 1;
        }
        
        map<string, int> index;//map은 key값과 value값이 pair를 이루고 있다.
        string u, v;
        int idx1, idx2;
        int num = 1;
        for(int j = 0; j < F; j++)
		{
            cin >> u >> v;
            if(index.count(u) == 0) index[u] = num++;//u에 num을 통해 노드번호를 부여
            idx1 = index[u];//u에 해당하는 value를 idx1에 저장
            if(index.count(v) == 0) index[v] = num++;//v에 num을 통해 노드번호를 부여
            idx2 = index[v];//v에 해당하는 value를 idx2에 저장
            cout << merge(idx1, idx2) << '\n';
        }
    }
	
	
	return 0;
}
