#include "Point.hpp"
#include <string>

class Line
{
    private: 
        double s;  
        double b; 
        double r_res; 
        double r_tot; 
    
    public:
        Line(); 
        Line(double); 
        Line(double, Point); 
        Point get_point(double); 
        void set_res(double); 
        void set_b_value(Point); 
        double get_slope(); 
        double get_res();
        void set_tot(double); 
        double get_tot();
        std::string to_string(); 
        double get_rsqr(); 
};