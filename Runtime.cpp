#include <iostream>
#include <math.h>
#include <fstream>
#include "Matrix.hpp"
#include "Housing.hpp"
#include "Line.hpp"
#include <cmath>


double getAverage(std::vector<double>); 
void scanHousing(std::vector<Housing> *); 
std::vector<double> get_d_r_values(std::vector<Housing> *, int); 
std::vector<Point> get_all_point(std::vector<double>* , std::vector<double>*); 
Line create_line(Point, Point); 
std::vector<Line> get_all_lines(Point, std::vector<Point>*); 
void swap(int, int, std::vector<Line>*); 
void quick_sort(std::vector<Line>*, int, int); 
double set_res(Line*, std::vector<Point>*); 
double get_slope_mode(std::vector<Line>*);
std::vector<double> get_place_values(double, double);
std::vector<Line> get_line_from_slopes(std::vector<double>, Point); 
double get_slope(double, double, Point, std::vector<Point> * ); 
double get_best_slope(std::vector<Line> *, std::vector<Point> *);
Line get_best_fit_line(int, int);  
void set_axis(std::string val,int*); 
std::string get_heading(int); 
void print_best_fit(int, int, Line); 
int print_predicted(Line); 
double set_selected(); 
void set_r_squr(Line *, Point *, std::vector<Point> *); 
void set_tot(Line *, Point *, std::vector<Point> *);

int main()
{

	std::vector<Line> all_lines(0); //all lines with input x and output being median house valuues

	//getting all the best fit lines 
	for (int i = 0; i < 8; i++)
	{
		Line temp; //line that represent the best fit line based off of x-axis (i) and y-axis
		temp = get_best_fit_line(i, 8); 
		all_lines.push_back(temp); 
	}

	//printing out result
	for (int i = 0; i < all_lines.size(); i++)
	{
		Line temp = all_lines[i]; 
		print_best_fit(i, 8, temp); 
	}


	return 0; 
}

/*
*Paramter: void, nothing 
*Return: input, the x value they want to test 
*/
double set_selected()
{
	system("clear");
	int input_val; 
	std::cout << "Enter an input value : "; 
	std::cin >> input_val; 
	return input_val; 
}

/*
*Paramter: ud, int, the user decision to do 
		   best_fit, Line, the line
*Return: int, the user decision 
*/
int print_predicted(Line line)
{
	bool val;  //determine if it should continue to run
	double user; //the user decision of what to do 

	val = true; 

	while (val)
	{
		Point t_val; 
		double output; //predicted  
		double input; //input entered by the user

		input = set_selected(); 

		//getting the predicted y value 
		t_val = line.get_point(input); 
		output = t_val.get_y(); 

		//print out output 
		system("clear"); 
		std::cout << "Input: " << input << std::endl; 
		std::cout << "Output: " << output << std::endl << std::endl; 

		//determine what to do 
		std::cout<< "1. Test another data point" << std::endl; 
		std::cout<< "2. See Another Relationship" << std::endl;
		std::cout<< "3. Quit Program" << std::endl;

		//get the user input 
		std::cin >> user; 

		val = !(--user); 
	}

	return user; //1 or 2 
}

/*
*Paramter: x, int, the input index heading
		   y, int, the output index heading
		   best, Line, line of best fit for the model 
*Return: the next step
*/
void print_best_fit(int x, int y, Line best)
{
	int select; //determine to see if they want to see another relationship or start inputting values

	//displaying result
	std::cout<< "x is " << get_heading(x) << std::endl; 
	std::cout<< "y is " << get_heading(y) << std::endl; 
	std::cout<< "The model: " << best.to_string() << std::endl; 
	std::cout<< "The r^2 value: " << best.get_rsqr() << std::endl << std::endl; 
}


/*
*Paramter: index, int, the index for the heading
*Return: string, the heading
*/
std::string get_heading(int index)
{
	std::string heading[9] = {"Longitude" , "Latitude" ,"Housing Median Age" , 
	"Total Rooms", "Total Bedrooms" , "Population" , "Households", 
	"Median Income", "Median House Value" }; 

	return heading[index]; 
}

/*
*Paramter: a, address of input/output, asking user what they want as their input/output 
*Return: pass by address 
*/
void set_axis(std::string val, int* a)
{
	std::cout << "Choose an " << val << " axis" << std::endl; 
	std::cout<< "1. " << "Longitude" << std::endl; 
	std::cout<< "2. " << "Latitude" << std::endl; 
	std::cout<< "3. " << "Housing Median Age" << std::endl; 
	std::cout<< "4. " << "Total Rooms" << std::endl; 
	std::cout<< "5. " << "Total Bedrooms" << std::endl; 
	std::cout<< "6. " << "Population" << std::endl; 
	std::cout<< "7. " << "Households" << std::endl; 
	std::cout<< "8. " << "Median Income" << std::endl; 
	std::cout<< "9. " << "Median House Value" << std::endl; 

	std::cin >> *a;

	//clear screen
	system("clear");

}

/*
*Paramter: x, int, the input value based off of columns 
*		   y, int, the output values based off the columns 
*Return: Line, the line of best fit 
*/
Line get_best_fit_line(int x, int y)
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

	double slope; //the slope of the line 

	//scan documents
	scanHousing(&all_housing); 

	//getting x values and w yavlues (change 0 and 1 later)
	x_values = get_d_r_values(&all_housing, x); 
	y_values = get_d_r_values(&all_housing, y); 

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

	slope = get_slope(mode_val, 1, average, &allPoints); 

	Line best_fit(slope, average); 

	//find least square regression for that line
	set_r_squr(&best_fit, &average, &allPoints); 

	return best_fit; 	
}

/*
*Paramter: s, double, slope of the most idea. 
*         p, int, position of guessing best 
*		  a, Point, average point from data set 
*		  all_points, vector with points, all the points in the data set 
*Return: double, the slope that best represent the corelation
*/
double get_slope(double s, double p, Point a, std::vector<Point> * all_points)
{
	//only up to 6 decimal places 
	if (p > 6)
	{
		return s; 
	}
	std::vector<double> temp_slope(0);
	std::vector<Line> temp_lines(0);
	
	double best_slope; 
	
	temp_slope = get_place_values(s, p); 
	temp_lines = get_line_from_slopes(temp_slope, a); 

	best_slope = get_best_slope(&temp_lines, all_points); 

	return get_slope(best_slope, ++p, a, all_points); 
}

/*
*Paramter: lines, address of vector of lines, a list of lines with approx slopes 
* 		   allPoints, address of vectors that contains Point, All the data point in the data set
*Return: double, the slope of the line with the smallest leas
*/
double get_best_slope(std::vector<Line> * all_lines, std::vector<Point> * allPoints)
{
	//the first line in the vector
	Line first_line = (*all_lines)[0]; 

	//set linear regression of first line 
	set_res(&first_line, allPoints); 
	
	//setting min 
	double min_least_squre = first_line.get_res(); 
	double slope = first_line.get_slope(); 

	//go through, find the best slope
	for (int i = 1; i < all_lines -> size(); i++)
	{
		Line temp_line = (*all_lines)[i]; 
		set_res(&temp_line, allPoints); 
		double temp_l_s = temp_line.get_res(); 
		double temp_s = temp_line.get_slope(); 
		
		//checking, if yes, then setting
		if (min_least_squre > temp_l_s)
		{
			min_least_squre = temp_l_s; 
			slope = temp_s; 
		}
	}

	return slope; 
}

/*
*Paramter: slope, std::vector<double>, the list of slopes 
*		   Point, point, the mid point of the regression
*Return: std::vector<Line>, a bunch of lines based off assigned slope and point
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
			p, double, the placement aka increment 
*Return: std::vector<double>, a possible list of slopes with a .1 increment
*/
std::vector<double> get_place_values(double mode, double p)
{
	std::vector<double> v(0);
	mode -= pow(10, -p + 1);
	for (int i = 0; i < 20; i++)
	{
		v.push_back(mode + pow(10, -p) * i); 
	}
	return v; 
}


/*
*Paramter: line, address of the line, the line that have an unknown square regression
* 		   points, address of vectors of points, the list of data sets 
*Return: double, the least square regression, (value is set in line)
*/
double set_res(Line * line, std::vector<Point> * points)
{
	double sum = 0; 
	for (int i = 0; i < points->size(); i++)
	{
		Point ac_point = points->at(i); 
		Point th_point = line->get_point(ac_point.get_x());
		sum += ac_point.get_least_squre_regression(th_point); 
	}
	line->set_res(sum); 
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

/*
*Paramter: line, address of line, the line to put least square regression
*		   average, adress of point, the point with average x and y value
*		   all_points, vector of points, all the points in the data set
*Return: void, nothing
*/
void set_r_squr(Line * line, Point * average , std::vector<Point> * all_points)
{
	//setting the res for the line 
	set_res(line, all_points); 

	//setting the tot for the line
	set_tot(line, average, all_points); 
}

/*
*Paramter: line, address of line, the line to put least square regression
*		   average, adress of point, the point with average x and y value
*		   all_points, vector of points, all the points in the data set
*Return: void, nothing
*/
void set_tot(Line * line, Point * average, std::vector<Point> * all_points)
{
	double sum = 0; 
	for (int i = 0; i < all_points->size(); i++)
	{
		double diff; //difference between average point and y value
		
		diff = (average->get_y() - all_points->at(i).get_y()); 
		sum += pow(diff, 2); 
	}

	line->set_tot(sum);
}

