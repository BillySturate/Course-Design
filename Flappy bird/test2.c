#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define column_num 5 //同一界面存在柱子的数目 


void HideCursor(){	//隐藏光标位置 ,这个函数复制代码就行 
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void gotoxy(int x,int y){	//把光标放在（0,0）位置 ,这个函数复制代码就行
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
} 

int IsEnd;//是否结束 
int interface_x,interface_y;//界面行数、列数 
int scores;//分数 
int column_x[column_num+1]; //柱子缺口的起始值 
int column_x_long;//柱子缺口的长度 
int column_y[column_num+1];//柱子位置
int column_y_width;//柱子宽度
int slow_v,slow_v_num;//移动变慢的值(越大速度越慢)，移动变慢的变量
int slow_vbird,slow_vbird_num;//小鸟移动变慢的值(越大速度越慢)，移动变慢的变量
int bird_x,bird_y;//小鸟位置 
int bird_jump; //小鸟跳跃变量 =0时不跳 =3、2、1时跳跃 


void startup(){	//【数据初始化】 
	int i; 
	HideCursor();//不显示光标 
	IsEnd = 0;
	interface_x = 22;
	interface_y = column_num*15;//此数应该为柱子数column_num的倍数 
	scores=0;
	column_x_long=interface_x/4;//柱子缺口长度是界面长、1/4 
	for(i=1;i<=column_num;i++){//柱子缺口起始位置 
		column_x[i]=rand()%(interface_x/2)+(interface_x/8);//位置有界面/2的选择范围,且下移1/8,不会挨着边界 
	}
	column_y_width=(interface_y*3/2)/column_num/5;//柱子宽度是3/2界面宽/柱子数/5；//界面变宽3/2是为了解决刷新问题 
	column_y[1]=interface_y-1;
	for(i=2;i<=column_num;i++){
		column_y[i] = column_y[i-1]+(interface_y*3/2)/column_num;
	}
	slow_v=1;
	slow_v_num=1; 
	bird_x=interface_x/3;
	bird_y=interface_y/3;
	bird_jump=0; 
	slow_vbird=3;//小鸟的慢速变量 
	slow_vbird_num=1; 
}
void show_begin(){//【初始页面展示】 
	int i,j;
	int start=0;
	char input;
 	while(!start){
 		gotoxy(0,0);//每次输出页面把鼠标放回(0,0) 
 		for(i=1;i<=interface_x/2-4;i++) printf("\n"); 
		for(i=1;i<interface_y/2-8;i++) printf(" ");
		printf("《flappy bird》\n\n");
		for(i=1;i<interface_y/2-9;i++) printf(" ");
		printf("请按任意键开始游戏\n\n");
		for(i=1;i<=interface_x/2-6;i++) printf("\n");
		if(kbhit()){
			input = getch();
			if(input) start=1;
		}
	}
} 
void show(){	//【显示画面】 
	gotoxy(0,0);//每次输出页面把鼠标放回(0,0) 
	int i,j;
	int k;
	int isprint;
	for(i=1;i<=interface_y/2-8;i++) printf(" ");
	printf("《flappy bird》") ;
	for(i=1;i<=interface_y/2-8-8;i++) printf(" ");
	printf("分数:%3d\n",scores);
	for(i=1;i<=interface_x;i++){
		printf(" ");//使屏幕对称加的空格 
		for(j=1;j<=interface_y;j++){			
			isprint=0;
			if(j==1||j==interface_y){	//左右边框 
				printf("|");
				isprint=1;
			}else if(i==interface_x){	//下边框 
				printf("=");
				isprint=1;
			}else if(i==1){		//上边框 
				printf("V");
				isprint=1;
			}else if(i==bird_x&&j==bird_y){		//上边框 
				printf("@");
				isprint=1;
			}
			if(!isprint){	//柱子 
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
			if(!isprint) printf(" ");	//什么也不是的位置输出空格 
		}
		printf("\n");
	}
	
}
void update_outinput(){	//【与输入无关的更新】 
	int i;
	slow_v_num=(slow_v_num==slow_v)? 1:slow_v_num+1;
	if(slow_v_num==slow_v){//每隔slow_v次运行一次 
		for(i=1;i<=column_num;i++){//对每个柱子操作 
			if(bird_x>=2&&bird_x<column_x[i]||bird_x>=column_x[i]+column_x_long&&bird_x<=interface_x-1){
				if(bird_y>=column_y[i]&&bird_y<=column_y[i]+column_y_width-1){
					IsEnd=1;//碰到柱子结束 
				}
			} 
			if(bird_x==1||bird_x==interface_x) IsEnd=1;//碰到边界结束 
			if(column_y[i]+column_y_width-1==1){//柱子位置的循环 
				column_y[i]=interface_y*3/2-column_y_width;//column_y[i]+column_y_width-1=interface_y*3/2-1
				column_x[i]=rand()%(interface_x/2)+(interface_x/8);
			}else{
				column_y[i]--;
			}
			if(bird_y==column_y[i]+column_y_width){//通过柱子分数+1 
				scores++;
				printf("\a");
			}			
		}		 
	} 
	slow_vbird_num=(slow_vbird_num==slow_vbird)? 1:slow_vbird_num+1;
	if(slow_vbird_num==slow_vbird){//每隔slow_vbird次运行一次 
		bird_x++;//小鸟默认下降 
		if(bird_jump>0){//如果按下空格，循环2次位置-2 
			bird_x -= 2;
			bird_jump--;
		}
	}
}
void update_input(){//【与输入有关的更新】 
	char input;
	if(kbhit()){
		input = getch();
		if(input==' '){
			if(bird_jump>0) bird_x--;//如果按下空格前也检测到有空格则位置额外-1 
			bird_jump=2;//之后要上升的次数 
		}		
	}
}
void show_end(){//【显示失败界面】 
	system("cls"); 
	int i;
	for(i=1;i<interface_x/2-2;i++) putchar('\n');
	for(i=1;i<interface_y/2-5;i++) putchar(' ');
	printf("game over!\n\n");
	for(i=1;i<interface_y/2-7;i++) putchar(' ');
	printf("您的分数是：%3d分\n",scores);
	for(i=1;i<interface_x/2-3;i++) putchar('\n');	
	system("pause");//暂停 
	system("pause");//暂停
}

int main(){
	startup();	//数据初始化
	show_begin();//初始页面 
	while(!IsEnd){	//游戏循环执行 
		show();	// 显示画面 
		update_outinput();	//与输入无关的更新 
		update_input();	//与输入有关的更新 
	}
	show_end(); //显示失败界面 
	return 0;
}
 
