#include <iostream>
#include <math.h>
#include <fstream>
#include "Object.hpp"
#include "Housing.hpp"
#include <cmath>

Matrix set_a_matrix(int, int, std::vector<Housing>*); 
Matrix get_b_output(std::vector<Housing>*); 
void scanHousing(std::vector<Housing> *); 
std::vector<double> get_p_output(Model, std::vector<Housing> *); 
double get_r_s(std::vector<double>, std::vector<Housing> *); 
void record_data(std::vector<double>); 

int main()
{
	std::vector<Housing> all_housing(0); //all the housing in one vector array
	
	int r; //number of rows for matrix A (all the data set)
	int c; //number of columns for matrix A (all the data set )
	
	Matrix b_mho; //the output for Ax aka the median house output 
	Matrix atb_mho; //the ouput when the operation A tranpose * b happens 

	Matrix a_matrix; //The A matrix from Ax = b
	Matrix at_matrix; //The Tranpose of A 
	Matrix ata_matrix; //A tranpose * A

	Matrix r_ech; // this is [At * A | At * b] preparing to be simplified to row echelon form 

	Model model; //model that best represent the situation
	std::vector<double> coef; //coefficient for the model

	std::vector<double> p_outputs; //predicted outputs from model 

	double r_s; //the r^2 value for the regression

	//scan documents
	scanHousing(&all_housing); 

	//getting list of outcomes
	b_mho = get_b_output(&all_housing); 

	//setting rows and columns 
	c = 8; 
	r = all_housing.size(); 

	//getting A and Tranpose of A 
	a_matrix = set_a_matrix(r, c, &all_housing); 
	at_matrix = a_matrix.get_tranpose(); 

	//Multiplying AT * A 
	ata_matrix = at_matrix.multiple_matrix(a_matrix);

	//Multiplying AT * b 
	atb_mho = at_matrix.multiple_matrix(b_mho); 

	//get matrix in row echelon form, preparing to be simplified 
	r_ech = ata_matrix.row_echelon(atb_mho.get_col(0)); 

	//getting coefficents for model and then creating the model
	coef = r_ech.solve(); 
	model.set_coef(coef);

	//get all the predicted outputs 
	p_outputs = get_p_output(model, &all_housing); 

	//getting r^2 value  
	r_s = get_r_s(p_outputs, &all_housing); 

	//displaying the model and the r^2 value
	std::cout<<"The Model: " << model.to_string()<<std::endl; 
	std::cout<<"R^2 value: "<<r_s<<std::endl; 

	record_data(p_outputs);

	return 0; 
}

/*
Paramter: vector, p_outputs, the predicted outputs 
Description: Puts all the predicted outputs with their IDs in 
* a csv file 
Return: void, nothing 
*/
void record_data(std::vector<double> p_outputs)
{
	std::ofstream myfile;
    myfile.open ("california_housing_submission.csv");
    myfile << "ID, median_house_value\n";
	for (int i = 0; i < p_outputs.size(); i++)
	{
		myfile << std::to_string(i + 1) + ", " + std::to_string(p_outputs[i]) + "\n"; 
	}
    myfile.close();
}

/*
Paramter: vector, p_out, the predicted outputs 
* pointer vector, all_hou, all the housing data givened 
Description: this gets the r^2 value of the model we predicted 
Return: the r^2 of the model
*/ 
double get_r_s(std::vector<double> p_out, std::vector<Housing> * all_hou)
{
	double average; //the average of median house prices 
	double tot; //the SS tot of the regression 
	double res; //the SS res of the regression 

	//starting values
	average = 0; 
	tot = 0; 
	res = 0; 

	//get the average 
	for (int i = 0; i < all_hou->size(); i++)
	{
		average += all_hou->at(i).get_value(8); 
	}
	average /= all_hou->size(); 
	std::cout << "Average: " << average << std::endl; 

	//getting SS tot value 
	for (int i = 0; i < p_out.size(); i++)
	{
		double diff; //p_out value - the average
		diff = all_hou->at(i).get_value(8) - average; 
		tot += diff * diff; 
	}

	//getting the SS res value 
	for (int i = 0; i < p_out.size(); i++)
	{
		double diff; //predicted - actual 
		diff = p_out[i] - all_hou->at(i).get_value(8); 
		res += diff * diff; 
	}

	return 1 - (res/tot); 

}

/*
Paramter: Model, model, the model that represent the data
* address of vector, all_housing, all the houses givened to us
Description: This gets all the outputs based off certain data points
* inserted into the data 
Return: vector, all predicted outputs 
*/
std::vector<double> get_p_output(Model model, std::vector<Housing> * all_housing)
{
	std::vector< std::vector<double> > inputs; //inputs from all housing
	std::vector<double> outputs; //the predicted outputs 

	//getting all the inputs 
	for (int i = 0; i < all_housing -> size(); i++)
	{
		std::vector<double> temp; //inputs at specific index
		Housing tHou; //house at specific index 

		tHou = all_housing->at(i); 
		 
		for (int j = 0; j < 8 ;j++)
		{
			temp.push_back(tHou.get_value(j)); 
		}
		
		inputs.push_back(temp); 
	}

	//getting the outputs 
	for (int i = 0; i < inputs.size(); i++)
	{
		double val; //value of predicted
		val = model.get_p(inputs[i]); 

		outputs.push_back(val); 
	}
	
	return outputs; 
}

/*
Parameter: vec, address of vector, list of all the housing options
Description: gets the values from the excel documents   
Return: void, null 
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

/*
Paramter:  *vector, all_housing, list of all the housing given
Description: gets the output aka b from Ax = b 
Return: vector, list of all the outputs 
*/ 
Matrix get_b_output(std::vector<Housing>* all_housing)
{	
	std::vector< std::vector<double> > twoD; //the matrix 
	
	//getting all the values 
	for (int i = 0; i < all_housing->size(); i++)
	{
		std::vector<double> temp; //vector with one element 
		Housing htemp; //housing temp 

		//getting house 
		htemp = all_housing->at(i); 

		//adding element into temp vector 
		temp.push_back(htemp.get_value(8)); 

		//adding vector into matrix
		twoD.push_back(temp); 
	}
	
	//creating the matrix 
	Matrix m(twoD); 

	return m;
}