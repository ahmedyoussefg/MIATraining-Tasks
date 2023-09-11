#include "pid_control.h"

/// @brief Default constructor: if no parameters sent in constructor, load default values (2,7,3,0.01)
PID::PID()
    : kp(2.0), ki(7.0), kd(3.0), dt(0.01), error(0.0), previous_error(0.0), derivative_term(0.0), integral_term(0.0), proportional_term(0.0) {
        
    }

/// @brief constructor if parameters sent to the constructor to set the parameters.
/// @param p kp: 
/// @param i ki: integral component
/// @param d kd: derivative component
/// @param t dt: delay
PID::PID(double p, double i, double d, double t)
    : kp(p), ki(i), kd(d), dt(t), error(0), previous_error(0), derivative_term(0), integral_term(0), proportional_term(0) {
    // Constructor body is empty because member variables are initialized in the initializer list
}

/// @brief function of PID control
/// @param current_value the current setpoint
/// @param target_value the target value we want to reach
/// @return the PID control calculations
double PID :: pid_control(double current_value, double target_value) {
    this->error = target_value - current_value;
    this->proportional_term = error;
    this->integral_term += error;
    this->derivative_term = error - previous_error;

    // updating error
    this->previous_error = this->error;

    // return PID control calculation
    return this->kp*proportional_term + ki*integral_term + kd*derivative_term;
}

/// @brief change value of Kp
/// @param p // new kp
void PID :: changeKp(double p){
    this->kp=p;
}

/// @brief get Value of Kp
/// @return Kp
double PID :: getKp(){
    return this->kp;
}

/// @brief change value of kd
/// @param d new kd
void PID :: changeKd(double d){
    this->kd=d;
}

/// @brief get value of kd
/// @return kd
double PID :: getKd(){
    return this->kd;
}

/// @brief change value of ki
/// @param i new ki
void PID :: changeKi(double i){
    this->ki=i;
}

/// @brief return value of ki
/// @return ki
double PID :: getKi(){
    return this->ki;
}

/// @brief change value of dt
/// @param t new dt
void PID :: changeDelay(double t){
    this->dt=t;
}

/// @brief get value of dt
/// @return dt (delay)
double PID :: getDelay(){
    return this->dt;
}