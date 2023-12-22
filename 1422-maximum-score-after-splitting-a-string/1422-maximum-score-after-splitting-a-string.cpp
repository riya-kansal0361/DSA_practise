class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        
        int result = INT_MIN;
                
        int zeros = 0;
        int ones = 0;
        
        for(int i=0;i<=n-2;i++){
            if(s[i] == '0') zeros++;
            else ones++;
            
            
            result = max(result, zeros - ones);
        }
        
        if(s[n-1] == '1') ones++;
        
        return result + ones;
    }
};