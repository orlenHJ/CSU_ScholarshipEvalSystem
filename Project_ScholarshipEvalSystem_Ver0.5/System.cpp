#include "fScholarshipEval.h"
#pragma warning(disable:4996) //解决C6031问题的代码


int main(void)
{
	for (;;) //任务运行
	{
		menuIN();


		char ch = _getch();
		//getchar();

		switch (ch)
		{
		case '1':
			InputStuInfo();
			break;
		case '2':
			PrintfStuInfo();
			break;
		case '3':		
		{			
			int TotalStuNums = TotalStu();
			printf("请选择学生信息排序方式：\n");
			printf("1:按学号排序\n2:按姓名排序(由A-Z)\n3:按总分排序(降序)\n4:按学习成绩排序(降序)\n5:按论文数量(降序)\n");
			char ch3 = _getch();
			switch (ch3)
			{
			case '1':
				printf("按学号排序：\n");
				RankStuID();
				PrintfStuWithRankID(TotalStuNums);
				break;
			case '2':
				printf("按姓名排序(由A-Z)：\n");
				RankStuName();
				PrintfStuWithRankName(TotalStuNums);
				break;
			case '3':
				printf("按总分排序(降序)：\n");
				RankStuScore();
				PrintfStuWithRANK(TotalStuNums);
				break;
			case '4':
				printf("按学习成绩排序(降序)\n");
				RankAcaRec();
				PrintfStuWithRankAcaRec(TotalStuNums);
				break;
			case '5':
				printf("按论文数量(降序)\n");
				RankPap();
				PrintfStuWithRankPap(TotalStuNums);
				break;
			}
			break;
		}
		case '4':
			SaveStuInfo();
			break;
		case '5':
			ReadStuInfo();
			break;
		case '6':
			LookUpStuInfo();
			break;
		case '7':
			ModifyStuInfo();
			break;
		case '8':
			DelStuInfo();
			break;
		case '0':
		{
			//退出系统：退出系统之前，要再次确认。
			printf("是否要退出系统？（输入1确认）\n");
			char ch1 = _getch();
			if (ch1 == '1') { 
				printf("\n/********感谢使用本系统********/\n");
				return 0; }
			break;
		}
		default:
			break;



		}
		system("cls");
	}

	return 0;


}

void menuIN(void)
{
	printf("******************************\n");
	printf("* 欢迎使用学生奖学金评定系统 *\n");
	printf("******************************\n");
	printf("   —> 1： 输入学生信息 *\n");
	printf("   —> 2： 打印并统计学生信息 *\n");
	printf("   —> 3： 排序学生信息 *\n");
	printf("   —> 4： 保存到学生信息文件 *\n");
	printf("   —> 5： 读取学生信息文件 *\n");
	printf("   —> 6： 查询学生信息 *\n");
	printf("   —> 7： 修改学生信息 *\n");
	printf("   —> 8： 删除学生信息 *\n");
	printf("   —> 0： 退出学生系统 *\n");
	printf("******************************\n");
	printf("——> 请选择操作<0-8> \n");

}


void InputStuInfo(void)
{


	char inName[100];
	char inID[100];
	char inSocWok[100];
	float inAcaRec;
	int inQOPaper;
	printf("请输入学生学号：\n");
	scanf("%s", inID);
	printf("请输入学生姓名：\n");
	scanf("%s", inName);
	printf("请输入该学生学业成绩：\n");
	scanf("%f", &inAcaRec);	
	printf("请输入该学生的论文数量：\n");
	scanf("%d", &inQOPaper);
	printf("请输入该学生的学生工作：\n");
	scanf("%s", inSocWok);	

	//要求学号不能重复，输入过程中如果出现相同的学号，应给出报错信号，并重新输入
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (strcmp(p->StuInfo.StuID, inID) == 0) {
			printf("该学号已存在，请重试！");
			return;
		}
		p = p->pNext;

	}
	if (p == NULL) {
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;

		//头插法
		if (g_pHead == NULL)
		{
			g_pHead = pNewNode;

		}
		else {
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;

		}
		strcpy(pNewNode->StuInfo.name, inName);
		strcpy(pNewNode->StuInfo.StuID, inID);
		strcpy(pNewNode->StuInfo.SocialWork, inSocWok);
		pNewNode->StuInfo.Academic_Record = inAcaRec;
		pNewNode->StuInfo.QuantityOfPaper = inQOPaper;
		CalcuScore(pNewNode);
	}
	

	printf("学生信息录入完成\n");
	system("pause");
	system("cls");


}



void PrintfStuInfo(void)
{
	//学号 姓名 学习成绩绩点 论文数量 社会工作 总分
	printf("* 学号 *\t");
	printf("* 姓名 *\t");
	printf("* 学习成绩绩点 *\t");
	printf("* 论文数量 *\t");
	printf("* 社会工作 *\t");
	printf("* 总分 *\t\n");

	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		printf("* %-6s *\t* %-6s *\t* %.2f *\t\t* %d *\t\t* %-6s *\t* %.2f *\n",
			p->StuInfo.StuID,
			p->StuInfo.name,
			p->StuInfo.Academic_Record,
			p->StuInfo.QuantityOfPaper,
			p->StuInfo.SocialWork,
			p->StuInfo.Total_Score
		);

		p = p->pNext;

	}


	system("pause");
	system("cls");

}


/*

//冒泡排序
void SortFunction(void) //12.3日志：目前还不知道能不能用
{
	Node* p = g_pHead;
	if (p == NULL || p->pNext == NULL) {
		return;
	}
	while (p != NULL)
	{
		if (p->pNext != NULL) {
			if (p->StuInfo.Total_Score > p->pNext->StuInfo.Total_Score) {//相邻节点比较，数据交换
				Node* pTemp1 = p;  //A
				Node* pTemp2 = p->pNext; //B
				p->pNext = pTemp2->pNext;
				p = pTemp2;


				
				

			}
		}
		p = p->pNext;
	}


}
*/


void ModifyStuInfo(void)
{
	char sfStuID[100];
	printf("请输入要修改的学生学号：\n");
	scanf("%s", sfStuID);
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (strcmp(p->StuInfo.StuID, sfStuID) == 0) {
			printf("已找到该学生，再次确认是否需要修改？（输入 7 确认修改）\n");
			char ch = _getch();
			if (ch != '7') { return; } //这里写return还是break哪个更好呢？
			//这里可以再完善 选择修改
			printf("请输入要修改的信息: 姓名 学习成绩绩点 论文数量 社会工作（空格隔开）：\n");
			scanf("%s %f %d %s",p->StuInfo.name, &p->StuInfo.Academic_Record, &p->StuInfo.QuantityOfPaper, p->StuInfo.SocialWork);
			printf("修改成功！\n");
			system("pause");
			break;
		}
		p = p->pNext;

	}
	if (p == NULL)
	{
		printf("未找到该学生！请重试 \n");
		system("pause");
	}

}



void DelStuInfo(void)
{
	char fStuID[100];
	printf("请输入要删除的学生的学号：\n");
	scanf("%s", &fStuID);
	Node* p1, * p2;
	
	//判断是否为头节点 StuInfo
	if (strcmp(g_pHead->StuInfo.StuID , fStuID) == 0) {
		printf("已找到该学生，再次确认是否删除？（输入 8 确认删除）\n");
		char ch = _getch();
		if (ch != '8') { return; }
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		printf("删除成功！\n");
		free(p1);
		system("pause");
		system("cls");
		return;

	}

	//非头节点
	Node* p = g_pHead;
	while (p->pNext != NULL)
	{
		if (strcmp(p->pNext->StuInfo.StuID, fStuID) == 0 && p->pNext != NULL) {
			printf("已找到该学生，再次确认是否删除修改？（输入 8 确认修改）\n");
			char ch = _getch();
			if (ch != '8') { return; }
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			printf("删除成功！\n");
			free(p2);
			system("pause");
			system("cls");
			return;

		}
		
		//p = p->pNext;
		if (p->pNext->pNext == NULL && strcmp(p->pNext->StuInfo.StuID, fStuID) == 0) //证明是链表的倒数第二个，将指向最后一个的p->Next 为NULL
		{
			printf("已找到该学生，再次确认是否删除修改？（输入 8 确认修改）\n");
			char ch = _getch();
			if (ch != '8') { return; }
			p2 = p->pNext;
			p->pNext = NULL;
			printf("删除成功！\n");
			free(p2);			
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;

	}

	printf("未找到该学生信息！\n");
	

	system("pause");
	system("cls");
}


void SaveStuInfo(void)
{
	//文件读写操作
	FILE* fp = fopen("D:\\StudentScholarshipEval_System.data", "w");
	if (fp == NULL)
	{
		printf("打开文件失败！ \n");
		return;

	}
	//遍历链表写入
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->StuInfo, 1, sizeof(Student_info), fp);
		p = p->pNext;

	}
	fclose(fp);

	printf("保存数据成功！\n");
	system("pause");
	system("cls");
}


/*
12.4修改日志：
	- 会出现 ： 屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯?       的BUG
	解决方法：
	- 便通过建立一个缓存结构体stu存放读取流
	- 再通过memcpy复制到原链表上

*/
void ReadStuInfo(void)
{
	FILE* fp = fopen("D:\\StudentScholarshipEval_System.data", "r");
	if (fp == NULL)
	{
		printf("打开文件失败！ \n");
		system("pause");
		return;
	}

	Student_info stu;

	while (fread(&stu, 1, sizeof(Student_info), fp))
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student_info));

		//头插法
		if (g_pHead == NULL)
		{
			g_pHead = pNewNode;

		}
		else {
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
	}
	fclose(fp);
	printf("加载数据成功！ \n");
	system("pause");
	system("cls");
}


void LookUpStuInfo(void)
{
	Node* p = g_pHead;
	printf("请选择查询方式：\n->1：按学号查询 \n->2：按姓名查询 \n->3：总分区间查询\n");
	char ch = _getch();
	switch (ch)
	{
	case '1':
	{
		printf("请输入要查找的学生学号：\n");
		char sfStuID[100];
		scanf("%s", sfStuID);

		while (p != NULL)
		{
			if (strcmp(p->StuInfo.StuID, sfStuID) == 0) {
				printf("* 学号 *\t");
				printf("* 姓名 *\t");
				printf("* 学习成绩绩点 *\t");
				printf("* 论文数量 *\t");
				printf("* 社会工作 *\t");
				printf("* 总分 *\t\n");
				printf("* %-6s *\t* %-6s *\t* %.2f *\t\t* %d *\t\t* %-6s *\t\t* %.2f *\n",
					p->StuInfo.StuID,
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);
				break;
			}
			p = p->pNext;
		}
		if (p == NULL)
		{
			printf("未找到该学生！请重试 \n");
		}

		break;
	}
	case '2':
	{
		printf("请输入要查找的学生姓名：\n");
		char fname[100];
		scanf("%s", fname);

		while (p != NULL)
		{
			if (strcmp(p->StuInfo.name, fname) == 0) {
				printf("* 学号 *\t");
				printf("* 姓名 *\t");
				printf("* 学习成绩绩点 *\t");
				printf("* 论文数量 *\t");
				printf("* 社会工作 *\t");
				printf("* 总分 *\t\n");
				printf("* %s *\t* %s *\t* %.2f *\t\t* %d *\t\t* %s *\t\t* %.2f *\n",
					p->StuInfo.StuID,
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);
				break;
			}
			p = p->pNext;
		}
		if (p == NULL)
		{
			printf("未找到该学生！请重试 \n");
		}
		break;
	}
	case '3':
	{
		printf("请输入要查找的总分区间（从xx到xx的分数区间，用空格隔开）：\n");
		float f1score, f2score;
		scanf("%f %f", &f1score, &f2score);
		int cnt = 0;
		while (p != NULL)
		{
			if (p->StuInfo.Total_Score >= f1score && p->StuInfo.Total_Score <= f2score) {
				printf("* 学号 *\t");
				printf("* 姓名 *\t");
				printf("* 学习成绩绩点 *\t");
				printf("* 论文数量 *\t");
				printf("* 社会工作 *\t");
				printf("* 总分 *\t\n");
				printf("* %s *\t* %s *\t* %.2f *\t\t* %d *\t\t* %s *\t\t* %.2f *\n",
					p->StuInfo.StuID,
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);
				cnt++;
			}
			p = p->pNext;
		}
		if (p == NULL && cnt == 0)
		{
			printf("未找到符合条件的学生！请重试 \n");
		}
		break;
	}
	default:
	{
		printf("错误！请重试！\n");
		break;
	}
	}
	system("pause");
	system("cls");
}


//总评分：学习成绩绩点*30%+学术成果计分*60%+社会工作计分*10%  
//这里仍有疑问
void CalcuScore(Node *p)
{
	int scoAcaRec = 0;
	int scoPaper = 0;
	int scoSocWok = 0;
	if (p->StuInfo.Academic_Record == 4.0) { scoAcaRec = 100; }
	if (p->StuInfo.Academic_Record > 3.7 && p->StuInfo.Academic_Record < 4.0) { scoAcaRec = 80; }
	if (p->StuInfo.Academic_Record > 3.3 && p->StuInfo.Academic_Record < 3.7) { scoAcaRec = 70; }
	if (p->StuInfo.Academic_Record > 2.7 && p->StuInfo.Academic_Record < 3.3) { scoAcaRec = 50; }
	if (p->StuInfo.Academic_Record < 2.7) { scoAcaRec = 0; } // ??????这里不太清楚

	if (p->StuInfo.QuantityOfPaper > 5) { scoPaper = 100; }
	if (p->StuInfo.QuantityOfPaper <= 5 && p->StuInfo.QuantityOfPaper >= 3) { scoPaper = 80; }
	if (p->StuInfo.QuantityOfPaper < 3 && p->StuInfo.QuantityOfPaper >= 2) { scoPaper = 70; }
	if (p->StuInfo.QuantityOfPaper == 1) { scoPaper = 50; }
	if (p->StuInfo.QuantityOfPaper == 0) { scoPaper = 0; }// ??????这里不太清楚

	if (strcmp(p->StuInfo.SocialWork, TOPA1) == 0 || strcmp(p->StuInfo.SocialWork, TOPA2) == 0 || strcmp(p->StuInfo.SocialWork, TOPA3) == 0)
	{
		scoSocWok = 100;
	}
	if (strcmp(p->StuInfo.SocialWork, TOPB1) == 0 || strcmp(p->StuInfo.SocialWork, TOPB2) == 0 || strcmp(p->StuInfo.SocialWork, TOPB3) == 0)
	{
		scoSocWok = 80;
	}
	if (strcmp(p->StuInfo.SocialWork, TOPC1) == 0 || strcmp(p->StuInfo.SocialWork, TOPC2) == 0 )
	{
		scoSocWok = 70;
	}
	if (strcmp(p->StuInfo.SocialWork, TOP0) == 0 )
	{
		scoSocWok = 50;
	}


	p->StuInfo.Total_Score = scoAcaRec * 0.3 + scoPaper * 0.6 + scoSocWok * 0.1;



}


int TotalStu(void) //计算总人数
{
	int nCount = 0;

	//遍历
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;

	}
	return nCount;


}







/*
（要求：至少提供三种排序方式，如按学号排序、按姓名排序、按总分排序等。）
*/

//遍历链表计算排名
void RankStuScore(void)
{
	int PWHSTY;//People with higher scores than you  ( PWHSTY + 1 = Rank)
	Node* p1 = g_pHead;
	while (p1 != NULL)
	{
		PWHSTY = 0; 
		Node* p2 = g_pHead;
		while (p2 != NULL)
		{

			if (p1->StuInfo.Total_Score < p2->StuInfo.Total_Score)
			{
				PWHSTY++;
			}
			p2 = p2->pNext;
		}
		p1->StuInfo.Rank = PWHSTY + 1;		
		p1 = p1->pNext;

	}





}

void PrintfStuWithRANK(int TotalStuNums)
{
	int pOutRank = 0;
	printf("* 学号 *\t");
	printf("* 姓名 *\t");
	printf("* 学习成绩绩点 *\t");
	printf("* 论文数量 *\t");
	printf("* 社会工作 *\t");
	printf("* 总分 *\t\n");
	for(;;)
	{ 
		pOutRank++;
		Node* p = g_pHead;
		while (p != NULL)
		{
			if (p->StuInfo.Rank == pOutRank) {
				
				printf("* %-6s *\t* %-6s *\t* %.2f *\t\t* %d *\t\t* %-6s *\t* %.2f *\n",
					p->StuInfo.StuID, 
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);			
			}
		
			p = p->pNext;
		}
		if (TotalStuNums == pOutRank) { break; }
	}
	system("pause");
	system("cls");


}

void RankStuName(void)
{
	int PWHSTY;//People with higher scores than you  ( PWHSTY + 1 = Rank)
	Node* p1 = g_pHead;
	while (p1 != NULL)
	{
		PWHSTY = 0;
		Node* p2 = g_pHead;
		while (p2 != NULL)
		{

			if (strcmp(p1->StuInfo.name , p2->StuInfo.name) > 0)
			{
				PWHSTY++;
			}
			p2 = p2->pNext;
		}
		p1->StuInfo.RankName = PWHSTY + 1;
		p1 = p1->pNext;

	}


}

void PrintfStuWithRankName(int TotalStuNums)
{
	int pOutRank = 0;
	printf("* 学号 *\t");
	printf("* 姓名 *\t");
	printf("* 学习成绩绩点 *\t");
	printf("* 论文数量 *\t");
	printf("* 社会工作 *\t");
	printf("* 总分 *\t\n");
	for (;;)
	{
		pOutRank++;
		Node* p = g_pHead;
		while (p != NULL)
		{
			if (p->StuInfo.RankName == pOutRank) {

				printf("* %-6s *\t* %-6s *\t* %.2f *\t\t* %d *\t\t* %-6s *\t* %.2f *\n",
					p->StuInfo.StuID,
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);
			}

			p = p->pNext;
		}
		if (TotalStuNums == pOutRank) { break; }
	}
	system("pause");
	system("cls");


}

void RankStuID(void)
{
	int PWHSTY;//People with higher scores than you  ( PWHSTY + 1 = Rank)
	Node* p1 = g_pHead;
	while (p1 != NULL)
	{
		PWHSTY = 0;
		Node* p2 = g_pHead;
		while (p2 != NULL)
		{

			if (strcmp(p1->StuInfo.StuID, p2->StuInfo.StuID) > 0)
			{
				PWHSTY++;
			}
			p2 = p2->pNext;
		}
		p1->StuInfo.RankID = PWHSTY + 1;
		p1 = p1->pNext;

	}


}

void PrintfStuWithRankID(int TotalStuNums)
{
	int pOutRank = 0;
	printf("* 学号 *\t");
	printf("* 姓名 *\t");
	printf("* 学习成绩绩点 *\t");
	printf("* 论文数量 *\t");
	printf("* 社会工作 *\t");
	printf("* 总分 *\t\n");
	for (;;)
	{
		pOutRank++;
		Node* p = g_pHead;
		while (p != NULL)
		{
			if (p->StuInfo.RankID == pOutRank) {

				printf("* %-6s *\t* %-6s *\t* %.2f *\t\t* %d *\t\t* %-6s *\t* %.2f *\n",
					p->StuInfo.StuID,
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);
			}

			p = p->pNext;
		}
		if (TotalStuNums == pOutRank) { break; }
	}
	system("pause");
	system("cls");


}

void RankAcaRec(void)
{
	int PWHSTY;//People with higher scores than you  ( PWHSTY + 1 = Rank)
	Node* p1 = g_pHead;
	while (p1 != NULL)
	{
		PWHSTY = 0;
		Node* p2 = g_pHead;
		while (p2 != NULL)
		{

			if (p1->StuInfo.Academic_Record < p2->StuInfo.Academic_Record)
			{
				PWHSTY++;
			}
			p2 = p2->pNext;
		}
		p1->StuInfo.RankAcaRec = PWHSTY + 1;
		p1 = p1->pNext;

	}


}

void PrintfStuWithRankAcaRec(int TotalStuNums)
{
	int pOutRank = 0;
	printf("* 学号 *\t");
	printf("* 姓名 *\t");
	printf("* 学习成绩绩点 *\t");
	printf("* 论文数量 *\t");
	printf("* 社会工作 *\t");
	printf("* 总分 *\t\n");
	for (;;)
	{
		pOutRank++;
		Node* p = g_pHead;
		while (p != NULL)
		{
			if (p->StuInfo.RankAcaRec == pOutRank) {

				printf("* %-6s *\t* %-6s *\t* %.2f *\t\t* %d *\t\t* %-6s *\t* %.2f *\n",
					p->StuInfo.StuID,
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);
			}

			p = p->pNext;
		}
		if (TotalStuNums == pOutRank) { break; }
	}
	system("pause");
	system("cls");


}

void RankPap(void)
{
	int PWHSTY;//People with higher scores than you  ( PWHSTY + 1 = Rank)
	Node* p1 = g_pHead;
	while (p1 != NULL)
	{
		PWHSTY = 0;
		Node* p2 = g_pHead;
		while (p2 != NULL)
		{

			if (p1->StuInfo.QuantityOfPaper < p2->StuInfo.QuantityOfPaper)
			{
				PWHSTY++;
			}
			p2 = p2->pNext;
		}
		p1->StuInfo.RankPap = PWHSTY + 1;
		p1 = p1->pNext;

	}


}

void PrintfStuWithRankPap(int TotalStuNums)
{
	int pOutRank = 0;
	printf("* 学号 *\t");
	printf("* 姓名 *\t");
	printf("* 学习成绩绩点 *\t");
	printf("* 论文数量 *\t");
	printf("* 社会工作 *\t");
	printf("* 总分 *\t\n");
	for (;;)
	{
		pOutRank++;
		Node* p = g_pHead;
		while (p != NULL)
		{
			if (p->StuInfo.RankPap == pOutRank) {

				printf("* %-6s *\t* %-6s *\t* %.2f *\t\t* %d *\t\t* %-6s *\t* %.2f *\n",
					p->StuInfo.StuID,
					p->StuInfo.name,
					p->StuInfo.Academic_Record,
					p->StuInfo.QuantityOfPaper,
					p->StuInfo.SocialWork,
					p->StuInfo.Total_Score
				);
			}

			p = p->pNext;
		}
		if (TotalStuNums == pOutRank) { break; }
	}
	system("pause");
	system("cls");


}

















