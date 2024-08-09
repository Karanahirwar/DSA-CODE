#include<iostream>
#include<unordered_map>
using namespace std;

void Countcharacter(unordered_map<char,int>&mapping,string str){
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        mapping[ch]++;
    }

// for each loop 
// for(char ch:str){
//         mapping[ch]++;

// }
}



int main(){
    string str="karan";
// create map 
unordered_map<char,int>mapping;

Countcharacter(mapping,str);
for(auto i:mapping){
    cout<<i.first<<" -> "<<i.second<<endl;
}

cout<<"size of map"<<mapping.size()<<endl;

    return 0;
}