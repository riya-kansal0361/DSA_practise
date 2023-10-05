class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj1 = NULL;
        int count1 = 0;
        
        int maj2 = NULL;
        int count2 = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] == maj1){
                count1++;
            }
            else if(nums[i] == maj2){
                count2++;
            }
            else if(count1 == 0){
                maj1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                maj2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        vector<int> result;
        int f1 = 0, f2 = 0;
        for(int &num : nums){
            if(num == maj1) f1++;
            else if(num == maj2) f2++;
        }
        
        if(f1 > floor(n/3)) result.push_back(maj1);
        if(f2 > floor(n/3)) result.push_back(maj2);
        
        return result;
    }
};