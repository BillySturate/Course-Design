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
	char bookname[N];			//���� 
	char price[N];
	TIME  chubantime;           //����ʱ�� 
	char chubanshe[N];     //������ 
	char writername[N]; 		//���� 
	char ID[N];					//ͼ���� 
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
	 n=read(book);         // ���ļ�д��ṹ������ ������ȡ���鳤�� 
MEUN: 	system("cls");
		menu();
	do
	{
		printf("ѡ������Ҫ�ķ���(0-7):\n");
		scanf("%d",&i);
	}while(i<0||i>7);
		switch(i)
		{
			case 1:
				system("cls");
				system("color 70");
				printf("\t\t    ͼ����Ϣ¼�����\t\t\n");
				n=luru(book,n);
			break;
			case 2:
				system("cls");
				system("color 70");
				printf("\t\t    ͼ����Ϣ��ӽ���\t\t\n");
				n=tianjia(book,n);
		    break; 
		    case 3:
		    	system("cls");
				system("color 70");
				printf("\t\t    ͼ����Ϣ��ѯ����\t\t\n");
				search(book,n);
			break;
			case 4:
		    	system("cls");
				system("color 70");
				printf("\t\t    ͼ����Ϣ�޸Ľ���\t\t\n");
				xiugai(book,n);
			break;
			case 5:
		    	system("cls");
				system("color 70");
				printf("\t\t    ͼ����Ϣɾ������\t\t\n");
				n=del(book,n);
			break;
		    case 6:
		    	system("cls");
				system("color 70");
				printf("\t\t    ͼ����Ϣ�������\t\t\n");
				liulan(book,n);
		    break;
		    case 7:
		    	system("cls");
				system("color 70");
				printf("\t\t    ͼ����Ϣ�������\t\t\n");
				paixu(book,n);
			break;		    	
			default:
			{
			printf("��лʹ�ñ�����!\n");
			j=1;
			break;
			} 
		}
	write(book,n);      // ��ִ����switch�к����󣬽��ṹ���������ݴ����ļ� 
	system("pause");
	if(j==0)
	goto MEUN;    	//  ��δѡ���˳�����ص��˵� 
	return 0;
}
void menu()
{
	system("color 70");
	system("cls");
	printf("\t\tͼ����Ϣ����ϵͳ                               \n");
	printf("\n\t\t1.¼��:¼��ÿ��ͼ�����Ϣ                             \n");
	printf("\t\t2.���:���ͼ����Ϣ                                    \n"); 
	printf("\t\t3.��ѯ:��������ѯͼ����Ϣ                               \n");
	printf("\t\t4.�޸�:�޸��������밴���ȷ���޸ĵ�ͼ����Ϣ��            \n");
	printf("\t\t5.ɾ��:������Ҫɾ����ͼ����Ϣ��������ţ�                 \n");
	printf("\t\t6.���:��ȡÿ��ͼ�����Ϣ����ʾ                     \n");
	printf("\t\t7.����:�����������򣬲���ʾ        \n"); 
	printf("\t\t0.��0�˳�ϵͳ                                           \n");
	printf("\n\t\t��ʾ���������������ѡ���Ӧ�Ĳ�����		                 \n");
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
		printf("\nͼ������:");
			fflush(stdin);
		gets(book[n].bookname);
		printf("\n�۸�:");
			fflush(stdin);
		gets(book[n].price);	
		printf("\n�������ڣ���ʽ�� 2020 1 1:");
			fflush(stdin);
		scanf("%s %s %s",&book[n].chubantime.year,
		&book[n].chubantime.month,
		&book[n].chubantime.day
			);
		fflush(stdin);
		printf("\nͼ����:");
			fflush(stdin);
		scanf("%s",&book[n].ID);
		fflush(stdin);
		printf("\nͼ��������:");
			fflush(stdin);
		gets(book[n].writername);
		fflush(stdin);
		printf("\n������:");
			fflush(stdin);
		gets(book[n].chubanshe);
		printf("�Ƿ�������ͼ��?(����������1���������¼��)\n");
			fflush(stdin);
			a=getchar();
	}while(a=='1');
	n=n+1;
	printf("ͼ��¼�����\n\n");
	for(i=0;i<n-1;i++)                    // ��¼����鼮�������� 
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

void liulan(BOOK book[],int n)				//  ���鼮��Ϣ��ӡ���� 
{
	int i;
	for(i=0;i<n;i++){
		printf("��%d���������\n",i+1);
		printf("\nͼ������:%s\n",book[i].bookname);
		printf("�۸�:%s\n",book[i].price);
		printf("��������:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("ͼ����:%s\n",book[i].ID);
		printf("������:%s\n",book[i].writername);
		printf("������:%s\n",book[i].chubanshe);
		printf("\n");
	}

}
int del(BOOK book[],int n)			// ɾ���鼮��Ϣ 
{
	int i,j,c,d=0;
	char str[50];
	printf("��������\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)		// �ж��Ƿ��и��鼮 
	{
		if(strcmp(str,book[i].bookname)==0)	// ����У� �Ƿ�ȷ��ɾ�����鼮 
		{	d=1;
		printf("\nͼ������:%s\n",book[i].bookname);
		printf("�۸�:%s\n",book[i].price);
		printf("��������:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("ͼ����:%s\n",book[i].ID);
		printf("������:%s\n",book[i].writername);
		printf("������:%s\n",book[i].chubanshe);
		printf("\n");
		do
		{
			printf("�Ƿ�ɾ�����鼮��(1 or 2)\n");
			printf("1 ��     2 ��\n");
			scanf("%d",&c);
		}while(c>2||c<1);
		 if(c==1)
		{
		for(j=i+1;j<n;j++,i++)
		{
			book[i]=book[j];
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
    	printf("�޸��鼮��\n\n");
    	return n; 
	}
}

int read(BOOK book[])				//  ���ļ���ģ�黯��ȡ���� ������ṹ�������� 
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
		return i-1;					//�� ���鳤�ȷ��� 
	}
	return 0;
	
}

void write(BOOK book[],int n)		//���ṹ������������ ��д���ļ� 
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
	    printf("\nͼ������:");
			fflush(stdin);
		gets(book[n].bookname);
		printf("\n�۸�:");
			fflush(stdin);
		gets(book[n].price);	
		//scanf("%f",book[a].price);
		printf("\n�������ڣ���ʽ�� 2020 1 1:");
			fflush(stdin);
		scanf("%s %s %s",&book[n].chubantime.year,
		&book[n].chubantime.month,
		&book[n].chubantime.day
			);
		fflush(stdin);
		printf("\nͼ����:");
			fflush(stdin);
		scanf("%s",&book[n].ID);
		fflush(stdin);
		printf("\nͼ��������:");
			fflush(stdin);
		gets(book[n].writername);
		fflush(stdin);
		printf("\n������:");
			fflush(stdin);
		gets(book[n].chubanshe);
		for(i=0;i<n;i++)   							 	//�ж��Ƿ��й����鼮 
	{
		if(strcmp(book[n].bookname,book[i].bookname)==0)
		{
			printf("���и��鼮���Ƿ��޸ģ�(1 or 2)\n");         // ���и��鼮������ѡ�������޸� 
			printf("1 �޸�		2 ����\n");
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
				n=n+1;                 //�����鼮�����鳤�� ��һ 
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
		if(j==0) 							//�޸��鼮�����д��벢���� 
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
				n=n+1;	  			//����鼮�����鳤�� ��һ 
			   }
		printf("��ӳɹ�!\n\n");
		return n;
}
void search(BOOK book[],int n)				// ��ѯ�鼮 
{
	int i,j,k=0;
	char str[50];
	printf("\t��ѯ��ʽ\n");
	printf("��������ʽ������Ϣ\n");
			printf("��������\n"); 
			fflush(stdin);
			gets(str);
			for(i=0;i<n;i++)
	{
		if(strcmp(str,book[i].bookname)==0)    // ����ѯ������ӡ���鼮
		{
		k=1;
	//	printf("��%d���������\n",i+1);
		printf("\nͼ������:%s\n",book[i].bookname);
		printf("�۸�:%s\n",book[i].price);
		printf("��������:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("ͼ����:%s\n",book[i].ID);
		printf("������:%s\n",book[i].writername);
		printf("������:%s\n",book[i].chubanshe);
		printf("\n");
	}		
		}
	if(k==0)      // ��δ��ѯ������ʾ�޸��鼮 
	printf("�޸��鼮��Ϣ!\n\n");
}
void xiugai(BOOK book[],int n) 		// �޸��鼮��Ϣ 
{
	int i,j=0,k=1;
	char str[50];
	printf("�����鼮����\n"); 
	fflush(stdin);
	gets(str);
	for(i=0;i<n;i++)    	//  ͨ���������в��� 
	{
		if(strcmp(str,book[i].bookname)==0)		// ���ҵ������ýṹ�����������ݽ����޸� 
		{ 
		if(k!=1)							// �ж��Ƿ���ͬ���鼮���� 
		printf("�鼮 %d �����Ϣ:\n\n",k);
		else
		printf("�鼮�����Ϣ��\n\n");
		printf("��%d���������\n",i+1);
		printf("\nͼ������:%s\n",book[i].bookname);
		printf("�۸�:%s\n",book[i].price);
		printf("��������:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("ͼ����:%s\n",book[i].ID);
		printf("������:%s\n",book[i].writername);
		printf("������:%s\n",book[i].chubanshe);
		printf("\n");
			printf("������޸�:\n");
		printf("\nͼ������:");
			fflush(stdin);
		gets(book[i].bookname);
		printf("\n�۸�:");
			fflush(stdin);
		gets(book[i].price);	
		//scanf("%f",book[a].price);
		printf("\n�������ڣ���ʽ�� 2020 1 1:");
			fflush(stdin);
		scanf("%s %s %s",&book[i].chubantime.year,
		&book[i].chubantime.month,
		&book[i].chubantime.day
			);
		fflush(stdin);
		printf("\nͼ����:");
			fflush(stdin);
		scanf("%s",&book[i].ID);
		fflush(stdin);
		printf("\nͼ��������:");
			fflush(stdin);
		gets(book[i].writername);
		fflush(stdin);
		printf("\n������:");
			fflush(stdin);
		gets(book[i].chubanshe);
		j=1;
		k++;
		printf("�޸ĳɹ�!\n\n");
		}
	
		}
	    if(j==0)
		printf("�޸��鼮!\n\n");
	}
void paixu(BOOK book[],int n)
{
	int i,k;
	BOOK temp;
	for(i=0;i<n-1;i++)                    // ��¼����鼮�������� 
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
		printf("��%d���������\n",i+1);
		printf("\nͼ������:%s\n",book[i].bookname);
		printf("�۸�:%s\n",book[i].price);
		printf("��������:%s %s %s \n",book[i].chubantime.year,book[i].chubantime.month,book[i].chubantime.day);
		printf("ͼ����:%s\n",book[i].ID);
		printf("������:%s\n",book[i].writername);
		printf("������:%s\n",book[i].chubanshe);
		printf("\n");
}
}
























