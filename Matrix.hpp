#include <vector> 

class Matrix
{
    private: 
        std::vector< std::vector<int> > matrix; 
    
    public: 
        Matrix(std::vector< std::vector<int> >);
        Matrix get_tranpose(); 
        Matrix multiple_matrix(Matrix); 
        Matrix row_echelon(Matrix, std::vector<int>); 
        std::vector<int> solve(); 
};