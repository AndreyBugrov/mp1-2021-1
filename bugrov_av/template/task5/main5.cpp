//����������� ������ ��������������� ����� � ����������� �������� ������.
//����� ��������������� ����� ������ ����������� ������ ����� �� ������� ������� �� ������ ������ �������� � ������.
//�������, ��� ������� ������� ���������� �� ������ � �������� 30 ���� �� ������� ����.
//�������, ��� �� �������� ������ �������� � ������ ��������� ��� ���������� ������ ���������, ���� ��������� � ���� ������ ����� � ����� � ������ �����������.
//��� ������ � ������� ��������� ��������� � �������� �� 100 ������� ����.
///� ��������� � ������ ������� ������ ���� ����� : 
///�����������(27 �������, 27 ������ ����),
///��������(18 �������, 18 ������ ����), 
///��(18 ������ ����).
//����� ������� � ������� ��������� � 8. 
///� ��������� ������
/// - 2 ������ ��, 
/// - 6 �������� �������, 
/// - 4 ����������� ������.
///� ������ ������ � 4 �������� ������, 8 ����������� �������.
//������ ���������������� ��������(������ ������� �� ��������� �� 1 �� 100), 
///������ � ��������(����� ����� �� 1 �� 12), 
/// ����� � ��������(����� ����� �� 1 �� ��������� ��� ������� ���� ������).
//���������� � ���� ������� � ���� ��������� ������� �������� � ������ ����������� �������� ������.
//��� ������� ������, ������� ���� ������ � ������� ���� ����� ����������� ��������� ������.
//�������, ��� ��� ������ �� ������ ������������� ��������� �� ��������.
//����� ��������������� ����� ������ ������������� ��������� �������� : 
//1) ������� ������ ���������� : ����, �����, ��� ������(���� ���� �����), ���������� ������� ������� ���������� ����(���� ���� �����), ��� ���������� 
//2) ��������� ������� ��������� ���� �� ������� ����������(��� ������������� ������ ��� ������ � ����� ������, ������� ����� ������������), 
//3) ��������������� �����,
//4) ���������� ����� ��������� �����//��, 
//5) �������� ����� �������, 
//6) ������������ ������(������ ����� �������� : ����, ����� ������, ����� ������, ����� �����, ��� ���������, ������� �����������, ������� ��������).
///����� ����������� �������� ������ ������ �������������� ��� ��������� ������ ������ ��������������� ����� � ����� ���� ���������� � ���������� - ����������� ��������.
///		            ������������� �� ������
/// ������ ���� ���� � ������� � ������
/// ���������, ��� � ��������� ������ �������� � ������� ��� �����, ����� �� ������ �������? yes
/// ��� ��������������� ����� ��� ���������� ����� �������� � �������?
/// ����� ��������� �� �������� ������ � ���� ������� (������ ��� ������� ��������� �� ������ �������)
/// ����� �������������� �� ���������� ������� ������������ ����� �������� ������ (�.�. ������� check �������� ���������� �� railway)
/// ��� ������ ������� ����� ��� ��������� �����, ����� ������ �� 1 �� max, ������� ��� ����� �������� �� max ����� ����������
#include "all.h"
//enum class trainType
//{
//	firm, speed, swallow
//};
//enum class wagonType
//{
//	up_c, down_c, up_r, down_r, sleep
//};
//class wagon
//{
//public:
//	wagon& operator=(wagon& v);
//protected:
//	const int COUPE = 18;
//	const int RESERVED = 27;
//};
////int ffo()
////{
////	wagonType c = wagonType::sleep;
////	int a = static_cast<int>(c);
////}
//class firm : public wagon
//{
//	const int SLEEPING = 18;
//	int up_coupe[6];//����
//	int down_coupe[6];
//	int up_reserved[4];//����������� ������
//	int down_reserved[4];
//	int sleeping[2];//�������� ������
//	enum places
//	{
//		c_first = 1, c_last = 6, r_first, r_last = 10, s_first, s_last = 12
//	};
//public:
//	firm()
//	{
//		for (int i = 0; i < 6; i++)
//			up_coupe[i] = down_coupe[i] = COUPE;
//		for (int i = 0; i < 4; i++)
//			up_reserved[i] = down_reserved[i] = RESERVED;
//		for (int i = 0; i < 2; i++)
//			sleeping[i] = SLEEPING;
//	}
//	firm& operator=(firm& f)
//	{
//		for (int i = 0; i < 6; i++)
//			up_coupe[i] = f.up_coupe[i];
//		for (int i = 0; i < 6; i++)
//			down_coupe[i] = f.down_coupe[i];
//		for (int i = 0; i < 4; i++)
//			up_reserved[i] = f.up_reserved[i];
//		for (int i = 0; i < 4; i++)
//			down_reserved[i] = f.down_reserved[i];
//		for (int i = 0; i < 2; i++)
//			sleeping[i] = SLEEPING;
//	}
//	friend class railway;
//};
//class speed: public wagon
//{
//	enum places
//	{
//		c_first = 1, c_last = 4, r_first, r_last = 12
//	};
//	int up_coupe[4];//����
//	int down_coupe[4];
//	int up_reserved[8];//����������� ������
//	int down_reserved[8];
//public:
//	speed()
//	{
//		for (int i = 0; i < 4; i++)
//			up_coupe[i] = down_coupe[i] = COUPE;
//		for (int i = 0; i < 8; i++)
//			up_reserved[i] = down_reserved[i] = RESERVED;
//	}
//	speed& operator=(speed& s)
//	{
//		for (int i = 0; i < 4; i++)
//			up_coupe[i] = s.up_coupe[i];
//		for (int i = 0; i < 4; i++)
//			down_coupe[i] = s.down_coupe[i];
//		for (int i = 0; i < 8; i++)
//			up_reserved[i] = s.up_reserved[i];
//		for (int i = 0; i < 8; i++)
//			down_reserved[i] = s.down_reserved[i];
//	}
//	friend class railway;
//};
//class swallow
//{
//	int wagon[8] = { 100,100, 100, 100, 100, 100, 100, 100 };
//	swallow()
//	{
//		for (int i = 0; i < 8; i++)
//			wagon[i] = 100;
//	}// ����������� ����������� �����������
//	friend class railway;
//};
//class userdata
//{
//	string surname;
//	string name;
//	string patronymic;
//	trainType Ttype;//
//	wagonType Wtype;//� �������� ������ ��� ���� ��������� �� ��, � ����� ����� ��� ���
//	int date[2];
//	char number;//����� ������
//	friend class cashbox;
//	friend class railway;
//public:
//};
//class railway
//{
//	swallow swtrain[3];
//	speed strain;
//	firm ftrain;
//public:
//	railway(railway& r)
//	{
//		for (int i = 0; i < 3; i++)
//			swtrain[i] = r.swtrain[i];
//		strain = r.strain;
//		ftrain = r.ftrain;
//	}
//	railway()
//	{
//
//	}
//	bool check(userdata inf);
//	friend class cashbox;
//};
//bool railway::check(userdata inf)//��� � ������� �����
//{
//	switch (inf.Ttype)
//	{
//	case trainType::firm:
//		switch (inf.Wtype)
//		{
//		case wagonType::down_c:
//			for (int i = ftrain.c_first; i < ftrain.c_last; i++)
//				if (ftrain.down_coupe[i])
//				{
//					ftrain.down_coupe[i]--;
//					return true;
//				}
//				return false;
//			break;
//		case wagonType::down_r:
//			for (int i = ftrain.r_first; i < ftrain.r_last; i++)
//				if (ftrain.down_reserved[i])
//				{
//					ftrain.down_reserved[i]--;
//					return true;
//				}
//			return false;
//			break;
//		case wagonType::up_c:
//			for (int i = ftrain.c_first; i < ftrain.c_last; i++)
//				if (ftrain.up_coupe[i])
//				{
//					ftrain.up_coupe[i]--;
//					return true;
//				}
//			return false;
//			break;
//		case wagonType::up_r:
//			for (int i = ftrain.r_first; i < ftrain.r_last; i++)
//				if (ftrain.up_reserved[i])
//				{
//					ftrain.up_reserved[i]--;
//					return true;
//				}					
//			return false;
//			break;
//		case wagonType::sleep:
//			for (int i = ftrain.s_first; i < ftrain.s_last; i++)
//				if (ftrain.sleeping[i])
//				{
//					ftrain.sleeping[i]--;
//					return true;
//				}
//		default:
//			break;
//		}
//		break;
//	case trainType::speed:
//		switch (inf.Wtype)
//		{
//		case wagonType::down_c:
//			for (int i = strain.c_first; i < strain.c_last; i++)
//				if (strain.down_coupe[i])
//				{
//					strain.down_coupe[i]--;
//					return true;
//				}
//			return false;
//			break;
//		case wagonType::down_r:
//			for (int i = strain.r_first; i < strain.r_last; i++)
//				if (strain.down_reserved[i])
//				{
//					strain.down_reserved[i]--;
//					return true;
//				}
//			return false;
//			break;
//		case wagonType::up_c:
//			for (int i = strain.c_first; i < strain.c_last; i++)
//				if (strain.up_coupe[i])
//				{
//					strain.up_coupe[i]--;
//					return true;
//				}
//			return false;
//			break;
//		case wagonType::up_r:
//			for (int i = strain.r_first; i < strain.r_last; i++)
//				if (strain.up_reserved[i])
//				{
//					strain.up_reserved[i]--;
//					return true;
//				}
//			else
//				return false;
//			break;
//		default:
//			break;
//		}
//		break;
//	case trainType::swallow:
//		int j = 0;
//		switch (inf.Wtype)
//		{
//		case wagonType::up_c:
//			j = 0;
//			goto met_default;
//			break;
//		case wagonType::down_c:
//			j = 1;
//			goto met_default;
//			break;
//		case wagonType::up_r:
//			j = 2;
//			goto met_default;
//			break;
//		default:
//met_default:			for (int i = 0; i < 8; i++)
//				if (swtrain[j].wagon[i])
//				{
//					swtrain[j].wagon[i]--;
//					return true;
//				}
//			return false;
//			break;
//		}
//		break;
//	default:
//		break;
//	}
//}
//class cashbox
//{
//	//���� � ���: 1 - ���������; 3 - ������; 5,7,9 - ��������
//	//���� � ��: 2 - ���������; 4 - ������; 6,8,10 - ��������
//	vector<railway> toNN, toMsk;
//	userdata SetData();//�������� ������ � ������������
//					   //���������, ����� �� ������� �� ���������� �������, ����� ��� �� ����� �������������
//	/// ������ ����� ����� ��������� �������.
//	void GetTicket(userdata inf);//������������ �����
//public:
//	void SetPlace();//������ ��������� �������� � ��������
//	cashbox()
//	{
//		railway tmp_rail;
//		for (int i = 0; i < 30; i++)/////����� ����� ��������� �� �����
//		{
//			toNN.push_back(tmp_rail);
//			toMsk.push_back(tmp_rail);
//		}
//	}
//};
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void menu()
{
	cashbox box;
	while (1)
		box.SetPlace();
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
}