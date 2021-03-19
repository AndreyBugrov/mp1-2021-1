#include <iostream>
#include <cmath>
using namespace std;
//����������� ����� ������ ����������.
//����� ������ ��������� ��������� ������������ �������� ��������� �� ������������ ������� ����� ����������, �������� � ���� ������� ����� C++.
//�������� ���������� ��������� � �������� �������� ��������������, ��������� ������ �����, ������ � ������� ���������������.
//����� ������ ��������� ����������� ��������� ������(������������, ���������� � ��.).
//����� ������ ������������� ��������� �������� : 
//1) ������ ������� �������, +
//2) ������ ������� ��������������, +
//3) ������ ������� ��������������, + 
//4) ������ ����� �������� ������ ���������������, +
//5) ������� ����� ����������, +
//6) ��������� �������� ��������� ��������� �������,
//7) ������� ��������� ���������� �� �����. +

typedef double(*math)(double);
enum way
{
	_left = 1,
	_mid,
	_right
};
double line(double x)
{
	return x;
}
class integral
{
	double lim[2];// ����� � ������ ������� ��������������
	math foo;// ��������� �� �������
	int n;// ����� ���������
	double res;// ��������� ����������
	way method;// ����� ��������������
	/* double midfinder(double a1, double b1)
	{
		return (b1 + (b1 - a1) / 2);
	}*/
	void calc();// ���������� ���������
public:
	integral(double l = 0, double r = 0, math f = abs) :lim{ l, r }, foo(f) // �����������
	{
		n = 1;
		res = 0;
		method = _mid;
	}
	void GetFoo(math f)// ������ ������� �������
	{
		foo = f;
	}
	void GetLim(double l, double r)// ������ ������� ��������������
	{
		lim[0] = l;
		lim[1] = r;
	}
	const double* OutLim()// ����� �������� ��������������
	{
		return lim;
	}
	void GetsegNum(int number)// ������ ����� �������� ������ ���������������
	{
		n = number;
	}
	double out() // ������� ��������� ���������� �� �����
	{
		calc();
		return res;
	}
	void GetWay(way choice)// ������� ����� ����������
	{
		method = choice;
	}
};
void integral::calc()
{
	res *= 0;
	double addend, segment = (lim[1] - lim[0]) / n;
	int  i = 0, _n = n;
	double x_i = lim[0];
	switch (method)
	{
	case _left:
		break;
	case _mid:
		for (; i < _n; i++)
		{
			addend = foo(x_i + (i + 0.5) * segment);
			res += addend;
		}
		res *= segment;
		return;
	case _right:
		x_i += segment;
		break;
	default:
		cout << "���-�� ����� �� ���" << endl;
		return;
	}
	for (; i < _n; i++)
	{
		addend = foo(x_i + i * segment);
		res += addend;
	}
	res *= segment;
}
void usefunk(integral& s)
{
	enum fname { _exp = 1, _sin, _cos, _sinh, _cosh, _sqrt, _log , _line};
	cout << "�������� ����� �������:" << endl;
	cout << "1. ����������" << endl;
	cout << "2. �����" << endl;
	cout << "3. �������" << endl;
	cout << "4. ��������������� �����" << endl;
	cout << "5. ��������������� �������" << endl;
	cout << "6. ���������� ������" << endl;
	cout << "7. ����������� ��������" << endl;
	cout << "8. ������ y=x" << endl;
	int ans;
	cin >> ans;
	math funk;
	switch (ans)
	{
	case _exp:
		funk = exp;
		break;
	case _sin:
		funk = sin;
		break;
	case _cos:
		funk = cos;
		break;
	case _sinh:
		funk = sinh;
		break;
	case _cosh:
		funk = cosh;
		break;
	case _sqrt:
		funk = sqrt;
		break;
	case _log:
		funk = log;
		break;
	case _line:
		funk = line;
		break;
	default:
		funk = abs;
		break;
	}
	s.GetFoo(funk);
}
void useway(integral& s)
{
	int ans;
	cout << "�������� ����� ���������� ���������" << endl;
	cout << "1. ����� ����� ���������������" << endl;
	cout << "2. ����� ������� ���������������"<<endl;
	cout << "3. ����� ������ ���������������"<<endl;
	cin >> ans;
	way getmeth;
	switch (ans)
	{
	case _left:
		getmeth = _left;
		break;
	case _mid:
		getmeth = _mid;
		break;
	case _right:
		getmeth = _right;
		break;
	default:
		break;
	}
	s.GetWay(getmeth);
}
void menu()
{
	integral s;
	const double* limits = nullptr;
	integral& sum = s;
	int ans;
	do {
		usefunk(sum);
		cout << "������� ������� ��������������" << endl;
		double leflim, riglim;
		bool flag = true;
		do
		{
			cin >> leflim >> riglim;
			if (leflim < riglim)
				flag = false;
			else
				cout << "�������� ������" << endl;
		} while (flag);
		s.GetLim(leflim, riglim);
		limits = s.OutLim();
		cout << "����� ������ ��������������: " << limits[0] << endl;
		cout << "������ ������ ��������������: " << limits[1] << endl;
		cout << "������� ����� �������� ������ ���������������" << endl;
		int segnum;
		cin >> segnum;
		s.GetsegNum(segnum);
		useway(sum);
		double res;
		res = s.out();
		cout << "��������� ����������: " << res << endl;
		char a;
		cout << "���� �� ������� ����������, ������� 0, ����� ������� ����� ������ ������" << endl;
		cin >> a;
		ans = static_cast<int>(a) - 48;
	} while (!ans);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "��������� �� ���������� ��������� �� ������������ ������� ������� ���������������"<<endl;
	menu();
	system("pause");
}
