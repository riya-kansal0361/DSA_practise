class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> rowarr(m,0);
        vector<int> colarr(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    rowarr[i]++;
                    colarr[j]++;
                }
            }
            
        }
        int result = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1 && rowarr[i] == 1 && colarr[j] == 1){
                    result++;
                }
            }
        }
        
        return result;
    }
};