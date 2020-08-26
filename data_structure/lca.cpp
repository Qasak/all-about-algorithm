#include<bits/stdc++.h>
using namespace std;
int const MAX_V = 1<<17;
vector<int> G[MAX_V]; // 邻接链表有向图

void print_vector(vector<int>& a) {
    for(int i=0;i<a.size();i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int root;
int parent[MAX_V];//根节点的父节点为-1
int depth[MAX_V];

void dfs(int v, int p, int d) {
    parent[v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++) {
        if(G[v][i]!=p) {
            dfs(G[v][i],v,d+1);
        }
    }
}

int lca(int u, int v) {
    //让u,v向上走到同一深度
    while(depth[u]>depth[v]) u=parent[u];
    while(depth[u]<depth[v]) v=parent[v];
    //让u,v向上走到统一节点
    while(u!=v) {u=parent[u];v=parent[v];}
    return u;
}

int main() {
    freopen("lca_in.txt","r",stdin);
    int n;
    cin>>n;
    int E=n-1;
    for(int i=0;i<2*E;i++) {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) {
        printf("Node %d:",i);
        print_vector(G[i]);
    }
    dfs(1,-1,0);
    for(int i=1;i<=n;i++) {
        printf("%d's Parent: %d\n",i, parent[i]);
        printf("%d's Depth: %d",i, depth[i]);
        cout<<endl;
    }
    int u,v;
    cin>>u>>v;
    cout<<lca(u,v);
    return 0;
}
