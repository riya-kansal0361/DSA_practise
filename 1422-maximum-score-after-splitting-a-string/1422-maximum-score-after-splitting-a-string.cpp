class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        
        int result = INT_MIN;
        
        int ones = count(s.begin(), s.end(), '1');
        
        int zeros = 0;
        int left_ones = 0;
        
        for(int i=0;i<=n-2;i++){
            if(s[i] == '0') zeros++;
            else left_ones++;
            
            int right_ones = ones - left_ones;
            
            result = max(result, zeros + right_ones);
        }
        
        return result;
    }
};