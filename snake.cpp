#include <iostream>
#include <fstream>
#include <curses.h>
#include <unistd.h>

using namespace std;
const int height=20;
const int length=20;
int sTailX[100],sTailY[100];

int size;
bool gameOver;
enum sDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
sDirection direction;


void setup()
{
    sTailX[0]=10;
sTailY[0]=10;
int size=1;
direction=STOP;
gameOver=false;


}


void draw()
{

    system("clear");
    bool d=false;
for(int i=0;i<=height;i++)
{
    for(int j=0;j<=length;j++)
    { d=false;
    
        if(i==0 || i==height || j==0 || j==length) {cout<<'#';d=true;}
        if(i==sTailX[0] && j==sTailY[0]) {cout<<'O';d=true;}
        for(int v=0;v<=size;v++)
        {
            if(i==sTailX[v] && j==sTailY[v]) {cout<<'o';d=true;}
        }
        if(!d) {cout<<" ";}
    }
    cout <<" "<<endl;
}

}


void input()
{
   int ch=getch();

    switch(ch)
    {
    case 97:     // a
    direction=LEFT;
    break;

    case 122:      // z
    direction=RIGHT;
    break;

    case 101:    // e 
    direction=UP;
    break;

    case 114:  // r   
    direction=DOWN;
    break;

    case 115:
    direction=STOP;
    gameOver=true;
    break;
    }
    
}

void logic()
{
    
switch(direction)
{   
    case UP:
    sTailY[0]--;
    break;
    case DOWN:
    sTailY[0]++;
    break;
    case LEFT:
    sTailX[0]--;
    break;
    case RIGHT:
    sTailX[0]++;
    break;
}
}


int main()
{
setup();
while(!gameOver)
{
        input();
        draw();
    usleep(10000);
}   
return 0;
}