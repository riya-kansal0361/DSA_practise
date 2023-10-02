class Solution {
public:
    bool hasDuplicate(string s1, string s2){
        int arr[26] = {0};
        
        for(char &ch : s1){
            if(arr[ch - 'a'] >  0) return true;
            arr[ch-'a'] ++;
        }
        
        for(char &ch : s2){
            if(arr[ch-'a'] > 0) return true;
        }
        return false;
    }
    unordered_map<string,int> mp;
    int solve(vector<string>&arr, int idx, string temp, int n){
        if(idx >= n){
            return temp.length();
        }
        if(mp.find(temp) != mp.end()) return mp[temp];
        int include = 0;
        int exclude = 0;
        
        if(hasDuplicate(arr[idx], temp)){
            exclude = solve(arr,idx+1,temp,n);
        }
           else{
               exclude = solve(arr,idx+1,temp,n);
               include = solve(arr,idx+1,temp+arr[idx],n);
           }
           return mp[temp] =    max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        mp.clear();
        string temp = "";
        int idx = 0;
        return solve(arr,idx,temp,n);
    }
};