#include <iostream> 
#include "Line.hpp"

/*
*Paramters: void, nothing
*Return: void, nothing 
*/
Line::Line(){}

/*
*Paramter: s, double, the slope of the line 
*          p, point, a point on the line 
*Return: void, nothing 
*/
Line::Line(double s, Point p)
{
    this->s = s; 
    set_b_value(p); 
}

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

/*
*Paramters: void, nothing
*Return: double, the least square regression of line 
*/
double Line::get_r_sq()
{
    return this->r_sq; 
}

/*
*Paramter: void, nothing
*Return: double, the best fit line 
*/
std::string Line::to_string()
{
    return "y = " + std::to_string(this->s) + "x + " + std::to_string(this->b);
}