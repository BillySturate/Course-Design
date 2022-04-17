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
#define N 20          //学校最大数目
#define M 20          //男子项目最大数目
#define W 20          //女子项目最大数目

typedef struct
{
	char name[20];//项目名字
	int inum;       //项目编号
	int top;           //取名次的数目
	int mark[5];       //学校的编号
	int score[5];	//存放项目信息,分数/
}SPORT;
typedef struct
{
	char name[20];//学校名字
	int snum;     //学校编号/
	int score;         //学校总分/
	int mscore;        //男团体总分/
	int wscore;        //女团体总分/  
}SCHOOL;             //存放学校信息
int number;
int one() {
	int v = 0;
	initgraph(580, 480);
	setbkcolor(YELLOW);
	cleardevice();
	//设置字体颜色 还有测试显示字体
	settextcolor(RED);
	settextstyle(25, 0, "楷体");
	outtextxy(150, 50, "请选择按何种方式进行排序输出");
	outtextxy(150, 100, "1 学校的编号");
	outtextxy(150, 150, "2 总分");
	outtextxy(150, 200, "3 男子项目总分");
	outtextxy(150, 250, "4 女子项目总分");
	outtextxy(150, 300, "0 返回首界面");
	outtextxy(150, 350, "请输入想使用的功能:");
	string str1, str2;   //头文件 string 
	char c;  //定义字符c接收键盘输入
	while (v != 2) {
		c = _getch();
		if (c == '\b')  //如果c是退格符，str1删掉一个
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
		str2 = "请输入想使用的功能:" + str1;
		cleardevice();
		outtextxy(150, 50, "请选择按何种方式进行排序输出");
		outtextxy(150, 100, "1 学校的编号");
		outtextxy(150, 150, "2 总分");
		outtextxy(150, 200, "3 男子项目总分");
		outtextxy(150, 250, "4 女子项目总分");
		outtextxy(150, 300, "0 返回首界面");
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
	//设置字体颜色 还有测试显示字体
	settextcolor(RED);
	settextstyle(25, 0, "楷体");
	outtextxy(150, 50, "请选择查询方式");
	outtextxy(150, 100, "1 查询某个学校的某个项目的情况");
	outtextxy(150, 150, "2 查询某个项目的学校排名情况");
	outtextxy(150, 200, "0 返回首界面");
	outtextxy(150, 250, "请输入想使用的功能:");
	string str1, str2;   //头文件 string 
	char c;  //定义字符c接收键盘输入
	while (v != 2) {
		c = _getch();
		if (c == '\b')  //如果c是退格符，str1删掉一个
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
		str2 = "请输入想使用的功能:" + str1;
		cleardevice();
		outtextxy(150, 50, "请选择查询方式");
		outtextxy(150, 100, "1 查询某个学校的某个项目的情况");
		outtextxy(150, 150, "2 查询某个项目的学校排名情况");
		outtextxy(150, 200, "0 返回首界面");
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
	printf("请输入有多少学校参赛:");
	scanf("%d", &number);
	for (i = 1; i <= number; i++)
	{
		printf("请输入第%d个学校的名称:", i);
		scanf("%s", &school[i].name);
		school[i].snum = i;
	}

	printf("请输入有多少男子项目:");
	scanf("%d", &mannum);
	printf("请输入有多少女子项目:");
	scanf("%d", &womannum);
	total[1] = mannum;
	total[2] = womannum;
	total[3] = mannum + womannum;
	total[4] = number;
	for (i = 1; i <= mannum; i++)
	{
		printf("请输入第%d个男子项目的名称:", i);
		scanf("%s", &sport[i].name);
		sport[i].inum = i;
	}
	for (i = 1 + mannum; i <= mannum + womannum; i++)
	{
		printf("请输入第%d个女子项目的名称:", count);
		scanf("%s", &sport[i].name);
		sport[i].inum = i;
		count++;
	}
	for (i = 1; i <= mannum + womannum; i++)
	{
		system("cls");
		printf("第%d个项目的名称为:%s     编号为:%d\n", i, sport[i].name, sport[i].inum);

		printf("第%d个项目是取前三名(按3)还是前五名(按5):", i);
		scanf("%d", &sport[i].top);
		if (sport[i].top == 3) {
			printf("请输入前三名的成绩\n");
			for (int j = 1; j <= 3; j++)
			{
				printf("第%d名的成绩为:", j);
				scanf("%d", &sport[i].score[j]);
				printf("请输入第%d名的学校编号:", j);
				scanf("%d", &sport[i].mark[j]);
			}
		}
		if (sport[i].top == 5) {
			printf("请输入前五名的成绩\n");
			for (int j = 1; j <= 5; j++)
			{
				printf("第%d名的成绩为:", j);
				scanf("%d", &sport[i].score[j]);
				printf("请输入第%d名的学校编号:", j);
				scanf("%d", &sport[i].mark[j]);
			}
		}
	}
	printf("录入成功,按任意一个数字返回首界面:"); scanf("%d", &d);
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
	int score_m[N] = { 0 };		//存放男子项目的各个学校的分数
	int score_w[N] = { 0 };		//存放女子项目的各个学校的分数
	int score_total[N] = { 0 };
	for (i = 1; i <= total[1]; i++)			//统计男子项目各个学校的分数
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
	for (i = 1 + total[1]; i <= total[3]; i++)		//统计女子项目各个项目的分数
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
	printf("统计成功,按任意一个数字返回首界面:"); scanf("%d", &d);


}
void show(SCHOOL school[], SPORT sport[], int total[])
{
	system("color 70");
	system("cls");
	int i, j, temp, d;
	SCHOOL school2[N];			//存放各个学校男子项目的分数排序后的结果
	SCHOOL school3[N];			//存放各个学校女子项目的分数排序后的结果
	SCHOOL school4[N];			//存放各个学校总分排完序后的结果
	SCHOOL school_test[N];
	for (i = 1; i <= total[4]; i++)
	{
		school2[i] = school[i];
		school3[i] = school[i];
		school4[i] = school[i];
	}
	for (i = 1; i <= total[4]; i++)
	{
		for (j = 1; j <= total[4] - i; j++)				//对各个学校男子项目的总分进行排序
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
		FILE* fpWrite = fopen("D:\\运动会数据.txt", "w");
		fprintf(fpWrite, "-----------------按总分排序-------------------------\n");
		fprintf(fpWrite, "序号\t学校名称\t学校编号\t总分\n");
		system("cls");
		for (i = 1; i <= total[4]; i++)
		{
			printf("第%d名\t学校的名称为:%s\t学校的编号为:%d", i, school4[i].name, school4[i].snum);
			printf("\t总分为:%d\n", school4[i].score);
			printf("可在D盘的运动会数据文档中查看\n");
			fprintf(fpWrite, "%d\t%s\t\t%d\t\t%d\n", i, school4[i].name, school4[i].snum, school4[i].score);
		}
		fclose(fpWrite);
		printf("按任意一个数字返回上一界面:"); scanf("%d", &d); goto H;
	}
	else if (choice == 3)
	{
		FILE* fpWrite = fopen("D:\\运动会数据.txt", "a+");
		fprintf(fpWrite, "-----------------按男子总分排序---------------------\n");
		fprintf(fpWrite, "序号\t学校名称\t学校编号\t男子运动总分\n");
		system("cls");
		for (i = 1; i <= total[4]; i++)
		{
			printf("第%d名\t学校的名称为:%s\t学校的编号为:%d", i, school2[i].name, school2[i].snum);
			printf("\t男子项目总分为:%d\n", school2[i].mscore);
			printf("可在D盘的运动会数据文档中查看\n");
			fprintf(fpWrite, "%d\t%s\t\t%d\t\t%d\n", i, school4[i].name, school4[i].snum, school2[i].mscore);
		}
		fclose(fpWrite);
		printf("按任意一个数字返回上一界面:"); scanf("%d", &d); goto H;
	}
	else if (choice == 4)
	{
		FILE* fpWrite = fopen("D:\\运动会数据.txt", "a+");
		fprintf(fpWrite, "-----------------按女子总分排序---------------------\n");
		fprintf(fpWrite, "序号\t学校名称\t学校编号\t女子运动总分\n");
		system("cls");
		for (i = 1; i <= total[4]; i++)
		{
			printf("第%d名\t学校的名称为:%s\t学校的编号为:%d", i, school3[i].name, school3[i].snum);
			printf("\t女子项目总分为:%d\n", school3[i].wscore);
			printf("可在D盘的运动会数据文档中查看\n");
			fprintf(fpWrite, "%d\t%s\t\t%d\t\t%d\n", i, school3[i].name, school3[i].snum, school3[i].wscore);
		}
		fclose(fpWrite);
		printf("按任意一个数字返回上一界面:"); scanf("%d", &d); goto H;
	}
	else if (choice == 1)
	{
		system("cls");
		for (i = 1; i <= number; i++)
		{
			printf("学校的编号为:%d\t学校的名称为:%s\t总分为:%d\n", i, school[i].name, school[i].score);
		}
		printf("按任意一个数字返回上一界面:"); scanf("%d", &d); goto H;
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
		printf("请输入要查询的学校编号:");
		scanf("%d", &choice2);
		for (i = 1; i <= total[4]; i++)
		{
			if (choice2 == school[i].snum)
			{
				printf("该学校的名称为:%s\n", school[i].name); a++;
			}
		}
		if (a == 0) {
			printf("该学校编号不存在，请重新输入!\n");
			system("pause");
			system("cls");
			goto G;
		}
	A:		printf("请输入要查询的项目编号:");
		scanf("%d", &choice3);
		for (i = 1; i <= total[3]; i++)
		{
			if (choice3 == sport[i].inum)
			{
				printf("该项目的名称为:%s\n", sport[i].name); b++;
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
				printf("该学校在该项目的得分为:%d\n", sum);
			}
		}	if (b == 0) {
			printf("该项目编号不存在，请重新输入!\n");
			system("pause");
			system("cls");
			goto A;
		}



		printf("按任意一个数字返回上一界面:"); scanf("%d", &d); goto F;



	}
	case 2: {
		system("cls");
	D:			printf("请输入要查询的项目编号:");
		scanf("%d", &choice1);
		for (i = 1; i <= total[3]; i++)
		{
			if (choice1 == sport[i].inum)
			{
				c++;
				if (sport[i].top == 3)
				{
					printf("该项目的名称为:%s\n", sport[i].name);
					printf("该项目前三名的成绩为:\t\t");
					for (j = 1; j <= 3; j++)
					{
						printf("%d\t", sport[i].score[j]);
					}
					printf("\n");
					printf("该项目前三名的学校编号为:\t");
					for (j = 1; j <= 3; j++)
					{
						printf("%d\t", sport[i].mark[j]);
					}
					printf("\n");
				}
				if (sport[i].top == 5)
				{
					printf("该项目的名称为:%s\n", sport[i].name);
					printf("该项目前五名的成绩为:\t");
					for (j = 1; j <= 5; j++)
					{
						printf("%d\t", sport[i].score[j]);
					}
					printf("\n");
					printf("该项目前五名的学校编号为:\t");
					for (j = 1; j <= 5; j++)
					{
						printf("%d\t", sport[i].mark[j]);
					}
					printf("\n");
				}

			}
		}if (c == 0) {
			printf("该项目编号不存在，请重新输入!\n");
			system("pause");
			system("cls");
			goto D;
		}
		printf("按任意一个数字返回上一界面:"); scanf("%d", &d); scanf("%d", &d); goto F;
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
	//设置字体颜色 还有测试显示字体
	settextcolor(RED);
	settextstyle(25, 0, "楷体");
	outtextxy(200, 50, "功能表");
	outtextxy(150, 100, "1 录入成绩");
	outtextxy(150, 150, "2 统计成绩");
	outtextxy(150, 200, "3 输出成绩");
	outtextxy(150, 250, "4 查询成绩");
	outtextxy(150, 300, "0 退出");
	outtextxy(150, 350, "请输入想使用的功能:");
	string str1, str2;   //头文件 string 
	char c;  //定义字符c接收键盘输入
	while (v != 2) {
		c = _getch();
		if (c == '\b')  //如果c是退格符，str1删掉一个
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
		str2 = "请输入想使用的功能:" + str1;
		cleardevice();
		outtextxy(200, 50, "功能表");
		outtextxy(150, 100, "1 录入成绩");
		outtextxy(150, 150, "2 统计成绩");
		outtextxy(150, 200, "3 输出成绩");
		outtextxy(150, 250, "4 查询成绩");
		outtextxy(150, 300, "0 退出");
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

	int total[5];//数组里分别存放男子项目总数，女子项目总数,所有项目总数和学校的总数
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
	case 0: system("color 70");system("cls"); printf("感谢使用!\n"); break;
	default:goto C;
	}



	return 0;
}
