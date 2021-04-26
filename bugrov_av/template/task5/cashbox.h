#pragma once
#include "all.h"
//----------------------------------------------------------
void setstr(string& s);
int getdate();
void updown(int& pointer, const int lim, bool& notEnter);
void setwtype(const int pointer, userdata& data);
int leftright(const string* var, int maxvar, string message);
//----------------------------------------------------------
class cashbox
{
	//���� � ���: 1 - ���������; 3 - ������; 5,7,9 - ��������
	//���� � ��: 2 - ���������; 4 - ������; 6,8,10 - ��������
	vector<railway> toNN, toMsk;
	int sum;
	userdata SetData();//�������� ������ � ������������
					   //���������, ����� �� ������� �� ���������� �������, ����� ��� �� ����� �������������
	/// ������ ����� ����� ��������� �������.
	void GetTicket(userdata inf);//������������ �����
	cashbox& operator=(cashbox& cash);/////////////////////////////////
	cashbox(cashbox& cash);////////////////////////////////////////////
	void change_database(userdata change, bool is_new);
	bool agree(const userdata& data);
	void do_repeat(bool& repeat);
public:
	virtual void calculate(const userdata& data);
	void SetPlace(bool& repeat);//������ ��������� �������� � ��������
	cashbox() : sum(0)
	{
		railway tmp_rail;
		for (int i = 0; i < 30; i++)/////����� ����� ��������� �� �����
		{
			toNN.push_back(tmp_rail);
			toMsk.push_back(tmp_rail);
		}
	}
};