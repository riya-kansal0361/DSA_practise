class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> child_to_parent;
        
        for(int i=0;i<n;i++){
            int node = i;
            
            int leftc = leftChild[node];
            
            if(leftc != -1){
                adj[node].push_back(leftc);
                
                if(child_to_parent.find(leftc) != child_to_parent.end()){
                    return false;
                }
                child_to_parent[leftc] = node;
            }
            
            int rightc = rightChild[node];
            
            if(rightc != -1){
                adj[node].push_back(rightc);
                
                if(child_to_parent.find(rightc) != child_to_parent.end()){
                    return false;
                }
                child_to_parent[rightc] = node;
            }
        }
            
            int root = -1;
            for(int i=0;i<n;i++){
                if(child_to_parent.find(i) == child_to_parent.end()){
                    if(root != -1) return false;
                    
                    root = i;
                }
            }
            
            if(root == -1) return false;
        
        queue<int> q;
        int count=0;
        vector<bool> visited(n,false);
        
        q.push(root);
        visited[root] = true;
        count++;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int &v : adj[curr]){
                visited[v] = true;
                count++;
                q.push(v);
            }
        }
        
        return count == n;
    }
};