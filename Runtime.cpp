#include <iostream>
#include "Housing.hpp"
#include <vector>
#include <math.h>
#include <fstream>
#include "Line.hpp"

double getAverage(std::vector<double>); 
void scanHousing(std::vector<Housing> *); 
std::vector<double> get_d_r_values(std::vector<Housing> *, int); 
std::vector<Point> get_all_point(std::vector<double>* , std::vector<double>*); 
Line create_line(Point, Point); 
std::vector<Line> get_all_lines(Point, std::vector<Point>*); 
void swap(int, int, std::vector<Line>*); 
void quick_sort(std::vector<Line>*, int, int); 
double set_linear_regession(Line*, std::vector<Point>*); 
double get_slope_mode(std::vector<Line>*);
std::vector<double> get_first_place_values(double);
std::vector<Line> get_line_from_slopes(std::vector<double> slope, Point points); 

int main()
{
	std::vector<Housing> all_housing(0); //all the housing in one vector array

	std::vector<double> x_values(0); //all the input values for a function
	std::vector<double> y_values(0); //all the output values for a function 
	std::vector<Point> allPoints(0); //all the points for input and outputs 
	std::vector<Line> allLines(0); //all the lines create from point data set and average 
	std::vector<double> first_decimal_slopes(0); //the approx range of slope for first data point
	std::vector<Line> list_point_one_lines(0); //the list of lines with .* as slopes

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
	
	//getting all the lines 
	allLines = get_all_lines(average, &allPoints); 

	//sort them
	quick_sort(&allLines, 0, allLines.size() - 1); 

	//Calculate linear regression. One less than mode, One Greater than mode. 
	int mode_val = get_slope_mode(&allLines); 

	//get a list of all possible slopes 
	first_decimal_slopes = get_first_place_values(mode_val);

	//get lines from all possible slopes
	list_point_one_lines = get_line_from_slopes(first_decimal_slopes, average); 

	//checking to see if the range is correct 
	for (int i = 0; i < list_point_one_lines.size(); i++)
	{
		set_linear_regession(&list_point_one_lines[i], &allPoints); 
		std::cout<<list_point_one_lines[i].get_r_sq()<<std::endl; 
	}

	return 0; 
}

/*
*Paramter: slope, std::vector<double>, the list of slopes 
*		   Point, point, the mid point of the regression
*/
std::vector<Line> get_line_from_slopes(std::vector<double> slope, Point point)
{
	std::vector<Line> lines(0); 
	for (int i = 0; i < slope.size(); i++)
	{
		Line temp(slope[i], point);
		lines.push_back(temp); 
	}
	return lines; 
}

/*
*Parmater: mode, double, the mode for slope for best least square regression
*Return: std::vector<double>, a possible list of slopes with a .1 increment
*/
std::vector<double> get_first_place_values(double mode)
{
	std::vector<double> v(0);
	mode--;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(mode + (0.1)*i); 
	}
	return v; 
}


/*
*Paramter: line, address of the line, the line that have an unknown square regression
* 		   points, address of vectors of points, the list of data sets 
*Return: double, the least square regression, (value is set in line)
*/
double set_linear_regession(Line * line, std::vector<Point> * points)
{
	double sum = 0; 
	for (int i = 0; i < points->size(); i++)
	{
		Point ac_point = points->at(i); 
		Point th_point = line->get_point(ac_point.get_x());
		sum += ac_point.get_least_squre_regression(th_point); 
	}
	line->set_r_sq(sum); 
	return sum; 
}

/*
*Parameter: all_line, the address of the vector wit line, all the lines from mid point to all the points
*Return: return the mode (rounded) that occurs most often
*/
double get_slope_mode(std::vector<Line> * all_line)
{
	int max_count = 0; 
	int current_count = 0; 
	int max_count_val = 0; 
	int current_val = 0;
	for (int i = 0; i < all_line->size(); i++)
	{
		int temp = all_line -> at(i).get_slope();
		//std::cout << temp << std::endl; 
		if (current_val == temp)
		{
			current_count++; 
		}
		else
		{
			if (current_count >= max_count)
			{
				max_count = current_count; 
				max_count_val = current_val;
			}
			current_count = 0;
			current_val = temp;
		}
	}
	return max_count_val; 
}

/*
*Paramter: array, address of vector<Line>, putting arrays in order 
* 		   low, int, index of low end to sort 
* 		   high, int, index of high end of the sort
*Return: null, nothing
*/
void quick_sort(std::vector<Line> * array, int low, int high)
{
	if (low >= high || low >= array->size()){
		return; 
	}

	//index of low
	int j = low - 1; 

	//go through the list and swap
	double pivot = (*array)[high].get_slope();
	for (int i = low; i <= high - 1; i++)
	{
		double val1 = (*array)[i].get_slope(); 
		
		if (val1 <= pivot)
		{
			swap(++j, i, array); 
		}
	}

	//std::cout << "The pivot location: " << j << std::endl;  
	//put pivot at proper place 
	swap(high, ++j, array);

	//the recursion
	quick_sort(array, low, j - 1 ); 
	quick_sort(array, j + 1, high); 
}

/*
*Paramter: x1, int, the index line 1
		   x2, int, the index of line 2 
*Return: void, nothing, swaps the two elements
*/
void swap(int x1, int x2, std::vector<Line> * array_line)
{
	//get value at index 
	Line l1 = array_line -> at(x1); 
	Line l2 = array_line -> at(x2); 
	
	//set the index
	(*array_line)[x1] = l2; 
	(*array_line)[x2] = l1; 
}

/*
*Parameter: ave_point, Point, Average point (Have to be on least square regression line)
* 			all_points, std::vector<Point>, all the data points 
*Return: std::vector<Line>, all the lines that could represent the line of best fit 
*/
std::vector<Line> get_all_lines(Point ave, std::vector<Point> * all_points)
{
	std::vector<Line> all_lines(0);
	for (int i = 0; i < all_points -> size(); i++)
	{
		all_lines.push_back(create_line(ave, (*all_points)[i])); 
	}
	return all_lines; 
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