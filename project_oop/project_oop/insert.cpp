#include "functions.h"
void insert_row(std::string name)
{
	std::fstream File(name,std::ios::in|std::ios::out|std::ios::binary);
	//cheta razmerite na tablicata
	int n, m;
	char ws;//white space
	File.seekg(-9, std::ios::end);
	File.read((char*)&n, sizeof(int));
	File.read((char*)&ws, sizeof(char));
	File.read((char*)&m, sizeof(int));


	File.seekg(-4, std::ios::end);
	int cols;		
	File.read((char*)&cols, sizeof(int));
	//vektor kadeto da zapisvam tipovete na vsqka kolona
	std::vector<int> col_type;
	col_type.reserve(cols);

	File.seekg(-5 * cols - 9);//zapisvam tipovete vav vektora
	for (int i = 0; i < cols; i++)
	{
		int a;
		File.read((char*)&a, sizeof(int));
		File.read((char*)&ws, sizeof(char));
		col_type[i] = a;
	}

	std::cout << "Now enter values into the new row\n";
	int int_ST;		std::string string_st;		double double_st;
	File.seekg(-5 * cols - 9);
	for (int i = 0; i < cols; i++)
	{
		if (col_type[i] == 4)
		{
			std::cout << "You must enter int value: ";
			std::cin >> int_ST;
			File.write((char*)&int_ST, sizeof(int));
			File << ws;
		}
		else if (col_type[i] == 8)
		{
			std::cout << "You must enter double value: ";
			std::cin >> double_st;
			File.write((char*)&double_st, sizeof(double));
			File << ws;
		}
		else if (col_type[i] == 20)
		{
			std::cout << "You must enter string value: ";
			std::cin >> string_st;
			File.write((char*)&string_st, sizeof(string_st));
			File << ws;
		}
		
	}
	File.seekg(-1, std::ios::end);
	ws = '\n';//prezapisvam edin \t vav \n
	File.write((char*)&ws, sizeof(char));	ws = '\t';

	for (int i = 0; i < cols; i++)//zapisvam obratno vav faila tipovete na kolonite
	{
		File.write((char*)&col_type[i],sizeof(int));
		File.write((char*)&ws, sizeof(char));
	}

	File.write((char*)&n, sizeof(int));
	File.write((char*)&ws, sizeof(char));
	File.write((char*)&m, sizeof(int));
	File.close();

}