class Housing
{
	private:
		double longitude; 
		double latitude; 
		double housing_median_age; 
		double total_rooms; 
		double total_bedrooms; 
		double population; 
		double households; 
		double median_income; 
		double median_house_value; 

	public:  
		Housing();
		Housing(double longitude, double latitude, 
		double housing_median_age, 
		double total_rooms, 
		double total_bedrooms, 
		double population,
		double households, 
		double median_income, 
		double median_house_value); 

		double get_longitude(); 

		double get_latitude(); 

		double get_housing_median_age(); 
		
		double get_total_rooms(); 

		double get_total_bedrooms();  
		
		double get_population(); 
		
		double get_households();  
		
		double get_median_income();  

		double get_value(int index); 

		int get_switch_index_val(int i, int index); 

}; 