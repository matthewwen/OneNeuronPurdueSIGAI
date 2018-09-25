#include "Point.hpp"

class Line
{
    private: 
        double s;  
        double b; 
        double r_sq; 
    
    public:
        Line(); 
        Line(double s); 
        Line(double a, double b); 
        Point get_point(double x); 
        void set_r_sq(double r_sq); 
        void set_b_value(Point point); 
        double get_slope(); 
        double get_r_sq();
};