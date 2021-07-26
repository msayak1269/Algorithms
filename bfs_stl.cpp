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
void bfs(int u)
{
  queue<int>q;
  q.push(u);
  visit[u]=true;
  while(!q.empty())
  {
    int f = q.front();
    q.pop();
    // cout<<f<<" ";
    ans.pb(f);
    for(int i=0;i<adj[f].size();i++)
    {
      if(!visit[adj[f][i]])
      {
        q.push(adj[f][i]);
        visit[adj[f][i]]=true;
      }
    }
  }
}
int main(void)
{
    int V,E;cin>>V>>E;
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
        bfs(i);
    }
    for(int i=0;i<ans.size();i++)
    {
      cout<<ans[i]<<" ";
    }
    return 0;
}
