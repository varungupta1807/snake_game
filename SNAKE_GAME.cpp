#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int width=80,height=20;
int x,y,fruitx,fruity,score=0;
bool gameover;
enum eDirection{STOP=0, UP, DOWN, LEFT, RIGHT};
eDirection dir;
int tailx[100], taily[100], ntail;


void setup()
{
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitx=rand()%width;
    fruity=rand()%height;
}


void draw()
{
    system("CLS");
    for (int i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            if(j==0 || j==width-1)
            {
                cout<<"#";
            }
            else if(i==y && j==x)
            {
                //cout<<"o";
                for (int i=0;i<=score;i+=10)
                {
                    cout<<"o";
                }
            }
            else if(i == fruity && j==fruitx)
            {
                cout<<"F";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for (int i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl<<"Score is: "<< score<<endl;

}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'w':
            dir=UP;
            break;
        case 'a':
            dir=LEFT;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'd':
            dir=RIGHT;
            break;
        default:
            break;
        }
    }
}

void logic()
{
    switch(dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }
    if(x<0 || x>width || y<0 || y>height)
    {
        gameover=true;
    }
    if(x == fruitx && y==fruity)
    {
        fruitx=rand()%width;
        fruity=rand()%height;
        score+=10;
    }
}

int main()
{
    int f=1;
    while(f==1)
    {
        setup();
        while(!gameover)
        {
            draw();
            input();
            logic();
            Sleep(100);
        }
        score=0;
        cout<<"\n press 1 to play again else press 0"<<endl;
        cin>>f;
    }
    return 0;
}
