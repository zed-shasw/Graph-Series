void solve(vector<int> adj[], vector<int> &visited, int i, stack<int> &st)
{
    visited[i] = 1;

    for (auto x : adj[i])
    {
        if (visited[x] == 0)
        {
            solve(adj, visited, x);
        }
    }
    st.push(i);
}

vector<int> topologicalSort(vector<int> &adj[v], int v, int e)
{
    vector<int> ans;
    stack<int> st;
    vector<int> visited(v + 1, 0);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            solve(adj, visited, i, st);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}