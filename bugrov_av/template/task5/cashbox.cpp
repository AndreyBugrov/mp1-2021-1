#include "all.h"

void cashbox::SetPlace()
{
	userdata information = SetData();
	if (information.tnumber % 2)
		if (toMsk[information.date-1].check(information))
		{
			//������ Reserved.txt ��������: std::ios::app
			GetTicket(information);
		}
		else
			cout << "������������ ��������� ����\n";
	else
		if (toNN[information.date-1].check(information))
		{
			//������ Reserved.txt ��������: std::ios::app
			GetTicket(information);
		}
		else
			cout << "������������ ��������� ����\n";
}
void cashbox::GetTicket(userdata inf)
{
	ofstream fout;
	fout.open("Ticket.txt");
	//����� ������ ���� ������� �������� ����� ��������� �������. �������� � (� �� ��������� ������ ��� �����)
	if (fout.is_open())
	{
		//������ � ���� ������� ������
	}
	fout.close();
}
void cashbox::change_database(userdata change, bool is_new)
{
	ofstream os;
	if (is_new)
	{
		os.open("Reserved.txt", ios_base::app);
		if (os.is_open())
			;/////////////////////////////////////////////
		os.close();
	}
}