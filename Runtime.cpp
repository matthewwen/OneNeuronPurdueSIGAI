#include <iostream>
#include "Housing.hpp"
#include <vector>

double getAverage(vector<double> vec); 

int main(){

	vector<double> x_values; //all the input values for a function
	vector<double> y_values; //all the output values for a function 

	//example 
	Housing h1(-117.66, 35.6,14,1740,391,850,317, 2.5812); 
 

	return 0; 
}

double getAverage(vector<double> vec){
	if (vec.size == 0){
		return 0; 
	}

	double sum = 0.0; 
	for (int i = 0; i < vec.size(); i++){
		sum += vec[i]; 
	}

	return sum / vec.size(); 
}