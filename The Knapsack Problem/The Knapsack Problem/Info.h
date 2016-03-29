#ifndef INFO_H
#define INFO_H
#include <iostream> 
#include <vector>

using namespace std;


class Knapsack
{
private:
	int items, capacity; // amount of items, max capacity of knapsack 
	int user_input;
	
	vector <int> item_val; //vector for individual item value 
	vector <int> item_w; //vector for individual item weight
	int value_matrix[100][100]; //2d arrays 
	int item_picked [100][100]; 
public:
	Knapsack()// constructor 
	{}	
	

	void show_mainMenu(); // controls main menu 
	void setArray_bounds(); // option 1 


	int maximum_value(int, int); // compares what value is the highest 


	int calculate_solution(int , int , vector <int> , vector <int>  ); // passes user's data into function to calculate 
	int fill_pick_array();// fills both arrays with 0's 
	int fill_value_array(); 
	
};

#endif 
