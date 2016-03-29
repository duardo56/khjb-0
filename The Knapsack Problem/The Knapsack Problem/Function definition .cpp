#include <iostream>
#include <vector> 
#include "Info.h"

using namespace std; 


int Knapsack::fill_pick_array() // fill the other array 
{
	for (int i = 0 ; i <= 100 ; i ++)
	{
		for (int j = 0 ; j <=100 ; j++) 
		{
			item_picked [i][j] = 0; 
		}
	}
	return item_picked[100][100]; 

}

int Knapsack::fill_value_array() // fill one array 
{
	for (int i = 0 ; i <= 100 ; i ++)
	{
		for (int j = 0 ; j <=100 ; j++) 
			value_matrix [i][j] = 0; 
	
	}
	return value_matrix[100][100]; 

}


int Knapsack::calculate_solution(int nItems, int size ,vector <int> weight, vector <int> item_val)
{
	fill_pick_array(); //initializes arrays to 0 
	fill_value_array(); 

	for (int i = 1; i <= nItems; i++) // rows
	{
		for (int j = 0; j <= size; j++)// coloumns 

		{
			if (weight[ i - 1] <= j) 
			{	value_matrix[i][j] = maximum_value(value_matrix[i-1][j], item_val[i-1] + value_matrix[i-1] [j - weight[i-1]]);
		
			if (item_val[i-1]+value_matrix[i-1][j-weight[i-1]]>value_matrix[i-1][j])
                    item_picked[i][j]= 1;
			else
				item_picked [i][j] = -1;
			}
			else
			{
				item_picked[i][j] = -1; 
				value_matrix[i][j] = value_matrix[i -1][j]; 
			}
		}
		
	}
	
	return value_matrix[nItems][size]; // optimal value 

}



void Knapsack::show_mainMenu( )
{
	do
	{
		cout<<"Main menu." <<endl; 
		cout<<"1. Sovle the problem\n";
		cout<<"0. Quit\n";
		cout <<"Please select an option from above:";
		cin >> user_input; 
		if (user_input < 0 || user_input > 1) 
		{
			cout<< "Please enter a valid number:"; 
			cin >> user_input;
			while (user_input <= -1 || user_input > 1)
			{
				cout<< "Please enter a valid number:";
				cin >> user_input; 
			}
		}


		if (user_input == 1)
		{
			setArray_bounds(); 
			cout << "Would you like to try agian? (0 for no, 1 for yes)"; 
			cin >> user_input;
					while (user_input <= -1 || user_input > 1)
			{
				cout<< "Please enter a valid number:";
				cin >> user_input; 
			}
					if (user_input == 1)
					{
						system("cls"); 
					
						
						// continue 
					}
					else if (user_input == 0)
					{
						exit(0); 
					}

		}
		else if (user_input == 0 ) 
		{
			exit(0);
		}


	} while (user_input >= 1 && user_input <= 1);
}



void Knapsack::setArray_bounds()
{
	int temp_v;
	int temp_w;


	cout <<"Enter the amount of items: ";
	cin >>items; // this will determine the number of items availabe in the knapsack 
	
	if(items <= 0)// will check if number entered is valid by user 
	{
		cout << "\nItems must be greater than 0.\n"; 
		while (items <=0)// checks to see if valid input 
		{
			cout << "\nPlease re-enter the amount of items:";
			cin >> items; 
		}
		
	}
	

	// sets item propeties 

	for (int index = 0; index < items ; index++)
	{
		// for the value of the item 
		cout << "Enter the value of item " << index +1 << ": " ; 
		cin >> temp_v; 
		if (temp_v <= 0)
		{
			cout <<"\nValue must be greater than 0.\n";
			while (temp_v <=0)
			{
				cout << "\nPlease re-enter the value of item " << index << ":";
				cin >> temp_v;
			}
		}
		
		item_val.push_back(temp_v);  // add value into the vector 
	

		// for the weight of the item 
		cout << "Enter the weight of item " << index + 1 << ": " ;  
		cin >> temp_w; 
		if (temp_w <= 0)
		{
			cout <<"\nWeight must be greater than 0.\n";
			while (temp_w <=0)
			{
				cout << "\nPlease re-enter the value of item " << index << ":";
				cin >> temp_w;
			}
		}
			item_w.push_back(temp_w);
	 
	}


	 // will enter the capacity of the knapsack 
	cout <<"Enter the maximum capacity of the knapsack: "; 
	cin >> capacity; 
	
	if(capacity <= 0)// will check if number entered is valid by user 
	{
		cout << "\nCapacity must be greater than 0.\n"; 
		while (capacity <=0)
		{
			cout << "\nPlease re-enter the capacity:";
			cin >> capacity; 
		}
		
	}
	


	 //passses the paratems in the function 

	 cout <<"The optimal solution : " << calculate_solution(items, capacity, item_w, item_val); 
	
	 cout << "\n";  

	 
}


int Knapsack::maximum_value(int value_1,int value_2) 
{
	// this will determine what value will go into the array
	return (value_1 > value_2) ? value_1 : value_2; 
}
