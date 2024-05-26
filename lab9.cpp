#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double lower_bound, upper_bound; 
    double epsilon; 

// Input coefficients of the equation
    cout << "Enter the coefficients of the equation (ax^2 + bx + c): ";
    cin >> a >> b >> c;
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
        // Calculate the false position
        root = upper_bound - ((fb * (upper_bound - lower_bound)) / (fb - fa));

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
            fb = fc; // Update f(b)
        } else {
            lower_bound = root;
            fa = fc; // Update f(a)
        }
    }

    cout << "Root is approximately: " << root << endl;
    return 0;
}
