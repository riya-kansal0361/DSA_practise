class Solution {
public:
    int N,M,K;
    int mod = 1e9+7;
    int t[51][51][101];
    int solve(int idx, int search_cost, int max_so_far){
        if(idx == N){
            if(search_cost == K) return 1;
            
            return 0;
        }
        if(t[idx][search_cost][max_so_far] != -1) return t[idx][search_cost][max_so_far];
        int result = 0;
        for(int i=1;i<=M;i++){
            if(i>max_so_far){
                result = (result + solve(idx+1, search_cost + 1, i))%mod;
            }
            else{
                result = (result + solve(idx+1,search_cost,max_so_far))%mod;
            }
        }
        return t[idx][search_cost][max_so_far] = result%mod;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};