#include "functions.h"

void import_a_newtable()
{
	int n, m;
	std::string name;
	std::cout << "To import a table, you need to first create it\n!";
	std::cout << "Enter the name of the new table and after that add \".bin\":";
	std::getline(std::cin, name);
	std::cout << "second enter dimensions of the table(rows and cols)";
	std::cout << "rows:"; std::cin >> n;
	std::cout << "cols:";std::cin >> m;
	if (n == 0 || m == 0)
	{
		std::cout << "Invalid table dimentions!!";
	}

	std::vector<std::string>tip_kolona;//trqbva mi da zapisha posle vida na vsqka kolona
	tip_kolona.reserve(m);
	std::cout << "Please enter the type of each column:";
	for (int i = 0; i < m; i++)
	{
		std::cin >> tip_kolona[i];
	}

	std::ofstream File(name, std::ios::binary);
	char ws = '\t';
	int int_st;
	double double_st;
	std::string string_st;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tip_kolona[j] == "int")
			{
				std::cout << "Enter a int value:"; 
				std::cin >> int_st;
				File.write((char*)&int_st, sizeof(int));
				File.write((char*)&ws, sizeof(char));
			}
			if (tip_kolona[j] == "double")
			{
				std::cout << "Enter a double value:";
				std::cin >> double_st;
				File.write((char*)&double_st, sizeof(double));
				File.write((char*)&ws, sizeof(char));
			}
			if (tip_kolona[j] == "string")
			{
				std::cout << "Enter a string value:";
				std::cin >> string_st;
				File.write((char*)&string_st, sizeof(string_st));
				File.write((char*)&ws, sizeof(char));
			}

		}

	}
}
