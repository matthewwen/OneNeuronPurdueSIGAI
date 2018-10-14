#include <iostream>
#include <math.h>
#include <fstream>
#include "Matrix.hpp"
#include "Housing.hpp"
#include <cmath>

Matrix set_a_matrix(int, int, std::vector<Housing>*); 
void scanHousing(std::vector<Housing> *); 
Matrix test(); 


int main()
{
	std::vector<Housing> all_housing(0); //all the housing in one vector array
	int r; //number of rows for matrix A (all the data set)
	int c; //number of columns for matrix A (all the data set )
	std::vector<double> b_median_house_output; 

	//scan documents
	scanHousing(&all_housing); 

	c = 8; 
	r = all_housing.size(); 

	Matrix a_matrix; 
	Matrix at_matrix; 
	Matrix ata_matrix; 

	a_matrix = set_a_matrix(r, c, &all_housing); 
	at_matrix = a_matrix.get_tranpose(); 
	ata_matrix = at_matrix.multiple_matrix(a_matrix);

	std::cout<<a_matrix.to_string()<<std::endl; 
	std::cout<<at_matrix.to_string()<<std::endl; 
	std::cout<<ata_matrix.to_string()<<std::endl; 

	return 0; 
}

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
Paramter: int, r, the number of rows in the matrix
* int, c, the number of columns in the matrix
* *vector, all_housing, list of all the housing given
Description: This sets up the matrix with the data value givened 
Return: Matrix, Matrix gotten from all the housing 
*/ 
Matrix set_a_matrix(int r, int c, std::vector<Housing>* all_housing)
{
	Matrix matrix(r,c); 
	for (int i = 0; i < r; i++)
	{
		Housing htemp; //housing temp 
		htemp = all_housing->at(i); 

		std::vector<double> temp;
		
		for (int j = 0; j < c; j++)
		{
			temp.push_back(htemp.get_value(j)); 
		}
		matrix.set_row_elements(i, temp); 
	}

	return matrix;
}