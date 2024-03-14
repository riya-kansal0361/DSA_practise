class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
//         unordered_map<int,int> mp;
        
//         int result = 0;
//         int sum = 0;
//         mp[sum]++;
//         for(int i=0;i<n;i++){
//             sum += nums[i];
//             int cum = sum - goal;
            
//             if(mp[cum]){
//                 result += mp[cum];
//             }
//             mp[sum]++;
//         }
        
//         return result;
        
        //SLIDING WINDOW
        
        int i=0;
        int j=0;
        
        int sum = 0;
        int result = 0;
        int zero = 0;
        
        while(j<n){
            sum += nums[j];
            
            while(i<j && (nums[i] ==0 || sum > goal)){
                if(nums[i] == 0) zero++;
                else zero=0;
                
                sum -= nums[i];
                i++;
            }
            
            if(sum == goal){
                result += 1 + zero;
            }
            j++;
        }
        
        return result;
    }
};