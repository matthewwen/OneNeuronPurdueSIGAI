#include <iostream>
#include "Housing.hpp"

Housing::Housing(){}

Housing::Housing(double longitude, double latitude, 
		int housing_median_age, 
		int total_rooms, 
		int total_bedrooms, 
		int population,
		int households, 
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

int Housing::get_housing_median_age(){
	return this->housing_median_age; 
} 
		
int Housing::get_total_rooms(){
	return this->total_rooms; 
}

int Housing::get_total_bedrooms(){
	return this->total_bedrooms; 
}  
		
int Housing::get_population(){
	return this->population; 
}
		
int Housing::get_households(){
	return this->households; 
}
		
double Housing::get_median_income(){
	return this->median_income; 
}