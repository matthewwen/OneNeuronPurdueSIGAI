#include <iostream>
#include "Housing.hpp"
#include <vector>
#include <math.h>
#include <fstream>

double getAverage(std::vector<double> vec); 
void scanHousing(std::vector<Housing> * vec); 
std::vector<double> get_d_r_values(std::vector<Housing> * hous, int index); 

int main()
{
	std::vector<Housing> all_housing(0); //all the housing in one vector array

	std::vector<double> x_values(0); //all the input values for a function
	std::vector<double> y_values(0); //all the output values for a function 

	double x_average; //the average of all the input values
	double y_average; //the average of all the output values

	//scan documents
	scanHousing(&all_housing); 

	//checking housing_median_age/ total_rooms/ median_house_value
	double hma = all_housing[0].get_value(2); 
	double tr = all_housing[0].get_value(3); 
	double mhv = all_housing[0].get_value(8); 

	//print the values saved in the first object
	std::cout << "Housing Median Age: " << hma << std::endl; 
	std::cout << "Total Rooms: " << tr << std::endl; 
	std::cout << "Median House Value: " << mhv << std::endl; 

	//getting x values and w yavlues  
	x_values = get_d_r_values(&all_housing, 0); 
	y_values = get_d_r_values(&all_housing, 1); 
	
	//extra variables vectors 
	std::vector<double> v01 = get_d_r_values(&all_housing, 2); 
	std::vector<double> v02 = get_d_r_values(&all_housing, 3); 
	std::vector<double> v03 = get_d_r_values(&all_housing, 4); 
	std::vector<double> v04 = get_d_r_values(&all_housing, 5); 
	std::vector<double> v05 = get_d_r_values(&all_housing, 6); 
	std::vector<double> v06 = get_d_r_values(&all_housing, 7); 
	std::vector<double> v07 = get_d_r_values(&all_housing, 8); 

	///getting the average for domain and range 
	x_average = getAverage(x_values); 
	y_average = getAverage(y_values); 

	//extra variables average
	double d01 = getAverage(v01); 
	double d02 = getAverage(v02); 
	double d03 = getAverage(v03); 
	double d04 = getAverage(v04); 
	double d05 = getAverage(v05); 
	double d06 = getAverage(v06); 
	double d07 = getAverage(v07); 

	std::cout << "0 average: " << x_average << std::endl; 
	std::cout << "1 average: " << y_average << std::endl; 

	//print result examples
	std::cout << "2 average: " << d01 << std::endl; 
	std::cout << "3 average: " << d02 << std::endl; 
	std::cout << "4 average: " << d03 << std::endl; 
	std::cout << "5 average: " << d04 << std::endl; 
	std::cout << "6 average: " << d05 << std::endl; 
	std::cout << "7 average: " << d06 << std::endl; 
	std::cout << "8 average: " << d07 << std::endl; 


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

std::vector<double> get_d_r_values(std::vector<Housing> * hous, int index)
{
	std::vector<double> vec(0); 
	for (int i = 0; i < hous->size(); i++)
	{
		vec.push_back((*hous)[i].get_value(index)); 
	}
	return vec; 
}