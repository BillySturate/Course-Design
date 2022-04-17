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
//ȫ�ֱ���
int snakex[Mlength],snakey[Mlength];       //�ߵ����꣬ͬʱ�涨�ߵ���󳤶�
int foodx,foody;            //ʳ�������
int map[hight][wideth]={0};     //0:�ո�    1:����  2:��ͷ  3��ʳ�� 4��Χǽ
int snklength;      //�߳�
int tx=0;       //��ͷ�ĵ�ǰx����λ��
int ty=0;       //��ͷ�ĵ�ǰy����λ��
int score;      //����
char c ;    //������Ϸ�ж����ߵĿ��Ʋ�����������������ǺϷ����߷�
//������
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
//�������ܣ���ʾ�˵����ṩ����ѡ������
char Menu(void)
{
    char m; //ѡ��˵�����
    char n; //ѡ����Ϸ�Ѷ�
    while (1)
    {
        system("cls");
        printf("̰������Ϸ\n1.��ʼ��Ϸ\n2.��Ϸ˵��\n");
        m=getchar();
        if(m=='1')
        {
            do{
                system("cls");
                printf("��ѡ����Ϸ�Ѷ�\n1.����\n2.��̬\n3.����\n");
                n=getchar();
            }while (n!='1'&&n!='2'&&n!='3');
            return n;
        }
        else if(m=='2')
        {
            system("cls");
            getchar();
            printf("��ʹ��w,s,a,d,��W,A,S,D�������ߵ��ƶ�\n");
            printf("�밴�س������ؿ�ʼ�Ĳ˵�!\n");
            getchar();
        }
    }
}
    //��������:���ع�꣬�����������������Ϸ����
    void HideCursor(void)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle,&CursorInfo);
    CursorInfo.bVisible=0;
    SetConsoleCursorInfo(handle,&CursorInfo);
}

    //��������:Ϊ�������ݸ���ֵ�������ߺ�ʳ��ĳ�ʼλ�ã������Լ�Χǽ��
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



    //��������:�ƶ���굽ָ������λ��
    void Gotoxy(int x,int y)
    {
        HANDLE handle =GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos;
        pos.X=x;
        pos.Y=y;
        SetConsoleCursorPosition(handle,pos);
    }

    //��������:��ʾ��Ϸ���桪��Χǽ���ߣ�ʳ��
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
                else if(map[i][j]==4)       //��ʾΧǽ
                {
                    printf("0");
                }
            }
            printf("\n");
        }
        printf("      YOUR SCORE:%d",score); //��ʾ��Ϸ�÷�
    }

        //��������:������֤�߲��ܷ������ߣ�û�з�������ʱ����1���򷵻�0
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


    //��������:��ÿ��һ���������������ͷ��λ������
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


    //��������:��ҿ����ߵ��ƶ�����������ͷ�ĵ�ǰ����λ��
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
        //��û���û�������������£����Լ����ŵ�ǰ�����ƶ�
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

//��������:�ж��µ������Ƿ�ˢ�����ߵ���������򷵻�0�����򷵻�1
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


    //��������:�ж����Ƿ�Ե�ʳ�ˢ���ߺ�ʳ���λ��
    void GetFood(void)
    {
        int flag;
        if(tx==foodx&&ty==foody)        //�ж��߳Ե���ʳ��
        {
            snklength++;            //������һ��
            score++;
            snakex[snklength-1]=tx;     //��ĩβ�����µ���ͷ�������������ƶ�����
            snakey[snklength-1]=ty;      
            map[snakex[snklength-1]][snakey[snklength-1]]=2;    //�µ���ͷ
            map[snakex[snklength-2]][snakey[snklength-2]]=1;    //ԭ��ͷ��Ϊ����
           do{
               srand((unsigned)time (NULL));
               foodx=rand()%(hight-4)+2;         //�����µ�ʳ��x����
               foody=rand()%(wideth-4)+2;        //�����µ�����y����
               flag=FoodPos(foodx,foody);        //�ж��µ�ʳ���Ƿ�ˢ�����ߵ�������
           }while (!flag);
          map[foodx][foody]=3;                  //�µ�����
        }
        else                    //�����û�гԵ�ʳ��
        {
            if(tx!=0||ty!=0)
            {
                Change();       //�����������ͷ��λ��
            }
        }
    }


    //��������:�ж���Ϸ�Ƿ�ʧ�ܣ���ʧ�ܽ�����Ϸ
    void IfFailure(void)
    {
        int i;
        if(snakex[snklength-1]==0||snakex[snklength-1]==hight-1||
           snakey[snklength-1]==0||snakey[snklength-1]==wideth-1)
        {
            printf("\n���ź�,��Ϸʧ�ܣ�\n");
            exit(1);
        }
        for(i=0;i<snklength-1;i++)
        {
            if(snakex[snklength-1]==snakex[i]&&
               snakey[snklength-1]==snakey[i])
               {
                   printf("\n���ź�����Ϸʧ�ܣ�\n");
                   exit(1);
               }
        }
    }


    //��������:�����û�ѡ����Ѷ�������ʱ
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




















































    
