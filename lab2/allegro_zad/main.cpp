#include <iostream>
#include <allegro.h>
#include <cmath>
#include <cstdlib>

using namespace std;


class Drawer{

int screenX;
int screenY;
public:
    Drawer(int sx, int sy){
    screenX = sx;
    screenY = sy;

    }

    int getX(){return screenX;}
    int getY(){return screenY;}

void drawALine(int x0, int y0, int x1, int y1){


if (x1<x0){
    int tmp=x0;
    x0=x1;
    x1=tmp;
    tmp=y0;
    y0=y1;
    y1=tmp;
   }
float dx = x1 - x0;
float dy = y1 - y0;

if(abs(dy/dx) < 1){

    float m = dy/dx;
    float y=y0;
    for(int x=x0; x<=x1; x++){
        putpixel(screen, x,  int(y+0.5), makecol(255,0,0));
        y+=m;
    }

}else
{

    if (y1<y0){
    int tmp=x0;
    x0=x1;
    x1=tmp;
    tmp=y0;
    y0=y1;
    y1=tmp;
   }
     float m=dx/dy;
     float x=x0;
    for(int y=y0; y<=y1; y++){
        putpixel(screen, int(x+0.5),  y, makecol(255,0,0));
        x+=m;
    }

}

}
};

void pktC(Drawer &dd){

for (int i=0;i<16;i++){
        dd.drawALine(dd.getX(),i*dd.getY()/16,0,0);
        dd.drawALine(0,i*dd.getY()/16,dd.getX(),dd.getY());
        dd.drawALine(i*dd.getX()/16,0,dd.getX(),dd.getY());
        dd.drawALine(i*dd.getX()/16,dd.getY(),0,0);
    }

}

void pktA(Drawer &dd){

for (int i=0;i<=8;i++){
        dd.drawALine(0,(4-i)*dd.getY()/8,dd.getX()/2,dd.getY()/2);
        dd.drawALine(dd.getX()/2,dd.getY()/2,dd.getX(),(4-i)*dd.getY()/8);
        dd.drawALine(i*dd.getX()/8,dd.getY(),dd.getX()/2,dd.getX()/2);

    }

}

void pktB(Drawer &dd){

for (int i=0;i<=8;i++){
        dd.drawALine(dd.getX()/2,0,(8-i)*dd.getX()/8,dd.getY());
        dd.drawALine(0,0,dd.getX()/2,(8-i)*dd.getY()/16);
        dd.drawALine(dd.getX()/2,(8-i)*dd.getY()/16,dd.getX(),0);


    }

}


int main()
{
    int screenX = 640;
    int screenY = 640;
    allegro_init();
    install_keyboard();
    install_mouse();
    set_gfx_mode(GFX_AUTODETECT,screenX,screenY,0,0);

    Drawer dd(screenX,screenY);

    //pktC(dd);
    //pktA(dd);
    pktB(dd);




    readkey();


    return 0;
}
END_OF_MAIN();
