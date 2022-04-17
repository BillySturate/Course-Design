#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define N 40
typedef struct time
{
	char year[N];
	char month[N];
	char day[N];
}TIME;
typedef struct book
{
	char bookname[N];			//书名 
	char price[N];
	TIME  chubantime;           //出版时间 
	char chubanshe[N];     //出版社 
	char writername[N]; 		//作者 
	char ID[N];					//图书编号 
}BOOK;
int luru(BOOK book[],int n);
int tianjia(BOOK book[],int n);
void liulan(BOOK book[],int n);
int read(BOOK book[]);
void write(BOOK book[],int n);
void search(BOOK book[],int n);
void xiugai(BOOK book[],int n);
int del(BOOK book[],int n);
void paixu(BOOK book[],int n);
BOOK book[N];
void menu();

int main()
{
	int i,j=0,n=0;
	 n=read(book);         // 将文件写入结构体数组 ，并获取数组长度 
MEUN: 	system("cls");
		menu();
	do
	{
		printf("选择你需要的服务(0-7):\n");
		scanf("%d",&i);
	}while(i<0||i>7);
		switch(i)
		{
			case 1:
				system("cls");
				system("color 70");
				printf("\t\t    图书信息录入界面\t\t\n");
				n=luru(book,n);
			break;
			case 2:
				system("cls");
				system("color 70");
				printf("\t\t    图书信息添加界面\t\t\n");
				n=tianjia(book,n);
		    break; 
		    case 3:
		    	system("cls");
				system("color 70");
				printf("\t\t    图书信息查询界面\t\t\n");
				search(book,n);
			break;
			case 4:
		    	system("cls");
				system("color 70");
				printf("\t\t    图书信息修改界面\t\t\n");
				xiugai(book,n);
			break;
			case 5:
		    	system("cls");
				system("color 70");
				printf("\t\t    图书信息删除界面\t\t\n");
				n=del(book,n);
			break;
		    case 6:
		    	system("cls");
				system("color 70");
				printf("\t\t    图书信息浏览界面\t\t\n");
				liulan(book,n);
		    break;
		    case 7:
		    	system("cls");
				system("color 70");
				printf("\t\t    图书信息排序界面\t\t\n");
				paixu(book,n);
			break;		    	
			default:
			{
			printf("感谢使用本程序!\n");
			j=1;
			break;
			} 
		}
	write(book,n);      // 在执行完switch中函数后，将结构体数组数据存入文件 
	system("pause");
	if(j==0)
	goto MEUN;    	//  若未选择退出，则回到菜单 
	return 0;
}
void menu()
{
	system("color 70");
	system("cls");
	printf("\t\t图书信息管理系统                               \n");
	printf("\n\t\t1.录入:录入每本图书的信息                             \n");
	printf("\t\t2.添加:添加图书信息                                    \n"); 
	printf("\t\t3.查询:按书名查询图书信息                               \n");
	printf("\t\t4.修改:修改书名（请按书号确定修改的图书信息）            \n");
	printf("\t\t5.删除:请输入要删除的图书信息（输入书号）                 \n");
	printf("\t\t6.浏览:读取每本图书的信息并显示                     \n");
	printf("\t\t7.排序:按出版社排序，并显示        \n"); 
	printf("\t\t0.按0退出系统                                           \n");
	printf("\n\t\t提示：请输入数字序号选择对应的操作！		                 \n");
}
int luru(BOOK book[],int n)
{
		int i,k;
	BOOK temp;
	char a;
	n=-1;
    do
	{   
		n++;
		printf("\n图书名称:");
			fflush(stdin);
		gets(book[n].bookname);
		printf("\n价格:");
			fflush(stdin);
		gets(book[n].price);	
		printf("\n出版日期，格式如 2020 1 1:");
			fflush(stdin);
		scanf("%s %s %s",&book[n].chubantime.year,
		&book[n].chubantime.month,
		&book[n].chubantime.day
			);
		fflush(stdin);
		printf("\n图书编号:");
			fflush(stdin);
		scanf("%s",&book[n].ID);
		fflush(stdin);
		printf("\n图书作者名:");
			fflush(stdin);
		gets(book[n].writername);
		fflush(stdin);
		printf("\n出版社:");
			fflush(stdin);
		gets(book[n].chubanshe);
		printf("是否继续添加图书?(继续请输入1，否则结束录入)\n");
			fflush(stdin);
			a=getchar();
	}while(a=='1');
	n=n+1;
	printf("图书录入结束\n\n");
	for(i=0;i<n-1;i++)                    // 对录入的书籍进行排序 
			{
				for(k=i+1;k<n;k++)
				{
					if(strcmp(book[i].ID,book[k].ID)>0)
					{
						temp=book[i];
						book[i]=book[k];
						book[k]=temp;
						}	
					}
				}
	return n;
}

void liulan(BOOK book[],int n)				//  将书籍信息打印出来 
{
	int i;
	for(i=0;i<n;i++){
		printf("第%d本书的内容\n",i+1);
		printf("\n图书名称:%s\n",book[i].bookname);
		printf("价格:%s\n",book[i].price);
		printf("出版日期:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("图书编号:%s\n",book[i].ID);
		printf("作者名:%s\n",book[i].writername);
		printf("出版社:%s\n",book[i].chubanshe);
		printf("\n");
	}

}
int del(BOOK book[],int n)			// 删除书籍信息 
{
	int i,j,c,d=0;
	char str[50];
	printf("输入书名\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)		// 判断是非有该书籍 
	{
		if(strcmp(str,book[i].bookname)==0)	// 如果有， 是否确定删除该书籍 
		{	d=1;
		printf("\n图书名称:%s\n",book[i].bookname);
		printf("价格:%s\n",book[i].price);
		printf("出版日期:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("图书编号:%s\n",book[i].ID);
		printf("作者名:%s\n",book[i].writername);
		printf("出版社:%s\n",book[i].chubanshe);
		printf("\n");
		do
		{
			printf("是否删除该书籍？(1 or 2)\n");
			printf("1 是     2 否\n");
			scanf("%d",&c);
		}while(c>2||c<1);
		 if(c==1)
		{
		for(j=i+1;j<n;j++,i++)
		{
			book[i]=book[j];
			}
			printf("删除成功！\n\n");
			return n-1;				//  删除后，数组长度减一 
		}
	    if(c==2)
		{
		printf("已取消删除!\n\n");
		return n;
		}
		}
    }
    if(d==0)
    {
    	printf("无该书籍！\n\n");
    	return n; 
	}
}

int read(BOOK book[])				//  从文件中模块化读取数据 ，放入结构体数组中 
{
	int i=0;
	FILE*fp;
	if((fp=fopen("Book.txt","a+"))==NULL)
	{
		printf("failure!");
		exit(0);
	}
	while(fread(&book[i++],1,sizeof(book),fp));
	fclose(fp);
	if(i>=1)
	{
		return i-1;					//将 数组长度返回 
	}
	return 0;
	
}

void write(BOOK book[],int n)		//将结构体数组中数据 ，写入文件 
{
	int i;
	FILE*fp;
	if((fp=fopen("Book.txt","w+"))==NULL)
	{
		printf("failure!");
		exit(0);
	}
			for(i=0;i<n;i++)
	{
		fwrite(&book[i],1,sizeof(book),fp);
	}
	fclose(fp);
}
int  tianjia(BOOK book[],int n)
{   
	int i,j=0,k;
	 BOOK temp;
	    printf("\n图书名称:");
			fflush(stdin);
		gets(book[n].bookname);
		printf("\n价格:");
			fflush(stdin);
		gets(book[n].price);	
		//scanf("%f",book[a].price);
		printf("\n出版日期，格式如 2020 1 1:");
			fflush(stdin);
		scanf("%s %s %s",&book[n].chubantime.year,
		&book[n].chubantime.month,
		&book[n].chubantime.day
			);
		fflush(stdin);
		printf("\n图书编号:");
			fflush(stdin);
		scanf("%s",&book[n].ID);
		fflush(stdin);
		printf("\n图书作者名:");
			fflush(stdin);
		gets(book[n].writername);
		fflush(stdin);
		printf("\n出版社:");
			fflush(stdin);
		gets(book[n].chubanshe);
		for(i=0;i<n;i++)   							 	//判断是否有过该书籍 
	{
		if(strcmp(book[n].bookname,book[i].bookname)==0)
		{
			printf("已有该书籍，是否修改？(1 or 2)\n");         // 已有该书籍，进行选择插入或修改 
			printf("1 修改		2 插入\n");
			do{
			scanf("%d",&j);
			}while(j>2||j<1);
			if(j==1)
			{
				book[i]=book[n];
				break; 
			   }
			if(j==2)
			{
				n=n+1;                 //插入书籍后，数组长度 加一 
				for(i=0;i<=n-1;i++)
			{
				for(k=i+1;k<=n;k++)
				{
					if(strcmp(book[i].bookname,book[k].bookname)>0)
					{
						temp=book[i];
						book[i]=book[k];
						book[k]=temp;
						}	
					}
				}
			   }
			}
		}
		if(j==0) 							//无该书籍，进行存入并排序 
			{
				for(i=0;i<=n-1;i++)
			{
				for(k=i+1;k<=n;k++)
				{
					if(strcmp(book[i].bookname,book[k].bookname)>0)
					{
						temp=book[i];
						book[i]=book[k];
						book[k]=temp;
						}	
					}
				}
				n=n+1;	  			//添加书籍，数组长度 加一 
			   }
		printf("添加成功!\n\n");
		return n;
}
void search(BOOK book[],int n)				// 查询书籍 
{
	int i,j,k=0;
	char str[50];
	printf("\t查询方式\n");
	printf("按书名方式查找信息\n");
			printf("输入书名\n"); 
			fflush(stdin);
			gets(str);
			for(i=0;i<n;i++)
	{
		if(strcmp(str,book[i].bookname)==0)    // 若查询到，打印该书籍
		{
		k=1;
	//	printf("第%d本书的内容\n",i+1);
		printf("\n图书名称:%s\n",book[i].bookname);
		printf("价格:%s\n",book[i].price);
		printf("出版日期:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("图书编号:%s\n",book[i].ID);
		printf("作者名:%s\n",book[i].writername);
		printf("出版社:%s\n",book[i].chubanshe);
		printf("\n");
	}		
		}
	if(k==0)      // 若未查询到，提示无该书籍 
	printf("无该书籍信息!\n\n");
}
void xiugai(BOOK book[],int n) 		// 修改书籍信息 
{
	int i,j=0,k=1;
	char str[50];
	printf("输入书籍名称\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)    	//  通过书名进行查找 
	{
		if(strcmp(str,book[i].bookname)==0)		// 若找到，将该结构体数组中数据进行修改 
		{ 
		if(k!=1)							// 判断是否有同名书籍存在 
		printf("书籍 %d 相关信息:\n\n",k);
		else
		printf("书籍相关信息：\n\n");
		printf("第%d本书的内容\n",i+1);
		printf("\n图书名称:%s\n",book[i].bookname);
		printf("价格:%s\n",book[i].price);
		printf("出版日期:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("图书编号:%s\n",book[i].ID);
		printf("作者名:%s\n",book[i].writername);
		printf("出版社:%s\n",book[i].chubanshe);
		printf("\n");
			printf("请进行修改:\n");
		printf("\n图书名称:");
			fflush(stdin);
		gets(book[i].bookname);
		printf("\n价格:");
			fflush(stdin);
		gets(book[i].price);	
		//scanf("%f",book[a].price);
		printf("\n出版日期，格式如 2020 1 1:");
			fflush(stdin);
		scanf("%s %s %s",&book[i].chubantime.year,
		&book[i].chubantime.month,
		&book[i].chubantime.day
			);
		fflush(stdin);
		printf("\n图书编号:");
			fflush(stdin);
		scanf("%s",&book[i].ID);
		fflush(stdin);
		printf("\n图书作者名:");
			fflush(stdin);
		gets(book[i].writername);
		fflush(stdin);
		printf("\n出版社:");
			fflush(stdin);
		gets(book[i].chubanshe);
		j=1;
		k++;
		printf("修改成功!\n\n");
		}
	
		}
	    if(j==0)
		printf("无该书籍!\n\n");
	}
void paixu(BOOK book[],int n)
{
	int i,k;
	BOOK temp;
	for(i=0;i<n-1;i++)                    // 对录入的书籍进行排序 
			{
				for(k=i+1;k<n;k++)
				{
					if(strcmp(book[i].chubanshe,book[k].chubanshe)>0)
					{
						temp=book[i];
						book[i]=book[k];
						book[k]=temp;
						}	
					}
				}
	
	for(i=0;i<n;i++){
		printf("第%d本书的内容\n",i+1);
		printf("\n图书名称:%s\n",book[i].bookname);
		printf("价格:%s\n",book[i].price);
		printf("出版日期:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("图书编号:%s\n",book[i].ID);
		printf("作者名:%s\n",book[i].writername);
		printf("出版社:%s\n",book[i].chubanshe);
		printf("\n");
}
}
























