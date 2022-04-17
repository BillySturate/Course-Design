#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 1000
typedef struct room
{
	int buildID;
	int roomID;
	double area;
	int number;
	int already;
}ROOM;
ROOM room[N];
void menu(){
	system("color 70");
	system("cls");
	printf("-------------------------------------------------\n");
	printf("\t\tѧ���������ϵͳ\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.¼��ÿ���������Ϣ\n");
	printf("\t\t2.���������Ϣ\n");
	printf("\t\t3.�޸�ָ������ŵĶ���\n");
	printf("\t\t4.��ѯ�������Ϣ\n");
	printf("\t\t5.ɾ��ָ������ŵ���Ϣ\n");
	printf("\t\t6.����(��������ס����)\n");
	printf("\t\t7.���\n");
	printf("\t\t(�밴�����ֽ�������\n");
	printf("------------------------------------------------\n");
}
int luru(ROOM room[]);
void liulan(ROOM room[],int n);
void paixu(ROOM room[],int n);
int tianjia(ROOM room[],int n);
void xiugai(ROOM room[],int n);
void chaxun(ROOM room[],int n);
int del(ROOM room[] ,int n );
void WritetoFile(ROOM room[],int n);
void ReadfromFile(ROOM room[],int n);
int main(void)
{
	int choice,n;
	 CS:menu();
	 do{
	 scanf("%d",&choice);
	 if(choice>7||choice<0){
	 	printf("\t\tInput Error!\n");
	 }
	}while(choice>7&&choice<0);
	 switch (choice){
	 	case 0:
	 		system("color 70");
	 		system("cls");
	 		printf("�˳�ϵͳ����\n");
	 		printf("��л��ʹ�ñ�����\n");
	 		exit (0);
	 	case 1:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t¼�����\n");
	 		n=luru(room);
			WritetoFile(room,n);
	 		break;
	 	case 2:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t��ӽ���\n");
	 		n=tianjia(room,n);
			WritetoFile(room,n);
	 		break;
	 	case 3:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t�޸Ľ���\n");
	 		xiugai(room,n);
			WritetoFile(room,n);
	 		break;
	 	case 4:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t��ѯ����\n");
	 		chaxun(room,n);
	 		break;
	 	case 5:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\tɾ������\n");
	 		n=del(room,n);
			WritetoFile(room,n);
	 		break;
	 	case 6:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t�������\n");
	 		paixu(room,n);
	 		break;
	 	case 7:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t�������\n");
			ReadfromFile(room,n);
	 		liulan(room,n);
	 		break;
	 }
	 system("pause");
	 goto CS;	 		
}
int luru(ROOM room[])
{
	int i=-1,count=0,a,j;
	ROOM temp;
	do
	{
	i++;
	count++;
	printf("������¥��\n");
	fflush(stdin);
	scanf("%d",&room[i].buildID);
	printf("�����뷿���\n");
	fflush(stdin);
	scanf("%d",&room[i].roomID);
	printf("���������(��/ƽ��)\n");
	fflush(stdin);
	scanf("%lf",&room[i].area);
	printf("����������������\n");
	fflush(stdin);
	scanf("%d",&room[i].number);
	printf("��������ס����\n");
	fflush(stdin);
	scanf("%d",&room[i].already);
	printf("�Ƿ����¼��(�� 1 �� 0)\n");
	scanf("%d",&a);
	}while(a==1);
	for(i=0;i<count-1;i++){
		for(j=1;j<count;j++){
			if(room[i].roomID>room[i+1].roomID){
				temp=room[i];
				room[i]=room[i+1];
				room[i+1]=temp;
			}
		}
	}
	return count;
}
void WritetoFile(ROOM room[],int n)
{
	FILE *fp;
	int i;

	if((fp=fopen("E:\\room.txt","w"))==NULL)
	{
		printf("Failure to open room.txt!\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		fprintf(fp,"\t\t��%d�����ҵ���Ϣ\n¥��Ϊ:%d\n�����Ϊ:%d\n���Ϊ%.2f(��/ƽ��)\n����������Ϊ:%d\n��ס����Ϊ:%d\n",i+1,
																										room[i].buildID,
																										room[i].roomID,
																										room[i].area,
																										room[i].number,
																										room[i].already);
	}
	fclose(fp);
}
void ReadfromFile(ROOM room[],int n)
{
	FILE * fp;
	int i;
	if((fp=fopen("E:\\room.txt","r"))==NULL)
	{
		printf("Failure to open room.txt!\n");
		exit (0);
	}
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&i+1);
		fscanf(fp,"%d",&room[i].buildID);
		fscanf(fp,"%d",&room[i].roomID);
		fscanf(fp,"%.2f",&room[i].area);
		fscanf(fp,"%d",&room[i].number);
		fscanf(fp,"%d",&room[i].already);
	}
	fclose(fp);

} 
void liulan(ROOM room[],int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("\t\t��%d�����ҵ���Ϣ\n",i+1);
		printf("\t  ¥��Ϊ:%d\n",room[i].buildID);
		printf("\t  �����Ϊ:%d\n",room[i].roomID);
		printf("\t  ���Ϊ:%.2f(��/ƽ��)\n",room[i].area);
		printf("\t  ����������Ϊ:%d\n",room[i].number);
		printf("\t  ��ס����Ϊ:%d\n",room[i].already);
	}
	 }
void paixu(ROOM room[],int n)
{
	int i,j;
	ROOM temp;
	for(i=0;i<n-1;i++){
		for(j=1;j<n;j++){
			if(room[i].already<room[i+1].already){
				temp=room[i];
				room[i]=room[i+1];
				room[i+1]=temp;
			}
		}
	}
		for(i=0;i<n;i++){
		printf("\t\t��%d�����ҵ���Ϣ\n",i+1);
		printf("\t  ¥��Ϊ:%d\n",room[i].buildID);
		printf("\t  �����Ϊ:%d\n",room[i].roomID);
		printf("\t  ���Ϊ:%.2f(��/ƽ��)\n",room[i].area);
		printf("\t  ����������Ϊ:%d\n",room[i].number);
		printf("\t  ��ס����Ϊ:%d\n",room[i].already);
	}
	
	 }	 
int tianjia(ROOM room[],int n)
{
	int i,k,j,z,choose;
	ROOM temp;
		printf("������¥��\n");
		fflush(stdin);
		scanf("%d",&room[n].buildID);
		printf("�����뷿���\n");
		fflush(stdin);
		scanf("%d",&room[n].roomID);
		printf("���������(��/ƽ��)\n");
		fflush(stdin);
		scanf("%lf",&room[n].area);
		printf("����������������\n");
		fflush(stdin);
		scanf("%d",&room[n].number);
		printf("��������ס����\n");
		fflush(stdin);
		scanf("%d",&room[n].already);
		for(k=0;k<n;k++){
			j=1;
			if(room[k].roomID==room[n].roomID&&room[k].buildID==room[n].buildID){
				j=0;
				printf("�Ѵ��ڸ�������Ϣ���Ƿ�����޸�(�� 1 �� 0)\n");
				do{
				scanf("%d",&choose);
			}while(choose>1||choose<0);
				if(choose==1){
					printf("�޸ĳɹ�!\n");
					room[k]=room[n];
					return n;
				}else if(choose==0){
					printf("��ӳɹ�!\n");
	for(i=0;i<n;i++){
		for(z=1;z<n+1;z++){
			if(room[i].already<room[i+1].already){
				temp=room[i];
				room[i]=room[i+1];
				room[i+1]=temp;
			}
		}
	}
					return n+1;
				}
			}
		}
		if(j==1){
			printf("��ӳɹ�!\n");
	for(i=0;i<n;i++){
		for(z=1;z<n+1;z++){
			if(room[i].already<room[i+1].already){
				temp=room[i];
				room[i]=room[i+1];
				room[i+1]=temp;
			}
		}
	}
		}
		
		return n+1;
}
void xiugai(ROOM room[],int n)
{
	int buildid,roomid,k,j;
	printf("������Ҫ�޸ĵ�¥��:\n");
	fflush(stdin);
	scanf("%d",&buildid);
	printf("������Ҫ�޸ĵķ����:\n");
	fflush(stdin);
	scanf("%d",&roomid);
	for(k=0;k<n;k++)
	{
		j=1;
		if(room[k].roomID==roomid&&room[k].buildID==buildid){
			j=0;
			printf("��Ϊ����ѯ��һ����¼�������޸���Ϣ\n");
			printf("������¥��\n");
			fflush(stdin);
			scanf("%d",&room[n].buildID);
			printf("�����뷿���\n");
			fflush(stdin);
			scanf("%d",&room[n].roomID);
			printf("���������(��/ƽ��)\n");
			fflush(stdin);
			scanf("%lf",&room[n].area);
			printf("����������������\n");
			fflush(stdin);
			scanf("%d",&room[n].number);
			printf("��������ס����\n");
			fflush(stdin);
			scanf("%d",&room[n].already);
			printf("�޸ĳɹ�!\n");
			room[k]=room[n];
			break;			
		}	
	}
	if(j==1){
		printf("δ��ѯ��������Ϣ!\n");	
	}
}
void chaxun(ROOM room[],int n)
{
	int buildid,roomid,k,j;
	printf("������Ҫ��ѯ��¥��:\n");
	fflush(stdin);
	scanf("%d",&buildid);
	printf("������Ҫ��ѯ�ķ����:\n");
	fflush(stdin);
	scanf("%d",&roomid);
	for(k=0;k<n;k++){
		j=1;
			if(room[k].roomID==roomid&&room[k].buildID==buildid){
				j=0;
				printf("��Ϊ���鵽һ����¼\n");
				printf("\t  ¥��Ϊ:%d\n",room[k].buildID);
				printf("\t  �����Ϊ:%d\n",room[k].roomID);
				printf("\t  ���Ϊ:%.2f(��/ƽ��)\n",room[k].area);
				printf("\t  ����������Ϊ:%d\n",room[k].number);
				printf("\t  ��ס����Ϊ:%d\n",room[k].already);
				break;
				
	}
		  
		  }
		  if(j==1){
		  	printf("δ��ѯ����������Ϣ\n");
		  }
	}
int del(ROOM room[] ,int n )
{
	int buildid,roomid,k,j,choice,h;
	printf("������Ҫɾ����¥��:\n");
	fflush(stdin);
	scanf("%d",&buildid);
	printf("������Ҫɾ���ķ����:\n");
	fflush(stdin);
	scanf("%d",&roomid);
	for(k=0;k<n;k++)
	{
		j=1;
		if(room[k].roomID==roomid&&room[k].buildID==buildid){
			j=0;
			printf("��Ϊ����ѯ��һ��������Ϣ���Ƿ�ɾ��(�� 1 �� 0)\n");
			do{
				scanf("%d",&choice);
			}while(choice>1||choice<0);
			if(choice==0){
				printf("ɾ��ʧ��!\n");
				return n;
			}else if(choice==1){
				printf("ɾ���ɹ�!\n");
				for(h=k;h<n;h++){
					room[k]=room[k+1];
				}
				return n-1;
			}
										}
			}
			if(j==1){
				printf("δ��ѯ����������Ϣ!\n");
			}
			return n;
	 }	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 








	 
