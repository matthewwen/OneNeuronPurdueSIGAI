#include <vector> 
#include <string> 

class Model
{
    private: 
        std::vector<double> coefficient; 
        double b_value; 
    
    public: 
        Model(std::vector<double>); 
        Model(); 
        double get_p(std::vector<double>); 
        double get_c(int); 
        int get_c_size(); 
        void set_coef(std::vector<double>); 
        std::string to_string(); 

}; 

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
        double get_value(int, int); 
        std::string to_string(); 
        std::vector<double> get_new_row_el(double, std::vector<double>, std::vector<double>); 
        std::vector<double> get_new_row_eu(double, std::vector<double>, std::vector<double>); 

};