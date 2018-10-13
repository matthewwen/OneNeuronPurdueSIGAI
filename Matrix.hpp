#include <vector> 

class Matrix
{
    private: 
        std::vector< std::vector<double> > matrix; 
    
    public: 
        Matrix(std::vector< std::vector<double> >);
        Matrix(int, int); 
        Matrix(); 
        int get_num_row(); 
        int get_num_col(); 
        std::vector<double> get_row(int r); 
        std::vector<double> get_col(int c);
        void set_row_elements(int, std::vector<double>); 
        Matrix get_tranpose(); 
        Matrix multiple_matrix(Matrix); 
        Matrix row_echelon(std::vector<double>); 
        std::vector<double> solve(); 
        void set_value(int, int, double); 
        int get_value(int, int); 
        std::string to_string(); 
};