
#include "../std_lib_facilities.h"
#include <locale>
#include "windows.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string file_name = "file.txt";
	ifstream ifs{ file_name };
	if (!ifs)
	{
		cerr << "file " << file_name << " is not found" << endl;
		return 3;
	}

	string temp_str;
	double s_num = 0.0;
	bool zapyataya = false;
	vector <double>vec_num;
	while (ifs >> temp_str)
	{
		zapyataya = false;
		char ch;
		for (int i = 0; i < temp_str.size(); i++)
		{
			if (isdigit(temp_str[i]))
			{
				if (i + 1 == temp_str.size())
				{
					stringstream sw{ temp_str };
					sw >> s_num;
					vec_num.push_back(s_num);
					break;
				}
			}
			else if (temp_str[i] == '.' || temp_str[i] == ',')
			{
				if (zapyataya == true)
				{
					break;
				}
				zapyataya = true;
			}
			else
				break;
		}
	}
	ofstream ofs{ "gupsy.txt" };
	if (!ofs)
	{
		cerr << "fileout ERROR" << endl;
		return 3;
	}
	int prov = 3;
	int u_num = 1;
	/*ofs << scientific << setprecision(8);
	cout << scientific << setprecision(8);*/
	sort(vec_num);
	for (int i = 0; i < vec_num.size(); i++)
	{
		while (true)
		{
			if (i + 1 != vec_num.size() && vec_num[i] == vec_num[i + 1])
			{
				u_num++;
				i++;
			}
			else
				break;
		}
		if (u_num > 1)
		{
			cout << vec_num[i] << " (" << u_num << ")" << endl;
			ofs << vec_num[i] << " (" << u_num << ")" << endl;
		}
		else
		{
			cout << vec_num[i] << endl;
			ofs << vec_num[i] << endl;
		}
		u_num = 1;
	}
	cout << endl << "bye" << endl;
	cin.get();
	cin.get();
	return 0;
}