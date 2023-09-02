#include <iostream>
#include <cmath>

using namespace std;

#define SIZE 10
#define ACC_MPU 0.79
#define ACC_BNO 0.92

double getWeightedAverage(double a, double b);
// The output finding weighted averages of both sensors only
int main()
{
    // The data from the sensors
    double mpu6050[SIZE] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    double bno55[SIZE] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};

    double result[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = getWeightedAverage(mpu6050[i], bno55[i]);
    }
    
    cout << "[";
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            cout << result[i];
        }
        else
            cout << result[i] << ", ";
    }
    cout << "]";
}

double getWeightedAverage(double a, double b)
{
    double weighted_av = (a * ACC_MPU + b * ACC_BNO) / (ACC_MPU + ACC_BNO);
    return weighted_av;
}