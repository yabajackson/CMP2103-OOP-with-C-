#include <cmath>
#include <iostream>

using namespace std;

const int MAX_BUFFERS = 20;
const int MAX_POINTS = 100;

int main()
{
    double centreX, centreY;
    double bufferSizes[MAX_BUFFERS];
    double pointX[MAX_POINTS];
    double pointY[MAX_POINTS];

    int numberOfBuffers;
    int numberOfPoints;

    cout << "BUFFER ANALYSIS PROGRAM\n";
    cout << "=======================\n\n";

    cout << "Enter the centre x-coordinate: ";
    cin >> centreX;

    cout << "Enter the centre y-coordinate: ";
    cin >> centreY;

    cout << "\nEnter the number of buffers: ";
    cin >> numberOfBuffers;

    if (numberOfBuffers <= 0 || numberOfBuffers > MAX_BUFFERS)
    {
        cout << "Enter between 1 and "
             << MAX_BUFFERS << " buffers.\n";
        return 1;
    }

    for (int i = 0; i < numberOfBuffers; i++)
    {
        cout << "Enter the size of buffer "
             << i + 1 << ": ";
        cin >> bufferSizes[i];

        if (bufferSizes[i] < 0)
        {
            cout << "A buffer size cannot be negative.\n";
            return 1;
        }
    }

    cout << "\nEnter the number of points: ";
    cin >> numberOfPoints;

    if (numberOfPoints <= 0 || numberOfPoints > MAX_POINTS)
    {
        cout << "Enter between 1 and "
             << MAX_POINTS << " points.\n";
        return 1;
    }

    for (int i = 0; i < numberOfPoints; i++)
    {
        cout << "\nEnter the x-coordinate of point "
             << i + 1 << ": ";
        cin >> pointX[i];

        cout << "Enter the y-coordinate of point "
             << i + 1 << ": ";
        cin >> pointY[i];
    }

    cout << "\nBUFFER ANALYSIS RESULTS\n";
    cout << "=======================\n";

    for (int i = 0; i < numberOfBuffers; i++)
    {
        bool pointFound = false;

        cout << "\nPoints inside the "
             << bufferSizes[i] << "-unit buffer:\n";

        for (int j = 0; j < numberOfPoints; j++)
        {
            double changeInX = pointX[j] - centreX;
            double changeInY = pointY[j] - centreY;

            double distance = sqrt(
                changeInX * changeInX +
                changeInY * changeInY
            );

            if (distance <= bufferSizes[i])
            {
                cout << "Point " << j + 1
                     << " (" << pointX[j]
                     << ", " << pointY[j] << ")"
                     << ", distance = " << distance
                     << " units\n";

                pointFound = true;
            }
        }

        if (!pointFound)
        {
            cout << "No points are contained in this buffer.\n";
        }
    }

    return 0;
}