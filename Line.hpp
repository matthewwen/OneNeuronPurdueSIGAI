class Line
{
    private: 
        double s;  
        double b; 
        double r_sq; 
    
    public:
        Line(double a, double b); 
        Point get_point(double x); 
        void set_r_sq(double r_sq); 
}