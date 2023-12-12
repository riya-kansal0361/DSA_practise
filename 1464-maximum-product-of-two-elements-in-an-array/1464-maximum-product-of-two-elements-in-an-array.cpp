class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 0;
        int sl = 0;
        
        for(int &num : nums){
            if(num > l){
                sl = l;
                l = num;
            }
            else{
                sl = max(sl,num);
            }
        }
        
        return (l-1)*(sl-1);
    }
};