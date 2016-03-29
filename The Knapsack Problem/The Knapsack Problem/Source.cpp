#include <iostream>
#include <Windows.h> 
#include "Info.h"
#include "Ascii art.h"

using namespace std; 



int main()
{
HANDLE hConsole;	// TO PRINT OUT COLOR
	   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	   SetConsoleTextAttribute(hConsole, 10); // makes lime green color 
artPrint kanpsack;  // prints out the greeting  
Knapsack object; 
object.show_mainMenu(); 







system("pause"); 
return 0; 
}
