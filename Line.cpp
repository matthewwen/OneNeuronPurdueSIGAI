#include <iostream> 
#include "Line.hpp"

/*
*Paramters: void, nothing
*Return: void, nothing 
*/
Line::Line(){}

/*
*Paramters: s, double, the slope of the line 
*Return: void, nothing 
*/
Line::Line(double s)
{
    this->s = s; 
}

/*
*Paramter: void, nothing 
*Return: double, the slope of the line
*/
double Line::get_slope()
{
    return this->s; 
}

void Line::set_b_value(Point point)
{
    this->b = point.get_y() - this->s * point.get_x(); 
}


/*
*Paramters: s, double, slope of the equation y = sx + b
*           b, double, constant of the equation y = sx + b 
*Return: void, nothing 
*/
Line::Line(double s, double b)
{
    this->s = s; 
    this->b = b; 
}

/*
*Paramters: x, double, the input of the equation y = sx + b 
*Return: Point, the theoretical value at a point 
*/
Point Line::get_point(double x)
{
    double y_value; //the theoretical y value based off of input of x 
    Point point; //the theoretical point 

    y_value = this-> s * x + this -> b; 

    point = Point(x, y_value); 

    return point; 
}

/*
*Paramters: r_sq, double, the least square regression of line 
*Return: void, nothing 
*/
void Line::set_r_sq(double r_sq)
{
    this->r_sq = r_sq; 
}

double Line::get_r_sq()
{
    return this->r_sq; 
}