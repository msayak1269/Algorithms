class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool bfs(int u,int parent,vector<bool>&visit,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        visit[u]=true;
        q.push({u,parent});
        while(!q.empty())
        {
            int front = q.front().first;
            int previous = q.front().second;
            q.pop();
            for(auto node : adj[front])
            {
                if(!visit[node])
                {
                    visit[node]=true;
                    q.push({node,front});
                }
                else if(node!=previous) return true;
            }
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
	            if(bfs(i,-1,visit,adj)) return true;
	        }
	    }
	    return false;
	}
};
