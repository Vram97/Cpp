class Solution {
public:
    bool pali(string str){
        int len=str.length();
        for(int x=0;x<len/2;x++){
            if(str[x]!=str[len-1-x]){
                return false;
            }
        }
        return true;
    }


    void combo(string temp,int index,vector<string> v,string actual, int sz){
        if(!pali(temp)){
            return ;
        }
        if(!temp.empty()){
            v.push_back(temp);
        }
        
        if(index==sz){
            vec.push_back(v);
        }

        for(int i=1;i<sz-index+1;i++){
            combo(actual.substr(index,i),index+i,v,actual, sz);
        }
        
    }

    vector<vector<string>> partition(string s) {
        // sz=s.length();
        // actual=s;
        vector<string> start;
        combo("",0,start,s,s.length());

        return vec;
    }
private:
    vector<vector<string>> vec;
    // string actual;
    // int sz;
};
