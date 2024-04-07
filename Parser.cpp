#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

class Parser{
protected:
ifstream file;
public:   
int n, K;
int* v;
int* w;
Parser(string f_name){
file.open(f_name);
if (file.is_open()){
  string s;   
  getline(file,s,' '); 
  n=stoi(s);
  getline(file,s,'\n'); 
  K=stoi(s);
  v=new int[n];
  w=new int[n];
  for(int i=0;i<n;i++){
     getline(file,s,' ');  
     v[i]=stoi(s);
     getline(file,s,'\n'); 
     w[i]=stoi(s);
     }
}
else 
  cout<<"Error:file is close"<<endl;
}

~Parser(){
file.close();
delete[]v;
delete[]w;
}
 
};
