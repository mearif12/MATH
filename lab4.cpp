#include <iostream>
using namespace std;
int main() {

//total number of point
    int n; 
    cout << "Enter the total number of point: ";
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
    cout << "Enter the value at which interpolation is desired: ";
    cin >> e;

//creating forward differnce table for interpolation
    double diff[n][n];
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1];
        }
    }

//applying Newton-Gregory's forward formula 
    double result = y[0];
    double u = (e - x[0]) / (x[1] - x[0]);
    double term = 1.0;
    for (int i = 1; i < n; i++) {
        term = term * (u - i + 1) / i;
        result = result + term * diff[0][i];
    }

    cout << "Interpolated value at f(" << e <<")" << " is " << result << endl;

    return 0;
}
