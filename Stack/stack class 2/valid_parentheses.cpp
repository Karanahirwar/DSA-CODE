#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthes(string s) {
        stack<char>st;
        for(int i = 0;i<s.length();i++){
            char ch = s[i];

   // insert open bracket in stack    
if(ch=='(' || ch=='{' || ch=='['){
    st.push(ch);
}
// closing bracket 
else{ 
    
    if(!st.empty() ){

if(ch ==')' && st.top()=='(' )
{
    st.pop();
}
 else if(ch =='}' && st.top()=='{' )
{
    st.pop();
}
 else if(ch ==']' && st.top()=='[' )
{
    st.pop();
}
// no match 
else{
    return false;
}
    }
// stack empty h 
else{
    return false;
}
 } 
}    
        

if(st.size()==0){
    return true;
}
else{
    return false;
}
}

int main(){
string s = "([{}])";

bool ans =  isValidParenthes(s);

if(ans ==true){
    cout<<" valid parenthes: "<<endl;
}
else {
    cout<<" invalid parenthes: "<<endl;
}

 return 0;
}