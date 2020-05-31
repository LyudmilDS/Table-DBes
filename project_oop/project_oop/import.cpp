#include "functions.h"

void import_a_newtable()
{
	int n, m;
	std::cout << "To import a table, you need to first create it\n!";
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

	int int_st;
	double double_st;
	std::string string_st;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tip_kolona[j] == "int")
			{

			}

		}

	}
}
