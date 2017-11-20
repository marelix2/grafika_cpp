#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <iostream>


class Ff{


float firstDimX[12][3];
float firstDimY[12][3];
float secDimX[12][2];
float secDimY[12][2];
float d = 150;


public:

Ff(){

startUp2D();
secDim();

}

void startUp2D(){
firstDimX[0][0] = 200;
firstDimX[0][1] = 400;
firstDimX[0][2] = 50;
firstDimY[0][0] = 200;
firstDimY[0][1] = 200;
firstDimY[0][2] = 200;

firstDimX[1][0] = 400;
firstDimX[1][1] = 400;
firstDimX[1][2] = 50;
firstDimY[1][0] = 200;
firstDimY[1][1] = 300;
firstDimY[1][2] = 200;

firstDimX[2][0] = 400;
firstDimX[2][1] = 250;
firstDimX[2][2] = 50;
firstDimY[2][0] = 300;
firstDimY[2][1] = 300;
firstDimY[2][2] = 200;

firstDimX[3][0] = 250;
firstDimX[3][1] = 250;
firstDimX[3][2] = 50;
firstDimY[3][0] = 300;
firstDimY[3][1] = 400;
firstDimY[3][2] = 200;

firstDimX[4][0] = 250;
firstDimX[4][1] = 350;
firstDimX[4][2] = 50;
firstDimY[4][0] = 400;
firstDimY[4][1] = 400;
firstDimY[4][2] = 200;

firstDimX[5][0] = 350;
firstDimX[5][1] = 350;
firstDimX[5][2] = 50;
firstDimY[5][0] = 400;
firstDimY[5][1] = 500;
firstDimY[5][2] = 200;

firstDimX[6][0] = 350;
firstDimX[6][1] = 250;
firstDimX[6][2] = 50;
firstDimY[6][0] = 500;
firstDimY[6][1] = 500;
firstDimY[6][2] = 200;

firstDimX[7][0] = 250;
firstDimX[7][1] = 250;
firstDimX[7][2] = 50;
firstDimY[7][0] = 500;
firstDimY[7][1] = 600;
firstDimY[7][2] = 200;

firstDimX[8][0] = 250;
firstDimX[8][1] = 400;
firstDimX[8][2] = 50;
firstDimY[8][0] = 600;
firstDimY[8][1] = 600;
firstDimY[8][2] = 200;

firstDimX[9][0] = 400;
firstDimX[9][1] = 400;
firstDimX[9][2] = 50;
firstDimY[9][0] = 600;
firstDimY[9][1] = 700;
firstDimY[9][2] = 200;

firstDimX[10][0] = 400;
firstDimX[10][1] = 200;
firstDimX[10][2] = 50;
firstDimY[10][0] = 700;
firstDimY[10][1] = 700;
firstDimY[10][2] = 200;

firstDimX[11][0] = 200;
firstDimX[11][1] = 200;
firstDimX[11][2] = 50;
firstDimY[11][0] = 700;
firstDimY[11][1] = 200;
firstDimY[11][2] = 200;

}

void secDim(int dd){
d += dd;
for(int i = 0; i < 12; i++){

    secDimX[i][0] = firstDimX[i][0] * (d / (firstDimX[i][2]+ d));
    secDimX[i][1] = firstDimX[i][1] * (d / (firstDimX[i][2]+ d));

    secDimY[i][0] = firstDimY[i][0] * (d / (firstDimY[i][2]+ d));
    secDimY[i][1] = firstDimY[i][1] * (d / (firstDimY[i][2]+ d));
}

}

void secDim(){

for(int i = 0; i < 12; i++){

    secDimX[i][0] = firstDimX[i][0] * (d / (firstDimX[i][2]+ d));
    secDimX[i][1] = firstDimX[i][1] * (d / (firstDimX[i][2]+ d));

    secDimY[i][0] = firstDimY[i][0] * (d / (firstDimY[i][2]+ d));
    secDimY[i][1] = firstDimY[i][1] * (d / (firstDimY[i][2]+ d));
}

}

void printIn2D(){

for (int i=0;i<12;i++) line(screen,firstDimX[i][0],firstDimY[i][0],firstDimX[i][1],firstDimY[i][1],makecol(255,0,0));


}

void printIn3D(){

for (int i=0;i<12;i++) {
        line(screen,firstDimX[i][0],firstDimY[i][0],firstDimX[i][1],firstDimY[i][1],makecol(255,0,0));
        line(screen,secDimX[i][0],secDimY[i][0],secDimX[i][1],secDimY[i][1],makecol(255,0,0));
        line(screen,firstDimX[i][1],firstDimY[i][1],secDimX[i][1],secDimY[i][1],makecol(255,0,0));
}


}



};



int main(int argc, char *argv[]){

   int SCREEN_WIDTH = 800;
   int SCREEN_HEIGHT = 800;
   allegro_init();
    install_keyboard();
    srand(time(NULL));
    set_color_depth(24);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0) != 0){
            allegro_message("BLAD\n");
    };

        Ff ff;

     while (!key[KEY_ESC]){
          if (key[KEY_R]) {
                clear_bitmap(screen);
                ff.printIn2D();
          }
          if (key[KEY_S]) {
                clear_bitmap(screen);
                ff.printIn3D();
          }
          if (key[KEY_PLUS_PAD]) {
                clear_bitmap(screen);
                ff.secDim(10);
                ff.printIn3D();

          }
          if (key[KEY_MINUS_PAD]) {
                clear_bitmap(screen);
                ff.secDim(-10);
                ff.printIn3D();

          }

     }



    allegro_exit();
    return 0;
}
END_OF_MAIN();

