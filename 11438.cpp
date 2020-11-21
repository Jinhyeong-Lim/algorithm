#include<bits/stdc++.h>
using namespace std;
const int MAX = 18; // roundup log(2, 100000)
 
int N, M;
int parent[100000][MAX]; // parent[i][k]: i�� 2^k��° �θ�
int depth[100000]; // ������ ���� (��Ʈ�� ����: 0)
vector<int> adj[100000]; // ���� ����Ʈ
 
// dfs�� Ʈ�� �����ϸ� parent[i][0], depth �迭 ä��
void makeTreeByDFS(int curr){
	
    for(int i=0;i<adj[curr].size();i++){
    	int k=adj[curr][i];
        if(depth[k] == -1){
            parent[k][0] = curr;
            depth[k] = depth[curr] + 1;
            makeTreeByDFS(k);
        }
    }
}
 
 
int main(){
    // Ʈ�� ���� �Է�
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // �迭 �ʱ�ȭ
    memset(parent, -1, sizeof(parent));
    fill(depth, depth+N, -1);
    depth[0] = 0;
    // Ʈ�� �����
    makeTreeByDFS(0);
 
    // parent �迭 ä��
    for(int j=0; j<MAX-1; j++)
        for(int i=1; i<N; i++)
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];
 
    // ���� �Է¹ޱ�
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
 
        // depth[u] >= depth[v]�� �ǵ��� �ʿ信 ���� u, v�� ����
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
 
        // ���� ��(diff)�� ���ָ� u�� �̵���Ŵ
        for(int j=0; diff; j++){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }
 
        // u�� v�� �ٸ��� ���ÿ� ���� ���̸�ŭ ���� �̵���Ŵ
        if(u != v){
            // ���� 2^17, 2^16, ..., 2^2, 2, 1 ������ �õ�
            for(int j=MAX-1; j>=0; j--){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            // �������� �� ���� u, v�� �θ� �����Ƿ� �� �� �� �ø�
            u = parent[u][0];
        }
 
        // LCA ���
        printf("%d\n", u+1);
    }
}





