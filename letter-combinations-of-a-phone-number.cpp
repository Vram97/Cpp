class Solution {
public:
    unordered_map<char,string> alphan;
    

    void combo(const int &sz,vector<string> &op, short index, vector<string> &ans, string curr){
        if(index==sz){
            ans.emplace_back(curr);
            return;
        }

        for(int i=0;i<op[index].size();i++){
            curr+=op[index][i];
            combo(sz,op,index+1,ans,curr);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {

        vector<string> options;
        int count=0;
        vector<string> ans;

        if(digits.empty()){
            return ans;
        }

        alphan.insert(pair<char,string>('2',"abc"));
        alphan.insert(pair<char,string>('3',"def"));
        alphan.insert(pair<char,string>('4',"ghi"));
        alphan.insert(pair<char,string>('5',"jkl"));
        alphan.insert(pair<char,string>('6',"mno"));
        alphan.insert(pair<char,string>('7',"pqrs"));
        alphan.insert(pair<char,string>('8',"tuv"));
        alphan.insert(pair<char,string>('9',"wxyz"));

        for(auto x: digits){
            options.emplace_back(alphan[x]);
            count++;
        }

        combo(count,options,0,ans,"");
        
        return ans;
    }
};
