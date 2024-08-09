#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
// create map 
unordered_map<string,int>mapping;

// creating pair 
// 1-> way 
pair<string,int>p = make_pair("karan",20);

// 2-> way 
pair<string,int>q("dinesh",28);

// 3-> way 
pair<string,int>r;
r.first="ansh";
r.second=5;

// insertion 
mapping.insert(p);
mapping.insert(q);
mapping.insert(r);

// another way
mapping["sohan"] = 40;
// size check 
cout<<"size of map "<<mapping.size()<<endl;

// access
cout<<"value of key "<<mapping.at("karan")<<endl;
// another way of acces
cout<<"value of key "<<mapping["sohan"]<<endl;

// searching 
cout<<"searching "<<mapping.count("karan")<<endl;

// another way for searching 
if(mapping.find("karan")!=mapping.end()){
    cout<<"found"<<endl;
}
else{
    cout<<" not found : "<<endl;
}

cout<<mapping["rohan"]<<endl; // agr value present nhi hogi 
// to default entry creat kr dega 
// aur size increase ho jayega 
cout<<"size of map "<<mapping.size()<<endl;

    return 0;
}