#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define column_num 5 //ͬһ����������ӵ���Ŀ 


void HideCursor(){	//���ع��λ�� ,����������ƴ������ 
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void gotoxy(int x,int y){	//�ѹ����ڣ�0,0��λ�� ,����������ƴ������
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
} 

int IsEnd;//�Ƿ���� 
int interface_x,interface_y;//�������������� 
int scores;//���� 
int column_x[column_num+1]; //����ȱ�ڵ���ʼֵ 
int column_x_long;//����ȱ�ڵĳ��� 
int column_y[column_num+1];//����λ��
int column_y_width;//���ӿ��
int slow_v,slow_v_num;//�ƶ�������ֵ(Խ���ٶ�Խ��)���ƶ������ı���
int slow_vbird,slow_vbird_num;//С���ƶ�������ֵ(Խ���ٶ�Խ��)���ƶ������ı���
int bird_x,bird_y;//С��λ�� 
int bird_jump; //С����Ծ���� =0ʱ���� =3��2��1ʱ��Ծ 


void startup(){	//�����ݳ�ʼ���� 
	int i; 
	HideCursor();//����ʾ��� 
	IsEnd = 0;
	interface_x = 22;
	interface_y = column_num*15;//����Ӧ��Ϊ������column_num�ı��� 
	scores=0;
	column_x_long=interface_x/4;//����ȱ�ڳ����ǽ��泤��1/4 
	for(i=1;i<=column_num;i++){//����ȱ����ʼλ�� 
		column_x[i]=rand()%(interface_x/2)+(interface_x/8);//λ���н���/2��ѡ��Χ,������1/8,���ᰤ�ű߽� 
	}
	column_y_width=(interface_y*3/2)/column_num/5;//���ӿ����3/2�����/������/5��//������3/2��Ϊ�˽��ˢ������ 
	column_y[1]=interface_y-1;
	for(i=2;i<=column_num;i++){
		column_y[i] = column_y[i-1]+(interface_y*3/2)/column_num;
	}
	slow_v=1;
	slow_v_num=1; 
	bird_x=interface_x/3;
	bird_y=interface_y/3;
	bird_jump=0; 
	slow_vbird=3;//С������ٱ��� 
	slow_vbird_num=1; 
}
void show_begin(){//����ʼҳ��չʾ�� 
	int i,j;
	int start=0;
	char input;
 	while(!start){
 		gotoxy(0,0);//ÿ�����ҳ������Ż�(0,0) 
 		for(i=1;i<=interface_x/2-4;i++) printf("\n"); 
		for(i=1;i<interface_y/2-8;i++) printf(" ");
		printf("��flappy bird��\n\n");
		for(i=1;i<interface_y/2-9;i++) printf(" ");
		printf("�밴�������ʼ��Ϸ\n\n");
		for(i=1;i<=interface_x/2-6;i++) printf("\n");
		if(kbhit()){
			input = getch();
			if(input) start=1;
		}
	}
} 
void show(){	//����ʾ���桿 
	gotoxy(0,0);//ÿ�����ҳ������Ż�(0,0) 
	int i,j;
	int k;
	int isprint;
	for(i=1;i<=interface_y/2-8;i++) printf(" ");
	printf("��flappy bird��") ;
	for(i=1;i<=interface_y/2-8-8;i++) printf(" ");
	printf("����:%3d\n",scores);
	for(i=1;i<=interface_x;i++){
		printf(" ");//ʹ��Ļ�ԳƼӵĿո� 
		for(j=1;j<=interface_y;j++){			
			isprint=0;
			if(j==1||j==interface_y){	//���ұ߿� 
				printf("|");
				isprint=1;
			}else if(i==interface_x){	//�±߿� 
				printf("=");
				isprint=1;
			}else if(i==1){		//�ϱ߿� 
				printf("V");
				isprint=1;
			}else if(i==bird_x&&j==bird_y){		//�ϱ߿� 
				printf("@");
				isprint=1;
			}
			if(!isprint){	//���� 
				for(k=1;k<=column_num;k++){
					if(i>=2&&i<column_x[k]||i>=column_x[k]+column_x_long&&i<=interface_x-1){
						if(j>=column_y[k]&&j<=column_y[k]+column_y_width-1){
							printf("H");
							isprint=1;
							break;
						}
					}
				}
			}
			if(!isprint) printf(" ");	//ʲôҲ���ǵ�λ������ո� 
		}
		printf("\n");
	}
	
}
void update_outinput(){	//���������޹صĸ��¡� 
	int i;
	slow_v_num=(slow_v_num==slow_v)? 1:slow_v_num+1;
	if(slow_v_num==slow_v){//ÿ��slow_v������һ�� 
		for(i=1;i<=column_num;i++){//��ÿ�����Ӳ��� 
			if(bird_x>=2&&bird_x<column_x[i]||bird_x>=column_x[i]+column_x_long&&bird_x<=interface_x-1){
				if(bird_y>=column_y[i]&&bird_y<=column_y[i]+column_y_width-1){
					IsEnd=1;//�������ӽ��� 
				}
			} 
			if(bird_x==1||bird_x==interface_x) IsEnd=1;//�����߽���� 
			if(column_y[i]+column_y_width-1==1){//����λ�õ�ѭ�� 
				column_y[i]=interface_y*3/2-column_y_width;//column_y[i]+column_y_width-1=interface_y*3/2-1
				column_x[i]=rand()%(interface_x/2)+(interface_x/8);
			}else{
				column_y[i]--;
			}
			if(bird_y==column_y[i]+column_y_width){//ͨ�����ӷ���+1 
				scores++;
				printf("\a");
			}			
		}		 
	} 
	slow_vbird_num=(slow_vbird_num==slow_vbird)? 1:slow_vbird_num+1;
	if(slow_vbird_num==slow_vbird){//ÿ��slow_vbird������һ�� 
		bird_x++;//С��Ĭ���½� 
		if(bird_jump>0){//������¿ո�ѭ��2��λ��-2 
			bird_x -= 2;
			bird_jump--;
		}
	}
}
void update_input(){//���������йصĸ��¡� 
	char input;
	if(kbhit()){
		input = getch();
		if(input==' '){
			if(bird_jump>0) bird_x--;//������¿ո�ǰҲ��⵽�пո���λ�ö���-1 
			bird_jump=2;//֮��Ҫ�����Ĵ��� 
		}		
	}
}
void show_end(){//����ʾʧ�ܽ��桿 
	system("cls"); 
	int i;
	for(i=1;i<interface_x/2-2;i++) putchar('\n');
	for(i=1;i<interface_y/2-5;i++) putchar(' ');
	printf("game over!\n\n");
	for(i=1;i<interface_y/2-7;i++) putchar(' ');
	printf("���ķ����ǣ�%3d��\n",scores);
	for(i=1;i<interface_x/2-3;i++) putchar('\n');	
	system("pause");//��ͣ 
	system("pause");//��ͣ
}

int main(){
	startup();	//���ݳ�ʼ��
	show_begin();//��ʼҳ�� 
	while(!IsEnd){	//��Ϸѭ��ִ�� 
		show();	// ��ʾ���� 
		update_outinput();	//�������޹صĸ��� 
		update_input();	//�������йصĸ��� 
	}
	show_end(); //��ʾʧ�ܽ��� 
	return 0;
}
 
