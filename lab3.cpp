#include <iostream>
using namespace std;
int main() {

    int R1[3][3], R2[3][3];

 // Input R1 elements
    cout << "Enter the elements of the first 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> R1[i][j];
        }
    }

 // Input R2 elements
    cout << "Enter the elements of the second 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> R2[i][j];
        }
    }

 // Print R1
    cout << "R1:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout <<R1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

 // Print R2
    cout << "R2:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << R2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Finding & Printing Union
    cout << "R1 U R2:" << endl;
        for (int i = 0; i < 3; i++)
       {
             for (int j = 0; j < 3; j++)
            {
               
               cout<<(R1[i][j] || R2[i][j] ?1:0)<<" ";
             
            }
            cout<<endl;
       }     

       cout<<endl;

    //Finding & Printing Itersection
     cout<< "R1 & R2:" << endl;
        for (int i = 0; i < 3; i++)
       {
             for (int j = 0; j < 3; j++)
            {
               
               cout<<(R1[i][j] && R2[i][j] ?1:0)<<" ";
             
            }
            cout<<endl;
        }   

    return 0;
}
