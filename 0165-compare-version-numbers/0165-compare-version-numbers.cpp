class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0,l1 = v1.length(), l2 = v2.length(),n1,n2;
        
        while(i<l1 || j<l2){
            n1 = 0;
            n2 = 0;
            
        while(i < l1 && v1[i] != '.'){
            n1 = (n1*10) + (v1[i] - '0');
            i++;
        }
            
        while(j<l2 && v2[j] != '.'){
            n2 = (n2*10) + (v2[j] - '0');
            j++;
        }
            
            if(n1<n2) return -1;
            if(n1>n2) return 1;
            
            i++;
            j++;
        }
        return 0;
    }
};