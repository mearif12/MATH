#include <iostream>
using namespace std;

int main() {
//input number of total point
    cout << "Enter the number of total point: ";
    int n;
    cin >> n;

//creating user input
    double x[n], y[n];
    cout << "Enter the values of x: ";
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    cout << "Enter the values of y: ";
    for(int i = 0; i < n; ++i) {
        cin >> y[i];
    }
   
//creating the divided difference table
    double div_diff[n][n];
    for (int i = 0; i < n; ++i) {
        div_diff[i][0] = y[i];
    }
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
          div_diff[i][j] = (div_diff[i + 1][j - 1] - div_diff[i][j - 1]) /(x[i + j] - x[i]);
        }
    }

//input the value for interpolation
    double e;
    cout << "Enter the value of x for interpolation: ";
    cin >> e;

//applying Newton's divided difference formula for unequal intervals 
    double result = div_diff[0][0];
    double term = 1.0;
    for (int i = 1; i < n; ++i) {
        term = term * (e - x[i - 1]);
        result = result + div_diff[0][i] * term;
    }

    cout << "The interpolated value at f(" << e <<")"<< " is " << result << endl;

  return 0;
}
