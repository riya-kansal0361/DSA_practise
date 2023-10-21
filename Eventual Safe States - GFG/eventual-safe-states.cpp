//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        queue<int> q;
        vector<int> indegree(V,0);
        
        vector<vector<int>> graph(V);
        
        for(int u=0;u<V;u++){
            for(int &v : adj[u]){
                graph[v].push_back(u);
                indegree[u]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<bool> safe_states(V,false);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            safe_states[u] = true;
            
            for(int &v : graph[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        vector<int> safe;
        for(int i=0;i<V;i++){
            if(safe_states[i] == true){
                safe.push_back(i);
            }
        }
        return safe;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends