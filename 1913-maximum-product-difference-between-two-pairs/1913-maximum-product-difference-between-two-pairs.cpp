class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int l = INT_MIN;
        int sl = INT_MIN;
        
        int s = INT_MAX;
        int ss = INT_MAX;
        
        for(int i=0;i<n;i++){
            if(nums[i] > l){
                 sl = l;
                l = nums[i];

            }
            else if(nums[i] > sl){
                sl = nums[i];
            }
            
            if(nums[i]< s){
                ss = s;
                s = nums[i];
            }
            
            else if(nums[i] < ss){
                ss = nums[i];
            }
        }
        
        return (l*sl) - (s*ss);
    }
};