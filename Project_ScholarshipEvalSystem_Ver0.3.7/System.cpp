#include "fScholarshipEval.h"
#pragma warning(disable:4996) //½â¾öC6031ÎÊÌâµÄ´úÂë


int main(void)
{
	for (;;) //ÈÎÎñÔËÐÐ
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
			printf("ÇëÑ¡ÔñÑ§ÉúÐÅÏ¢ÅÅÐò·½Ê½£º\n");
			printf("1:°´Ñ§ºÅÅÅÐò\n2:°´ÐÕÃûÅÅÐò(ÓÉA-Z)\n3:°´×Ü·ÖÅÅÐò(½µÐò)\n4:°´Ñ§Ï°³É¼¨ÅÅÐò(½µÐò)\n5:°´ÂÛÎÄÊýÁ¿(½µÐò)\n");
			char ch3 = _getch();
			switch (ch3)
			{
			case '1':
				printf("°´Ñ§ºÅÅÅÐò£º\n");
				RankStuID();
				PrintfStuWithRankID(TotalStuNums);
				break;
			case '2':
				printf("°´ÐÕÃûÅÅÐò(ÓÉA-Z)£º\n");
				RankStuName();
				PrintfStuWithRankName(TotalStuNums);
				break;
			case '3':
				printf("°´×Ü·ÖÅÅÐò(½µÐò)£º\n");
				RankStuScore();
				PrintfStuWithRANK(TotalStuNums);
				break;
			case '4':
				printf("°´Ñ§Ï°³É¼¨ÅÅÐò(½µÐò)\n");
				RankAcaRec();
				PrintfStuWithRankAcaRec(TotalStuNums);
				break;
			case '5':
				printf("°´ÂÛÎÄÊýÁ¿(½µÐò)\n");
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
			//ÍË³öÏµÍ³£ºÍË³öÏµÍ³Ö®Ç°£¬ÒªÔÙ´ÎÈ·ÈÏ¡£
			printf("ÊÇ·ñÒªÍË³öÏµÍ³£¿£¨ÊäÈë1È·ÈÏ£©\n");
			char ch1 = _getch();
			if (ch1 == '1') { 
				printf("\n/********¸ÐÐ»Ê¹ÓÃ±¾ÏµÍ³********/\n/*×÷Õß£ºCSU- orlenHJ *\n/******************************/\n");
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
	printf("* »¶Ó­Ê¹ÓÃÑ§Éú½±Ñ§½ðÆÀ¶¨ÏµÍ³ *\n");
	printf("******************************\n");
	printf("   ¡ª> 1£º ÊäÈëÑ§ÉúÐÅÏ¢ *\n");
	printf("   ¡ª> 2£º ´òÓ¡²¢Í³¼ÆÑ§ÉúÐÅÏ¢ *\n");
	printf("   ¡ª> 3£º ÅÅÐòÑ§ÉúÐÅÏ¢ *\n");
	printf("   ¡ª> 4£º ±£´æµ½Ñ§ÉúÐÅÏ¢ÎÄ¼þ *\n");
	printf("   ¡ª> 5£º ¶ÁÈ¡Ñ§ÉúÐÅÏ¢ÎÄ¼þ *\n");
	printf("   ¡ª> 6£º ²éÑ¯Ñ§ÉúÐÅÏ¢ *\n");
	printf("   ¡ª> 7£º ÐÞ¸ÄÑ§ÉúÐÅÏ¢ *\n");
	printf("   ¡ª> 8£º É¾³ýÑ§ÉúÐÅÏ¢ *\n");
	printf("   ¡ª> 0£º ÍË³öÑ§ÉúÏµÍ³ *\n");
	printf("******************************\n");
	printf("¡ª¡ª> ÇëÑ¡Ôñ²Ù×÷<0-8> \n");

}


void InputStuInfo(void)
{


	char inName[100];
	char inID[100];
	char inSocWok[100];
	float inAcaRec;
	int inQOPaper;
	printf("ÇëÊäÈëÑ§ÉúÑ§ºÅ£º\n");
	scanf("%s", inID);
	printf("ÇëÊäÈëÑ§ÉúÐÕÃû£º\n");
	scanf("%s", inName);
	printf("ÇëÊäÈë¸ÃÑ§ÉúÑ§Òµ³É¼¨£º\n");
	scanf("%f", &inAcaRec);	
	printf("ÇëÊäÈë¸ÃÑ§ÉúµÄÂÛÎÄÊýÁ¿£º\n");
	scanf("%d", &inQOPaper);
	printf("ÇëÊäÈë¸ÃÑ§ÉúµÄÑ§Éú¹¤×÷£º\n");
	scanf("%s", inSocWok);	

	//ÒªÇóÑ§ºÅ²»ÄÜÖØ¸´£¬ÊäÈë¹ý³ÌÖÐÈç¹û³öÏÖÏàÍ¬µÄÑ§ºÅ£¬Ó¦¸ø³ö±¨´íÐÅºÅ£¬²¢ÖØÐÂÊäÈë
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (strcmp(p->StuInfo.StuID, inID) == 0) {
			printf("¸ÃÑ§ºÅÒÑ´æÔÚ£¬ÇëÖØÊÔ£¡");
			return;
		}
		p = p->pNext;

	}
	if (p == NULL) {
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;

		//Í·²å·¨
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
	

	printf("Ñ§ÉúÐÅÏ¢Â¼ÈëÍê³É\n");
	system("pause");
	system("cls");


}



void PrintfStuInfo(void)
{
	//Ñ§ºÅ ÐÕÃû Ñ§Ï°³É¼¨¼¨µã ÂÛÎÄÊýÁ¿ Éç»á¹¤×÷ ×Ü·Ö
	printf("* Ñ§ºÅ *\t");
	printf("* ÐÕÃû *\t");
	printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
	printf("* ÂÛÎÄÊýÁ¿ *\t");
	printf("* Éç»á¹¤×÷ *\t");
	printf("* ×Ü·Ö *\t\n");

	//±éÀúÁ´±í
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

//Ã°ÅÝÅÅÐò
void SortFunction(void) //12.3ÈÕÖ¾£ºÄ¿Ç°»¹²»ÖªµÀÄÜ²»ÄÜÓÃ
{
	Node* p = g_pHead;
	if (p == NULL || p->pNext == NULL) {
		return;
	}
	while (p != NULL)
	{
		if (p->pNext != NULL) {
			if (p->StuInfo.Total_Score > p->pNext->StuInfo.Total_Score) {//ÏàÁÚ½Úµã±È½Ï£¬Êý¾Ý½»»»
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


//ÐÞ¸ÄÐÅÏ¢ÕâÀï¿ÉÒÔÔÙÍêÉÆ  12.5  15:33
void ModifyStuInfo(void)
{
	char sfStuID[100];
	printf("ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúÑ§ºÅ£º\n");
	scanf("%s", sfStuID);
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (strcmp(p->StuInfo.StuID, sfStuID) == 0) {
			printf("ÒÑÕÒµ½¸ÃÑ§Éú£¬ÔÙ´ÎÈ·ÈÏÊÇ·ñÐèÒªÐÞ¸Ä£¿£¨ÊäÈë 7 È·ÈÏÐÞ¸Ä£©\n");
			char ch = _getch();
			if (ch != '7') { return; } //ÕâÀïÐ´return»¹ÊÇbreakÄÄ¸ö¸üºÃÄØ£¿
			//ÕâÀï¿ÉÒÔÔÙÍêÉÆ Ñ¡ÔñÐÞ¸Ä
			printf("ÇëÊäÈëÒªÐÞ¸ÄµÄÐÅÏ¢: ÐÕÃû Ñ§Ï°³É¼¨¼¨µã ÂÛÎÄÊýÁ¿ Éç»á¹¤×÷£¨¿Õ¸ñ¸ô¿ª£©£º\n");
			scanf("%s %f %d %s",p->StuInfo.name, &p->StuInfo.Academic_Record, &p->StuInfo.QuantityOfPaper, p->StuInfo.SocialWork);
			printf("ÐÞ¸Ä³É¹¦£¡\n");
			system("pause");
			break;
		}
		p = p->pNext;

	}
	if (p == NULL)
	{
		printf("Î´ÕÒµ½¸ÃÑ§Éú£¡ÇëÖØÊÔ \n");

	}

}



void DelStuInfo(void)
{
	char fStuID[100];
	printf("ÇëÊäÈëÒªÉ¾³ýµÄÑ§ÉúµÄÑ§ºÅ£º\n");
	scanf("%s", &fStuID);
	Node* p1, * p2;
	
	//ÅÐ¶ÏÊÇ·ñÎªÍ·½Úµã StuInfo
	if (strcmp(g_pHead->StuInfo.StuID , fStuID) == 0) {
		printf("ÒÑÕÒµ½¸ÃÑ§Éú£¬ÔÙ´ÎÈ·ÈÏÊÇ·ñÉ¾³ýÐÞ¸Ä£¿£¨ÊäÈë 8 È·ÈÏÐÞ¸Ä£©\n");
		char ch = _getch();
		if (ch != '8') { return; }
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		printf("É¾³ý³É¹¦£¡\n");
		free(p1);
		system("pause");
		system("cls");
		return;

	}

	//·ÇÍ·½Úµã
	Node* p = g_pHead;
	while (p->pNext != NULL)
	{
		if (strcmp(p->pNext->StuInfo.StuID, fStuID) == 0 && p->pNext != NULL) {
			printf("ÒÑÕÒµ½¸ÃÑ§Éú£¬ÔÙ´ÎÈ·ÈÏÊÇ·ñÉ¾³ýÐÞ¸Ä£¿£¨ÊäÈë 8 È·ÈÏÐÞ¸Ä£©\n");
			char ch = _getch();
			if (ch != '8') { return; }
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			printf("É¾³ý³É¹¦£¡\n");
			free(p2);
			system("pause");
			system("cls");
			return;

		}
		
		//p = p->pNext;
		if (p->pNext->pNext == NULL && strcmp(p->pNext->StuInfo.StuID, fStuID) == 0) //Ö¤Ã÷ÊÇÁ´±íµÄµ¹ÊýµÚ¶þ¸ö£¬½«Ö¸Ïò×îºóÒ»¸öµÄp->Next ÎªNULL
		{
			printf("ÒÑÕÒµ½¸ÃÑ§Éú£¬ÔÙ´ÎÈ·ÈÏÊÇ·ñÉ¾³ýÐÞ¸Ä£¿£¨ÊäÈë 8 È·ÈÏÐÞ¸Ä£©\n");
			char ch = _getch();
			if (ch != '8') { return; }
			p2 = p->pNext;
			p->pNext = NULL;
			printf("É¾³ý³É¹¦£¡\n");
			free(p2);			
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;

	}

	printf("Î´ÕÒµ½¸ÃÑ§ÉúÐÅÏ¢£¡\n");
	

	system("pause");
	system("cls");
}


void SaveStuInfo(void)
{
	//ÎÄ¼þ¶ÁÐ´²Ù×÷
	FILE* fp = fopen("D:\\StudentScholarshipEval_System.data", "w");
	if (fp == NULL)
	{
		printf("´ò¿ªÎÄ¼þÊ§°Ü£¡ \n");
		return;

	}
	//±éÀúÁ´±íÐ´Èë
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->StuInfo, 1, sizeof(Student_info), fp);
		p = p->pNext;

	}
	fclose(fp);

	printf("±£´æÊý¾Ý³É¹¦£¡\n");
	system("pause");
	system("cls");
}


/*
12.4ÐÞ¸ÄÈÕÖ¾£º
	- »á³öÏÖ £º ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ?       µÄBUG
	½â¾ö·½·¨£º
	- ±ãÍ¨¹ý½¨Á¢Ò»¸ö»º´æ½á¹¹Ìåstu´æ·Å¶ÁÈ¡Á÷
	- ÔÙÍ¨¹ýmemcpy¸´ÖÆµ½Ô­Á´±íÉÏ

*/
void ReadStuInfo(void)
{
	FILE* fp = fopen("D:\\StudentScholarshipEval_System.data", "r");
	if (fp == NULL)
	{
		printf("´ò¿ªÎÄ¼þÊ§°Ü£¡ \n");
		system("pause");
		return;
	}

	Student_info stu;

	while (fread(&stu, 1, sizeof(Student_info), fp))
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student_info));

		//Í·²å·¨
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
	printf("¼ÓÔØÊý¾Ý³É¹¦£¡ \n");
	system("pause");
	system("cls");
}


void LookUpStuInfo(void)
{
	Node* p = g_pHead;
	printf("ÇëÑ¡Ôñ²éÑ¯·½Ê½£º\n->1£º°´Ñ§ºÅ²éÑ¯ \n->2£º°´ÐÕÃû²éÑ¯ \n->3£º×Ü·ÖÇø¼ä²éÑ¯\n");
	char ch = _getch();
	switch (ch)
	{
	case '1':
	{
		printf("ÇëÊäÈëÒª²éÕÒµÄÑ§ÉúÑ§ºÅ£º\n");
		char sfStuID[100];
		scanf("%s", sfStuID);

		while (p != NULL)
		{
			if (strcmp(p->StuInfo.StuID, sfStuID) == 0) {
				printf("* Ñ§ºÅ *\t");
				printf("* ÐÕÃû *\t");
				printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
				printf("* ÂÛÎÄÊýÁ¿ *\t");
				printf("* Éç»á¹¤×÷ *\t");
				printf("* ×Ü·Ö *\t\n");
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
			printf("Î´ÕÒµ½¸ÃÑ§Éú£¡ÇëÖØÊÔ \n");
		}

		break;
	}
	case '2':
	{
		printf("ÇëÊäÈëÒª²éÕÒµÄÑ§ÉúÐÕÃû£º\n");
		char fname[100];
		scanf("%s", fname);

		while (p != NULL)
		{
			if (strcmp(p->StuInfo.name, fname) == 0) {
				printf("* Ñ§ºÅ *\t");
				printf("* ÐÕÃû *\t");
				printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
				printf("* ÂÛÎÄÊýÁ¿ *\t");
				printf("* Éç»á¹¤×÷ *\t");
				printf("* ×Ü·Ö *\t\n");
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
			printf("Î´ÕÒµ½¸ÃÑ§Éú£¡ÇëÖØÊÔ \n");
		}
		break;
	}
	case '3':
	{
		printf("ÇëÊäÈëÒª²éÕÒµÄ×Ü·ÖÇø¼ä£¨´Óxxµ½xxµÄ·ÖÊýÇø¼ä£¬ÓÃ¿Õ¸ñ¸ô¿ª£©£º\n");
		float f1score, f2score;
		scanf("%f %f", &f1score, &f2score);
		int cnt = 0;
		while (p != NULL)
		{
			if (p->StuInfo.Total_Score >= f1score && p->StuInfo.Total_Score <= f2score) {
				printf("* Ñ§ºÅ *\t");
				printf("* ÐÕÃû *\t");
				printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
				printf("* ÂÛÎÄÊýÁ¿ *\t");
				printf("* Éç»á¹¤×÷ *\t");
				printf("* ×Ü·Ö *\t\n");
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
			printf("Î´ÕÒµ½·ûºÏÌõ¼þµÄÑ§Éú£¡ÇëÖØÊÔ \n");
		}
		break;
	}
	default:
	{
		printf("´íÎó£¡ÇëÖØÊÔ£¡\n");
		break;
	}
	}
	system("pause");
	system("cls");
}


//×ÜÆÀ·Ö£ºÑ§Ï°³É¼¨¼¨µã*30%+Ñ§Êõ³É¹û¼Æ·Ö*60%+Éç»á¹¤×÷¼Æ·Ö*10%  
//ÕâÀïÈÔÓÐÒÉÎÊ
void CalcuScore(Node *p)
{
	int scoAcaRec = 0;
	int scoPaper = 0;
	int scoSocWok = 0;
	if (p->StuInfo.Academic_Record == 4.0) { scoAcaRec = 100; }
	if (p->StuInfo.Academic_Record > 3.7 && p->StuInfo.Academic_Record < 4.0) { scoAcaRec = 80; }
	if (p->StuInfo.Academic_Record > 3.3 && p->StuInfo.Academic_Record < 3.7) { scoAcaRec = 70; }
	if (p->StuInfo.Academic_Record > 2.7 && p->StuInfo.Academic_Record < 3.3) { scoAcaRec = 50; }
	if (p->StuInfo.Academic_Record < 2.7) { scoAcaRec = 0; } // ??????ÕâÀï²»Ì«Çå³þ

	if (p->StuInfo.QuantityOfPaper > 5) { scoPaper = 100; }
	if (p->StuInfo.QuantityOfPaper <= 5 && p->StuInfo.QuantityOfPaper >= 3) { scoPaper = 80; }
	if (p->StuInfo.QuantityOfPaper < 3 && p->StuInfo.QuantityOfPaper >= 2) { scoPaper = 70; }
	if (p->StuInfo.QuantityOfPaper == 1) { scoPaper = 50; }
	if (p->StuInfo.QuantityOfPaper == 0) { scoPaper = 0; }// ??????ÕâÀï²»Ì«Çå³þ

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


int TotalStu(void) //¼ÆËã×ÜÈËÊý
{
	int nCount = 0;

	//±éÀú
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;

	}
	return nCount;


}







/*
£¨ÒªÇó£ºÖÁÉÙÌá¹©ÈýÖÖÅÅÐò·½Ê½£¬Èç°´Ñ§ºÅÅÅÐò¡¢°´ÐÕÃûÅÅÐò¡¢°´×Ü·ÖÅÅÐòµÈ¡££©
*/

//±éÀúÁ´±í¼ÆËãÅÅÃû
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
	printf("* Ñ§ºÅ *\t");
	printf("* ÐÕÃû *\t");
	printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
	printf("* ÂÛÎÄÊýÁ¿ *\t");
	printf("* Éç»á¹¤×÷ *\t");
	printf("* ×Ü·Ö *\t\n");
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
	printf("* Ñ§ºÅ *\t");
	printf("* ÐÕÃû *\t");
	printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
	printf("* ÂÛÎÄÊýÁ¿ *\t");
	printf("* Éç»á¹¤×÷ *\t");
	printf("* ×Ü·Ö *\t\n");
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
	printf("* Ñ§ºÅ *\t");
	printf("* ÐÕÃû *\t");
	printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
	printf("* ÂÛÎÄÊýÁ¿ *\t");
	printf("* Éç»á¹¤×÷ *\t");
	printf("* ×Ü·Ö *\t\n");
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
	printf("* Ñ§ºÅ *\t");
	printf("* ÐÕÃû *\t");
	printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
	printf("* ÂÛÎÄÊýÁ¿ *\t");
	printf("* Éç»á¹¤×÷ *\t");
	printf("* ×Ü·Ö *\t\n");
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
	printf("* Ñ§ºÅ *\t");
	printf("* ÐÕÃû *\t");
	printf("* Ñ§Ï°³É¼¨¼¨µã *\t");
	printf("* ÂÛÎÄÊýÁ¿ *\t");
	printf("* Éç»á¹¤×÷ *\t");
	printf("* ×Ü·Ö *\t\n");
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

















