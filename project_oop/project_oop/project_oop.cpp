#include<iostream>
#include "functions.h"
int main()
{	
	std::string file_name, str;	
	int a=1;
	while (a != 0)
	{
		std::cout << "What do you want to do now?\n";
		std::cout << "press 1 to Import a new table\n";
		std::cout << "press 2 to Describe the cols type of a table\n";
		std::cout << "press 3 to Print a table\n";
		std::cout << "press 4 to Insert a new row in a table\n";
		std::cout << "press 5 to do Innerjoin on two tables\n";
		std::cout << "press 6 to Add a new column in a table\n";
		std::cout << "press 7 to see all tables\n";
		std::cout << "or press 0 to end the program\n";
		std::cin >> a;
		std::cin.ignore();
		switch (a)
		{
		case 1: import_a_newtable(); break;
		case 2:std::cout << "Enter for which table you'd like to call the function: "; 
			std::getline(std::cin, file_name); 
			describe_table(file_name); break;

		case 3:std::cout << "Enter for which table you'd like to call the function: ";
			std::getline(std::cin, file_name); 
			print_table(file_name); break;

		case 4:std::cout << "Enter for which table you'd like to call the function: ";
			std::getline(std::cin, file_name); 
			insert_row(file_name); break;

		case 5:std::cout << "Enter for which table you'd like to call the function.\n Enter two names: ";
			std::getline(std::cin, file_name);
			std::getline(std::cin, str); 
			innerjoin(file_name,str); break;
		case 6:std::cout << "Enter for which table you'd like to call the function: ";
			std::getline(std::cin, file_name);
			addcolumn(file_name); break;

		case 7:std::cout << "Enter for which table you'd like to call the function: "; 
			std::getline(std::cin, file_name); 
			insert_row(file_name); break;			
		}
	}
	return 0;
}
