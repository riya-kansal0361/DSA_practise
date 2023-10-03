class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        
        int result = 0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                result += mp[nums[i]];
            }
            
            mp[nums[i]]++;
        }
        return result;
    }
};