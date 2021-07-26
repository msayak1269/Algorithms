#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
vector<bool>visit;
vector<vector<int>>adj;
vector<int>ans;
void addEdge(int u,int v)
{
  adj[u].pb(v);
  adj[v].pb(u);
}
void dfs(int u)
{
    visit[u]=true;
    // cout<<u<<" ";
    ans.pb(u);
    for(int i=0;i<adj[u].size();i++)
    {
        if(!visit[adj[u][i]])
            dfs(adj[u][i]);
    }
}
int main(void)
{
    int V,E;
    cin>>V>>E;
    visit.assign(V,false);
    adj.assign(V,vector<int>());
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    for(int i=0;i<V;i++)
    {
        if(!visit[i])
            dfs(i);
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}