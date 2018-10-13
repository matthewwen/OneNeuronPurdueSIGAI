#include "Matrix.hpp"

/*
Paramter: vector<vector<int>>, matrix, each element represent a row and 
* then each element have elements that represent a column element 
*Description: Constructor Method of Matrix
*Return: void, nothing 
*/
Matrix::Matrix(std::vector< std::vector<int> > matrix)
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
    std::vector<int> rows(c); //rows with just 0s filled with c elements 
    std::vector<std::vector<int>> matrix; //a matrix with r rows and c columns with all it's elements as 0 
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
Matrix::Matrix(){}

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
std::vector<int> Matrix::get_row(int r)
{
    return this->matrix[r]; 
}

/*
Paramter: int, c, the column where you want to get it's elements 
Description: gets the element at a specific column 
Return: vector, a vector with all the elements at that column  
*/
std::vector<int> Matrix::get_col(int c)
{
    std::vector<int> v; //vector with all elements in that column 
    for (int i = 0; i < get_num_col(); i++)
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
void Matrix::set_row_elements(int r, std::vector<int> v)
{
    this->matrix[r] = v; 
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

// Matrix multiple_matrix(Matrix); 
// Matrix row_echelon(Matrix, std::vector<int>); 
// std::vector<int> solve();