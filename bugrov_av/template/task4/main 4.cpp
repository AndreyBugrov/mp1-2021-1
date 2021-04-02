#include "All.h"
using namespace std;
//����������� ����� ��������.
//����� ������ ������� ���������� � ��������� ���������.
//������ ������� �������� ��������� ������ : 
//�������; 
//���;
//��������;
//�������;
//���� ��������(����, �����, ���);
//�������, ��������� �� ������� � ���������.
//�������� �������� ������������ �� �������, �����, ��������.
//�������, ���, ��������(���) �������� ������������� ������.
//������ �������� �� ������� �����.
//����� ������ ��������� ����������� ��������� ������.
//����� ������ ������������� ��������� �������� : 
/// 
/// �����:
/// ������� �� ���
/// ������� �� ��������
/// ��� �������� �� ��� �����
/// 
//1) ������� ����� �������,
//2) �������� ��������� �������, 
//3) ����� ������� �� ���,
//4) ����� ������� �� ��������, 
//5) ������ ��� �������� �� �������� �����, 
//6) ������ ������� ����� ���������, 
//7) ������ ������� � ������ ���������,
//8) ������� ������� �� ������ ���������,
//9) ������ ��� ��������� ��������, 
//10) ������� �������, 
//11) ��������� �������� � ����, 
//12) ������� �������� �� �����.
//�������� �� ������ ��������� ���� � �� �� ���	
///������ ��������:
/// ��� ����� ������� ������ ���� ������������ ������?
/// ��� ��� ������� �������� ������ � char'�
//����� �������� ��� ������� �������, ����� ���� � ������, �������� �� ���
class List
{
	contact* man;
	int k;
	void sort();
public:
	List(int _k = 0) :k(_k)
	{
		if (k)
			man = new contact[k];
		else
			man = nullptr;
		//name = surname = patronymic = nullptr;
	}
	~List()
	{
		k = 0;
		delete[] man;
	}
	//������ ����� �������
	void _new(contact extra)
	{
		int i;
		contact* tmp = new contact[k + 1];
		for (i = 0; i < k; i++)
		{
			tmp[i] = man[i];
		}
		tmp[i] = extra;
		k++;
		man = new contact[k];
		for (i = 0; i < k; i++)
		{
			man[i] = tmp[i];
		}
		delete[] tmp;
		sort();
	}
	//�������� ��������� �������
	void change_contact(contact dif)
	{

	}
	//������� ����� ��������� +
	int getk()
	{
		return k;
	}
	//+
	void favour(int point)
	{
		man[point].favorite = true;
	}
	//+
	void dis_favor(int point)
	{
		man[point].favorite = false;
	}
	//������� ��� ��������� ��������???
	contact* getfav()
	{
		int i;
		int n=0;//���������� ��������� ���������
		for (i = 0; i < k; i++)
		{
			if (man[i].favorite)
				n++;
		}

	}
	//������� �������
	void _delete(contact deleted)
	{
		int i, j = 0, num;
		contact* tmp = new contact[k-1];
		for (i = 0; i < k; i++)
			if (man[i] != deleted)
			{
				tmp[j] = man[i];
				j++;
			}
			else
				num = i;
		delete[] man;
		k--;
		man = new contact[k];
		for (i = 0; i < k; i++)
		{
			man[i] = tmp[i];
		}
		delete[] tmp;
		sort();
	}
	void setlist();//������� ������ � ����
	void getlist();//�������� ����� �� �����
	void show();
	bool exitmenu();
	friend void menu();
};
void menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
	List list(200);
	bool repeat = true;
	list.show();
}
bool List::exitmenu()
{
	enum point
	{
		yes, no
	};
	int c;
	bool repeat = true;
	bool badsymb = true;
	point choice = yes;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		system("CLS");
		cout << "�� �������, ��� ������ �����?" << endl;
		if (choice == yes)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((CYAN << 4) | YELLOW));
			cout << "��";
			SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
			cout << " ���";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
			cout << "�� ";
			SetConsoleTextAttribute(hConsole, (WORD)((CYAN << 4) | YELLOW));
			cout << "���";
			SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
		}
		do
		{
			c = _getch();
			switch (c)
			{
			case a: case A:
			case d: case D:
				if (choice == yes)
					choice = no;
				else
					choice = yes;
				badsymb = false;
				break;
			case 13:
				if (choice == yes)
					return false;//���������� ������� ���������� ����������� � �������� false
				else
					return true;//���������� ������� ���������� ����������� � �������� true
			case 27:
				return true;//���������� ������� ���������� ����������� � �������� false
			default:
				badsymb = true;
			}
		} while (badsymb);
	} while (repeat);
}
void List::show()
{
	int i;
	int pointer = 0;
	int c;
	bool repeat = true;
	bool notnorm;
	const char arrow = 17;
	const char like = 3;
	const int out = 27;
	int screen = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	man[2].favorite = true;
	man[4].favorite = true;
	man[103].favorite = true;
	man[181].favorite = true;
	do
	{
		SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
		notnorm = true;
		system("CLS");
		cout << "���������, ��� � ��� �� ���������� ������ ������� ���������" << endl;
		for (i = screen; i < pointer; i++)
			if (man[i].favorite) 
			{
				SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | RED));
				cout << like;
				SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
				cout << i << " ";
				man[i].printc();
			}
			else
			{
				SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
				cout << " ";
				cout << i << " ";
				man[i].printc();
			}
		if (man[i].favorite)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | RED));
			cout << like;
			SetConsoleTextAttribute(hConsole, (WORD)((CYAN << 4) | YELLOW));
			cout << i << " ";
			man[pointer].printc();
		}
		else
		{
			cout << " ";
			SetConsoleTextAttribute(hConsole, (WORD)((CYAN << 4) | YELLOW));	
			cout << i << " ";
			man[pointer].printc();
		}
		for (i = pointer + 1; i < k && i < screen + out; i++)
			if (man[i].favorite)
			{
				SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | RED));
				cout << like;
				SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
				cout << i << " ";
				man[i].printc();
			}
			else
			{
				SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
				cout << " ";
				cout << i << " ";
				man[i].printc();
			}
		SetConsoleTextAttribute(hConsole, (WORD)((DARKGRAY << 4) | YELLOW));
		cout << " ����� ����� ���������: " << getk() << ". ���� ��������� ������ " << out - 1 << ", ������ ���������� ����� ���������� ����� � ������" << endl;
		while (notnorm)
		{
			c = _getch();
			switch (c)
			{
			case w:case W:
				if (pointer == screen)
					if (screen + out < k)
						pointer = screen + out - 1;
					else
						pointer = k - 1;
				else
					pointer--;
				notnorm = false;
				break;
			case s: case S:
				if (pointer < screen + out - 1 && pointer < k - 1)
					pointer++;
				else
					pointer = screen;
				notnorm = false;
				break;
			case _n:
				man[pointer].contact_menu();
				break;
			case esc:
				repeat = exitmenu();
				notnorm = false;
				break;
			case a: case A:
				if (screen >= out)
				{
					pointer -= out;
					screen -= out;
				}
				else
				{
					screen = k / out;
					screen *= k;
					if (pointer + screen < k)
						pointer += screen;
					else
						pointer = k - 1;
				}
				notnorm = false;
				break;
			case D: case d:
				if (screen + out < k)
				{
					screen += out;
					if (pointer + out < k)
						pointer += out;
					else
						pointer = screen;
				}
				else
				{
					pointer -= screen;
					screen = 0;
				}
				notnorm = false;
				break;
			}
		}
	} while (repeat);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	menu();
	system("pause");
}
