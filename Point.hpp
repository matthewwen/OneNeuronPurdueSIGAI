class Point{

    private:
        double x; 
        double y; 
        
    public: 
        Point(); 
        Point(double x, double y);
        double get_x(); 
        double get_y(); 
        double get_least_squre_regression(Point point); 
        double get_slope(Point point); 

}; 