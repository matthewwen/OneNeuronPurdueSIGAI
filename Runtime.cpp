#include <iostream>
#include "Housing.hpp"
#include <vector>
#include <math.h>
#include <fstream>
#include "Line.hpp"

double getAverage(std::vector<double> vec); 
void scanHousing(std::vector<Housing> * vec); 
std::vector<double> get_d_r_values(std::vector<Housing> * hous, int index); 
std::vector<Point> get_all_point(std::vector<double> * x_values, std::vector<double> * y_values); 
Line create_line(Point p1, Point p2); 

int main()
{
	std::vector<Housing> all_housing(0); //all the housing in one vector array

	std::vector<double> x_values(0); //all the input values for a function
	std::vector<double> y_values(0); //all the output values for a function 
	std::vector<Point> allPoints(0); //all the points for input and outputs 

	double x_average; //the average of all the input values
	double y_average; //the average of all the output values

	//scan documents
	scanHousing(&all_housing); 

	//getting x values and w yavlues (change 0 and 1 later)
	x_values = get_d_r_values(&all_housing, 0); 
	y_values = get_d_r_values(&all_housing, 1); 

	///getting the average for domain and range 
	x_average = getAverage(x_values); 
	y_average = getAverage(y_values); 

	//create point for the average
	Point average(x_average, y_average); 
	
	//getting all the points
	allPoints = get_all_point(&x_values, &y_values); 

	return 0; 
}

/*
*Paramter: p1, Point, a point in the data set 
		   p2, Point, another poin the data set
*Return: Line, the line that passes the two points
*/
Line create_line(Point p1, Point p2)
{
	double slope; //the slope of the line
	double b_value; //the constant of the line 

	//creating paramters for line 
	slope = p1.get_slope(p2); 
	Line my_line(slope); 
	my_line.set_b_value(p1); 

	return my_line; 
} 

/*
* Parameter: vec, vector<double>, a vector with a set of values
* Return: the average value
*/
double getAverage(std::vector<double> vec)
{
	if (vec.size() == 0){
		return 0; 
	}

	double sum = 0.0; 
	for (int i = 0; i < vec.size(); i++){
		sum += vec[i]; 
	}

	return sum / vec.size(); 
};

/*
* Parameter: vec, address of vector, list of all the housing options  
* Return: void, null 
*/ 
void scanHousing(std::vector<Housing> * vec)
{
	//opening the file 
	std::ifstream ip; 
	ip.open("california_housing_train.csv"); 

	//getting the headings
	std::string val; 
	getline(ip, val, '\n');  

	//setting it into vector 
	while (ip.good()){
		std::string longitude; 
		std::string latitude; 
		std::string housing_median_age; 
		std::string total_rooms; 
		std::string total_bedrooms; 
		std::string population; 
		std::string households; 
		std::string median_income; 
		std::string median_house_value; 

		getline(ip, longitude, ','); 
		getline(ip, latitude, ','); 
		getline(ip, housing_median_age, ','); 
		getline(ip, total_rooms, ','); 
		getline(ip, total_bedrooms, ','); 
		getline(ip, population, ','); 
		getline(ip, households, ','); 
		getline(ip, median_income, ','); 
		getline(ip, median_house_value, '\n'); 

		Housing temp(stod(longitude), stod(latitude), 
			stod(housing_median_age), stod(total_rooms), 
			stod(total_bedrooms), stod(population), 
			stod(households), stod(median_income), 
			stod(median_house_value)); 
	
		vec->push_back(temp); 
	}

	ip.close(); 
}


/* 
*Paramter: hous, address of Housing, list of all the housing options 
*		   index, int, the logitutde etc. it want to return 
*Return: vector<double> list of all the values for that particualar column (input/output)
*/
std::vector<double> get_d_r_values(std::vector<Housing> * hous, int index)
{
	std::vector<double> vec(0); 
	for (int i = 0; i < hous->size(); i++)
	{
		vec.push_back((*hous)[i].get_value(index)); 
	}
	return vec; 
}

/*
*Paramter: x_values, std::vector<double>, all the x values for coordinate plane 
* 		   y_values, std::vector<double>, all the y values for coordinate plane 
*Return: std::vector<Point> a list of all the points
*/
std::vector<Point> get_all_point(std::vector<double> * x_values, std::vector<double> * y_values)
{
	std::vector<Point> allPoints(0); //collection of all the points
	for (int i = 0 ; i < x_values->size(); i++)
	{
		Point point((*x_values)[i], (*y_values)[i]); 
		allPoints.push_back(point); 
	}

	return allPoints; 
}