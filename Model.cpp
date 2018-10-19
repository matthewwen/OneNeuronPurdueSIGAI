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
Paramter: void, nothing
Description: get the d constant for the model
Return: double, constant for the model 
*/
double Model::get_constant()
{
    return this->constant; 
}

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
        sum += get_c(i) * pow(inputs[i],1); 
    }

    sum += get_constant(); 

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
    this->constant = coefficient[0]; 
    coefficient.erase(coefficient.begin()); 
    this->coefficient = coefficient; 
}

/*
Paramter: void, nothing 
Description: get's the number of coefficients 
Return: int, number of inputs  
*/ 
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
    std::string result = ""; 
    char conin [] = {'x','y','z','a','b','c','d','g','h','i','j','k','l','m','n','o','p'}; 
    for (int i = 0; i < get_c_size(); i++)
    {
        result += std::to_string(get_c(i)) + "*" + conin[i] +  " + "; 
        if (!(get_c_size() - i - 1))
        {
            result += std::to_string(get_constant()) + " = Median House Value"; 
        }
    }

    return result; 
}