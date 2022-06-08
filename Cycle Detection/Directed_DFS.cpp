class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> &vis, vector<int> &visPath, vector<int> adj[])
    {
        vis[node] = 1;
        visPath[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, visPath, adj))
                    return true;
                ;
            }
            if (vis[it] && visPath[it])
                return true;
        }

        visPath[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V + 1, 0), visPath(V + 1, 0);
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, visPath, adj))
                    return true;
            }
        }
        return false;
    }
};