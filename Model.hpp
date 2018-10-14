#include "Matrix.hpp"

class Model
{
    private: 
        std::vector<double> coefficient; 
    
    public: 
        Model(std::vector<double>); 
        Model(); 
        double get_p(std::vector<double>); 
        double get_c(int); 
        void set_coef(std::vector<double>); 

}; 