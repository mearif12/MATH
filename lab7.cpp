#include <iostream>
using namespace std;

int main() {
//input number of total point
    cout << "Enter the number of total point: ";
    int n;
    cin >> n;

//taking user input
    double x[n], y[n];
    cout << "Enter the values of x: ";
    for (int i = 0; i < n; ++i) {
        cin >> x[i];       
    }
    cout << "Enter the values of y: ";
    for (int i = 0; i < n; ++i) {
        cin >> y[i];       
    }

//input the value for interpolation
    double e;
    cout << "Enter the value of x for interpolation: ";
    cin >> e;

// calculate the interpolated value using Lagrange interpolation
    double result = 0;
    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                term = term * (e - x[j]) / (x[i] - x[j]);
            }
        }
        result = result + term;
    }

    cout << "Estimated f(" << e << "): " << result << endl;

    return 0;
}
