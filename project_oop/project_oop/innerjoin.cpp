#include"functions.h"

void innerjoin(std::string name1, std::string name2)
{
	std::ifstream File1(name1, std::ios::binary);
	std::ifstream File2(name2, std::ios::binary);
	std::ofstream File3("innerjoin_rezult.bin", std::ios::binary);
	int cols1, row1, cols2, row2;
	char ws;//white space

	//vzimam razmeri na tablca 1
	File1.seekg(-9, std::ios::end);
	File1.read((char*)&row1, sizeof(int));
	File1.read((char*)&ws, sizeof(char));
	File1.read((char*)&cols1, sizeof(int));

	//razmeri na tablica 2
	File2.seekg(-9, std::ios::end);
	File2.read((char*)&row2, sizeof(int));
	File2.read((char*)&ws, sizeof(char));
	File2.read((char*)&cols2, sizeof(int));

	//namiram minimumite
	int m, n;
	(row1 < row2) ? m = row1 : m = row2;
	(cols1 < cols2) ? n = cols1 : n = cols2;
	

	File1.seekg(-5 * cols1 - 9, std::ios::end);
	int tip1, check1 = File1.tellg(), check2 = 0;
	File2.seekg(-5 * cols2 - 9, std::ios::end);
	int tip2, check21 = File2.tellg(), check22 = 0;

	bool flag = 0;//shte proverq dali sechenieto na tablicite dava koloni s ednakvi tipove
	//ako edna kolona se razlichava to nqma da se sravnqvat

	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			File1.read((char*)&tip1, sizeof(int));
			File1.read((char*)&ws, sizeof(char));

			File2.read((char*)&tip2, sizeof(int));
			File2.read((char*)&ws, sizeof(char));
			if (tip1 == tip2) flag = 1;
		}
	if (flag == 0) std::cout << "Tables cannot be compared\n";
	else {
		int int_st1,int_st2;
		std::string string_st1,string_st2;
		double double_st1,double_st2;
		File1.seekg(-5 * cols1 - 9, std::ios::end); check1 = File1.tellg();
		File2.seekg(-5 * cols2 - 9, std::ios::end); check21 = File2.tellg();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				File1.seekg(check1);
				File1.read((char*)&tip1, sizeof(int));
				File1.read((char*)&ws, sizeof(char));
				File2.seekg(check21);
				File2.read((char*)&tip2, sizeof(int));
				File2.read((char*)&ws, sizeof(char));


				check1 = File1.tellg();
				File1.seekg(check2, std::ios::beg);
				check21 = File2.tellg();
				File2.seekg(check22, std::ios::beg);

				if (tip1 == 4)
				{
					File1.read((char*)&int_st1, sizeof(int));
					File1.read((char*)&ws, sizeof(char));
				}
				else if (tip1 == 8)
				{
					File1.read((char*)&double_st1, sizeof(double));
					File1.read((char*)&ws, sizeof(char));
				}
				else if (tip1 == 20)
				{
					File1.read((char*)&string_st1, sizeof(string_st1));
					File1.read((char*)&ws, sizeof(char));
				}
				check2 = File1.tellg();
				 

				if (tip2 == 4)
				{
					File2.read((char*)&int_st2, sizeof(int));
					File2.read((char*)&ws, sizeof(char));
					if (int_st1 == int_st2)
					{
						File3.write((char*)&int_st2, sizeof(int));
						File3 << '\t';
					}
				}
				else if (tip2 == 8)
				{
					File1.read((char*)&double_st2, sizeof(double));
					File1.read((char*)&ws, sizeof(char));
					if (double_st1 == double_st2)
					{
						File3.write((char*)&double_st2, sizeof(double));
						File3 << '\t';
					}
				}
				else if (tip2 == 20)
				{
					File2.read((char*)&string_st2, sizeof(string_st2));
					File2.read((char*)&ws, sizeof(char));
					if (string_st1 == string_st2)
					{
						File3.write((char*)&string_st2, sizeof(string_st2));
						File3 << '\t';
					}
				}
				check22 = File2.tellg();

			}
			File1.seekg(-5 * m - 9, std::ios::end);
			check1 = File1.tellg();
		}
	}
}