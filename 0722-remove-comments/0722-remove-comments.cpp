class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string out = "";
        bool blocked = false;
        
        for(string &line : source){
            for(int i=0;i<line.size();i++){
                if(blocked == false){
                    if(i == line.size()-1){
                        out += line[i];
                    }
                    else{
                        string t = line.substr(i,2);
                        if(t == "//"){
                            break;
                        }
                        else if(t == "/*"){
                            blocked = true;
                            i++;
                        }
                        else{
                            out += line[i];
                        }
                    }
                }
                else{
                    string t = line.substr(i,2);
                    if(t == "*/"){
                        blocked = false;
                        i++;
                    }
                }
            }
            
            if(out.empty() == false && blocked == false){
                res.push_back(out);
                out = "";
            }
        }
        return res;
    }
};