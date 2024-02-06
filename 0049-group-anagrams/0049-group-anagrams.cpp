class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(auto &it : strs){
            string s = it;
            sort(it.begin(), it.end());
            string t = it;
            
                mp[t].push_back(s);
        
        }
        
        for(auto &it : mp){
            vector<string> s;
            for(auto &i : it.second){
                s.push_back(i);
            }
            ans.push_back(s);
        }
        
        return ans;
    }
};