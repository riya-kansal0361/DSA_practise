class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> mp(26,0);
        
        for(char &ch : tasks){
            mp[ch-'A']++;
        }
        sort(mp.begin(),mp.end());
        int maxFreq = mp[25];
        int gadhe =maxFreq-1;
        int idle = n*gadhe;
        
        for(int i=24;i>=0;i--){
            
            idle -= min(mp[i],gadhe);
        }
        
        if(idle>0) return tasks.size()+idle;
        
        
        return tasks.size();
    }
};