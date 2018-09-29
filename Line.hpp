#include "Point.hpp"
#include <string>

class Line
{
    private: 
        double s;  
        double b; 
        double r_sq; 
    
    public:
        Line(); 
        Line(double); 
        Line(double, Point); 
        Point get_point(double); 
        void set_r_sq(double); 
        void set_b_value(Point); 
        double get_slope(); 
        double get_r_sq();
        std::string to_string(); 
};