class Solution {
public:
    string generate(string &word){
        int arr[26] = {0};
        
        for(int i=0;i<word.size();i++){
            arr[word[i] - 'a']++;
        }
        string ans = "";
        
        for(int i=0;i<26;i++){
            int freq = arr[i];
            
            ans += string(freq, i+'a');
        }
       return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        
        
        for(auto &it : strs){
            string s = it;
            
            string new_word = generate(s);
            
            mp[new_word].push_back(s);
        }
        
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};