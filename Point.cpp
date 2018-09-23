#include <iostream>
#include "Point.hpp"

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

double Point::get_x()
{
    return this->x; 
}

double Point::get_y()
{
    return this->y; 
}

double Point::get_least_squre_regression(Point point)
{
    return 0.0; 
} 

double Point::get_slope(Point point)
{
    return 0.0; 
} 