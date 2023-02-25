class Solution {
public:
    bool reorderedPowerOf2(int n) {

        if(n==1 ){
            return true;
        }
        char x;
        
        string num_str=to_string(n);
        float temp;
        sort(num_str.begin(),num_str.end());

        do{ 
            x=num_str.back();
            if(num_str[0]!='0' && (x=='2' || x=='4' || x=='6' || x=='8')){
                // temp=log(stoi(num_str))/log(2);
                temp=stoi(num_str)/2;
                while(floor(temp)==temp){
                    temp/=2;
                    if(temp==2){
                        return true;
                    }
                }
                // // cout<<temp<<endl;
                // if(floor(temp)==temp){
                //     return true;
                // }
            }
        }

        while(next_permutation(num_str.begin(),num_str.end()));

        // generate combination

        //check combinations

        return false;

              
    }
};
