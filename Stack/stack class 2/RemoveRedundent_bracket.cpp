#include<iostream>
#include <stack>
using namespace std;


bool cheackExtraBracket(string &str){
stack<char> st;

for(int i = 0;i<str.length();i++){
    char ch = str[i];

if(ch == '(' || ch == '+' ||ch == '-' ||ch == '*' ||ch == '/'){
    st.push(ch);
}


else if(ch==')'){

    int operatorCount  = 0;
while(!st.empty()&& st.top()!='('){

int temp = st.top();

if(temp=='+'|| temp=='-'|| temp=='*'|| temp=='/'){
    
    operatorCount++;
}
st.pop();

}
// yha pr tabhi aayege jb stack 
// ke top me opening bracket hoga

st.pop();

if(operatorCount==0){
    return true;
}

}

}
// agr me yha tk pahucha hu iska matlab 
// har ek bracket ke pair ke beech me 
//  ek operator jarur mila hoga

return false;
}




int main(){
string str = "(a+b)";

bool ans = cheackExtraBracket(str);

if(ans == true){
    cout<<" present redundant(faltu) bracket:";
}
else{
    cout<<"  not present redundant(faltu) bracket:";

}
 return 0;
}