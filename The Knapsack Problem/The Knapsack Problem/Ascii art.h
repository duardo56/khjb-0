#ifndef ASCII_ART_INCLUDE
#define ASCII_ART_INCLUDE

#include <iostream>
#include <string> 
#include <fstream> 


using namespace std; 


class artPrint
{
public:
	artPrint();
	
	string artContent(ifstream&);
	string get_Ascii(string); 
	

private:
	string asciiArt;

};


artPrint::artPrint()
{
	ifstream inputfile; 
	inputfile.open("backpack.txt"); 
	string retrive_data; 
	get_Ascii(retrive_data); 
	
	retrive_data = artContent(inputfile); 

	cout << retrive_data << endl; 

	inputfile.close();
	cout<<"*****************************************\n";
	cout << "\tThe knapsack problem\n";
	cout<<"*****************************************\n";
}

string artPrint::get_Ascii(string p)
{
	asciiArt = p; 
	return p; 
}


string artPrint::artContent(ifstream& File)
{
	string Lines = ""; 

	if (File)
	{
		while (File.good())
		{
			string Temp_line; 
			getline(File, Temp_line);
			Temp_line += "\n";

			Lines += Temp_line; 
		}
		return Lines; 
	}
	else
	{
		cout << "Error, file was not found "; 
	}
	return Lines;
}

#endif 