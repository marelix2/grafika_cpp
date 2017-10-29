#include <allegro.h>
#include <time.h>
#include <winalleg.h>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <stack>


#define M_PI 3.14159265358979323846264338327


int screenWidth = 800;
int screenHeight = 640;


class Circle{

int    x;
int    y;
int    r;

BITMAP * _bitmap;

public :
Circle(int x, int y, int r){

this->x = x;
this->y = y;
this->r = r;

}


Circle(){

this->x = randomX();
this->y = randomY();
this->r = randomR();

}
int randomX(){

return  rand()%screenWidth;

}

int randomY(){

return  rand()%screenHeight;

}

int randomR(){

return 20 +rand()%50;

}

int getX() {
            return x;
        }

        int getY() {
            return y;
        }


void initDraw(){


drawCircle(makecol(255,255,255));

}

void drawCircle(int color){
    int x1, y1;
    double i;

   for( i = 0; i <= M_PI/4.0; i += 1.0 / (2 * r)){
        x1 = r * cos(i);
        y1 = r * sin(i);
        putpixel(screen, x + x1, y + y1, color);
        putpixel(screen, x + y1, y + x1, color);
        putpixel(screen, x - y1, y + x1, color);
        putpixel(screen, x - x1, y + y1, color);
        putpixel(screen, x - x1, y - y1, color);
        putpixel(screen, x - y1, y - x1, color);
        putpixel(screen, x + y1, y - x1, color);
        putpixel(screen, x + x1, y - y1, color);
    }

};

void drawCircle(int color, int R){
    int x1, y1;
    double i;

   for( i = 0; i <= 3.14/4.0; i += 1.0 / (2 * r)){
        x1 = R * cos(i);
        y1 = R * sin(i);
        putpixel(screen, x + x1, y + y1, color);
        putpixel(screen, x + y1, y + x1, color);
        putpixel(screen, x - y1, y + x1, color);
        putpixel(screen, x - x1, y + y1, color);
        putpixel(screen, x - x1, y - y1, color);
        putpixel(screen, x - y1, y - x1, color);
        putpixel(screen, x + y1, y - x1, color);
        putpixel(screen, x + x1, y - y1, color);
    }

};

int randomColor(){

return makecol(rand()%256,rand()%256,rand()%256);

}

void fillBackground(){

    int filingColor = randomColor();

    for(int i = 0; i< r ; i++){

        drawCircle(filingColor, i);




    }




}




};


int main(){
    allegro_init();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, screenWidth, screenHeight, 0, 0);
    install_keyboard();
    install_mouse();
    install_timer();

    Circle *cc;


    while(1){
            cc = new Circle;
            cc->initDraw();
            cc->fillBackground();


    }
    return 0;
}
END_OF_MAIN();

