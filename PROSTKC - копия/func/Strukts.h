#ifndef _STRUKTS
#define _STRUKTS
#include "XKY_HBO_5_0.h"

struct Floats //��������� ��� ���������� ��������� ������ �� ��� ����������� ��������� �������� ��� ��������� ��������
{
  int name;
  //double r[6];//������  ����� � ��������

  float tn1;
  float tk1;
  float tn2;
  float tk2;
  float tn3;
  float tk3;
  float tn4;
  float tk4;
  float tab;

};
//��� ��������� ��
struct Kosmo
{
	public:
	int name;
	double r[6];//������  ����� � ��������
	KU_TimeDATA ts;
	int ru[5]; // ����� � ��������� �������� �������
};

#endif