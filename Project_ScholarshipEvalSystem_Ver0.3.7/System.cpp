#include "fScholarshipEval.h"
#pragma warning(disable:4996) //���C6031����Ĵ���


int main(void)
{
	for (;;) //��������
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
			printf("��ѡ��ѧ����Ϣ����ʽ��\n");
			printf("1:��ѧ������\n2:����������(��A-Z)\n3:���ܷ�����(����)\n4:��ѧϰ�ɼ�����(����)\n5:����������(����)\n");
			char ch3 = _getch();
			switch (ch3)
			{
			case '1':
				printf("��ѧ������\n");
				RankStuID();
				PrintfStuWithRankID(TotalStuNums);
				break;
			case '2':
				printf("����������(��A-Z)��\n");
				RankStuName();
				PrintfStuWithRankName(TotalStuNums);
				break;
			case '3':
				printf("���ܷ�����(����)��\n");
				RankStuScore();
				PrintfStuWithRANK(TotalStuNums);
				break;
			case '4':
				printf("��ѧϰ�ɼ�����(����)\n");
				RankAcaRec();
				PrintfStuWithRankAcaRec(TotalStuNums);
				break;
			case '5':
				printf("����������(����)\n");
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
			//�˳�ϵͳ���˳�ϵͳ֮ǰ��Ҫ�ٴ�ȷ�ϡ�
			printf("�Ƿ�Ҫ�˳�ϵͳ��������1ȷ�ϣ�\n");
			char ch1 = _getch();
			if (ch1 == '1') { 
				printf("\n/********��лʹ�ñ�ϵͳ********/\n/*���ߣ�CSU- orlenHJ *\n/******************************/\n");
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
	printf("* ��ӭʹ��ѧ����ѧ������ϵͳ *\n");
	printf("******************************\n");
	printf("   ��> 1�� ����ѧ����Ϣ *\n");
	printf("   ��> 2�� ��ӡ��ͳ��ѧ����Ϣ *\n");
	printf("   ��> 3�� ����ѧ����Ϣ *\n");
	printf("   ��> 4�� ���浽ѧ����Ϣ�ļ� *\n");
	printf("   ��> 5�� ��ȡѧ����Ϣ�ļ� *\n");
	printf("   ��> 6�� ��ѯѧ����Ϣ *\n");
	printf("   ��> 7�� �޸�ѧ����Ϣ *\n");
	printf("   ��> 8�� ɾ��ѧ����Ϣ *\n");
	printf("   ��> 0�� �˳�ѧ��ϵͳ *\n");
	printf("******************************\n");
	printf("����> ��ѡ�����<0-8> \n");

}


void InputStuInfo(void)
{


	char inName[100];
	char inID[100];
	char inSocWok[100];
	float inAcaRec;
	int inQOPaper;
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%s", inID);
	printf("������ѧ��������\n");
	scanf("%s", inName);
	printf("�������ѧ��ѧҵ�ɼ���\n");
	scanf("%f", &inAcaRec);	
	printf("�������ѧ��������������\n");
	scanf("%d", &inQOPaper);
	printf("�������ѧ����ѧ��������\n");
	scanf("%s", inSocWok);	

	//Ҫ��ѧ�Ų����ظ���������������������ͬ��ѧ�ţ�Ӧ���������źţ�����������
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (strcmp(p->StuInfo.StuID, inID) == 0) {
			printf("��ѧ���Ѵ��ڣ������ԣ�");
			return;
		}
		p = p->pNext;

	}
	if (p == NULL) {
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;

		//ͷ�巨
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
	

	printf("ѧ����Ϣ¼�����\n");
	system("pause");
	system("cls");


}



void PrintfStuInfo(void)
{
	//ѧ�� ���� ѧϰ�ɼ����� �������� ��Ṥ�� �ܷ�
	printf("* ѧ�� *\t");
	printf("* ���� *\t");
	printf("* ѧϰ�ɼ����� *\t");
	printf("* �������� *\t");
	printf("* ��Ṥ�� *\t");
	printf("* �ܷ� *\t\n");

	//��������
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

//ð������
void SortFunction(void) //12.3��־��Ŀǰ����֪���ܲ�����
{
	Node* p = g_pHead;
	if (p == NULL || p->pNext == NULL) {
		return;
	}
	while (p != NULL)
	{
		if (p->pNext != NULL) {
			if (p->StuInfo.Total_Score > p->pNext->StuInfo.Total_Score) {//���ڽڵ�Ƚϣ����ݽ���
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


//�޸���Ϣ�������������  12.5  15:33
void ModifyStuInfo(void)
{
	char sfStuID[100];
	printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
	scanf("%s", sfStuID);
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (strcmp(p->StuInfo.StuID, sfStuID) == 0) {
			printf("���ҵ���ѧ�����ٴ�ȷ���Ƿ���Ҫ�޸ģ������� 7 ȷ���޸ģ�\n");
			char ch = _getch();
			if (ch != '7') { return; } //����дreturn����break�ĸ������أ�
			//������������� ѡ���޸�
			printf("������Ҫ�޸ĵ���Ϣ: ���� ѧϰ�ɼ����� �������� ��Ṥ�����ո��������\n");
			scanf("%s %f %d %s",p->StuInfo.name, &p->StuInfo.Academic_Record, &p->StuInfo.QuantityOfPaper, p->StuInfo.SocialWork);
			printf("�޸ĳɹ���\n");
			system("pause");
			break;
		}
		p = p->pNext;

	}
	if (p == NULL)
	{
		printf("δ�ҵ���ѧ���������� \n");

	}

}



void DelStuInfo(void)
{
	char fStuID[100];
	printf("������Ҫɾ����ѧ����ѧ�ţ�\n");
	scanf("%s", &fStuID);
	Node* p1, * p2;
	
	//�ж��Ƿ�Ϊͷ�ڵ� StuInfo
	if (strcmp(g_pHead->StuInfo.StuID , fStuID) == 0) {
		printf("���ҵ���ѧ�����ٴ�ȷ���Ƿ�ɾ���޸ģ������� 8 ȷ���޸ģ�\n");
		char ch = _getch();
		if (ch != '8') { return; }
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		printf("ɾ���ɹ���\n");
		free(p1);
		system("pause");
		system("cls");
		return;

	}

	//��ͷ�ڵ�
	Node* p = g_pHead;
	while (p->pNext != NULL)
	{
		if (strcmp(p->pNext->StuInfo.StuID, fStuID) == 0 && p->pNext != NULL) {
			printf("���ҵ���ѧ�����ٴ�ȷ���Ƿ�ɾ���޸ģ������� 8 ȷ���޸ģ�\n");
			char ch = _getch();
			if (ch != '8') { return; }
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			printf("ɾ���ɹ���\n");
			free(p2);
			system("pause");
			system("cls");
			return;

		}
		
		//p = p->pNext;
		if (p->pNext->pNext == NULL && strcmp(p->pNext->StuInfo.StuID, fStuID) == 0) //֤��������ĵ����ڶ�������ָ�����һ����p->Next ΪNULL
		{
			printf("���ҵ���ѧ�����ٴ�ȷ���Ƿ�ɾ���޸ģ������� 8 ȷ���޸ģ�\n");
			char ch = _getch();
			if (ch != '8') { return; }
			p2 = p->pNext;
			p->pNext = NULL;
			printf("ɾ���ɹ���\n");
			free(p2);			
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;

	}

	printf("δ�ҵ���ѧ����Ϣ��\n");
	

	system("pause");
	system("cls");
}


void SaveStuInfo(void)
{
	//�ļ���д����
	FILE* fp = fopen("D:\\StudentScholarshipEval_System.data", "w");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ� \n");
		return;

	}
	//��������д��
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->StuInfo, 1, sizeof(Student_info), fp);
		p = p->pNext;

	}
	fclose(fp);

	printf("�������ݳɹ���\n");
	system("pause");
	system("cls");
}


/*
12.4�޸���־��
	- ����� �� ����������������������������������������������?       ��BUG
	���������
	- ��ͨ������һ������ṹ��stu��Ŷ�ȡ��
	- ��ͨ��memcpy���Ƶ�ԭ������

*/
void ReadStuInfo(void)
{
	FILE* fp = fopen("D:\\StudentScholarshipEval_System.data", "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ� \n");
		system("pause");
		return;
	}

	Student_info stu;

	while (fread(&stu, 1, sizeof(Student_info), fp))
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student_info));

		//ͷ�巨
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
	printf("�������ݳɹ��� \n");
	system("pause");
	system("cls");
}


void LookUpStuInfo(void)
{
	Node* p = g_pHead;
	printf("��ѡ���ѯ��ʽ��\n->1����ѧ�Ų�ѯ \n->2����������ѯ \n->3���ܷ������ѯ\n");
	char ch = _getch();
	switch (ch)
	{
	case '1':
	{
		printf("������Ҫ���ҵ�ѧ��ѧ�ţ�\n");
		char sfStuID[100];
		scanf("%s", sfStuID);

		while (p != NULL)
		{
			if (strcmp(p->StuInfo.StuID, sfStuID) == 0) {
				printf("* ѧ�� *\t");
				printf("* ���� *\t");
				printf("* ѧϰ�ɼ����� *\t");
				printf("* �������� *\t");
				printf("* ��Ṥ�� *\t");
				printf("* �ܷ� *\t\n");
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
			printf("δ�ҵ���ѧ���������� \n");
		}

		break;
	}
	case '2':
	{
		printf("������Ҫ���ҵ�ѧ��������\n");
		char fname[100];
		scanf("%s", fname);

		while (p != NULL)
		{
			if (strcmp(p->StuInfo.name, fname) == 0) {
				printf("* ѧ�� *\t");
				printf("* ���� *\t");
				printf("* ѧϰ�ɼ����� *\t");
				printf("* �������� *\t");
				printf("* ��Ṥ�� *\t");
				printf("* �ܷ� *\t\n");
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
			printf("δ�ҵ���ѧ���������� \n");
		}
		break;
	}
	case '3':
	{
		printf("������Ҫ���ҵ��ܷ����䣨��xx��xx�ķ������䣬�ÿո��������\n");
		float f1score, f2score;
		scanf("%f %f", &f1score, &f2score);
		int cnt = 0;
		while (p != NULL)
		{
			if (p->StuInfo.Total_Score >= f1score && p->StuInfo.Total_Score <= f2score) {
				printf("* ѧ�� *\t");
				printf("* ���� *\t");
				printf("* ѧϰ�ɼ����� *\t");
				printf("* �������� *\t");
				printf("* ��Ṥ�� *\t");
				printf("* �ܷ� *\t\n");
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
			printf("δ�ҵ�����������ѧ���������� \n");
		}
		break;
	}
	default:
	{
		printf("���������ԣ�\n");
		break;
	}
	}
	system("pause");
	system("cls");
}


//�����֣�ѧϰ�ɼ�����*30%+ѧ���ɹ��Ʒ�*60%+��Ṥ���Ʒ�*10%  
//������������
void CalcuScore(Node *p)
{
	int scoAcaRec = 0;
	int scoPaper = 0;
	int scoSocWok = 0;
	if (p->StuInfo.Academic_Record == 4.0) { scoAcaRec = 100; }
	if (p->StuInfo.Academic_Record > 3.7 && p->StuInfo.Academic_Record < 4.0) { scoAcaRec = 80; }
	if (p->StuInfo.Academic_Record > 3.3 && p->StuInfo.Academic_Record < 3.7) { scoAcaRec = 70; }
	if (p->StuInfo.Academic_Record > 2.7 && p->StuInfo.Academic_Record < 3.3) { scoAcaRec = 50; }
	if (p->StuInfo.Academic_Record < 2.7) { scoAcaRec = 0; } // ??????���ﲻ̫���

	if (p->StuInfo.QuantityOfPaper > 5) { scoPaper = 100; }
	if (p->StuInfo.QuantityOfPaper <= 5 && p->StuInfo.QuantityOfPaper >= 3) { scoPaper = 80; }
	if (p->StuInfo.QuantityOfPaper < 3 && p->StuInfo.QuantityOfPaper >= 2) { scoPaper = 70; }
	if (p->StuInfo.QuantityOfPaper == 1) { scoPaper = 50; }
	if (p->StuInfo.QuantityOfPaper == 0) { scoPaper = 0; }// ??????���ﲻ̫���

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


int TotalStu(void) //����������
{
	int nCount = 0;

	//����
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;

	}
	return nCount;


}







/*
��Ҫ�������ṩ��������ʽ���簴ѧ�����򡢰��������򡢰��ܷ�����ȡ���
*/

//���������������
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
	printf("* ѧ�� *\t");
	printf("* ���� *\t");
	printf("* ѧϰ�ɼ����� *\t");
	printf("* �������� *\t");
	printf("* ��Ṥ�� *\t");
	printf("* �ܷ� *\t\n");
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
	printf("* ѧ�� *\t");
	printf("* ���� *\t");
	printf("* ѧϰ�ɼ����� *\t");
	printf("* �������� *\t");
	printf("* ��Ṥ�� *\t");
	printf("* �ܷ� *\t\n");
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
	printf("* ѧ�� *\t");
	printf("* ���� *\t");
	printf("* ѧϰ�ɼ����� *\t");
	printf("* �������� *\t");
	printf("* ��Ṥ�� *\t");
	printf("* �ܷ� *\t\n");
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
	printf("* ѧ�� *\t");
	printf("* ���� *\t");
	printf("* ѧϰ�ɼ����� *\t");
	printf("* �������� *\t");
	printf("* ��Ṥ�� *\t");
	printf("* �ܷ� *\t\n");
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
	printf("* ѧ�� *\t");
	printf("* ���� *\t");
	printf("* ѧϰ�ɼ����� *\t");
	printf("* �������� *\t");
	printf("* ��Ṥ�� *\t");
	printf("* �ܷ� *\t\n");
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

















