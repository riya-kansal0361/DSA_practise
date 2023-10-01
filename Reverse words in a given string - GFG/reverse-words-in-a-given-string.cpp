//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        int n = s.length();
        int i=n-1;
        int j=n-1;
        string result = "";
        while(i >= 0){
            if(s[i] == '.'){
                result += s.substr(i+1,j-i) + '.';
                j=i-1;
            }
            i--;
        }
        result += s.substr(i+1,j-i);
        return result.substr(0,result.length());
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends