#include <iostream>
#include <cstdlib>
#include "maker.h"
using namespace std;

int main(int argc, char** argv)
{
	Str cmd("mkdir ");
	int nameIdx = -1;
	
	bool cfile = false;		//-c option
	bool header = false;	//-h option

	try
	{
		if(argc == 1)
			throw 1;

		for(int i = 1; i < argc;i++)
		{
			if(argv[i][0] == '-')	//옵션인 경우
			{
				switch(argv[i][1])
				{
					case 'c':
						cfile = true;
						break;
					case 'h':
						header = true;
						break;
					default:
						throw 1;
						break;
				}
			}
			else
			{
				if(nameIdx == -1)
					nameIdx = i;
				else
					throw 1;
			}
		}

		if(nameIdx == -1)
			throw 1;
	}
	catch (int err)
	{
		cout << "./maker <file-name>"<< endl;
		cout << "options\n";
		cout << "-c : make c file" << endl << "-h : separate header file and make main source file" << endl;

		return 1;
	}

	//make <directory>
	system((cmd << argv[nameIdx]).GetStr());

	//make <makefile>
	makefile(argv[nameIdx], cfile, header);

	//make <name.c(cpp)>
	if(cfile)
		c(argv[nameIdx], header);
	else
		cpp(argv[nameIdx], header);

	//if have -h option, make <name.h, main.c(cpp)>
	if(header)
	{
		head(argv[nameIdx], cfile);
		makemain(argv[nameIdx], cfile);
	}

	return 0;
}
