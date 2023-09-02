#include <iostream>
#include <cmath>

using namespace std;

// Integrating mechanics of a projectile & Kalman Filter equations

// The size of the input arrays
#define SIZE 10

// The accuracies of the two sensors respectively
#define ACC_MPU 0.79
#define ACC_BNO 0.92

// Function that calculates weighted averages (the weights are the accuracies of the sensors)
double getWeightedAverage(double a, double b);

// Function that prints the output array
void printResult(double result[SIZE]);

// Function that applies Kalman Filter algorithm of Sensor Fusion to return the estimate value of the calculations of the sensors' data
double kalmanFilter(double first, double second, double v_y, double t);

// Function that predicts the original estimate and error estimate by using the projectile motion mechanics laws
void predict(double estimates[3], double error_estimates[3], double first, double second, double v_y, double t);

// Function updates the value of estimates, error estimates, kalman gain using the calculations of Kalman Filter
void update(double estimates[3], double error_estimates[3], double error_measured[3], double kg[3], double measured, int cnt, double accuracy);

int main()
{
    // The data from the sensors
    double mpu6050[SIZE] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    double bno55[SIZE] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    // result =         [0, 9.73202, 16.8037, 21.4396, 23.6324, 23.3779, 20.6613, 15.6004, 7.96393, -1.27252] (THE OUTPUT)
    double result[SIZE];

    // first point is sure (from ground at y = 0)
    result[0] = 0.0;

    // Initial velocity, and initial angle in degree
    double v_o = 30;
    double theta_o = 46;
    
    // Converting initial degree to radians
    theta_o = theta_o * 3.14159 / 180;

    // the initial velocity in y direction
    double v_y = v_o * sin(theta_o);

    double t = 0.5; // taking inputs every 0.5 second
    for (int i = 1; i < SIZE; i++, t += 0.5)
    {
        result[i] = kalmanFilter(mpu6050[i], bno55[i], v_y, t);
    }

    // Function that prints the result array
    printResult(result);
}

// Function that calculates weighted averages (the weights are the accuracies of the sensors)
double getWeightedAverage(double a, double b)
{
    double weighted_av = (a * ACC_MPU + b * ACC_BNO) / (ACC_MPU + ACC_BNO);
    return weighted_av;
}

// Function that prints the output array
void printResult(double result[SIZE])
{
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
    cout << "]\n";
}

// Function that applies Kalman Filter algorithm of Sensor Fusion to return the estimate value of the calculations of the sensors' data
double kalmanFilter(double first, double second, double v_y, double t)
{
    double estimates[3];
    double error_estimates[3];
    double error_measured[3];
    double kg[3];

    // predict initial conditions from phyisics of the projectile
    predict(estimates, error_estimates, first, second, v_y, t);

    // arrays to iterate over, to send the value to the update function
    double params_accs[2] = {ACC_MPU, ACC_BNO};
    double params_measures[2] = {first, second};

    for (int cnt = 1; cnt <= 2; cnt++)
    {
        // update the values for each input from sensors' data
        update(estimates, error_estimates, error_measured, kg, params_measures[cnt - 1], cnt, params_accs[cnt - 1]);
    }

    // return final value of the estimate
    return estimates[2];
}

// Function that predicts the original estimate and error estimate by using the projectile motion mechanics laws
void predict(double estimates[3], double error_estimates[3], double first, double second, double v_y, double t)
{
    // let the previous estimate be calculated from the projectile motion mechanics (using the initial velocity and angle)
    estimates[0] = v_y * t - 0.5 * 9.81 * t * t;

    // let the previous error estimated be the weighted average of both next error estimates
    error_estimates[0] = getWeightedAverage(fabs(first - estimates[0]), fabs(second - estimates[0]));
}


// Function updates the value of estimates, error estimates, kalman gain using the calculations of Kalman Filter
void update(double estimates[3], double error_estimates[3], double error_measured[3], double kg[3], double measured, int cnt, double accuracy)
{
    error_measured[cnt] = measured * accuracy;
    error_estimates[cnt] = error_measured[cnt] * error_estimates[cnt-1] / (error_measured[cnt] + error_estimates[cnt-1]);
    kg[cnt] = error_estimates[cnt] / (error_estimates[cnt] + error_measured[cnt]);
    estimates[cnt] = estimates[cnt-1] + kg[cnt] * (measured - estimates[cnt - 1]);
}
