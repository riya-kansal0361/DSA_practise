class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;
        
        vector<int> candidates{arr[n/4], arr[n/2], arr[3*n/4]};
        
        for(int &cand : candidates){
            int left = lower_bound(arr.begin(), arr.end(), cand) - arr.begin();
            int ub = upper_bound(arr.begin(), arr.end(), cand) - arr.begin();
            int right = ub-1;
            
            if(right-left+1 > freq){
                return arr[left];
            }
        }
        
        return -1;
    }
};