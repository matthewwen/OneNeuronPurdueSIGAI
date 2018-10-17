#include "Object.hpp"
#include <math.h> 

/*
Paramter: vector, coefficent, the coefficients of the model 
Description: constructor method that sets the coefficients 
* of the model 
Return: void, nothing 
*/ 
Model::Model(std::vector<double> coefficient)
{   
    set_coef(coefficient); 
}

/*
Paramter: void, nothing 
Description: Empty Construction
Return: void, nothing 
*/
Model::Model(){}

/*
Paramter: vector, inputs, the input values for model
Description: based off the inputs, this gets a predicted
* output based off the model 
Return: double, predicted output 
*/
double Model::get_p(std::vector<double> inputs)
{
    double sum = 0; 
    for (int i = 0; i < inputs.size(); i++)
    {
        sum += get_c(3 * i) * pow(inputs[i], 1); 
        sum += get_c(3 * i + 1) * pow(inputs[i], 2); 
        sum += get_c(3 * i + 2) * pow(inputs[i], 3); 
    }

    sum += this->b_value; 

    return sum; 
}

/*
Paramter: int, pos, the position for the coefficent 
Description: this get's the coefficient based off a given 
* index ex. (0, longitude or 1, latitude)
Return: double, coefficient for that input value 
*/
double Model::get_c(int pos)
{
    return this->coefficient[pos]; 
}

/*
Paramter: vector, coefficient, the coefficients of model 
Description: this sets the coefficent of the model 
Return: void, nothing 
*/ 
void Model::set_coef(std::vector<double> coefficient)
{
    this->b_value = coefficient[0]; 
    coefficient.erase(coefficient.begin()); 
    this->coefficient = coefficient;  
}

int Model::get_c_size()
{
    return this->coefficient.size(); 
}

/*
Paramater: void, nothing 
Description: This displays the equation for the model 
Return: string, the model from the data set 
*/ 
std::string Model::to_string()
{
    std::string result = "Constant: " + std::to_string(this->b_value) + "\n"; 
    for (int i = 0 ; i < this->coefficient.size(); i++)
    {
        result += std::to_string(get_c(i)) + ", "; 
    } 

    return result; 
}