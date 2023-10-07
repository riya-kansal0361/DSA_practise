class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        
        while(pq.size() > 1){
            int topfreq1 = pq.top().first;
            int topchar = pq.top().second;
            pq.pop();
            
            if(topfreq1 > 1){
                ans += topchar;
                ans += topchar;
                topfreq1-=2;
            }
            else{
                ans += topchar;
                topfreq1--;
            }
            
            int topfreq2 = pq.top().first;
            int topchar2 = pq.top().second;
            pq.pop();
            
            if(topfreq2 > 1 && topfreq2 >= topfreq1){
                ans += topchar2;
                ans += topchar2;
                topfreq2-=2;
            }
            else{
                ans += topchar2;
                topfreq2--;
            }
            if(topfreq1 > 0) pq.push({topfreq1, topchar});
            if(topfreq2 > 0) pq.push({topfreq2, topchar2});
        }
        
        while(!pq.empty()){
            int topfreq1 = pq.top().first;
            int topchar = pq.top().second;
            pq.pop();
            
            if(topfreq1 > 1){
                ans += topchar;
                ans += topchar;
                topfreq1-=2;
            }
            else{
                ans += topchar;
                topfreq1--;
            }
        }
        return ans;
    }
};