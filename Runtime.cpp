#include <iostream>
#include "Housing.hpp"
#include <vector>
#include <math.h>

double getAverage(std::vector<double> vec); 

int main()
{

	std::vector<double> x_values(0); //all the input values for a function
	std::vector<double> y_values(0); //all the output values for a function 

	int x_average; //the average of all the input values
	int y_average; //the average of all the output values

	//example 
	Housing h1(-117.66, 35.6,14,1740,391,850,317, 2.5812); 
 

	return 0; 
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
}