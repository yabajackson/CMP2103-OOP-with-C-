// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>

using namespace std;

int main()
{
    const long long CURRENT_POPULATION = 312032486;
    const int DAYS_PER_YEAR = 365;
    const int HOURS_PER_DAY = 24;
    const int MINUTES_PER_HOUR = 60;
    const int SECONDS_PER_MINUTE = 60;

    const int BIRTH_INTERVAL = 7;
    const int DEATH_INTERVAL = 13;
    const int IMMIGRANT_INTERVAL = 45;

    // Calculate the number of seconds in one year.
    long long secondsPerYear =
        DAYS_PER_YEAR *
        HOURS_PER_DAY *
        MINUTES_PER_HOUR *
        SECONDS_PER_MINUTE;

    double birthsPerYear =
        static_cast<double>(secondsPerYear) / BIRTH_INTERVAL;

    double deathsPerYear =
        static_cast<double>(secondsPerYear) / DEATH_INTERVAL;

    double immigrantsPerYear =
        static_cast<double>(secondsPerYear) / IMMIGRANT_INTERVAL;

    double annualPopulationIncrease =
        birthsPerYear - deathsPerYear + immigrantsPerYear;

    double population = CURRENT_POPULATION;

    cout << "POPULATION PROJECTION FOR THE NEXT FIVE YEARS\n";
    cout << "=============================================\n\n";

    for (int year = 1; year <= 5; year++)
    {
        population += annualPopulationIncrease;

        cout << "Year " << year << ": "
             << static_cast<long long>(population)
             << endl;
    }

    return 0;
}
