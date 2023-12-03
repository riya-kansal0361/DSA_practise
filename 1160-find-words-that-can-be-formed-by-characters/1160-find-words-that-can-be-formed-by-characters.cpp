class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(char &ch : chars){
            freq[ch - 'a']++;
        }
        int result = 0;
        for(string &word : words){
            vector<int> wordCount(26,0);
            
            for(char &ch : word){
                wordCount[ch-'a']++;
            }
            bool ok = true;
            for(int i=0;i<26;i++){
                if(wordCount[i] > freq[i]){
                    ok=false;
                }
            }
            
            if(ok == true){
                result += word.length();
            }
        }
        
        return result;
    }
};