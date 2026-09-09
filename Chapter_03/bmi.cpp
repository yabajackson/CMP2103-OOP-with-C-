// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5–24.9 Normal
// 25.0–29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter Weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    double weightInPounds;
    double heightInInches;

    const double POUNDS_TO_KILOGRAMS = 0.45359237;
    const double INCHES_TO_METERS = 0.0254;

    cout << "Enter weight in pounds: ";
    cin >> weightInPounds;

    cout << "Enter height in inches: ";
    cin >> heightInInches;

    if (weightInPounds <= 0 || heightInInches <= 0)
    {
        cout << "Weight and height must be greater than zero." << endl;
        return 1;
    }

    double weightInKilograms =
        weightInPounds * POUNDS_TO_KILOGRAMS;

    double heightInMeters =
        heightInInches * INCHES_TO_METERS;

    double bmi =
        weightInKilograms / pow(heightInMeters, 2);

    cout << fixed << setprecision(1);
    cout << "The BMI is " << bmi << endl;

    if (bmi < 18.5)
    {
        cout << "Underweight" << endl;
    }
    else if (bmi < 25.0)
    {
        cout << "Normal" << endl;
    }
    else if (bmi < 30.0)
    {
        cout << "Overweight" << endl;
    }
    else
    {
        cout << "Obese" << endl;
    }

    return 0;
}