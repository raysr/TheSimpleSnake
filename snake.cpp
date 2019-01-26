#include<iostream>
#include<ncurses.h>
#include<string.h>
#include <string>
#include <random>
#include <unistd.h>
#include<string.h>
#include <stdlib.h>
#include<thread>
#include<time.h>
using namespace std;

const int height=20;
const int width=60;
const int length=20;

int sTailX[100],sTailY[100];

int size=1;
int gameOver=0;
string direction="RIGHT";
//int fruitX=(rand()%height)+1;
//int fruitY=(rand()%width)+1;
int fruitX=20;
int fruitY=10;


void drawing()
{

int i=0;
for(i=0;i<size;i++){
        
        mvaddch(sTailY[i],sTailX[i], 'O');
}
}

void setup()
{
    sTailX[0]=10;
    sTailY[0]=10;
    int size=1;
    direction="RIGHT";
    gameOver=false;
        initscr();
        clear();
  	    noecho();
  	    cbreak();
        keypad(stdscr, TRUE);
  	    curs_set(0);
         int i=1;
         int j=1;

        for(i=1;i<height+1;i++)
        {
            for(j=1;j<width+1;j++)
            {
            if(i==1 || i==height || j==1 || j==width){mvaddch(i,j,'O');}
            }
        }
        drawing();
}
void maj()
{
    int i=1;
    for(i=1;i<size;i++)
    {
        sTailX[i]=sTailX[i-1];
        sTailY[i]=sTailY[i-1];
    }
}

void draw()
{

        clear();
         int i=1;
         int j=1;

        for(i=1;i<height+1;i++)
        {
            for(j=1;j<width+1;j++)
            {
            if(i==1 || i==height || j==1 || j==width){mvaddch(i,j,'O');}
            }
        }
    if(direction.compare("UP")==0){maj();sTailY[0]--;}
    else if(direction.compare("DOWN")==0){maj();sTailY[0]++;}
    else if(direction.compare("LEFT")==0){maj();sTailX[0]--;}
    else if(direction.compare("RIGHT")==0){maj();sTailX[0]++;}
    mvaddch(fruitY, fruitX, 'P');
    drawing();
    if(sTailY[0]==fruitY && sTailX[0]==fruitX)
    {
        sTailX[size]=sTailX[size-1]+1;
        sTailY[size]=sTailY[size-1];
        size=size+1;
        fruitX=(rand()%width)+2;
        fruitY=(rand()%height)+2;
    }
    refresh();
}




string input()
{
while(true){
    int ch=getch();
	if(ch == KEY_LEFT && direction.compare("RIGHT")!=0) 
    {
 	    direction="LEFT";
 	}
 	else if(ch == KEY_RIGHT && direction.compare("LEFT")!=0) 
    {
 		direction="RIGHT";
 	}
 	else if(ch == KEY_UP && direction.compare("DOWN")!=0) 
     {
 		direction="UP";
 	}
 	else if(ch == KEY_DOWN && direction.compare("UP")!=0) 
     {
        direction="DOWN";
 	}
}
}

int verify()
{
    if(sTailX[0]>=width || sTailY[0]>=height || sTailY[0]<=0 || sTailY[0]<=0)
    {
        return 1;
    }
    else
    {
        int i=1;
        for(i=1;i<size;i++)
        {
            if(sTailX[0]==sTailX[i] && sTailY[i]==sTailY[0])
            {
                return 1;
            }
        }
        return 0;
    }
}


int main()
{
    srand(time(NULL));
    string incoming;
setup();
std::thread first(input);
while(gameOver==0)
{
        draw();
        gameOver=verify();
        usleep(100000);
}   
return 0;
}