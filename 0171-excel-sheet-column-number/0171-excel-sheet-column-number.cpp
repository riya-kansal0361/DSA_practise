class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(int i=0;i<columnTitle.size();i++){
            int add = result*26 + (columnTitle[i] - 'A' + 1);
            result = add;
        }
        
        return result;
    }
};