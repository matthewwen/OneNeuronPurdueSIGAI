#include <iostream>
#include "Housing.hpp"

Housing::Housing(){}

Housing::Housing(double longitude, double latitude, 
		double housing_median_age, 
		double total_rooms, 
		double total_bedrooms, 
		double population,
		double households, 
		double median_income, 
		double median_house_value){
	this->longitude = longitude; 
	this->latitude = latitude; 
	this->housing_median_age = housing_median_age; 
	this->total_rooms = total_rooms; 
	this->total_bedrooms = total_bedrooms; 
	this->population = population; 
	this->households = households; 
	this->median_income = median_income; 
	this->median_house_value = median_house_value; 
}

/*
*Paramter: void, nothing 
*Return: double, the longitude
*/
double Housing::get_longitude()
{
	return this->longitude; 
}

/*
*Paramter: void, nothing 
*Return: double, the latitude
*/
double Housing::get_latitude()
{
	return this->latitude; 
} 

/*
*Paramter: void, nothing 
*Return: double, the housing median age
*/
double Housing::get_housing_median_age()
{
	return this->housing_median_age; 
} 

/*
*Paramter: void, nothing 
*Return: double, the total rooms
*/		
double Housing::get_total_rooms()
{
	return this->total_rooms; 
}

/*
*Paramter: void, nothing 
*Return: double, the total bedrooms 
*/
double Housing::get_total_bedrooms()
{
	return this->total_bedrooms; 
}  

/*
*Paramter: void, nothing 
*Return: double, the population 
*/		
double Housing::get_population()
{
	return this->population; 
}

/*
*Paramter: void, nothing 
*Return: double, the households 
*/		
double Housing::get_households()
{
	return this->households; 
}

/*
*Paramter: void, nothing 
*Return: double, the median income 
*/		
double Housing::get_median_income()
{
	return this->median_income; 
}

/*
* Paramter: index, int, the index of local variables (longitude, latitude, housing median age)
* Return: Housing, the value (longitude, latitude, housing median)
*/
double Housing::get_value(int index)
{
	return get_switch_index_val(0, index) * this->longitude + 
	get_switch_index_val(1, index) * this->latitude + 
	get_switch_index_val(2, index) * this->housing_median_age + 
	get_switch_index_val(3, index) * this->total_rooms + 
	get_switch_index_val(4, index) * this->total_bedrooms + 
	get_switch_index_val(5, index) * this->population + 
	get_switch_index_val(6, index) * this->households + 
	get_switch_index_val(7, index) * this->median_income + 
	get_switch_index_val(8, index) * this->median_house_value; 
}

/*
*Paramter: i, int, position of variable (longitude = 1). 
		   index, int, index of the value the user want to use (longitude = 0, latitude = 1)
*Return: double, the 
*/
int Housing::get_switch_index_val(int i, int index) 
{
	return ((i+1) % (index + 2) / (i + 1)) * ((i+1) % (index + 2) / (index + 1)); 
}