#include <vector> 

class Matrix
{
    private: 
        std::vector< std::vector<int> > matrix; 
    
    public: 
        Matrix(std::vector< std::vector<int> >);
        Matrix(int, int); 
        Matrix(); 
        int get_num_row(); 
        int get_num_col(); 
        std::vector<int> get_row(int r); 
        std::vector<int> get_col(int c);
        void set_row_elements(int, std::vector<int>); 
        Matrix get_tranpose(); 
        Matrix multiple_matrix(Matrix); 
        Matrix row_echelon(Matrix, std::vector<int>); 
        std::vector<int> solve(); 
};