class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        
        vector<int> temp(n);
        int topCorner = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = 0;
                int count = 0;
                //[i+1][j-1], [i+1][j], [i+1][j+1];
                
                if(i+1 < m){
                    if(j-1 >= 0){
                        sum += img[i+1][j-1];
                        count++;
                    }
                    
                    sum += img[i+1][j];
                    count++;
                    
                    if(j+1 < n){
                        sum += img[i+1][j+1];
                        count++;
                    }
                    
                }
                
                //[i][j+1]
                if(j+1 < n){
                    sum += img[i][j+1];
                    count++;
                }
                
                sum += img[i][j];
                count++;
                
                //[i][j-1]
                if(j-1 >= 0){
                    sum += temp[j-1];
                    count++;
                }
                
                //[i-1][j-1], [i-1][j] , [i-1][j+1]
                if(i-1 >= 0){
                    if(j-1 >= 0){
                    sum += topCorner;
                    count++;
                    }
                
                
                sum += temp[j];
                count++;
                
                if(j+1 < n){
                    sum += temp[j+1];
                    count++;
                }
                }
                
                if(i-1 >= 0)
                topCorner = temp[j];
                
                temp[j] = img[i][j];
                
                img[i][j] = sum/count;
                
            }
        }
        
        return img;
    }
};