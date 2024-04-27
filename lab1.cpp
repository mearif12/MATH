#include<iostream>
#include<set>
using namespace std;
int main(){
    
       int n;
       cout<<"Enter the element number in A: ";
       cin>>n;
       set<int> A;
       cout<<"Enter the elements of set A: "<<endl;
       for(int i=0;i<n;i++){
          int ele;
          cin>>ele;
          A.insert(ele);
       }

          //AXA
       for(int a:A){
         for(int b:A){
            cout<<"("<<a<<","<<b<<")";
         }
       }

          //R1{(a,b)|a divides b}
       cout<<endl<<"ordered pairs in R1: "<<endl;
       for(int a:A){
        for(int b:A){
            if(b%a==0){
                cout<<"("<<a<<","<<b<<")";
            }
        }
       }

          //R2{(a,b)|a<=b}
       cout<<endl<<"ordered pairs in R2: "<<endl;
       for(int a:A){
        for(int b:A){
            if(a<=b){
                cout<<"("<<a<<","<<b<<")";
            }
        }
       }
  return 0;  
}
