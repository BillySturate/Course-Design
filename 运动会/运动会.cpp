#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
#include <graphics.h>
#include <windows.h>
#include<math.h>
#include <process.h>


#include <stdio.h>
#include <string.h>
#define N 20          //ѧУ�����Ŀ
#define M 20          //������Ŀ�����Ŀ
#define W 20          //Ů����Ŀ�����Ŀ

typedef struct
{
	char name[20];//��Ŀ����
	int inum;       //��Ŀ���
	int top;           //ȡ���ε���Ŀ
	int mark[5];       //ѧУ�ı��
	int score[5];	//�����Ŀ��Ϣ,����/
}SPORT;
typedef struct
{
	char name[20];//ѧУ����
	int snum;     //ѧУ���/
	int score;         //ѧУ�ܷ�/
	int mscore;        //�������ܷ�/
	int wscore;        //Ů�����ܷ�/  
}SCHOOL;             //���ѧУ��Ϣ
int number;
int one() {
	int v = 0;
	initgraph(580, 480);
	setbkcolor(YELLOW);
	cleardevice();
	//����������ɫ ���в�����ʾ����
	settextcolor(RED);
	settextstyle(25, 0, "����");
	outtextxy(150, 50, "��ѡ�񰴺��ַ�ʽ�����������");
	outtextxy(150, 100, "1 ѧУ�ı��");
	outtextxy(150, 150, "2 �ܷ�");
	outtextxy(150, 200, "3 ������Ŀ�ܷ�");
	outtextxy(150, 250, "4 Ů����Ŀ�ܷ�");
	outtextxy(150, 300, "0 �����׽���");
	outtextxy(150, 350, "��������ʹ�õĹ���:");
	string str1, str2;   //ͷ�ļ� string 
	char c;  //�����ַ�c���ռ�������
	while (v != 2) {
		c = _getch();
		if (c == '\b')  //���c���˸����str1ɾ��һ��
		{
			v--;
			if (v < 2)
				str1 = str1.substr(0, str1.size() - 1);
		}
		else {
			if (c != ' ')
				v++;
			if (v <= 1) {

				str1 += (int)c;

			}

		}
		str2 = "��������ʹ�õĹ���:" + str1;
		cleardevice();
		outtextxy(150, 50, "��ѡ�񰴺��ַ�ʽ�����������");
		outtextxy(150, 100, "1 ѧУ�ı��");
		outtextxy(150, 150, "2 �ܷ�");
		outtextxy(150, 200, "3 ������Ŀ�ܷ�");
		outtextxy(150, 250, "4 Ů����Ŀ�ܷ�");
		outtextxy(150, 300, "0 �����׽���");
		outtextxy(150, 350, str2.c_str());
		if (v == 1) {
			v++;
			_getch();
		}
	}closegraph();
	return c - 48;
}
int two() {
	int v = 0;
	initgraph(580, 480);
	setbkcolor(YELLOW);
	cleardevice();
	//����������ɫ ���в�����ʾ����
	settextcolor(RED);
	settextstyle(25, 0, "����");
	outtextxy(150, 50, "��ѡ���ѯ��ʽ");
	outtextxy(150, 100, "1 ��ѯĳ��ѧУ��ĳ����Ŀ�����");
	outtextxy(150, 150, "2 ��ѯĳ����Ŀ��ѧУ�������");
	outtextxy(150, 200, "0 �����׽���");
	outtextxy(150, 250, "��������ʹ�õĹ���:");
	string str1, str2;   //ͷ�ļ� string 
	char c;  //�����ַ�c���ռ�������
	while (v != 2) {
		c = _getch();
		if (c == '\b')  //���c���˸����str1ɾ��һ��
		{
			v--;
			if (v < 2)
				str1 = str1.substr(0, str1.size() - 1);
		}
		else {
			if (c != ' ')
				v++;
			if (v <= 1) {

				str1 += (int)c;

			}

		}
		str2 = "��������ʹ�õĹ���:" + str1;
		cleardevice();
		outtextxy(150, 50, "��ѡ���ѯ��ʽ");
		outtextxy(150, 100, "1 ��ѯĳ��ѧУ��ĳ����Ŀ�����");
		outtextxy(150, 150, "2 ��ѯĳ����Ŀ��ѧУ�������");
		outtextxy(150, 200, "0 �����׽���");
		outtextxy(150, 250, str2.c_str());
		if (v == 1) {
			v++;
			_getch();
		}
	}closegraph();
	return c - 48;
}
void luru(SCHOOL school[], SPORT sport[], int total[])
{
	system("color 70");
	system("cls");
	int  mannum, womannum;
	int count = 1;
	int i, j, d;
	printf("�������ж���ѧУ����:");
	scanf("%d", &number);
	for (i = 1; i <= number; i++)
	{
		printf("�������%d��ѧУ������:", i);
		scanf("%s", &school[i].name);
		school[i].snum = i;
	}

	printf("�������ж���������Ŀ:");
	scanf("%d", &mannum);
	printf("�������ж���Ů����Ŀ:");
	scanf("%d", &womannum);
	total[1] = mannum;
	total[2] = womannum;
	total[3] = mannum + womannum;
	total[4] = number;
	for (i = 1; i <= mannum; i++)
	{
		printf("�������%d��������Ŀ������:", i);
		scanf("%s", &sport[i].name);
		sport[i].inum = i;
	}
	for (i = 1 + mannum; i <= mannum + womannum; i++)
	{
		printf("�������%d��Ů����Ŀ������:", count);
		scanf("%s", &sport[i].name);
		sport[i].inum = i;
		count++;
	}
	for (i = 1; i <= mannum + womannum; i++)
	{
		system("cls");
		printf("��%d����Ŀ������Ϊ:%s     ���Ϊ:%d\n", i, sport[i].name, sport[i].inum);

		printf("��%d����Ŀ��ȡǰ����(��3)����ǰ����(��5):", i);
		scanf("%d", &sport[i].top);
		if (sport[i].top == 3) {
			printf("������ǰ�����ĳɼ�\n");
			for (int j = 1; j <= 3; j++)
			{
				printf("��%d���ĳɼ�Ϊ:", j);
				scanf("%d", &sport[i].score[j]);
				printf("�������%d����ѧУ���:", j);
				scanf("%d", &sport[i].mark[j]);
			}
		}
		if (sport[i].top == 5) {
			printf("������ǰ�����ĳɼ�\n");
			for (int j = 1; j <= 5; j++)
			{
				printf("��%d���ĳɼ�Ϊ:", j);
				scanf("%d", &sport[i].score[j]);
				printf("�������%d����ѧУ���:", j);
				scanf("%d", &sport[i].mark[j]);
			}
		}
	}
	printf("¼��ɹ�,������һ�����ַ����׽���:"); scanf("%d", &d);
}
void tongji(SCHOOL school[], SPORT sport[], int total[])
{
	system("color 70");
	system("cls");
	int score1[6] = { 0,7,5,3,2,1 };
	int score2[4] = { 0,5,3,2 };
	int summan = 0;
	int sumwoman = 0;
	int i, j, d;
	int score_m[N] = { 0 };		//���������Ŀ�ĸ���ѧУ�ķ���
	int score_w[N] = { 0 };		//���Ů����Ŀ�ĸ���ѧУ�ķ���
	int score_total[N] = { 0 };
	for (i = 1; i <= total[1]; i++)			//ͳ��������Ŀ����ѧУ�ķ���
	{
		if (sport[i].top == 3)
		{
			for (j = 1; j <= 3; j++)
			{
				score_m[sport[i].mark[j]] += score2[j];
			}
		}
		if (sport[i].top == 5)
		{
			for (j = 1; j <= 5; j++)
			{
				score_m[sport[i].mark[j]] += score1[j];
			}
		}
	}
	for (i = 1 + total[1]; i <= total[3]; i++)		//ͳ��Ů����Ŀ������Ŀ�ķ���
	{
		if (sport[i].top == 3)
		{
			for (j = 1; j <= 3; j++)
			{
				score_w[sport[i].mark[j]] += score2[j];
			}
		}
		if (sport[i].top == 5)
		{
			for (j = 1; j <= 5; j++)
			{
				score_w[sport[i].mark[j]] += score1[j];
			}
		}
	}
	for (i = 1; i <= total[4]; i++)
	{
		score_total[i] = score_m[i] + score_w[i];
	}
	for (i = 1; i <= total[4]; i++)
	{
		school[i].score = score_total[i];
		school[i].mscore = score_m[i];
		school[i].wscore = score_w[i];
	}
	printf("ͳ�Ƴɹ�,������һ�����ַ����׽���:"); scanf("%d", &d);


}
void show(SCHOOL school[], SPORT sport[], int total[])
{
	system("color 70");
	system("cls");
	int i, j, temp, d;
	SCHOOL school2[N];			//��Ÿ���ѧУ������Ŀ�ķ��������Ľ��
	SCHOOL school3[N];			//��Ÿ���ѧУŮ����Ŀ�ķ��������Ľ��
	SCHOOL school4[N];			//��Ÿ���ѧУ�ܷ��������Ľ��
	SCHOOL school_test[N];
	for (i = 1; i <= total[4]; i++)
	{
		school2[i] = school[i];
		school3[i] = school[i];
		school4[i] = school[i];
	}
	for (i = 1; i <= total[4]; i++)
	{
		for (j = 1; j <= total[4] - i; j++)				//�Ը���ѧУ������Ŀ���ֽܷ�������
		{
			if (school2[i].mscore < school2[i + 1].mscore)
			{
				school_test[i] = school2[i];
				school2[i] = school2[i + 1];
				school2[i + 1] = school_test[i];
			}
			if (school3[i].wscore < school3[i + 1].wscore)
			{
				school_test[i] = school3[i];
				school3[i] = school3[i + 1];
				school3[i + 1] = school_test[i];
			}
			if (school4[i].score < school4[i + 1].score)
			{
				school_test[i] = school4[i];
				school4[i] = school4[i + 1];
				school4[i + 1] = school_test[i];
			}
		}
	}
	int choice;
H:	choice = one();

	if (choice == 2)
	{
		FILE* fpWrite = fopen("D:\\�˶�������.txt", "w");
		fprintf(fpWrite, "-----------------���ܷ�����-------------------------\n");
		fprintf(fpWrite, "���\tѧУ����\tѧУ���\t�ܷ�\n");
		system("cls");
		for (i = 1; i <= total[4]; i++)
		{
			printf("��%d��\tѧУ������Ϊ:%s\tѧУ�ı��Ϊ:%d", i, school4[i].name, school4[i].snum);
			printf("\t�ܷ�Ϊ:%d\n", school4[i].score);
			printf("����D�̵��˶��������ĵ��в鿴\n");
			fprintf(fpWrite, "%d\t%s\t\t%d\t\t%d\n", i, school4[i].name, school4[i].snum, school4[i].score);
		}
		fclose(fpWrite);
		printf("������һ�����ַ�����һ����:"); scanf("%d", &d); goto H;
	}
	else if (choice == 3)
	{
		FILE* fpWrite = fopen("D:\\�˶�������.txt", "a+");
		fprintf(fpWrite, "-----------------�������ܷ�����---------------------\n");
		fprintf(fpWrite, "���\tѧУ����\tѧУ���\t�����˶��ܷ�\n");
		system("cls");
		for (i = 1; i <= total[4]; i++)
		{
			printf("��%d��\tѧУ������Ϊ:%s\tѧУ�ı��Ϊ:%d", i, school2[i].name, school2[i].snum);
			printf("\t������Ŀ�ܷ�Ϊ:%d\n", school2[i].mscore);
			printf("����D�̵��˶��������ĵ��в鿴\n");
			fprintf(fpWrite, "%d\t%s\t\t%d\t\t%d\n", i, school4[i].name, school4[i].snum, school2[i].mscore);
		}
		fclose(fpWrite);
		printf("������һ�����ַ�����һ����:"); scanf("%d", &d); goto H;
	}
	else if (choice == 4)
	{
		FILE* fpWrite = fopen("D:\\�˶�������.txt", "a+");
		fprintf(fpWrite, "-----------------��Ů���ܷ�����---------------------\n");
		fprintf(fpWrite, "���\tѧУ����\tѧУ���\tŮ���˶��ܷ�\n");
		system("cls");
		for (i = 1; i <= total[4]; i++)
		{
			printf("��%d��\tѧУ������Ϊ:%s\tѧУ�ı��Ϊ:%d", i, school3[i].name, school3[i].snum);
			printf("\tŮ����Ŀ�ܷ�Ϊ:%d\n", school3[i].wscore);
			printf("����D�̵��˶��������ĵ��в鿴\n");
			fprintf(fpWrite, "%d\t%s\t\t%d\t\t%d\n", i, school3[i].name, school3[i].snum, school3[i].wscore);
		}
		fclose(fpWrite);
		printf("������һ�����ַ�����һ����:"); scanf("%d", &d); goto H;
	}
	else if (choice == 1)
	{
		system("cls");
		for (i = 1; i <= number; i++)
		{
			printf("ѧУ�ı��Ϊ:%d\tѧУ������Ϊ:%s\t�ܷ�Ϊ:%d\n", i, school[i].name, school[i].score);
		}
		printf("������һ�����ַ�����һ����:"); scanf("%d", &d); goto H;
	}
	else if (choice == 0) return;
	else { goto H; }


}
void search(SCHOOL school[], SPORT sport[], int total[])
{
	system("color 70");
	system("cls");
	int i, j, sum = 0;
	int a = 0;
	int b = 0, c = 0, d;
	int choice, choice1, choice2, choice3;
	int score1[6] = { 0,7,5,3,2,1 };
	int score2[4] = { 0,5,3,2 };
F:	choice = two();
	switch (choice)
	{
	case 1: {


	G:		
		printf("������Ҫ��ѯ��ѧУ���:");
		scanf("%d", &choice2);
		for (i = 1; i <= total[4]; i++)
		{
			if (choice2 == school[i].snum)
			{
				printf("��ѧУ������Ϊ:%s\n", school[i].name); a++;
			}
		}
		if (a == 0) {
			printf("��ѧУ��Ų����ڣ�����������!\n");
			system("pause");
			system("cls");
			goto G;
		}
	A:		printf("������Ҫ��ѯ����Ŀ���:");
		scanf("%d", &choice3);
		for (i = 1; i <= total[3]; i++)
		{
			if (choice3 == sport[i].inum)
			{
				printf("����Ŀ������Ϊ:%s\n", sport[i].name); b++;
				if (sport[i].top == 3)
				{
					for (j = 1; j <= 3; j++) {
						if (sport[i].mark[j] == choice2)
						{
							sum += score2[j];
						}
					}
				}
				if (sport[i].top == 5)
				{
					for (j = 1; j <= 5; j++)
					{
						if (sport[i].mark[j] == choice2)
						{
							sum += score1[j];
						}
					}
				}
				printf("��ѧУ�ڸ���Ŀ�ĵ÷�Ϊ:%d\n", sum);
			}
		}	if (b == 0) {
			printf("����Ŀ��Ų����ڣ�����������!\n");
			system("pause");
			system("cls");
			goto A;
		}



		printf("������һ�����ַ�����һ����:"); scanf("%d", &d); goto F;



	}
	case 2: {
		system("cls");
	D:			printf("������Ҫ��ѯ����Ŀ���:");
		scanf("%d", &choice1);
		for (i = 1; i <= total[3]; i++)
		{
			if (choice1 == sport[i].inum)
			{
				c++;
				if (sport[i].top == 3)
				{
					printf("����Ŀ������Ϊ:%s\n", sport[i].name);
					printf("����Ŀǰ�����ĳɼ�Ϊ:\t\t");
					for (j = 1; j <= 3; j++)
					{
						printf("%d\t", sport[i].score[j]);
					}
					printf("\n");
					printf("����Ŀǰ������ѧУ���Ϊ:\t");
					for (j = 1; j <= 3; j++)
					{
						printf("%d\t", sport[i].mark[j]);
					}
					printf("\n");
				}
				if (sport[i].top == 5)
				{
					printf("����Ŀ������Ϊ:%s\n", sport[i].name);
					printf("����Ŀǰ�����ĳɼ�Ϊ:\t");
					for (j = 1; j <= 5; j++)
					{
						printf("%d\t", sport[i].score[j]);
					}
					printf("\n");
					printf("����Ŀǰ������ѧУ���Ϊ:\t");
					for (j = 1; j <= 5; j++)
					{
						printf("%d\t", sport[i].mark[j]);
					}
					printf("\n");
				}

			}
		}if (c == 0) {
			printf("����Ŀ��Ų����ڣ�����������!\n");
			system("pause");
			system("cls");
			goto D;
		}
		printf("������һ�����ַ�����һ����:"); scanf("%d", &d); scanf("%d", &d); goto F;
	}
	case 0:break;
	default: {

		goto F;
	}
	}
}

int gongneng() {
	int v = 0;
	initgraph(480, 480);
	setbkcolor(YELLOW);
	cleardevice();
	//����������ɫ ���в�����ʾ����
	settextcolor(RED);
	settextstyle(25, 0, "����");
	outtextxy(200, 50, "���ܱ�");
	outtextxy(150, 100, "1 ¼��ɼ�");
	outtextxy(150, 150, "2 ͳ�Ƴɼ�");
	outtextxy(150, 200, "3 ����ɼ�");
	outtextxy(150, 250, "4 ��ѯ�ɼ�");
	outtextxy(150, 300, "0 �˳�");
	outtextxy(150, 350, "��������ʹ�õĹ���:");
	string str1, str2;   //ͷ�ļ� string 
	char c;  //�����ַ�c���ռ�������
	while (v != 2) {
		c = _getch();
		if (c == '\b')  //���c���˸����str1ɾ��һ��
		{
			v--;
			if (v < 2)
				str1 = str1.substr(0, str1.size() - 1);
		}
		else {
			if (c != ' ')
				v++;
			if (v <= 1) {

				str1 += (int)c;

			}

		}
		str2 = "��������ʹ�õĹ���:" + str1;
		cleardevice();
		outtextxy(200, 50, "���ܱ�");
		outtextxy(150, 100, "1 ¼��ɼ�");
		outtextxy(150, 150, "2 ͳ�Ƴɼ�");
		outtextxy(150, 200, "3 ����ɼ�");
		outtextxy(150, 250, "4 ��ѯ�ɼ�");
		outtextxy(150, 300, "0 �˳�");
		outtextxy(150, 350, str2.c_str());
		if (v == 1) {
			v++;
			_getch();
		}
	}closegraph();

	return c - 48;
}

int  main()
{

	int total[5];//������ֱ���������Ŀ������Ů����Ŀ����,������Ŀ������ѧУ������
	SCHOOL school[N + 1];
	SPORT sport[M + W + 1];

	int a;
C:
	a = gongneng();



	switch (a)
	{
	case 1: luru(school, sport, total); goto C;
	case 2:	tongji(school, sport, total); goto C;
	case 3:	show(school, sport, total); goto C;
	case 4: search(school, sport, total); goto C;
	case 0: system("color 70");system("cls"); printf("��лʹ��!\n"); break;
	default:goto C;
	}



	return 0;
}
