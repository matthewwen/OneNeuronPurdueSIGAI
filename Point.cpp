#include <iostream>
#include "Point.hpp"

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
*Paramter: point, Point, point that have average input/output 
*Return: double, least squre regression for y values
*/
double Point::get_least_squre_regression(Point point)
{
    return 0.0; 
} 

/*
*Paramter: point, Point, a point on coordinate plane 
*Return: double, slope created from the two points 
*/
double Point::get_slope(Point point)
{
    return 0.0; 
} 