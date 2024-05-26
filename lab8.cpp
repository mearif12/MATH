#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c; // Coefficients of the equation
    double lower_bound, upper_bound; // Interval bounds
    double epsilon; // Desired accuracy

    // Input coefficients of the equation
    cout << "Enter the coefficients of the equation (ax^2 + bx + c): ";
    cin >> a >> b >> c;

    // Input interval bounds
    cout << "Enter the lower and upper bounds of the interval [a, b]: ";
    cin >> lower_bound >> upper_bound;

    // Input desired accuracy
    cout << "Enter the desired accuracy (epsilon): ";
    cin >> epsilon;

    // Calculate the values of the function at the interval bounds
    double fa = a * lower_bound * lower_bound + b * lower_bound + c;
    double fb = a * upper_bound * upper_bound + b * upper_bound + c;

    // Check if the function values have opposite signs, indicating a root exists in the interval
    if (fa * fb >= 0) {
        cout << "Root not found in the given interval." << endl;
        return 0;
    }

    double root;
    while ((upper_bound - lower_bound) >= epsilon) {
        // Calculate the midpoint of the interval
        root = (lower_bound + upper_bound) / 2;

        // Calculate the value of the function at the midpoint
        double fc = a * root * root + b * root + c;

        // Check if the midpoint is a root
        if (fc == 0.0) {
            cout << "Root is approximately: " << root << endl;
            return 0;
        }
        // Decide the side to repeat the steps
        else if (fa * fc < 0) {
            upper_bound = root;
        } else {
            lower_bound = root;
        }
    }

    cout << "Root is approximately: " << (lower_bound + upper_bound) / 2 << endl;
    return 0;
}
