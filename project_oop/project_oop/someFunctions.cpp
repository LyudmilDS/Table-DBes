#include"functions.h"

int number_cols(std::string name)
{
	std::ifstream File(name, std::ios::binary);
	File.seekg(-4, std::ios::end);
	int m;
	File.read((char*)&m, sizeof(int));
	File.close();
	return m;
}


void showtables(std::vector<std::string>spisak)
{//izvejdam elementite na vektora s elementi vsichki failove
	for (int i = 0; i < spisak.size(); i++)
	{
		std::cout << spisak[i];
	}
}
void showtables()
{
	std::vector<std::string>spisak;
	char ws;
	std::string file_name;
	std::ifstream katalog("catalog.bin", std::ios::binary);
	if (!katalog)
	{
		std::cout << "Couldnt open the file!\n";
	}
	std::cout << "The files in the catalog are:\n";

	while (katalog)
	{
		katalog.read((char*)&file_name, sizeof(file_name));
		katalog.read((char*)&ws, sizeof(char));
		std::cout << file_name << ws;
	}
	katalog.close();
}


void addcolumn(std::string name)
{
	std::fstream File(name, std::ios::binary);
	int n, m; char ws;
	//namiram razmerite na tablicata
	File.seekg(-9, std::ios::end);
	File.read((char*)&n, sizeof(int));
	File.read((char*)&ws, sizeof(char));
	File.read((char*)&m, sizeof(int));


	File.seekg(-9 - 5 * m, std::ios::end);//shte obhodq vsichki tipove
	int tip, check1 = File.tellg(), check2 = 0;

	int st_st;
	std::string ST_st;
	double st_ST;
//shte obhodq cqlata tablica i sled vsqka posledna kolena shte 
//prezapisvam \n sas \t i shte dobavqm NULL, posle uvelichavam br_columns
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
			if (j == m - 1)//tuk dobavqm novata kolona i prezapisvam \n sas \t
			{
				char WS = '\t';
				int zero = NULL;
				File.seekg(-1, std::ios::cur);
				File.write((char*)&WS, sizeof(char));
				File.write((char*)&zero, sizeof(int));
			}
		}
		File.seekg(-5 * m - 9, std::ios::end);
		check1 = File.tellg();
	}
	m += 1;//uvelichavam br_columns
	File.seekg(-4, std::ios::end);
	File.write((char*)&m, sizeof(int));
}
