class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        pq.push({S, 0});
        while (pq.size())
        {
            int src = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            for (auto x : adj[src])
            {
                int node = x[0];
                int weight = x[1];
                if (dist[node] > weight + dis)
                {
                    pq.push({node, weight + dis});
                    dist[node] = weight + dis;
                }
            }
        }
        return dist;
    }
};