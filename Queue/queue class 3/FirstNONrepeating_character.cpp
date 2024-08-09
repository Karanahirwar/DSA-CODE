#include<iostream>
#include<queue>
using namespace std;

void FirstNonRepeating(int *freq,string &str){
queue<int>q;
for(int i =0;i<str.length();i++){
char ch =  str[i];
freq[ch-'a']++;  // count ho rha h kon sa word kitni bar aaya h 
q.push(ch);

// answer find kro 
while(!q.empty()){

char  frontcharacter = q.front();
  if(freq[frontcharacter-'a'] >1){
    // yani ye answer nhi h 
    q.pop();
  }
   else{
    // ==1 wala yhi anwer h 
   cout<<frontcharacter<<" -> ";
  break;
   }
}
                           

if(q.empty()){
    cout<<" # "<<" -> ";
}
}
}


int main(){
string str = "a";
int freq[26]={0};

//  array ka size 26 isiliye liye h because total no of alphabat is 26

FirstNonRepeating(freq,str);

 return 0;
}