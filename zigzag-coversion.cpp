class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string> v(numRows,"");

        const int len = s.length();

        unsigned int count=0;
        short int inc=-1;
        int val=numRows-1;

        for(int i=0; i<len; i++){
            v[count]+=s[i];
            if(count==0 || count==val){
                inc*=-1;
            }
            count+=inc;

        }
        
        string ans="";
        for(auto x:v){
            ans+=x;
        }

        return ans;
    }
};
