#ifndef PID_CONTROL_H
#define PID_CONTROL_H

/// @brief The PID Class
class PID {
    private:
        // PID attributes
        // Defining PID gains, these parameters must be tuned.

        // proportional component
        double kp;
        
        // integral component
        double ki;

        // derivative component
        double kd;

        // delay
        double dt;
    public:
        // error variables
        double error = 0;
        double previous_error = 0;
        
        // PID terms
        double derivative_term;
        double integral_term;
        double proportional_term;

        /// @brief Default constructor: if no parameters sent in constructor, load default values (2,7,3,0.01)
        PID();

        /// @brief overloading constructor if parameters sent to the constructor to set the parameters.
        /// @param p kp: 
        /// @param i ki: integral component
        /// @param d kd: derivative component
        /// @param t dt: delay
        PID(double p, double i, double d, double t);

        /// @brief function of PID control
        /// @param current_value the current setpoint
        /// @param target_value the target value we want to reach
        /// @return the PID control calculations
        double pid_control(double current_value, double target_value);

        /// @brief change value of Kp
        /// @param p // new kp
        void changeKp(double p);

        /// @brief get Value of Kp
        /// @return Kp
        double getKp();

        /// @brief change value of kd
        /// @param d new kd
        void changeKd(double d);

        /// @brief get value of kd
        /// @return kd
        double getKd();
 
        /// @brief change value of ki
        /// @param i new ki
        void changeKi(double i);

        /// @brief return value of ki
        /// @return ki
        double getKi();

        /// @brief change value of dt
        /// @param t new dt
        void changeDelay(double t);

        /// @brief get value of dt
        /// @return dt (delay)
        double getDelay();
};

#endif