#include<string>
class Solution {
public:
    void reverse_str(string &num){
        int end=num.length();
        int add=0;
        if(num[0]=='-'){
            add++;
        }
        for(int i=add;i<end/2;i++){
            swap(num[i],num[end-i+add-1]);
        }
        
    }

    int reverse(int x) {
    //     int fk=1;
    //     string num=to_string(x);
    //     if(num.find('-') != std::string::npos){
    //         num.erase(0,1);
    //         fk=-1;
    //     }

    //     int sz=num.size();
    //     signed int limit=pow(2,31)-1;;
    //     int factor=pow(10,sz-1);
    //     // cout<<factor<<endl;
    //     long long ans=0;

    //     for(int i=sz-1;i>-1;i--){
    //         double val=factor*(num[i]-'0');
    //         if(val<limit){
    //             auto new_val=val+ans;
    //             if(val>limit){return 0;}
    //             else{
    //                 ans=new_val;
    //             }
    //         }
    //         else{
    //             return 0;
    //         }

    //         factor/=10;

    //     }
    //     return ans*fk;
    // }
        string x_str=to_string(x);
        reverse_str(x_str);


        long long val=stoll(x_str);

        return(val>INT_MAX || val<INT_MIN)?0:val;
    }
};
