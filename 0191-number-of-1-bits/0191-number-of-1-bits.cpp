class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        // for(int i=31;i>=0;i--){
        //     if(((n>>i) & 1) == 1){
        //         count++;
        //     }
        // }
        
        // while(n){
        //     n = (n & (n-1));
        //     count++;
        // }
        
        // while(n){
        //     count += (n%2);
        //     n = n/2;
        // }
        // return count;
        
        return __builtin_popcount(n);
    }
};