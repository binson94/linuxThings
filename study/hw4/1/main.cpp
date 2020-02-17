#include<iostream>
using namespace std;

class myArray
{
	int len;
	int arr[10];
public:
	myArray() : len(0) {}

	void operator<<(int el)
	{
		if(len == 10)
		{
			cout << "가득 참" << endl;
			return;
		}

		arr[len++] = el;
		return;
	}

	int Remove()
	{
		int ret = arr[0];
		for(int i = 1; i < len; i++)
			arr[i - 1] = arr[i];

		len--;
		return ret;
	}

	bool IsEmpty()
	{
		return len == 0;
	}

	bool operator[](int val)
	{
		for(int i = 0; i < len;i++)
			if(arr[i] == val)
				return true;

		return false;
	}

	friend ostream& operator<<(ostream&, const myArray&);
};

ostream& operator<<(ostream& os, const myArray& a)
{
	for(int i = 0; i < a.len;i++)
		os << a.arr[i] <<'\t';

	return os;
}

int main(void)
{
	myArray arr;
	int menu, val;

	while (true)
	{
		cout << "메뉴 선택(1 : 입력, 2 : 출력, 3 : 제일 앞 제거, 4 : 검색, 5 : 종료) : ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cout << "값 입력 : ";
				cin >> val;
				arr << val;
				break;
			case 2:
				cout << arr << endl;
				break;
			case 3:
				if(arr.IsEmpty())
					cout << "비어있음" << endl;
				else
					cout << arr.Remove() << " 제거됨" << endl;
				break;
			case 4:
				cout << "값 입력 : ";
				cin >> val;

				if(arr[val])
					cout << val << " 찾음" << endl;
				else
					cout << val << " 존재하지 않음" << endl;
				break;
			case 5:
				return 0;
			default:
				cout << "잘못된 입력" << endl;
				break;
		}
	}
}
