class Solution
{
public:
    bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj);
            }
            else if (it != parent)
                return true;
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        for (int i = 1; i < V; ++i)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};