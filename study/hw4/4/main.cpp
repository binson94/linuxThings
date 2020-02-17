#include<iostream>
#include<cstring>
using namespace std;

class CString
{
	int len;
	char* str;
public:
	CString(const char* s = "");
	CString(const CString&);
	~CString();
	CString& operator=(const CString&);
	CString& operator=(const char*);
	CString operator+(const CString&);
	CString operator-(char);

	friend ostream& operator<<(ostream&, const CString&);
};

CString::CString(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

CString::CString(const CString& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

CString::~CString()
{
	delete[] str;
}

CString& CString::operator=(const CString& s)
{
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

CString& CString::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

CString CString::operator+(const CString& s)
{
	int tmpL = len + s.len;
	char* tmp = new char[tmpL + 1];

	strcpy(tmp, str);
	strcpy(tmp + len, s.str);

	return CString(tmp);
}

CString CString::operator-(char c)
{
	int tmpL = 0;
	char* tmp;
	for(int i = 0;i <= len;i++)
		if(str[i] != c)
			tmpL++;

	tmp = new char[tmpL + 1];

	tmpL = 0;
	for(int i = 0;i <= len;i++)
		if(str[i] != c)
			tmp[tmpL++] = str[i];

	return CString(tmp);
}

ostream& operator<<(ostream& os, const CString& s)
{
	os << s.str;
	return os;
}

int main(void)
{
	CString s1("hi");
	CString s2;

	s2 = ", hello";

	cout << s1 << s2 << endl;

	CString s3 = s1 + s2;

	cout << s3 << endl;

	s3 = s3 - 'l';

	cout << s3 << endl;
}
