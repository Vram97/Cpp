class Solution {
public:
    string simplifyPath(string path) {
        char prev;
        

        // if(path[0]!="/"){
        //     path.insert(0,"/");
        // }
        int sz=path.length();
        string ans("");
        // int prev=path[0];
        while(path.find("/")!=string::npos){
            int index = path.find("/");
            string temp=path.substr(0,index);
            if(temp!="" && temp!=".." && temp!="."){
                ans=ans + "/" + temp;
            }
            else if(temp=="."){
                ;
            }
            else if(temp==".."){
                int index=ans.rfind("/");
                cout<<index<<endl;
                if(index>-1){
                    ans.erase(index,ans.length()-index);
                }

            }
            path.erase(0,index+1);
        }
        if(path==".."){
            int index=ans.rfind("/");
            // cout<<index<<endl;
            if(index>-1){
                ans.erase(index,ans.length()-index);
            }
        }
        else if(path!="." && path!=""){
            ans=ans+"/" +path;
        }
        return (ans=="")?"/":ans;
        
    }
};
