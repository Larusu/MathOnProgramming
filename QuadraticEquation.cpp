#include <iostream>
#include <iomanip>
using namespace std;

void quadraticFormula(int a, int b, int c);
double discriminant(int a, int b, int c);
double sqrtN(double num);

int main() {
    // x^2 - 5x = 3
	int a = 1;
	int b = -5;
    int c = -3;

    quadraticFormula(a, b, c);
}

double discriminant(int a, int b, int c) { return (b * b) - (4 * a * c); }

void quadraticFormula(int a, int b, int c) {
    double x, x1, x2;

    cout << fixed << setprecision(4); // 4 decimal places
    if (discriminant(a, b, c) < 0) {
        cout << "No real roots" << endl;
    }
    else if (discriminant(a, b, c) == 0) {
        x = (-b / (2 * a)) * 1.0;
        cout << "One real root: " << x << endl;
    }
    else {
        x1 = ((-b + sqrtN(discriminant(a, b, c))) / (2 * a)) * 1.0;
        x2 = ((-b - sqrtN(discriminant(a, b, c))) / (2 * a)) * 1.0;
        cout << "Two real roots: " << x1 << " and " << x2 << endl;
    }    
    cout.unsetf(ios::fixed); // default decimal format
}

// Square root using Babylonian method (from Stack Overflow)
double sqrtN(double num) 
{
    double error = 0.00001; //define the precision of your result
    double s = num;

    while ((s - num / s) > error) //loop until precision satisfied 
    {
        s = (s + num / s) / 2;
    }
    return s;
}