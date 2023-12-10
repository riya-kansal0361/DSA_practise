class Solution {
public:
    int first(vector<int>& nums, int target){
        int n = nums.size();
        int result = -1;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target){
                result = mid;
                high = mid-1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
    
    int last(vector<int>& nums, int target){
        int n = nums.size();
        int result = -1;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target){
                result = mid;
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = first(nums,target);
        int h = last(nums,target);
        
        return {l,h};
    }
};