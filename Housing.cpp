#include <iostream>
#include "Housing.hpp"

Housing::Housing(){}

Housing::Housing(double longitude, double latitude, 
		double housing_median_age, 
		double total_rooms, 
		double total_bedrooms, 
		double population,
		double households, 
		double median_income){
	this->longitude = longitude; 
	this->latitude = latitude; 
	this->total_rooms = total_rooms; 
	this->total_bedrooms = total_bedrooms; 
	this->population = population; 
	this->households = households; 
	this->median_income = median_income; 
}

double Housing::get_longitude(){
	return this->longitude; 
}

double Housing::get_latitude(){
	return this->latitude; 
} 

double Housing::get_housing_median_age(){
	return this->housing_median_age; 
} 
		
double Housing::get_total_rooms(){
	return this->total_rooms; 
}

double Housing::get_total_bedrooms(){
	return this->total_bedrooms; 
}  
		
double Housing::get_population(){
	return this->population; 
}
		
double Housing::get_households(){
	return this->households; 
}
		
double Housing::get_median_income(){
	return this->median_income; 
}