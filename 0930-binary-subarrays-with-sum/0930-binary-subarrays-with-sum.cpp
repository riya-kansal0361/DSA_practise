class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        
        int result = 0;
        int sum = 0;
        mp[sum]++;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int cum = sum - goal;
            
            if(mp[cum]){
                result += mp[cum];
            }
            mp[sum]++;
        }
        
        return result;
    }
};