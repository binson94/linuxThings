#include"maker.h"
#include<fstream>
using namespace std;

//make <makefile>
void makefile(char* name, bool cfile, bool header)
{
	Str dir(name);
	dir << "/makefile";

	//comfiler setting
	Str gpp("g++ ");
	if(cfile)
		gpp = "gcc ";

	//extention setting
	Str cpp(".cpp");
	if(cfile)
		cpp = ".c";

	Str s(name); 
	s << " : ";
	//name : 

	if(header)
	{
		s << "main.o " << name << ".o\n";
		s << "\t" << gpp <<  "main.o " << name << ".o -o " << name;
		s << "\nmain.o " << name << ".o : " << name << ".h";
		//name : main.o name.o
		//	g++ main.o name.o -o name
		//main.o name.o : name.h
	}
	else
	{
		s << name << cpp << "\n\t";
		s << gpp << name << cpp << " -o " << name;
		//name : name.cpp
		//	g++ name.cpp -o name
	}

	s << "\n\nclean :\n\trm -f *.o";
	//clean :
	//	rm -f *.o

	ofstream file(dir.GetStr());

	file << s.GetStr();

	file.close();
}

//make <name.cpp>, doesn't have -c option
void cpp(char* name, bool header)
{
	Str dir(name);
	dir << "/" << name << ".cpp";
	//directory setting : name/name.cpp
	
	ofstream file(dir.GetStr());

	file << "#include<iostream>\n";

	//if have -h option, "name.h" file include
	if(header)
		file << "#include\"" << name << ".h\"\n";

	file << "using namespace std;\n\n";
	
	//if have -h option, main function is located in main.cpp
	//if doesn't have -h option, main funcion is located here
	if(!header)
	{
		file << "int main(void)\n";
		file << "{\n\n}";
	}
	
	file.close();
}

//make <name.c>, have -c option
void c(char* name, bool header)
{
	Str dir(name);
	dir << "/" << name << ".c";
	//directory setting : name/name.c
	
	ofstream file(dir.GetStr());

	file << "#include<stdio.h>\n";

	//if have -h option, "name.h" file include, main function is located in main.c
	if(header)
		file << "#include \"" << name << ".h\"\n";
	//if does'n have -h option, main function is located here
	else
	{
		file << "\nint main(void)\n";
		file << "{\n\n}";
	}

	file.close();
}

//all alphabets in from will be LARGE and saved in to
void ToLarge(char* to, char* from)
{
	for(int i = 0; from[i] != '\0'; i++)
	{
		if(('a' <= from[i]) && (from[i] <= 'z'))
			to[i] = from[i] - 32;
		else
			to[i] = from[i];
	}
}

//make <name.h>, have -h option
void head(char* name, bool cfile)
{
	Str dir(name);
	char tmp[100];
	ToLarge(tmp, name);

	dir << "/" << name << ".h";
	//directory setting : name/name.h
	
	ofstream file(dir.GetStr());

	file << "#ifndef " << tmp << "_H\n";
	file << "#define " << tmp << "_H\n\n";
	file << "#endif";

	file.close();
}

//make <main.cpp>, have -h option
void makemain(char* name, bool cfile)
{
	Str dir(name);
	dir << "/main.c";
	if(!cfile)
		dir << "pp";
	//directory setting : name/main.c(cpp)

	ofstream file(dir.GetStr());

	file << "#include \"" << name << ".h\"\n";
	if(cfile)
	{
		file << "#include <stdio.h>\n";
	}
	else
		file << "#include <iostream>\nusing namespace std;\n";

	file << "\n";

	file << "int main(void)\n";
	file << "{\n\n}";

	file.close();
}
