class Housing
{
	private:
		double longitude; 
		double latitude; 
		int housing_median_age; 
		int total_rooms; 
		int total_bedrooms; 
		int population; 
		int households; 
		double median_income; 

	public:  
		Housing();
		Housing(double longitude, double latitude, 
		int housing_median_age, 
		int total_rooms, 
		int total_bedrooms, 
		int population,
		int households, 
		double median_income); 

		double get_longitude(); 

		double get_latitude(); 

		int get_housing_median_age(); 
		
		int get_total_rooms(); 

		int get_total_bedrooms();  
		
		int get_population(); 
		
		int get_households();  
		
		double get_median_income();  

}; 
