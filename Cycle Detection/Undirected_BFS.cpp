class Solution
{
public:
    bool bfs(int i, int V, vector<bool> &vis, vector<int> adj[])
    {
        vis[i] = true;
        queue<pair<int, int>> q;
        q.push({i, -1});
        while (q.size())
        {
            pair<int, int> node = q.front();
            q.pop();
            for (auto x : adj[node.first])
            {
                if (!vis[x])
                {
                    q.push({x, node.first});
                    vis[x] = true;
                }
                else if (x != node.second)
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V - 1, false);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (bfs(i, V, vis, adj))
                    return true;
            }
        }
        return false;
    }
};