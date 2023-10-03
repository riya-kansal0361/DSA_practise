//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        
        while(n){
        long long rem = n%26;
        if(rem == 0){
            ans = "Z" + ans;
            n = n/26 - 1;
        }
        else{
            char ch = 'A' + rem - 1;
            ans = ch + ans;
            n = n/26;
        }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends