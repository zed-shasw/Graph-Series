class Solution
{
    
    void dfs(int node, stack<int> &st, vector<int> adj[], vector<bool> &vis) {
        vis[node] = true;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x,st,adj,vis);
            }
        }
        st.push(node);
    }
    
    void reverseDFS(int node, vector<int> transpose[], vector<bool> &vis, vector<int> &v){
        vis[node] = true;
        v.push_back(node);
        for(auto x: transpose[node]){
            if(!vis[x]) reverseDFS(x,transpose,vis,v);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> vis(V, false);
        
        // storing in stack(for concept of TopoSort)
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i,st,adj,vis);
            }
        }
        
        vector<int> transpose[V];
        for(int i=0; i<V; i++) {
            vis[i]=false;
            for(auto x: adj[i]) {
                transpose[x].push_back(i);
            }
        }
        
        vector<vector<int>> res; // to store the strongly components
        
        while(st.size()){
            int i = st.top();
            st.pop();
            if(!vis[i]) {
                vector<int> v;
                reverseDFS(i,transpose,vis,v);
                res.push_back(v);
            }
        }
        
        return res.size();
        
    }
};