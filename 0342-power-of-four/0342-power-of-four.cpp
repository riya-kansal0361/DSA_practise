class Solution {
public:
    bool isPowerOfFour(int n) {
//         while(n%4==0){
//             n = n/4;
//         }
        
//         if(n==1) return true;
        
//         return false;
         if(n <= 0) return false;
//         int x = log(n)/log(4);
        
//         if(n == pow(4,x)) return true;
        
//         return false;
        
        if((n&(n-1)) == 0 && (n-1)%3 == 0) return true;
        
        return false;
    }
};