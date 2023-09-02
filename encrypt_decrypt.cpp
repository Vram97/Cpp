/*
* Author: Shivaram Srikanth
* Date: 09/01/2023
* This code implements an encryption and decryption algorithm to a string based on an input password.
*/

// Including neccessary libraries
#include <iostream>
#include<algorithm>
#include<unordered_map>


using namespace std;

// Mmemoization function
void memoize(string& pwd,unordered_map<int,int>& mp,int& count){
  /*
  * This function helps memoize the initial logic that I came up with. This combines 3 seperate functions
  * from the previous code into 1 -> Finding length of password, Calculation of ascii value of characters &
  * converting letters into lower case for case insensitivity.
  * @param1 pwd -> The Password, by reference
  * @param2 mp -> Map for memoization of ascii values.
  * @param3 count --> Counter that will increment to calculate the size of the password. 
  */
  for(char& x:pwd){
    x=tolower(x);  // Converting to lower case
    
    // Condition for upper case
    if(isalpha(x)){
      mp[count]=x-'0'-49; // Storing in map
    }
    
    count++;
  }
}

// Encrypt function
string encrypt(string& input,string password){
  /*
  * @param1 input -> Text input to be encrypted
  * @param2 password -> Text used to perform rotations on text letters
  * @return ans -> Encrypted text
  */
  
  unordered_map<int,int> mp; // Initializing map for memoization
  int pwd_sz=0;              // Initializing size of password to 0
  memoize(password,mp,pwd_sz); // Calling memoize function
  
  string ans=""; // Initializing answer
  
  // Storing string lengths for future use
  const int sz_pwd=pwd_sz; 
  const int sz_text=input.length();
  
  // In case password is empty
  if(sz_pwd==0){
    return input;
  }
  
  // Making sure that password is case insensitive /* REDUNDANT AFTER MEMOIZATION */
  // transform(password.begin(),password.end(),password.begin(),::tolower);
  
  // Initializing counter for checking number of times the rotations are skipped.
  // This is useful to iterate through the password cyclically.
  int count=0;
  
  // Looping through text
  for(int i=0;i<sz_text;i++){
    
    // Cyclical indexing.
    int curr=(i-count)%sz_pwd;
    
    if(mp.find(curr)!=mp.end()){
      
      // Checking if values are Lower case.
      if(input[i]>='a' && input[i]<='z'){
        //Lower case
        
        char val=input[i] + mp[curr];
        
        // Checking if value is exceeding bounds.
        if(val>'z'){
          val='a'+val-'z';
        }
        
        // Adding to final output.
        ans+=val;
        
      }
      
      // Checking if values are Upper case.
      else if(input[i]>='A' && input[i]<='Z'){
        // Upper case
        char val=input[i] + mp[curr];
        
        // Checking if value is exceeding bounds.      
        if(val>'Z'){
          val='A'+val-'Z';
        }
        
        // Adding to final output.      
        ans+=val;
        
      }
      else{
        // Unchanged
        count++;
        ans+=input[i];
      }
    }
    
    else{
      ans+=input[i];
    }

  }
  
  return ans;
}

// Decrypt function
string decrypt(string& input,string password){
  /*
  * @param1 input -> Text input to be decrypted
  * @param2 password -> Text used to perform rotations on text letters
  * @return ans -> Decrypted text
  */
  
  unordered_map<int,int> mp; // Initializing map for memoization
  int pwd_sz=0;              // Initializing size of password to 0
  memoize(password,mp,pwd_sz); // Calling memoize function
  
  string ans=""; // Initializing answer
  
  // Storing string lengths for future use
  const int sz_pwd=pwd_sz;
  const int sz_text=input.length();
  
  // In case password is empty
  if(sz_pwd==0){
    return input;
  }
  
  // Making sure that password is case insensitive /* REDUNDANT AFTER MEMOIZATION */
  // transform(password.begin(),password.end(),password.begin(),::tolower);
  
   // Initializing counter for checking number of times the rotations are skipped.
  // This is useful to iterate through the password cyclically.
  int count=0;
  
  // Looping through text
  for(int i=0;i<sz_text;i++){
    // Cyclical indexing.
    int curr=(i-count)%sz_pwd;
    if(mp.find(curr)!=mp.end()){
      // Checking if values are Lower case.
      if(input[i]>='a' && input[i]<='z'){
        //Lower case
        
        char val=input[i] - mp[curr];
        
        // Checking if value is exceeding bounds.
        if(val<'a'){
          val='z'-('a'-val);
        }
        
        // Adding to final output.
        ans+=val;
        
      }
      
      // Checking if values are Upper case.
      else if(input[i]>='A' && input[i]<='Z'){
        // Upper case
        char val=input[i] - mp[curr];
        
        // Checking if value is exceeding bounds.
        if(val<'A'){
          val='Z'-('A'-val);
        }
        
        // Checking if value is exceeding bounds. 
        ans+=val;
        
      }
      else{
        // Unchanged
        count++;
        ans+=input[i];
      }
    }
    else{
      ans+=input[i];
    }
  }
  
  return ans;
}
int main() {
  
  string text="aaaaaa";
  string text2="Hello World!";
  string text3="Hfnlp Yosnd!";
  string text4="abcabc";
  string password="abc";
  
  string answer=encrypt(text,password);
  string answer2=decrypt(text4,password);
  
  cout<<answer<<endl;
  cout<<answer2<<endl;
}
