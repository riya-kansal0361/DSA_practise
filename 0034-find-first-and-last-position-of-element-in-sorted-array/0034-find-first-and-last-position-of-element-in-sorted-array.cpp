class Solution {
public:
    int find_left(vector<int>& arr, int n, int target){
        int left = -1;
        
        int l=0,r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid] == target){
                left = mid;
                r = mid-1;
            }
            else if(arr[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return left;
    }
    int find_right(vector<int>& arr, int n, int target){
        int right = -1;
        
        int l=0,r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid] == target){
                right = mid;
                l = mid+1;
            }
            else if(arr[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = find_left(nums,n,target);
        int r = find_right(nums,n,target);
        
        return {l,r};
    }
};