#include<iostream>
#include<set>
using namespace std;
int main(){

    int sA,sB;
    set<int> A,B;
    cout<<"Enter size of A: ";
    cin>>sA;
    cout<<"Enter size of B: ";
    cin>>sB;
    
    cout<<"Enter elements of A:\n";
    for(int i=1;i<=sA;i++){
        int eleA;
        cin>>eleA;
        A.insert(eleA);
    }

    cout<<"Enter elements of B:\n";
    for(int i=1;i<=sB;i++){
        int eleB;
        cin>>eleB;
        B.insert(eleB);
    }

      //R{(a,b)|a>b}
    cout<<"Relation:\n";
    for(int a:A){
        for(int b:B){
            if(a>b){
            cout<<"("<<a<<","<<b<<")";
            }
        }
    }

      //Matrix
    cout<<endl<<"Matrix:\n";
    for(int a:A){
        for(int b:B){
            cout<<(a>b?1:0)<< " ";
        }
        cout<<endl;
    }  
  return 0;  
}
