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
	printf("\t\t学生宿舍管理系统\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.录入每个宿舍的信息\n");
	printf("\t\t2.添加宿舍信息\n");
	printf("\t\t3.修改指定房间号的对象\n");
	printf("\t\t4.查询宿舍的信息\n");
	printf("\t\t5.删除指定房间号的信息\n");
	printf("\t\t6.排序(按宿舍能住人数)\n");
	printf("\t\t7.浏览\n");
	printf("\t\t(请按照数字进行输入\n");
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
	 		printf("退出系统界面\n");
	 		printf("感谢您使用本程序\n");
	 		exit (0);
	 	case 1:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t录入界面\n");
	 		n=luru(room);
			WritetoFile(room,n);
	 		break;
	 	case 2:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t添加界面\n");
	 		n=tianjia(room,n);
			WritetoFile(room,n);
	 		break;
	 	case 3:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t修改界面\n");
	 		xiugai(room,n);
			WritetoFile(room,n);
	 		break;
	 	case 4:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t查询界面\n");
	 		chaxun(room,n);
	 		break;
	 	case 5:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t删除界面\n");
	 		n=del(room,n);
			WritetoFile(room,n);
	 		break;
	 	case 6:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t排序界面\n");
	 		paixu(room,n);
	 		break;
	 	case 7:
	 		system("color 70");
	 		system("cls");
	 		printf("\t\t浏览界面\n");
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
	printf("请输入楼号\n");
	fflush(stdin);
	scanf("%d",&room[i].buildID);
	printf("请输入房间号\n");
	fflush(stdin);
	scanf("%d",&room[i].roomID);
	printf("请输入面积(米/平方)\n");
	fflush(stdin);
	scanf("%lf",&room[i].area);
	printf("请输入所容纳人数\n");
	fflush(stdin);
	scanf("%d",&room[i].number);
	printf("请输入已住人数\n");
	fflush(stdin);
	scanf("%d",&room[i].already);
	printf("是否继续录入(是 1 否 0)\n");
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
		fprintf(fp,"\t\t第%d个寝室的信息\n楼号为:%d\n房间号为:%d\n面积为%.2f(米/平方)\n所容纳人数为:%d\n已住人数为:%d\n",i+1,
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
		printf("\t\t第%d个寝室的信息\n",i+1);
		printf("\t  楼号为:%d\n",room[i].buildID);
		printf("\t  房间号为:%d\n",room[i].roomID);
		printf("\t  面积为:%.2f(米/平方)\n",room[i].area);
		printf("\t  所容纳人数为:%d\n",room[i].number);
		printf("\t  已住人数为:%d\n",room[i].already);
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
		printf("\t\t第%d个寝室的信息\n",i+1);
		printf("\t  楼号为:%d\n",room[i].buildID);
		printf("\t  房间号为:%d\n",room[i].roomID);
		printf("\t  面积为:%.2f(米/平方)\n",room[i].area);
		printf("\t  所容纳人数为:%d\n",room[i].number);
		printf("\t  已住人数为:%d\n",room[i].already);
	}
	
	 }	 
int tianjia(ROOM room[],int n)
{
	int i,k,j,z,choose;
	ROOM temp;
		printf("请输入楼号\n");
		fflush(stdin);
		scanf("%d",&room[n].buildID);
		printf("请输入房间号\n");
		fflush(stdin);
		scanf("%d",&room[n].roomID);
		printf("请输入面积(米/平方)\n");
		fflush(stdin);
		scanf("%lf",&room[n].area);
		printf("请输入所容纳人数\n");
		fflush(stdin);
		scanf("%d",&room[n].number);
		printf("请输入已住人数\n");
		fflush(stdin);
		scanf("%d",&room[n].already);
		for(k=0;k<n;k++){
			j=1;
			if(room[k].roomID==room[n].roomID&&room[k].buildID==room[n].buildID){
				j=0;
				printf("已存在该宿舍信息，是否进行修改(是 1 否 0)\n");
				do{
				scanf("%d",&choose);
			}while(choose>1||choose<0);
				if(choose==1){
					printf("修改成功!\n");
					room[k]=room[n];
					return n;
				}else if(choose==0){
					printf("添加成功!\n");
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
			printf("添加成功!\n");
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
	printf("请输入要修改的楼号:\n");
	fflush(stdin);
	scanf("%d",&buildid);
	printf("请输入要修改的房间号:\n");
	fflush(stdin);
	scanf("%d",&roomid);
	for(k=0;k<n;k++)
	{
		j=1;
		if(room[k].roomID==roomid&&room[k].buildID==buildid){
			j=0;
			printf("已为您查询到一条记录请输入修改信息\n");
			printf("请输入楼号\n");
			fflush(stdin);
			scanf("%d",&room[n].buildID);
			printf("请输入房间号\n");
			fflush(stdin);
			scanf("%d",&room[n].roomID);
			printf("请输入面积(米/平方)\n");
			fflush(stdin);
			scanf("%lf",&room[n].area);
			printf("请输入所容纳人数\n");
			fflush(stdin);
			scanf("%d",&room[n].number);
			printf("请输入已住人数\n");
			fflush(stdin);
			scanf("%d",&room[n].already);
			printf("修改成功!\n");
			room[k]=room[n];
			break;			
		}	
	}
	if(j==1){
		printf("未查询到宿舍信息!\n");	
	}
}
void chaxun(ROOM room[],int n)
{
	int buildid,roomid,k,j;
	printf("请输入要查询的楼号:\n");
	fflush(stdin);
	scanf("%d",&buildid);
	printf("请输入要查询的房间号:\n");
	fflush(stdin);
	scanf("%d",&roomid);
	for(k=0;k<n;k++){
		j=1;
			if(room[k].roomID==roomid&&room[k].buildID==buildid){
				j=0;
				printf("已为您查到一条记录\n");
				printf("\t  楼号为:%d\n",room[k].buildID);
				printf("\t  房间号为:%d\n",room[k].roomID);
				printf("\t  面积为:%.2f(米/平方)\n",room[k].area);
				printf("\t  所容纳人数为:%d\n",room[k].number);
				printf("\t  已住人数为:%d\n",room[k].already);
				break;
				
	}
		  
		  }
		  if(j==1){
		  	printf("未查询到该宿舍信息\n");
		  }
	}
int del(ROOM room[] ,int n )
{
	int buildid,roomid,k,j,choice,h;
	printf("请输入要删除的楼号:\n");
	fflush(stdin);
	scanf("%d",&buildid);
	printf("请输入要删除的房间号:\n");
	fflush(stdin);
	scanf("%d",&roomid);
	for(k=0;k<n;k++)
	{
		j=1;
		if(room[k].roomID==roomid&&room[k].buildID==buildid){
			j=0;
			printf("已为您查询到一条宿舍信息，是否删除(是 1 否 0)\n");
			do{
				scanf("%d",&choice);
			}while(choice>1||choice<0);
			if(choice==0){
				printf("删除失败!\n");
				return n;
			}else if(choice==1){
				printf("删除成功!\n");
				for(h=k;h<n;h++){
					room[k]=room[k+1];
				}
				return n-1;
			}
										}
			}
			if(j==1){
				printf("未查询到该宿舍信息!\n");
			}
			return n;
	 }	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 








	 
