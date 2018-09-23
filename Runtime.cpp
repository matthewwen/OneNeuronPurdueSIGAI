#include <iostream>
#include "Housing.hpp"

int main(){

	Housing h1(-117.66, 35.6,14,1740,391,850,317, 2.5812); 

	std::cout << "Housing 1 long: " << h1.get_longitude() << std::endl; 

	return 0; 
}