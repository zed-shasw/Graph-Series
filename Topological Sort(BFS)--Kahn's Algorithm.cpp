class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V, 0), ans;
        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
            for (auto it : adj[i])
            {
                // i--->it
                indegree[it]++;
            }
        }
        for (int i = 0; i < V; ++i)
            if (indegree[i] == 0)
                q.push(i);
        while (q.size())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};