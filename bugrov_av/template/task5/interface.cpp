#include "all.h"
//---------------------------------------------------
void setstr(string& s)
{
	s.clear();
	cout << " ���������� �������� �� ����� 32\n";
	char get;
	for (int i = 0; i < 32; i++)
	{
		get = getchar();
		if (get == '\0' || get == '\n' || get == '\r' || get == ' ')
			break;
		s.push_back(get);
	}
}
int getdate()
{
	int n;
	int res;
	do
	{
		res = 0;
	first_digit:	do
	{
		n = _getch() - '0';
	} while (n < 0 || n>9);
	cout << n;
	res += n * 10;
	do
	{
		n = _getch() - '0';
		if (n == '\b' - '0')
		{
			res = 0;
			cout << "\b \b";
			goto first_digit;
		}
	} while ((n < 0 || n>9) && n != 13 - '0');
	if (n != 13 - '0')
	{
		cout << n << "\n";
		res += n;
	}
	else
	{
		res /= 10;
		cout << "\n";
	}
	if (res > 30)
		cout << "�������� ������\n";
	} while (res > 30);
	return res;
}
void updown(int& pointer, const int lim, bool& notEnter)
{
	bool repeat = true;
	int input;
	enum choice
	{
		W_en = 87,
		W = 214,
		w_en = 119,
		w = 246,
		A_en = 65,
		A = 212,
		a_en = 97,
		a = 244,
		S_en = 83,
		S = 219,
		s_en = 115,
		s = 251,
		D_en = 68,
		D = 194,
		d_en = 100,
		d = 226,
		_n = 13,
		esc = 27
	};
	while (repeat)
	{
		input = _getch();
		switch (input)
		{
		case w: case W: case w_en: case W_en:
			if (pointer > 0)
				pointer--;
			else
				pointer = lim - 1;
			notEnter = true;
			repeat = false;
			break;
		case S: case s: case S_en: case s_en:
			if (pointer < lim - 1)
				pointer++;
			else
				pointer = 0;
			notEnter = true;
			repeat = false;
			break;
		case _n:
			notEnter = false;
			repeat = false;
			break;
		}
	}
}
int leftright(const string* var, int maxvar, string message)
{
	bool repeat = true;
	int input;
	int pointer = 0;
	int i;
	enum choice
	{
		W_en = 87,
		W = 214,
		w_en = 119,
		w = 246,
		A_en = 65,
		A = 212,
		a_en = 97,
		a = 244,
		S_en = 83,
		S = 219,
		s_en = 115,
		s = 251,
		D_en = 68,
		D = 194,
		d_en = 100,
		d = 226,
		_n = 13,
		esc = 27
	};
	enum color
	{
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		MAGENTA = 5,
		BROWN = 6,
		LIGHTGRAY = 7,
		DARKGRAY = 8,
		LIGHTBLUE = 9,
		LIGHTGREEN = 10,
		LIGHTCYAN = 11,
		LIGHTRED = 12,
		LIGHTMAGENTA = 13,
		YELLOW = 14,
		WHITE = 15
	};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color B2");//LIGHTCYAN GREEN	
	do
	{
		system("cls");
		cout << message;
		repeat = true;
		for (i = 0; i < pointer; i++)
			cout << var[i] << "\t";
		if (pointer < maxvar)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((YELLOW << 4) | GREEN));
			cout << var[pointer] << "\t";
			i++;
			SetConsoleTextAttribute(hConsole, (WORD)((LIGHTCYAN << 4) | GREEN));
			for (i; i < maxvar; i++)
				cout << var[i] << "\t";
		}
		while (repeat)
		{
			input = _getch();
			switch (input)
			{
			case A: case a: case A_en: case a_en:
				if (pointer > 0)
					pointer--;
				else
					pointer = maxvar - 1;
				repeat = false;
				break;
			case D: case d: case d_en: case D_en:
				if (pointer < maxvar - 1)
					pointer++;
				else
					pointer = 0;
				repeat = false;
				break;
			case _n:
				repeat = false;
				break;
			}
		}
	} while (input != _n);
	system("cls");
	return pointer;
}
void setwtype(const int pointer, userdata& data)
{
	switch (pointer)
	{
	case 0:
		data.Wtype = wagonType::down_c;
		break;
	case 1:
		data.Wtype = wagonType::up_c;
		break;
	case 2:
		data.Wtype = wagonType::down_r;
		break;
	case 3:
		data.Wtype = wagonType::up_r;
		break;
	case 4:
		data.Wtype = wagonType::sleep;
		break;
	}
}
bool cashbox::agree(const userdata& data)
{
	system("cls");
	system("color B2");
	cout << "��������������, ��� ���� ������ ������� ���������: (����� ������ �� �����������)\n";
	//cout<<data; - ������� ������ � ������������
	cout << "\n ���� �����-���� ������ ��������� �������, ������� esc. ���� �� �����, ������� Enter\n";
	int ans;
	do
	{
		ans = _getch();
		switch (ans)
		{
		case 13:
			return true;
		case 27:
			return false;
		}
	} while (1);
}
void cashbox::do_repeat(bool& repeat)
{
	system("color B2");
	cout << "������ �� �� ���������� ��� ������? Enter - ��, Esc - ���\n";
	int ans;
	bool badsymb;
	do
	{
		ans = _getch();
		switch (ans)
		{
		case 13:
			repeat = true;
			badsymb = false;
			break;
		case 27:
			repeat = false;
			badsymb = false;
			break;
		default:
			badsymb = true;
		}
	} while (badsymb);
}
//---------------------------------------------------
userdata cashbox::SetData()
{
	enum color
	{
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		MAGENTA = 5,
		BROWN = 6,
		LIGHTGRAY = 7,
		DARKGRAY = 8,
		LIGHTBLUE = 9,
		LIGHTGREEN = 10,
		LIGHTCYAN = 11,
		LIGHTRED = 12,
		LIGHTMAGENTA = 13,
		YELLOW = 14,
		WHITE = 15
	};
	//
	//���� � ���: 1 - ���������; 3 - ������; 5,7,9 - ��������
	//���� � ��: 2 - ���������; 4 - ������; 6,8,10 - ��������
	//
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	userdata data;
	system("color B2");//LIGHTCYAN GREEN
	do {
		cout << "������� ���� ����������� ������. ������ ���� - ������� (26.04.21), ��������� ���� - 30-�\n";
		data.date = getdate();
		string message = "�������� �����������\n\n";
		{
			string var[2] = { "������ - ������ ��������", "������ �������� - ������" };
			data.tnumber = leftright(var, 2, message);
		}
		cout << "������� ������� ��� �������� � ������������.";
		setstr(data.surname);
		cout << "������� ��� ��� �������� � ������������.";
		setstr(data.name);
		cout << "������� ��������. ���� ��� ���, ������� ������, ����� Enter.";
		setstr(data.patronymic);
		system("cls");
		const string trains[3] = { "\"��������\"","��������� �����","������ �����" };
		int pointer = 0;
		int input;
		int i;
		bool notEnter;
		do
		{
			i = 0;
			system("cls");
			cout << "�������� ��� ������:\n\n";
			for (i; i < pointer; i++)
				cout << trains[i] << endl;
			SetConsoleTextAttribute(hConsole, (WORD)((YELLOW << 4) | GREEN));
			cout << trains[i] << endl;
			i++;
			SetConsoleTextAttribute(hConsole, (WORD)((LIGHTCYAN << 4) | GREEN));
			for (i; i < 3; i++)
				cout << trains[i] << endl;
			updown(pointer, 3, notEnter);
		} while (notEnter);
		switch (pointer)
		{
		case 0:
			data.Ttype = trainType::swallow;
			break;
		case 1:
			data.Ttype = trainType::firm;
			break;
		case 2:
			data.Ttype = trainType::speed;
		}
		system("cls");
		string wagtype[5] = { "���� (������ �����)", "���� (������� �����)", "�������� (������ �����)", "�������� (������� �����)", "��" };
		int firmmax = 5;
		int speedmax = firmmax - 1;
		switch (data.Ttype)
		{
		case trainType::swallow:
			message = "�������� ����� ������:\n";
			if (data.tnumber)
			{
				string var[3] = { "�6 (4:30)", "�8 (11:00)", "�10 (17:30)" };
				data.tnumber = leftright(var, 3, message);
				switch (data.tnumber)
				{
				case 0:
					data.tnumber = 6;
					break;
				case 1:
					data.tnumber = 8;
					break;
				case 2:
					data.tnumber = 10;
					break;
				}
			}
			else
			{
				string var[3] = { "�5 (4:30)", "�7 (11:00)", "�9 (17:30)" };
				data.tnumber = leftright(var, 3, message);
				switch (data.tnumber)
				{
				case 0:
					data.tnumber = 5;
					break;
				case 1:
					data.tnumber = 7;
					break;
				case 2:
					data.tnumber = 9;
					break;
				}
			}
			break;
		case trainType::firm:
			pointer = 0;
			input = 0;
			do
			{
				system("cls");
				cout << "�������� ��� �����:\n\n";
				bool repeat = true;
				for (i = 0; i < pointer; i++)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((LIGHTCYAN << 4) | GREEN));
					cout << wagtype[i] << "\n";
				}
				if (pointer < firmmax)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((YELLOW << 4) | GREEN));
					cout << wagtype[pointer] << "\n";
					SetConsoleTextAttribute(hConsole, (WORD)((LIGHTCYAN << 4) | GREEN));
					i++;
				}
				for (i; i < firmmax; i++)
					cout << wagtype[i] << "\n";
				updown(pointer, firmmax, notEnter);
			} while (notEnter);
			if (data.tnumber)
				data.tnumber = 1;
			else
				data.tnumber = 2;
			setwtype(pointer, data);
			break;
		case trainType::speed:
			pointer = 0;
			input = 0;
			do
			{
				system("cls");
				cout << "�������� ��� �����: \n\n";
				bool repeat = true;
				for (i = 0; i < pointer; i++)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((LIGHTCYAN << 4) | GREEN));
					cout << wagtype[i] << "\n";
				}
				if (pointer < speedmax)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((YELLOW << 4) | GREEN));
					cout << wagtype[pointer] << "\n";
					SetConsoleTextAttribute(hConsole, (WORD)((LIGHTCYAN << 4) | GREEN));
					i++;
				}
				for (i; i < speedmax; i++)
					cout << wagtype[i] << "\n";
				updown(pointer, speedmax, notEnter);
			} while (notEnter);
			if (data.tnumber)
				data.tnumber = 3;
			else
				data.tnumber = 4;
			setwtype(pointer, data);
			break;
		default:
			break;
		}
	} while (agree(data));
	return data;
}