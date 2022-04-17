#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define wideth 60
#define hight 20
#define Mlength 200
char Menu(void);
void HideCursor(void);
void Startup(void);
void Gotoxy(int x,int y);
void Show(void);
int Legal(char c);
void Change(void);
void UserInput(void);
int FoodPos(int foodx,int foody);
void GetFood(void);
void IfFailure(void);
void SetGameDifficulty(char n);
//全局变量
int snakex[Mlength],snakey[Mlength];       //蛇的坐标，同时规定蛇的最大长度
int foodx,foody;            //食物的坐标
int map[hight][wideth]={0};     //0:空格    1:蛇身  2:蛇头  3：食物 4：围墙
int snklength;      //蛇长
int tx=0;       //蛇头的当前x坐标位置
int ty=0;       //蛇头的当前y坐标位置
int score;      //分数
char c ;    //保存游戏中对于蛇的控制操作，而且所保存的是合法的走法
//主函数
int main()
{
    char n;
    system("color F4");
    Startup();
    n=Menu();
    while(1)
    {
        HideCursor();
        Show();
        UserInput();
        GetFood();
        IfFailure();
        SetGameDifficulty(n);
    }
    return 0;
}
//函数功能：显示菜单，提供各种选择设置
char Menu(void)
{
    char m; //选择菜单功能
    char n; //选择游戏难度
    while (1)
    {
        system("cls");
        printf("贪吃蛇游戏\n1.开始游戏\n2.游戏说明\n");
        m=getchar();
        if(m=='1')
        {
            do{
                system("cls");
                printf("请选择游戏难度\n1.菜鸟\n2.变态\n3.老手\n");
                n=getchar();
            }while (n!='1'&&n!='2'&&n!='3');
            return n;
        }
        else if(m=='2')
        {
            system("cls");
            getchar();
            printf("请使用w,s,a,d,或W,A,S,D来控制蛇的移动\n");
            printf("请按回车键返回开始的菜单!\n");
            getchar();
        }
    }
}
    //函数功能:隐藏光标，避免闪屏现象，提高游戏体验
    void HideCursor(void)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle,&CursorInfo);
    CursorInfo.bVisible=0;
    SetConsoleCursorInfo(handle,&CursorInfo);
}

    //函数功能:为各种数据赋初值，包括蛇和食物的初始位置，长度以及围墙等
    void Startup(void)
    {
        int i,j;
        snakex[0]=hight/2;
        snakey[0]=wideth/2;
        snakex[1]=hight/2+1;
        snakey[1]=wideth/2;
        snklength=2;
        foodx=hight/2;
        foody=wideth/3;
        map[snakex[0]][snakey[0]]=1;
        map[snakex[1]][snakey[1]]=2;
        map[foodx][foody]=3;
        for(i=0;i<hight;i++){
            for(j=0;j<wideth;j++){
                if(i==0||i==hight-1||j==0||j==wideth-1){
                    map[i][j]=4;
                }
            }
        }
    }   



    //函数功能:移动光标到指定坐标位置
    void Gotoxy(int x,int y)
    {
        HANDLE handle =GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos;
        pos.X=x;
        pos.Y=y;
        SetConsoleCursorPosition(handle,pos);
    }

    //函数功能:显示游戏界面——围墙，蛇，食物
    void Show(void)
    {
        int i,j;
        Gotoxy(0,0);
        for(i=0;i<hight;i++){
            for(j=0;j<wideth;j++){
                if(map[i][j]==0){
                    printf(" ");
                }
                else if(map[i][j]==1)
                {
                    printf("*");
                }
                else if(map[i][j]==2)
                {
                    printf("@");
                }
                else if(map[i][j]==3)
                {
                    printf("$");
                }
                else if(map[i][j]==4)       //显示围墙
                {
                    printf("0");
                }
            }
            printf("\n");
        }
        printf("      YOUR SCORE:%d",score); //显示游戏得分
    }

        //函数功能:初步保证蛇不能反向行走，没有反向行走时返回1否则返回0
        int Legal(char c)
        {
            if(c=='w'||c=='W')
            {
                if((snakex[snklength-1]-1)!=snakex[snklength-2])
                {
                    return 1;
                }
            }
            else if(c=='s'||c=='S')
            {
                if((snakex[snklength-1]+1)!=snakex[snklength-2])
                {
                    return 1;
                }
            }
            else if(c=='a'||c=='A')
            {
                if((snakey[snklength-1]-1)!=snakey[snklength-2])
                {
                    return 1;
                }
            }
            else if(c=='d'||c=='D')
            {
                if((snakey[snklength-1]+1)!=snakey[snklength-2])
                {
                    return 1;
                }
            }
            return 0;
        }


    //函数功能:蛇每走一步，更新蛇身和蛇头的位置坐标
    void Change(void)
    {
        int i;
        map[snakex[0]][snakey[0]]=0;
        for(i=0;i<snklength-1;i++)
        {
            snakex[i]=snakex[i+1];
            snakey[i]=snakey[i+1];
            map[snakex[i]][snakey[i]]=1;
        } 
        snakex[snklength-1]=tx;
        snakey[snklength-1]=ty;
        map[tx][ty]=2;
    }


    //函数功能:玩家控制蛇的移动，并更新蛇头的当前坐标位置
    void UserInput(void)
    {
        char temp;
        if(kbhit())
        {
            temp=getch();
            if(Legal(temp))
            {
                c=temp;
            }
        }
        //在没有用户按键操作情况下，蛇自己沿着当前方向移动
        if((c=='w'||c=='W')&&Legal(c))
        {
            tx=snakex[snklength-1]-1;
            ty=snakey[snklength-1];
        }
        else if((c=='s'||c=='S')&&Legal(c))
        {
            tx=snakex[snklength-1]+1;
            ty=snakey[snklength-1];
        }
        else if((c=='a'||c=='A')&&Legal(c))
        {
            ty=snakey[snklength-1]-1;
            tx=snakex[snklength-1];
        }
         else if((c=='d'||c=='D')&&Legal(c))
        {
            ty=snakey[snklength-1]+1;
            tx=snakex[snklength-1];
        }
    }

//函数功能:判断新的事物是否被刷到了蛇的身体里，是则返回0，否则返回1
int FoodPos(int foodx,int foody)
{
    int i;
    for(i=0;i<snklength-1;i++)
    {
        if(foodx==snakex[i]&&foody==snakey[i])
        {
            return 0;
        }
    }
    if(foodx==tx&&foody==ty)
    {
        return 0;
    }
    return 1;
}


    //函数功能:判断蛇是否吃到食物；刷新蛇和食物的位置
    void GetFood(void)
    {
        int flag;
        if(tx==foodx&&ty==foody)        //判断蛇吃到了食物
        {
            snklength++;            //蛇增长一节
            score++;
            snakex[snklength-1]=tx;     //在末尾添上新的蛇头，无需再整体移动数组
            snakey[snklength-1]=ty;      
            map[snakex[snklength-1]][snakey[snklength-1]]=2;    //新的蛇头
            map[snakex[snklength-2]][snakey[snklength-2]]=1;    //原蛇头变为蛇身
           do{
               srand((unsigned)time (NULL));
               foodx=rand()%(hight-4)+2;         //生成新的食物x坐标
               foody=rand()%(wideth-4)+2;        //生成新的事物y坐标
               flag=FoodPos(foodx,foody);        //判断新的食物是否被刷到了蛇的身体里
           }while (!flag);
          map[foodx][foody]=3;                  //新的事物
        }
        else                    //如果蛇没有吃到食物
        {
            if(tx!=0||ty!=0)
            {
                Change();       //更新蛇身和蛇头的位置
            }
        }
    }


    //函数功能:判断游戏是否失败，若失败结束游戏
    void IfFailure(void)
    {
        int i;
        if(snakex[snklength-1]==0||snakex[snklength-1]==hight-1||
           snakey[snklength-1]==0||snakey[snklength-1]==wideth-1)
        {
            printf("\n很遗憾,游戏失败！\n");
            exit(1);
        }
        for(i=0;i<snklength-1;i++)
        {
            if(snakex[snklength-1]==snakex[i]&&
               snakey[snklength-1]==snakey[i])
               {
                   printf("\n很遗憾，游戏失败！\n");
                   exit(1);
               }
        }
    }


    //函数功能:根据用户选择的难度设置延时
    void SetGameDifficulty(char n)
    {
        switch (n)
        {
        case '1':
            Sleep(400);
            break;
        case '2':
            Sleep(200);
            break;
        case '3':
            ;
        }
    }




















































    
