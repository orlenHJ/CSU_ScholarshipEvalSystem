#pragma once
#ifndef __FSCHOLARSHIPEVAL_H__
#define __FSCHOLARSHIPEVAL_H__
#endif

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//作计算使用
extern char TOPA1[] = "年级长";
extern char TOPA2[] = "党支部书书记";
extern char TOPA3[] = "学生会部长";

extern char TOPB1[] = "班长";
extern char TOPB2[] = "学生会副部长";
extern char TOPB3[] = "党支部副书记";

extern char TOPC1[] = "班委";
extern char TOPC2[] = "党支部委员";

extern char TOP0[] = "无";



/*

分数	学习成绩	论文数量	担任的干部职位
100			4		   >5		年级长、党支部书书记、学生会部长
80			3.7			3		班长、学生会副部长、党支部副书记
70			3.3			2		班委、党支部委员
50			2.7以上		1		无

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

typedef struct _Node  //节点
{
	Student_info StuInfo;
	struct _Node* pNext; //指向下一（链表）节点的指针


}Node;

Node* g_pHead = NULL; //头节点

void menuIN(void);
void PrintfStuInfo(void);
void InputStuInfo(void);
/*
1、输入功能：输入学生相关信息，如：编号、姓名、学习成绩绩点、论文数量、项目
社会工作。（要求：① 至少输入 10 位学生的信息；② 可以在原有记录的基础上，添加新的
记录；③ 要求学号不能重复，输入过程中如果出现相同的学号，应给出报错信号，并重新
输入；④ 编号、姓名、项目社会工作要求用字符数组或字符指针；论文数量、等要求用整
数；学习成绩绩点、总分用实数，并且总分保留两位小数；
*/
//void SortFunction(void); //12.3日志：目前还不知道能不能用
/*
2、排序功能：对所有录入的学生记录进行排序，并以表 2 的 PrintfStuInfo(void) 方式输出。（要求：至少提
供三种排序方式，如按学号排序、按姓名排序、按总分排序等。）
*/

//void Statistics_Function(void);
/*
统计功能：对学生的信息进行统计。（要求：自己设计统计表格的形式，但必须包括
以下统计信息：总成绩在前三的学生学号、姓名、学习成绩绩点、论文数量、项目社会工作
等）

拓展内容：学习成绩绩点平均分，总成绩平均分 ，

*/

void CalcuScore(Node* p); //计算功能 总成绩评分

void ModifyStuInfo(void);
/*修改功能：输入学生学号，若存在，则可以对学生的评分表信息进行修改；如果该
不存在，必须有相应的提示。（要求：修改之前应再次确认是否修改。）*/


void DelStuInfo(void);
/*6、 删除功能：输入学生学号，若存在，删除其所有信息；否则，须有相应的提示。（要
求：删除之前应再次确认是否删除。）*/

void SaveStuInfo(void); //保存到学生信息文件
void ReadStuInfo(void); //读取学生信息文件


void LookUpStuInfo(void);
/*
要求：
① 提供三种查询方式：按学号查询、按姓名查询、按总分是否在某个区间查询；
② 如果满足条件的记录有多条，应全部列出；
③ 如果没有满足条件的记录，应给出相应的提示。
*/


/*
12.4日志：
	SortFunction(void); 不能用
	打算以结构体中学生定义多一个 ： Rank 排名
	通过比较TotalScore来计算排名

*/

void RankStuScore(void);//遍历链表计算排名
void PrintfStuWithRANK(int TotalStuNums);
int TotalStu(void);





















