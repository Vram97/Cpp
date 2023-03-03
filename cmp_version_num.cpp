class Solution {
public:
    int compareVersion(string version1, string version2) {

           string::iterator v1=version1.begin();
           string::iterator v2=version2.begin();

           int sub_v1;
           int sub_v2;

           while(v1!=version1.end() || v2!=version2.end()){

               string::iterator v1_it=find(v1,version1.end(),'.');
               string::iterator v2_it=find(v2,version2.end(),'.');

            //    cout<<v1_it-v1<<endl;
            //    cout<<v2_it-v2<<endl;

            //    cout<<version1.substr(v1,v1_it)<<endl;

               sub_v1=stoi("0" + version1.substr(v1-version1.begin(),v1_it-v1+1));
               sub_v2=stoi("0" + version2.substr(v2-version2.begin(),v2_it-v2+1));

               if(sub_v1<sub_v2){
                   return -1;
               }

               if(sub_v1>sub_v2){
                   return 1;
               }

               if(v1_it!=version1.end()){
                   v1=v1_it + 1;
               }
               else{
                   v1=v1_it;

               }

               if(v2_it!=version2.end()){
                   v2=v2_it+1;

               }
               else{
                    v2=v2_it;
               }
            
           }
           return 0;

        
    }
};
