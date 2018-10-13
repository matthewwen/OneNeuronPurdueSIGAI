#include <iostream>
#include "hpp/Point.hpp"
#include <math.h> 

/*
*Parameter: void, nothing
*Return: void, nothing
*/
Point::Point(){}

/*
*Paramter: x, double, the x value of coordinate plane
*          y, double, the y value of the coordinate plnae 
*Return: void, nothing 
*/
Point::Point(double x, double y)
{
    this->x = x; 
    this->y = y; 
}

/*
*Paramter: void, nothing  
*Return: double, x value on coordinate plane 
*/
double Point::get_x()
{
    return this->x; 
}

/*
*Paramter: void, nothing  
*Return: double, y value on coordinate plane 
*/
double Point::get_y()
{
    return this->y; 
}

/*
*Paramter: point, Point, theoretical point value on line or Average point value  
*Return: double, least squre regression for y values
*/
double Point::get_least_squre_regression(Point point)
{
    double dif_t_to_a; //difference between theoretical to actual point value (object itself) 

    dif_t_to_a = this->get_y() - point.get_y();

    return dif_t_to_a * dif_t_to_a; 
} 

/*
*Paramter: point, Point, a point on coordinate plane 
*Return: double, slope created from the two points 
*/
double Point::get_slope(Point point)
{
    double diff_x; //difference in x values
    double diff_y; //difference in y values

    diff_y = this->get_y() - point.get_y(); 
    diff_x = this->get_x() - point.get_x(); 

    return diff_y / diff_x; 
} 