#include <iostream> 
#include "hpp/Line.hpp"

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
*Paramters: r_res, double, the RES for least square regression
*Return: void, nothing 
*/
void Line::set_res(double r_res)
{
    this->r_res = r_res; 
}

/*
*Paramters: void, nothing
*Return: double, the RES for least square regression
*/
double Line::get_res()
{
    return this->r_res; 
}

/*
*Paramters: r_tot, double, the TOT for least square regression
*Return: void, nothing 
*/
void Line::set_tot(double r_tot)
{
    this->r_tot = r_tot; 
}

/*
*Paramters: void, nothing
*Return: double, the TOT for least square regression
*/
double Line::get_tot()
{
    return this->r_tot; 
}

/*
*Paramter: void, nothing
*Return: double, the best fit line 
*/
std::string Line::to_string()
{
    return "y = " + std::to_string(this->s) + "x + " + std::to_string(this->b);
}

/*
*Paramter: void, nothing
*Return: double, the least square regression
*/
double Line::get_rsqr()
{
    return 1 - (get_res() / get_tot()); 
}