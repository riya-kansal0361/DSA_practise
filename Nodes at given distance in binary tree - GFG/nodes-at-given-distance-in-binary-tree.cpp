//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    Node* find(Node* root, int target){
        if(root == NULL){
            return NULL;
        }
        if(root->data == target){
            return root;
        }
        
        Node* l = find(root->left,target);
        if(l != NULL)
        return l;
        Node* r = find(root->right,target);
        return r;
        
    }
    
    void markpar(Node* root, unordered_map<Node*,Node*> &par, Node* target ){
         queue<Node*> q;
         q.push(root);

         while(!q.empty()){
             auto curr = q.front();
             q.pop();

             if(curr->left){
                 q.push(curr->left);
                 par[curr->left] = curr;
             }

             if(curr->right){
                 q.push(curr->right);
                 par[curr->right] = curr;
             }
         }
}
public:
    
    vector <int> KDistanceNodes(Node* root, int t , int k)
    {
        // return the sorted vector of all nodes at k dist
        Node* target = find(root,t);
        if(root == NULL){
            return {};
        }
        unordered_map<Node*,Node*> par;
        markpar(root,par,target);

        unordered_map<Node*,bool> vis;

        queue<Node*> q;
        q.push(target);
        vis[target] = true;

        int lvl = 0;
        while(!q.empty()){
            int n = q.size();
            if(lvl == k)  break;
            lvl++;

            while(n--){
                auto front = q.front();
                q.pop();

                if(front->left && !vis[front->left]){
                    q.push(front->left);
                    vis[front->left] = true;
                }

                if(front->right && !vis[front->right]){
                    q.push(front->right);
                    vis[front->right] = true;
                }

                if(par[front] && !vis[par[front]]){
                    q.push(par[front]);
                    vis[par[front]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        
        sort(ans.begin(),ans.end());

        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends