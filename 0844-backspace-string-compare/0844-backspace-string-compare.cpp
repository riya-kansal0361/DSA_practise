class Solution {
public:
    string BuildString(string s){
        int n = s.length();
        string temp = "";
        int i=0;
        
        while(i<n){
            if(s[i] != '#'){
                temp.push_back(s[i]);
            }
            else{
                if(temp.length()>0){
                    temp.pop_back();
                }
            }
            i++;
        }
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = BuildString(s);
        string s2 = BuildString(t);
        
        return s1 == s2;
    }
};