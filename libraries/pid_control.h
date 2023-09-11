/**
 * @class PID Class
 * @brief The PID Class
*/
class PID {
    private:
        /// @brief PID attributes
        // Defining PID gains, these parameters must be tuned.

        
        double kp;///<proportional component
        
        double ki;///<integral component



        double kd;///<derivative component

        // delay
        double dt;
    public:
        /// @brief error variables
        double error = 0; ///<error variables
        double previous_error = 0; ///<error variables
        
        /// @brief PID terms
        double derivative_term; ///<PID Term used in calculating pid function
        double integral_term;///<PID Term used in calculating pid function
        double proportional_term;///<PID Term used in calculating pid function
        /**
         * @brief Default constructor: if no parameters sent in constructor, load default values (2,7,3,0.1)
         */
        PID()
            : kp(2.0), ki(7.0), kd(3.0), dt(0.1), error(0.0), previous_error(0.0), derivative_term(0.0), integral_term(0.0), proportional_term(0.0) {
        }
        /**
         * @brief overloading constructor if parameters sent to the constructor to set the parameters.
         * @param p kp: 
         * @param i ki: integral component
         * @param d kd: derivative component
         * @param t dt: delay
        */
        PID(double p, double i, double d, double t)
            : kp(p), ki(i), kd(d), dt(t), error(0), previous_error(0), derivative_term(0), integral_term(0), proportional_term(0) {
        }
        /**
         * @brief function of PID control
         * @param current_value the current setpoint
         * @param target_value the target value we want to reach
         * @return the PID control calculations
         */
        double pid_control(double current_value, double target_value) {
            this->error = target_value - current_value;
            this->proportional_term = error;
            this->integral_term += error;
            this->derivative_term = error - previous_error;

            // updating error
            this->previous_error = this->error;

            // return PID control calculation
            return this->kp*proportional_term + ki*integral_term + kd*derivative_term;
        }
        /**
         * @brief change value of Kp
         * @param p // new kp
         */
        void changeKp(double p){
            this->kp=p;
        }
        /**
         * @brief get Value of Kp
         * @return Kp
         */
        double getKp(){
            return this->kp;
        }
        /**
         * @brief change value of kd
         * @param d new kd
         */
        void changeKd(double d){
            this->kd=d;
        }
        /**
         * @brief get value of kd
         * @return kd
         */
        double getKd(){
            return this->kd;
        }
        /**
         * @brief change value of ki
         * @param i new ki
         */
        void changeKi(double i){
            this->ki=i;
        }
        /**
         * @brief return value of ki
         * @return ki
         */
        double getKi(){
            return this->ki;
        }
        /**
         * @brief change value of dt
         * @param t new dt
         */
        void changeDelay(double t){
            this->dt=t;
        }
        /**
         * @brief get value of dt
         * @return dt (delay)
         */
        double getDelay(){
            return this->dt;
        }
};