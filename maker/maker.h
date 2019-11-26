#ifndef MAKER_H
#define MAKER_H
#include<cstring>
using namespace std;
void makefile(char*, bool, bool);		//make <makefile>
void cpp(char*, bool);					//make <name.cpp>    <- if doesn't have -c option
void c(char*, bool);					//make <name.c>      <- if have -c option
void head(char*, bool);					//make <name.h>      <- if have -h option
void makemain(char*, bool);				//make <main.c(cpp)> <- if have -h option

class Str{
	char* str;
	int len;
public:
	Str(const char* s)
	{
		len = strlen(s);
		str = new char[len + 1];

		strcpy(str, s);
	}
	Str& operator<<(const char* s)
	{
		char* tmp = new char[len + strlen(s) + 1];
		
		strcpy(tmp, str);
		strcpy(tmp + len, s);

		len = strlen(tmp);
		delete[] str;
		str = tmp;

		return *this;
	}

	Str& operator<<(Str& s)
	{
		char* tmp = new char[len + s.len + 1];

		strcpy(tmp, str);
		strcpy(tmp + len, s.str);

		len += s.len;

		delete[] str;
		str = tmp;

		return *this;
	}

	void Clear()
	{
		delete[] str;
		str = NULL;
		len = 0;
	}

	Str& operator=(const char* s)
	{
		char* tmp = new char[strlen(s) + 1];
		len = strlen(s);
		strcpy(tmp, s);
		delete[] str;
		str = tmp;

		return *this;
	}

	Str& operator=(Str& s)
	{
		char* tmp = new char[s.len + 1];

		len = s.len;
		strcpy(tmp, s.str);

		delete[] str;
		str = tmp;

		return *this;
	}

	char* GetStr()
	{
		return str;
	}
};
#endif
