class Solution {
public:
    vector<int> result;
    void dfs(int u,int prev,unordered_map<int,vector<int>> &adj){
        result.push_back(u);
        
        for(auto &it : adj[u]){
            if(it != prev){
                dfs(it,u,adj);
            }
        }
            
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adj;
        
        for(auto &it : adjacentPairs){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int start = -1;
        
        for(auto &it : adj){
            if(it.second.size() == 1){
                start = it.first;
                break;
            }
        }
        
        dfs(start,INT_MIN,adj);
        return result;
    }
};