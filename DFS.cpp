class Solution
{
public:
    void dfs(int i, vector<bool> &vis, vector<int> adj[], vector<int> &storeDFS)
    {
        storeDFS.push_back(i);
        vis[i] = true;
        for (auto it : adj[i])
        {
            if (!vis[it])
                dfs(it, vis, adj, storeDFS);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> storeDFS;
        vector<bool> vis(V + 1, false);
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
                dfs(i, vis, adj, storeDFS);
        }
        return storeDFS;
    }
};