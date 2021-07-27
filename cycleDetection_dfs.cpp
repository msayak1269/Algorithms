class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(int u,int parent,vector<bool>&visit,vector<int>adj[])
    {
        visit[u]=true;
        for(auto node : adj[u])
        {
            if(!visit[node])
            {
                if(dfs(node,u,visit,adj))   return true;
            }
            else if(node!=parent)   return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>visit(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!visit[i])
	        {
	            if(dfs(i,-1,visit,adj)) return true;
	        }
	    }
	    return false;
	}
};
