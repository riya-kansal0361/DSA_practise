class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i=k;
        int j=k;
        int currMin = nums[k];
        int result = nums[k];
        
        while(i>0 || j<n-1){
            int left_val = (i>0) ? nums[i-1] : 0;
            int right_val = (j<n-1) ? nums[j+1] : 0;
            if(left_val > right_val){
                i--;
                currMin = min(currMin, left_val);
                result = max(result, currMin* (j-i+1));
            }
            else{
                j++;
                currMin = min(currMin, right_val);
                result = max(result, currMin* (j-i+1));
            }
        }
        return result;
    }
};