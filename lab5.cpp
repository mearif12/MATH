#include <iostream>
using namespace std;
int main() {
//total number of points
    int n; 
    cout << "Enter the total number of points: ";
    cin >> n;

//taking user input
    double x[n], y[n]; 
    cout << "Enter the values of x: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << "Enter the values of y: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
  
//estimated interpolating point
    double e;
    cout << "Enter the value at which interpolation is needed: ";
    cin >> e;

//creating backward difference table for interpolation
    double diff[n][n];
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

//applying Newton-Gregory's backward formula
    double result = y[n - 1];
    double u = (e - x[n - 1]) / (x[1] - x[0]);
    double term = 1.0;
    for (int i = 1; i < n; i++) {
        term = term * (u + i - 1) / i;
        result = result + term * diff[n - 1][i];
    }

    cout << "Interpolated value at f(" << e << ") is " << result << endl;

    return 0;
}
