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
	 n=read(x);         // ���ļ�д��ṹ������ ������ȡ���鳤�� 
MEUN: 	system("cls");
		menu();
	do
	{
		printf("ѡ������Ҫ�ķ���(0-6):\n");
		scanf("%d",&i);
	}while(i<0||i>7);
		switch(i)
		{
			case 1:
				system("cls");
				system("color 70");
				printf("\t\t    ��ϵ��¼�����\t\t\n");
				n=luru(x,n);
			break;
			case 2:
				system("cls");
				system("color 70");
				printf("\t\t    ��ϵ����ӽ���\t\t\n");
				 n=tianjia(x,n);
		    break; 
		    case 3:
		    	system("cls");
				system("color 70");
				printf("\t\t    ��ϵ�˲�ѯ����\t\t\n");
				search(x,n);
			break;
			case 4:
		    	system("cls");
				system("color 70");
				printf("\t\t    ��ϵ���޸Ľ���\t\t\n");
				xiugai(x,n);
			break;
			case 5:
		    	system("cls");
				system("color 70");
				printf("\t\t    ��ϵ��ɾ������\t\t\n");
				n=del(x,n);
			break;
		    case 6:
		    	system("cls");
				system("color 70");
				printf("\t\t    ��ϵ���������\t\t\n");
				liulan(x,n);
		    break;
			default:
			{
			printf("��лʹ�ñ�����!\n");
			j=1;
			break;
			} 
		}
	write(x,n);      // ��ִ����switch�к����󣬽��ṹ���������ݴ����ļ� 
	system("pause");
	if(j==0)
	goto MEUN;    	//  ��δѡ���˳�����ص��˵� 
	return 0;
}
void menu()                 //       �˵� 
{
	system("color 70");
	printf("\t\t    ����ͨѶ¼����ϵͳ\t\t\n");
	 printf("====================================================\n");
	printf("\t\t\t1 ¼��		  	   \n");
	printf("\t\t\t2 ���		  	   \n");
	printf("\t\t\t3 ��ѯ		  	   \n");
	printf("\t\t\t4 �޸�		  	   \n");
	printf("\t\t\t5 ɾ��		  	   \n");
	printf("\t\t\t6 ���		  	   \n");
	printf("\t\t\t0 �˳�   	  	   \n");
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
		printf("��ϵ�� %d\n",n+1);
		printf("��������:\n");
			fflush(stdin);
		scanf("%s",&x[n].name);
		printf("����绰1:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number1);
		printf("����绰2:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number2);
		printf("����绰3:\n");
		fflush(stdin);
		scanf("%s",&x[n].number.number3);
		printf("����QQ:\n");
			fflush(stdin);
		scanf("%s",&x[n].QQ);
		printf("����΢�ź�:\n");
			fflush(stdin);
		scanf("%s",&x[n].wechat);
		printf("�����ַ:\n");
			fflush(stdin);
		scanf("%s",&x[n].address);
		printf("�Ƿ���������ϵ��?(����������1���������¼��)\n");
			fflush(stdin);
			a=getchar();
	}while(a=='1');
	n=n+1;
	printf("��ϵ��¼�����\n\n");
	for(i=0;i<n-1;i++)                    // ��¼�����ϵ�˽������� 
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
	    printf("��������:\n");
	    	fflush(stdin);
		scanf("%s",&x[n].name);
		printf("����绰1:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number1);
		printf("����绰2:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number2);
		printf("����绰3:\n");
			fflush(stdin);
		scanf("%s",&x[n].number.number3);
		printf("����QQ:\n");
			fflush(stdin);
		scanf("%s",&x[n].QQ);
		printf("����΢�ź�:\n");
			fflush(stdin);
		scanf("%s",&x[n].wechat);
		printf("�����ַ:\n");
			fflush(stdin);
		scanf("%s",&x[n].address);
		for(i=0;i<n;i++)   							 	//�ж��Ƿ��й�����ϵ�� 
	{
		if(strcmp(x[n].name,x[i].name)==0)
		{
			printf("���и���ϵ�ˣ��Ƿ��޸ģ�(1 or 2)\n");         // ���и���ϵ�ˣ�����ѡ�������޸� 
			printf("1 �޸�		2 ����\n");
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
				n=n+1;                 //������ϵ�˺����鳤�� ��һ 
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
		if(j==0) 							//�޸���ϵ�ˣ����д��벢���� 
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
				n=n+1;	  			//�����ϵ�ˣ����鳤�� ��һ 
			   }
		printf("��ӳɹ�!\n\n");
		return n;
}

void liulan(stu x[],int n)				//  ����ϵ����Ϣ��ӡ���� 
{
	int i;
	printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","����","�ֻ���1","�ֻ���2","�ֻ���3","QQ","΢��","��ַ");
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

int read(stu x[])				//  ���ļ���ģ�黯��ȡ���� ������ṹ�������� 
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
		return i-1;					//�� ���鳤�ȷ��� 
	}
	return 0;
	
}

void write(stu x[],int n)		//���ṹ������������ ��д���ļ� 
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

void search(stu x[],int n)				// ��ѯ��ϵ�� 
{
	int i,j,k=0;
	char str[50];
	printf("\t��ѯ��ʽ\n");
	printf("1 ������	2 ���绰����\n");	//ѡ���ѯ��ʽ 
	do
	{printf("ѡ���ѯ��ʽ(1 or 2)\n");
	scanf("%d",&j);
	}while(j>2||j<1);
	switch(j)
	{
		case 1:							// ��������ѯ 
			printf("��������\n"); 
			fflush(stdin);
			gets(str);
			for(i=0;i<n;i++)
	{
		if(strcmp(str,x[i].name)==0)    // ����ѯ������ӡ����ϵ�� 
		{
		k=1;
		printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","����","�ֻ���1","�ֻ���2","�ֻ���3","QQ","΢��","��ַ");
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
		case 2:						// �������ѯ 
			printf("����绰����\n");
			fflush(stdin);
			gets(str);
			for(i=0;i<n;i++)		// ����ѯ������ӡ����ϵ�� 
		{
			if(strcmp(str,x[i].number.number1)==0||strcmp(str,x[i].number.number2)==0||strcmp(str,x[i].number.number3)==0)
			{
			k=1;	
			printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","����","�ֻ���1","�ֻ���2","�ֻ���3","QQ","΢��","��ַ");
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
	if(k==0)      // ��δ��ѯ������ʾ�޸���ϵ�� 
	printf("�޸���ϵ��!\n\n");
}

void xiugai(stu x[],int n) 		// �޸���ϵ����Ϣ 
{
	int i,j=0,k=1;
	char str[50];
	printf("��������\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)    	//  ͨ���������в��� 
	{
		if(strcmp(str,x[i].name)==0)		// ���ҵ������ýṹ�����������ݽ����޸� 
		{ 
		if(k!=1)							// �ж��Ƿ���ͬ����ϵ�˴��� 
		printf("��ϵ�� %d �����Ϣ:\n\n",k);
		else
		printf("��ϵ�������Ϣ��\n\n");
		printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","����","�ֻ���1","�ֻ���2","�ֻ���3","QQ","΢��","��ַ");
			printf("%-10s",x[i].name);
			printf("%-15s",x[i].number.number1);
			printf("%-15s",x[i].number.number2);
			printf("%-15s",x[i].number.number3);	
			printf("%-15s",x[i].QQ);	
			printf("%-20s",x[i].wechat);	
			printf("%-20s\n",x[i].address);
			printf("������޸�:\n");
		printf("����绰1:\n");
			fflush(stdin);
		scanf("%s",&x[i].number.number1);
		printf("����绰2:\n");
			fflush(stdin);
		scanf("%s",&x[i].number.number2);
		printf("����绰3:\n");
		fflush(stdin);
		scanf("%s",&x[i].number.number3);
		printf("����QQ:\n");
			fflush(stdin);
		scanf("%s",&x[i].QQ);
		printf("����΢�ź�:\n");
			fflush(stdin);
		scanf("%s",&x[i].wechat);
		printf("�����ַ:\n");
			fflush(stdin);
		scanf("%s",&x[i].address);
		j=1;
		k++;
		printf("�޸ĳɹ�!\n\n");
		}
	
		}
	    if(j==0)
		printf("�޸���ϵ��!\n\n");
	}


int del(stu x[],int n)			// ɾ����ϵ�� 
{
	int i,j,c,d=0;
	char str[50];
	printf("��������\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)		// �ж��Ƿ��и���ϵ�� 
	{
		if(strcmp(str,x[i].name)==0)	// ����У� �Ƿ�ȷ��ɾ������ϵ��
		{	d=1;
		printf("%-10s%-15s%-15s%-15s%-15s%-20s%-20s\n","����","�ֻ���1","�ֻ���2","�ֻ���3","QQ","΢��","��ַ");
			printf("%-10s",x[i].name);
			printf("%-15s",x[i].number.number1);	// ����ϵ����Ϣ����������ͬ����ϵ�ˣ��ý���ѡ���Ƿ�ɾ�� 
			printf("%-15s",x[i].number.number2);
			printf("%-15s",x[i].number.number3);	
			printf("%-15s",x[i].QQ);	
			printf("%-20s",x[i].wechat);	
			printf("%-20s\n",x[i].address);
		do
		{
			printf("�Ƿ�ɾ������ϵ�ˣ�(1 or 2)\n");
			printf("1 ��     2 ��\n");
			scanf("%d",&c);
		}while(c>2||c<1);
		 if(c==1)
		{
		for(j=i+1;j<n;j++,i++)
		{
			x[i]=x[j];
			}
			printf("ɾ���ɹ���\n\n");
			return n-1;				//  ɾ�������鳤�ȼ�һ 
		}
	    if(c==2)
		{
		printf("��ȡ��ɾ��!\n\n");
		return n;
		}
		}
    }
    if(d==0)
    {
    	printf("�޸���ϵ�ˣ�\n\n");
    	return n; 
	}
}


