class Solution {
public:

    string reverseWords(string s) {
        
        stringstream X(s);
        string ans="";
        string temp;

        while(getline(X,temp,' ')){
            
            if(ans=="" && temp!=" "){
                ans=temp;
            }
            else if(temp==""){
                ;
            }
            else{
                cout<<temp<<endl;
                ans=temp + " " + ans;
            }
        }
       
        return ans;
    }
};
