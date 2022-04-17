#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 40
void menu();

typedef struct number
{
	
	char number1[N];
	char number2[N];
	char number3[N];
	
}many;
typedef struct student 
{
	char name[N];
	many number;
	char QQ[N];
	char wechat[N];
	char address[N];
}stu;

int luru(stu x[],int n);
int tianjia(stu x[],int n);
void liulan(stu x[],int n);
int read(stu x[]);
void write(stu x[],int n);
void search(stu x[],int n);
void xiugai(stu x[],int n);
int del(stu x[],int n);
stu x[N];

int main()
{
	int i,j=0,n=0;
	 n=read(x);         // 将文件写入结构体数组 ，并获取数组长度 
MEUN: 	system("cls");
		menu();
	do
	{
		printf("选择你需要的服务(0-6):\n");
		scanf("%d",&i);
	}while(i<0||i>7);
		switch(i)
		{
			case 1:
				system("cls");
				system("color 70");
				printf("\t\t    联系人录入界面\t\t\n");
				n=luru(x,n);
			break;
			case 2:
				system("cls");
				system("color 70");
				printf("\t\t    联系人添加界面\t\t\n");
				 n=tianjia(x,n);
		    break; 
		    case 3:
		    	system("cls");
				system("color 70");
				printf("\t\t    联系人查询界面\t\t\n");
				search(x,n);
			break;
			case 4:
		    	system("cls");
				system("color 70");
				printf("\t\t    联系人修改界面\t\t\n");
				xiugai(x,n);
			break;
			case 5:
		    	system("cls");
				system("color 70");
				printf("\t\t    联系人删除界面\t\t\n");
				n=del(x,n);
			break;
		    case 6:
		    	system("cls");
				system("color 70");
				printf("\t\t    联系人浏览界面\t\t\n");
				liulan(x,n);
		    break;
			default:
			{
			printf("感谢使用本程序!\n");
			j=1;
			break;
			} 
		}
	write(x,n);      // 在执行完switch中函数后，将结构体数组数据存入文件 
	system("pause");
	if(j==0)
	goto MEUN;    	//  若未选择退出，则回到菜单 
	return 0;
}
void menu()                 //       菜单 
{
	system("color 70");
	printf("\t\t    个人通讯录管理系统\t\t\n");
	 printf("====================================================\n");
	printf("\t\t\t1 录入		  	   \n");
	printf("\t\t\t2 添加		  	   \n");
	printf("\t\t\t3 查询		  	   \n");
	printf("\t\t\t4 修改		  	   \n");
	printf("\t\t\t5 删除		  	   \n");
	printf("\t\t\t6 浏览		  	   \n");
	printf("\t\t\t0 退出   	  	   \n");
    printf("====================================================\n");
 } 
int luru(stu x[],int n)
{
		int i,k;
	stu temp;
	char a;
	n=-1;
    do
	{   
		n++;
		printf("联系人 %d\n",n+1);
		printf("输入姓名:\n");
			fflush(stdin);
		scanf("%s",&x[n].name);
		printf("输入电话1:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number1);
		printf("输入电话2:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number2);
		printf("输入电话3:\n");
		fflush(stdin);
		scanf("%s",&x[n].number.number3);
		printf("输入QQ:\n");
			fflush(stdin);
		scanf("%s",&x[n].QQ);
		printf("输入微信号:\n");
			fflush(stdin);
		scanf("%s",&x[n].wechat);
		printf("输入地址:\n");
			fflush(stdin);
		scanf("%s",&x[n].address);
		printf("是否继续添加联系人?(继续请输入1，否则结束录入)\n");
			fflush(stdin);
			a=getchar();
	}while(a=='1');
	n=n+1;
	printf("联系人录入结束\n\n");
	for(i=0;i<n-1;i++)                    // 对录入的联系人进行排序 
			{
				for(k=i+1;k<n;k++)
				{
					if(strcmp(x[i].name,x[k].name)>0)
					{
						temp=x[i];
						x[i]=x[k];
						x[k]=temp;
						}	
					}
				}
	return n;
}
int  tianjia(stu x[],int n)
{   
	int i,j=0,k;
	stu temp;
	    printf("输入姓名:\n");
	    	fflush(stdin);
		scanf("%s",&x[n].name);
		printf("输入电话1:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number1);
		printf("输入电话2:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number2);
		printf("输入电话3:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number3);
		printf("输入QQ:\n");
			fflush(stdin);
		scanf("%s",&x[n].QQ);
		printf("输入微信号:\n");
			fflush(stdin);
		scanf("%s",&x[n].wechat);
		printf("输入地址:\n");
			fflush(stdin);
		scanf("%s",&x[n].address);
		for(i=0;i<n;i++)   							 	//判断是否有过该联系人 
	{
		if(strcmp(x[n].name,x[i].name)==0)
		{
			printf("已有该联系人，是否修改？(1 or 2)\n");         // 已有该联系人，进行选择插入或修改 
			printf("1 修改		2 插入\n");
			do{
			scanf("%d",&j);
			}while(j>2||j<1);
			if(j==1)
			{
				x[i]=x[n];
				break; 
			   }
			if(j==2)
			{
				n=n+1;                 //插入联系人后，数组长度 加一 
				for(i=0;i<=n-1;i++)
			{
				for(k=i+1;k<=n;k++)
				{
					if(strcmp(x[i].name,x[k].name)>0)
					{
						temp=x[i];
						x[i]=x[k];
						x[k]=temp;
						}	
					}
				}
			   }
			}
		}
		if(j==0) 							//无该联系人，进行存入并排序 
			{
				for(i=0;i<=n-1;i++)
			{
				for(k=i+1;k<=n;k++)
				{
					if(strcmp(x[i].name,x[k].name)>0)
					{
						temp=x[i];
						x[i]=x[k];
						x[k]=temp;
						}	
					}
				}
				n=n+1;	  			//添加联系人，数组长度 加一 
			   }
		printf("添加成功!\n\n");
		return n;
}

void liulan(stu x[],int n)				//  将联系人信息打印出来 
{
	int i;
	printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","姓名","手机号1","手机号2","手机号3","QQ","微信","地址");
	for(i=0;i<n;i++)
	{
		printf("%-10s",x[i].name);
		printf("%-15s",x[i].number.number1);
		printf("%-15s",x[i].number.number2);
		printf("%-15s",x[i].number.number3);	
		printf("%-15s",x[i].QQ);	
		printf("%-20s",x[i].wechat);	
		printf("%-20s\n",x[i].address);	
	}		
}

int read(stu x[])				//  从文件中模块化读取数据 ，放入结构体数组中 
{
	int i=0;
	FILE*fp;
	if((fp=fopen("D:\\data.txt","a+"))==NULL)
	{
		printf("failure!");
		exit(0);
	}
	while(fread(&x[i++],1,sizeof(stu),fp));
	fclose(fp);
	if(i>=1)
	{
		return i-1;					//将 数组长度返回 
	}
	return 0;
	
}

void write(stu x[],int n)		//将结构体数组中数据 ，写入文件 
{
	int i;
	FILE*fp;
	if((fp=fopen("D:\\data.txt","w+"))==NULL)
	{
		printf("failure!");
		exit(0);
	}
			for(i=0;i<n;i++)
	{
		fwrite(&x[i],1,sizeof(stu),fp);
	}
	fclose(fp);
}

void search(stu x[],int n)				// 查询联系人 
{
	int i,j,k=0;
	char str[50];
	printf("\t查询方式\n");
	printf("1 按姓名	2 按电话号码\n");	//选择查询方式 
	do
	{printf("选择查询方式(1 or 2)\n");
	scanf("%d",&j);
	}while(j>2||j<1);
	switch(j)
	{
		case 1:							// 按姓名查询 
			printf("输入姓名\n"); 
			fflush(stdin);
			gets(str);
			for(i=0;i<n;i++)
	{
		if(strcmp(str,x[i].name)==0)    // 若查询到，打印该联系人 
		{
		k=1;
		printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","姓名","手机号1","手机号2","手机号3","QQ","微信","地址");
		printf("%-10s",x[i].name);
		printf("%-15s",x[i].number.number1);
		printf("%-15s",x[i].number.number2);
		printf("%-15s",x[i].number.number3);	
		printf("%-15s",x[i].QQ);	
		printf("%-20s",x[i].wechat);	
		printf("%-20s\n",x[i].address);	
		}
	}
	break;
		case 2:						// 按号码查询 
			printf("输入电话号码\n");
			fflush(stdin);
			gets(str);
			for(i=0;i<n;i++)		// 若查询到，打印该联系人 
		{
			if(strcmp(str,x[i].number.number1)==0||strcmp(str,x[i].number.number2)==0||strcmp(str,x[i].number.number3)==0)
			{
			k=1;	
			printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","姓名","手机号1","手机号2","手机号3","QQ","微信","地址");
			printf("%-10s",x[i].name);
			printf("%-15s",x[i].number.number1);
			printf("%-15s",x[i].number.number2);
			printf("%-15s",x[i].number.number3);	
			printf("%-15s",x[i].QQ);	
			printf("%-20s",x[i].wechat);	
			printf("%-20s\n",x[i].address);	
			}	
		}
		break;
	}
	if(k==0)      // 若未查询到，提示无该联系人 
	printf("无该联系人!\n\n");
}

void xiugai(stu x[],int n) 		// 修改联系人信息 
{
	int i,j=0,k=1;
	char str[50];
	printf("输入姓名\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)    	//  通过姓名进行查找 
	{
		if(strcmp(str,x[i].name)==0)		// 若找到，将该结构体数组中数据进行修改 
		{ 
		if(k!=1)							// 判断是否有同名联系人存在 
		printf("联系人 %d 相关信息:\n\n",k);
		else
		printf("联系人相关信息：\n\n");
		printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","姓名","手机号1","手机号2","手机号3","QQ","微信","地址");
			printf("%-10s",x[i].name);
			printf("%-15s",x[i].number.number1);
			printf("%-15s",x[i].number.number2);
			printf("%-15s",x[i].number.number3);	
			printf("%-15s",x[i].QQ);	
			printf("%-20s",x[i].wechat);	
			printf("%-20s\n",x[i].address);
			printf("请进行修改:\n");
		printf("输入电话1:\n");
			fflush(stdin);
		scanf("%s",&x[i].number.number1);
		printf("输入电话2:\n");
			fflush(stdin);
		scanf("%s",&x[i].number.number2);
		printf("输入电话3:\n");
		fflush(stdin);
		scanf("%s",&x[i].number.number3);
		printf("输入QQ:\n");
			fflush(stdin);
		scanf("%s",&x[i].QQ);
		printf("输入微信号:\n");
			fflush(stdin);
		scanf("%s",&x[i].wechat);
		printf("输入地址:\n");
			fflush(stdin);
		scanf("%s",&x[i].address);
		j=1;
		k++;
		printf("修改成功!\n\n");
		}
	
		}
	    if(j==0)
		printf("无该联系人!\n\n");
	}


int del(stu x[],int n)			// 删除联系人 
{
	int i,j,c,d=0;
	char str[50];
	printf("输入姓名\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)		// 判断是非有该联系人 
	{
		if(strcmp(str,x[i].name)==0)	// 如果有， 是否确定删除该联系人
		{	d=1;
		printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","姓名","手机号1","手机号2","手机号3","QQ","微信","地址");
			printf("%-10s",x[i].name);
			printf("%-15s",x[i].number.number1);	// 将联系人信息输出，如果有同名联系人，好进行选择是否删除 
			printf("%-15s",x[i].number.number2);
			printf("%-15s",x[i].number.number3);	
			printf("%-15s",x[i].QQ);	
			printf("%-20s",x[i].wechat);	
			printf("%-20s\n",x[i].address);
		do
		{
			printf("是否删除该联系人？(1 or 2)\n");
			printf("1 是     2 否\n");
			scanf("%d",&c);
		}while(c>2||c<1);
		 if(c==1)
		{
		for(j=i+1;j<n;j++,i++)
		{
			x[i]=x[j];
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
    	printf("无该联系人！\n\n");
    	return n; 
	}
}


