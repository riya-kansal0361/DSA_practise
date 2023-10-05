//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long solve(string &s, int n, int p){
        int c[26] = {0};
        int f = 0;
        long long count = 0;
        int i,j;
        i=j=0;
        for(int i=0;i<n;i++){
    
            while(j<n && f<p){
                 c[s[j]- 97]++;
                 if(c[s[j] - 97] == 1) f++;
                 j++;
            }
            
            if(f >= p){
                count += (n - j + 1);
            }
            c[s[i] - 97]--;
            if(c[s[i] - 97] == 0)f--;
        }
        return count;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	int n = s.length();
    	return solve(s,n,k) - solve(s,n,k+1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends