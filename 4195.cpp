#include<bits/stdc++.h>
using namespace std;
int parent[2000001];
int counter[2000001];

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
 
//�� ������ ��ġ�� �Լ�
int merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u != v){//���� ���տ� ���� �ʴٸ�
        parent[v] = u;//�� ������ ����
        counter[u] += counter[v];//v������ u�� ������
        counter[v] = 1;//v�� ���߿� �ٸ� ������ ���� �� ������ 1�� �ʱ�ȭ ������
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
        
        map<string, int> index;//map�� key���� value���� pair�� �̷�� �ִ�.
        string u, v;
        int idx1, idx2;
        int num = 1;
        for(int j = 0; j < F; j++)
		{
            cin >> u >> v;
            if(index.count(u) == 0) index[u] = num++;//u�� num�� ���� ����ȣ�� �ο�
            idx1 = index[u];//u�� �ش��ϴ� value�� idx1�� ����
            if(index.count(v) == 0) index[v] = num++;//v�� num�� ���� ����ȣ�� �ο�
            idx2 = index[v];//v�� �ش��ϴ� value�� idx2�� ����
            cout << merge(idx1, idx2) << '\n';
        }
    }
	
	
	return 0;
}
