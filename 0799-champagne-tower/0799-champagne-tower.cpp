class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
           vector<vector<double>> t(101, vector<double>(101, 0.0));
        t[0][0] = (double)poured;
        
        for(int row = 0; row<=query_row; row++) {
            //0th row has 0th column
            //1st row had 0th column, 1st column
            //2nd row has 0th column, 1st column, 2nd column
            //so, col = 0; col <= row
            for(int col = 0; col<=row; col++) {
                
                double excess = (t[row][col] - 1.0)/2.0;
                
                if(excess > 0) { //it means it will flow in next row (two glasses below it)
                    t[row+1][col]   += excess;
                    t[row+1][col+1] += excess;
                }
            }
        }
        
        //It may be the case that some Champagne was excess in t[query_row][query_glass]
        //So, And we need to tell how much Champagne is in there in t[query_row][query_glass]
        //Hence, we will return 1 in that case and so is the statement below
        return min(1.0, t[query_row][query_glass]);
    }
};