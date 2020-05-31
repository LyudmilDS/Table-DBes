

#include "functions.h"
int main()
{
	std::vector<std::string>spisak;
	char ws;
	std::string file_name;
	std::ifstream katalog("catalog.bin", std::ios::binary);
	if (!katalog)
	{
		std::cout << "Couldnt open the file!\n";
		return 1;
	}
	std::cout << "The files in the catalog are:\n";

	while (katalog)
	{
		katalog.read((char*)&file_name, sizeof(file_name));
		katalog.read((char*)&ws, sizeof(char));
		std::cout << file_name << ws;
	}
	katalog.close();
	std::cout << "What do you want to do now?\n";
	std::cout << "press 1 to Import a new table\n";//import(name)
	std::cout << "press 2 to Describe the cols type of a table\n"; //describe(name)
	std::cout << "press 3 to Print a table\n";//(name)
	std::cout << "press 4 to Insert a new row in a table\n";//name
	
	return 0;
}
