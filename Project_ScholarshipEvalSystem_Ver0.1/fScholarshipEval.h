#pragma once
#ifndef __FSCHOLARSHIPEVAL_H__
#define __FSCHOLARSHIPEVAL_H__
#endif

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//������ʹ��
extern char TOPA1[] = "�꼶��";
extern char TOPA2[] = "��֧�������";
extern char TOPA3[] = "ѧ���Ჿ��";

extern char TOPB1[] = "�೤";
extern char TOPB2[] = "ѧ���ḱ����";
extern char TOPB3[] = "��֧�������";

extern char TOPC1[] = "��ί";
extern char TOPC2[] = "��֧��ίԱ";

extern char TOP0[] = "��";



/*

����	ѧϰ�ɼ�	��������	���εĸɲ�ְλ
100			4		   >5		�꼶������֧������ǡ�ѧ���Ჿ��
80			3.7			3		�೤��ѧ���ḱ��������֧�������
70			3.3			2		��ί����֧��ίԱ
50			2.7����		1		��

*/



typedef struct _StuData
{
	char name[100];
	char SocialWork[100];
	char StuID[100];
	
	int QuantityOfPaper;
	
	float Academic_Record;	
	float Total_Score;

	int Rank;

}Student_info;

typedef struct _Node  //�ڵ�
{
	Student_info StuInfo;
	struct _Node* pNext; //ָ����һ�������ڵ��ָ��


}Node;

Node* g_pHead = NULL; //ͷ�ڵ�

void menuIN(void);
void PrintfStuInfo(void);
void InputStuInfo(void);
/*
1�����빦�ܣ�����ѧ�������Ϣ���磺��š�������ѧϰ�ɼ����㡢������������Ŀ
��Ṥ������Ҫ�󣺢� �������� 10 λѧ������Ϣ���� ������ԭ�м�¼�Ļ����ϣ�����µ�
��¼���� Ҫ��ѧ�Ų����ظ���������������������ͬ��ѧ�ţ�Ӧ���������źţ�������
���룻�� ��š���������Ŀ��Ṥ��Ҫ�����ַ�������ַ�ָ�룻������������Ҫ������
����ѧϰ�ɼ����㡢�ܷ���ʵ���������ֱܷ�����λС����
*/
//void SortFunction(void); //12.3��־��Ŀǰ����֪���ܲ�����
/*
2�������ܣ�������¼���ѧ����¼�������򣬲��Ա� 2 �� PrintfStuInfo(void) ��ʽ�������Ҫ��������
����������ʽ���簴ѧ�����򡢰��������򡢰��ܷ�����ȡ���
*/

//void Statistics_Function(void);
/*
ͳ�ƹ��ܣ���ѧ������Ϣ����ͳ�ơ���Ҫ���Լ����ͳ�Ʊ�����ʽ�����������
����ͳ����Ϣ���ܳɼ���ǰ����ѧ��ѧ�š�������ѧϰ�ɼ����㡢������������Ŀ��Ṥ��
�ȣ�

��չ���ݣ�ѧϰ�ɼ�����ƽ���֣��ܳɼ�ƽ���� ��

*/

void CalcuScore(Node* p); //���㹦�� �ܳɼ�����

void ModifyStuInfo(void);
/*�޸Ĺ��ܣ�����ѧ��ѧ�ţ������ڣ�����Զ�ѧ�������ֱ���Ϣ�����޸ģ������
�����ڣ���������Ӧ����ʾ����Ҫ���޸�֮ǰӦ�ٴ�ȷ���Ƿ��޸ġ���*/


void DelStuInfo(void);
/*6�� ɾ�����ܣ�����ѧ��ѧ�ţ������ڣ�ɾ����������Ϣ������������Ӧ����ʾ����Ҫ
��ɾ��֮ǰӦ�ٴ�ȷ���Ƿ�ɾ������*/

void SaveStuInfo(void); //���浽ѧ����Ϣ�ļ�
void ReadStuInfo(void); //��ȡѧ����Ϣ�ļ�


void LookUpStuInfo(void);
/*
Ҫ��
�� �ṩ���ֲ�ѯ��ʽ����ѧ�Ų�ѯ����������ѯ�����ܷ��Ƿ���ĳ�������ѯ��
�� ������������ļ�¼�ж�����Ӧȫ���г���
�� ���û�����������ļ�¼��Ӧ������Ӧ����ʾ��
*/


/*
12.4��־��
	SortFunction(void); ������
	�����Խṹ����ѧ�������һ�� �� Rank ����
	ͨ���Ƚ�TotalScore����������

*/

void RankStuScore(void);//���������������
void PrintfStuWithRANK(int TotalStuNums);
int TotalStu(void);





















