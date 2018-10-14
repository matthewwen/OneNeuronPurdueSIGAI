#include "Matrix.hpp"
#include <iostream> 

double add_vectors(std::vector<double>, std::vector<double>); 

/*
Paramter: vector<vector<double>>, matrix, each element represent a row and 
* then each element have elements that represent a column element 
*Description: Constructor Method of Matrix
*Return: void, nothing 
*/
Matrix::Matrix(std::vector< std::vector<double> > matrix)
{
    this->matrix = matrix; 
}

/*
Paramter: int, r, number of rows in Matrix
* int, c, number of columns in Matrix 
Description: Delcaration of Matirx with unknown elements
Return: void, nothing 
*/ 
Matrix::Matrix(int r, int c)
{
    std::vector<double> rows(c); //rows with just 0s filled with c elements 
    std::vector< std::vector<double> > matrix; //a matrix with r rows and c columns with all it's elements as 0 
    for (int i = 0; i < r; i++)
    {
        matrix.push_back(rows); 
    }

    this->matrix = matrix; 
}

/*
Paramter: void, nothing 
Description: Empty Constructor
Return: void, nothing
*/ 
Matrix::Matrix()
{
    std::vector< std::vector<double> > v(0); 
    this->matrix = v;  
}

/*
Paramter: void, nothing 
Description: gets the number of rows in a matrix 
Return: int, the number of rows in a matrix
*/
int Matrix::get_num_row()
{
    return this->matrix.size(); 
}

/*
Paramter: void, nothing 
Description: gets the number of columns in a matrix
Return: int, the number of columns in a matrix 
*/ 
int Matrix::get_num_col()
{
    return this->matrix[0].size(); 
} 

/*
Paramter: int, r, the row where you want to get it's elements 
Description: gets the element at a specific row 
Return: vector, a vector with all the elements at that row  
*/ 
std::vector<double> Matrix::get_row(int r)
{
    return this->matrix[r]; 
}

/*
Paramter: int, c, the column where you want to get it's elements 
Description: gets the element at a specific column 
Return: vector, a vector with all the elements at that column  
*/
std::vector<double> Matrix::get_col(int c)
{
    std::vector<double> v; //vector with all elements in that column 
    for (int i = 0; i < get_num_row(); i++)
    {
        v.push_back(this->matrix[i][c]); 
    }

    return v; 
}

/*
Paramater: int, r, the row to change
* vector, v, the elements that will be set at that row 
Description: it is setting elements inside a matrix at a specific row 
Return: void, nothing 
*/  
void Matrix::set_row_elements(int r, std::vector<double> v)
{
    this->matrix[r] = v; 
}

/*
Parameter: int, r, specific row 
* int, c, specific column 
* int, value, value to put at that position 
Description: placing value at a specific element on matrix
Return: void, nothing
*/
void Matrix::set_value(int r, int c, double value)
{
    this->matrix[r][c] = value; 
}

/*
Parameter: int, r, specific row 
* int, c, specific column 
Description: getting value from specific row and column
Return: int, value at r and c 
*/
double Matrix::get_value(int r, int c)
{
    return this->matrix[r][c]; 
}

/*
Paramter: void, nothing 
Description: gets the transpose of this matrix 
Return: The Transpose of the Matrix
*/ 
Matrix Matrix::get_tranpose()
{
    int c; //columns for tranpose 
    int r; //rows for tranpose 

    c = get_num_row();
    r = get_num_col();

    Matrix matrix(r, c); //the matrix in tranpose form 

    for (int i = 0; i < r; i++)
    {
        matrix.set_row_elements(i, get_col(i)); 
    }

    return matrix; 
}

/*
Paramter: Matrix, matrix, the matrix being multiplied second to this matrix 
Description: This Matrix multiplies this matrix to the Matrix in the Paramter
Return: The result from the Multiplication
*/ 
Matrix Matrix::multiple_matrix(Matrix matrix)
{   
    int r; //number of rows for finished matrix 
    int c; //number of columns for finished matrix 

    r = get_num_row(); 
    c = matrix.get_num_col();
    Matrix result(r,c); //the result of the Matrix 

    for (int i = 0; i < r; i++)
    {
        std::vector<double> val1; //values at row 
        
        val1 = get_row(i); 
        for (int j = 0; j < c; j++)
        {
            std::vector<double> val2; //values at columns 
            double value; //value at index (i, j)
            val2 = matrix.get_col(j); 
            value = add_vectors(val1, val2);
            result.set_value(i, j, value); 
        }
    }

    return result; 
}

/*
Paramter: std::vector<int>, val1, the row at matrix 1 
* std::vector<int>, val2, the column at matrix 2 
Description: Based off the row and column, it gets the value
* at that specific point
Return: void, nothing 
*/ 
double add_vectors(std::vector<double> val1, std::vector<double> val2)
{
    if (val1.size() != val2.size())
    {
        return 0; 
    }

    double sum = 0; 
    for (int i = 0; i < val1.size(); i++)
    {   
        sum += val1[i] * val2[i]; 
    }

    return sum; 
}

/*
Paramter: std::vector<int>, output, the b for Ax = b 
Description: it converts A to [A | b] so it can solve 
* for x using row_echelon. It is basically preparing
* the matrix 
Return: Matrix, matrix in terms of [A | b]  
*/ 
Matrix Matrix::row_echelon(std::vector<double> output)
{
    int r; // number of rows for new matrix
    int c; // number of columns for new matrix 

    r = get_num_row(); 
    c = get_num_col() + 1; 
    Matrix matrix(r, c); //matrix with the extra column for row echelon form 
    
    //putting original elements into original place 
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            matrix.set_value(i, j, get_value(i, j)); 
        }
    }

    //putting the outputs in
    for (int i = 0; i < output.size(); i++)
    {
        matrix.set_value(i, c - 1, output[i]); 
    }

    return matrix; 
}

/*
Paramter: void, nothing 
Description: Print out the Matrix 
Return: String, the Matrix 
*/ 
std::string Matrix::to_string()
{
	std::string result = ""; //the result 
	for (int i = 0; i < get_num_row(); i++)
	{
		result += "["; 
		for (int j = 0; j < get_num_col(); j++)
		{
			result += std::to_string(get_value(i, j)); 
			if (get_num_col() - 1 - j)
			{
				result += ", "; 
			}
		}
		result += "]\n";
	}

	return result; 
}

/*
Paramter: void, nothing 
Description: Assuming this matrix is in row echelon form, this gets 
* the answer in reduce form 
Return: the coefficient for each vector. 
*/ 
std::vector<double> Matrix::solve()
{
    std::vector<double> v; 
    return v; 
}

