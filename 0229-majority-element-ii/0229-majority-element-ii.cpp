class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        int mini = (int)(n/3) + 1;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == mini){
                ls.push_back(nums[i]);
            }
        }

        return ls;
    }
};