#include "functions.h"

void describe_table(std::string name)
{//izvejdam tipa na vsqka kolona
	std::ifstream File(name, std::ios::binary);
	int m=number_cols(name);
	File.seekg(-9 - 5 * m,std::ios::end);//iiteratorat v nachaloto na posledniq red
	int A;
	char ws;
	for (int i = 0; i < m; i++)
	{
		File.read((char*)&A, sizeof(int));
		File.read((char*)&ws, sizeof(char));
		if (A == 4)
			std::cout << "int" << ws;
		else if(A==8)
			std::cout << "double" << ws;
		else if(A==20)
			std::cout << "string" << ws;
	}
	File.close();
}



void print_table(std::string name)
{
	std::ifstream File(name, std::ios::binary);

	int n, m;
	char ws;
	File.seekg(-9, std::ios::end);//shte cheta razmerite na tablicata
	File.read((char*)&n, sizeof(int));
	File.read((char*)&ws, sizeof(char));
	File.read((char*)&m, sizeof(int));

	//shte obhodq cqlata tablica, bez znachenie ot tipa na kolonite
		File.seekg(-5 * m - 9, std::ios::end);
int tip,check1 = File.tellg(), check2 = 0;

	int st_st; 
	std::string ST_st; 
	double st_ST;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			File.seekg(check1);
			File.read((char*)&tip, sizeof(int));
			File.read((char*)&ws, sizeof(char));


			check1 = File.tellg();
			File.seekg(check2, std::ios::beg);

			if (tip == 4)
			{
				File.read((char*)&st_st, sizeof(int));
				File.read((char*)&ws, sizeof(char));
				std::cout << st_st << ws;
			}
			else if (tip == 8)
			{
				File.read((char*)&st_ST, sizeof(double));
				File.read((char*)&ws, sizeof(char));
				std::cout << st_ST << ws;
			}
			else if (tip == 20)
			{
				File.read((char*)&ST_st, sizeof(ST_st));
				File.read((char*)&ws, sizeof(char));
				std::cout << ST_st << ws;
			}
			check2 = File.tellg();
		}
		File.seekg(-5 * m - 9, std::ios::end);
		check1 = File.tellg();
	}
	File.close();
}
