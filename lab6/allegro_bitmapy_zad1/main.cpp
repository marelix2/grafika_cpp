#include <allegro.h>
#include <time.h>
#include <winalleg.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class movingBox{

int _screenWidth;
int _screenHeight;

BITMAP *buffer;
BITMAP *secbuffer;

int positionToAnimate[2]; //0 - x  1 - y
int vectorr[2] = {1, 1};

int blackColor = makecol(0,0,0);
int redColor = makecol(255,0,0);

public:
movingBox( int screenWidth, int screenHeight){

_screenWidth = screenWidth;
_screenHeight = screenHeight;

positionToAnimate[0] = _screenWidth / 2;
positionToAnimate[1] = _screenHeight / 2;

buffer = create_bitmap(_screenWidth, _screenHeight);
clear_to_color(buffer,blackColor);

secbuffer = create_bitmap(30,30);


};

void animate(){
    clear_to_color(buffer, blackColor);

    rectfill(secbuffer,0 ,0 , secbuffer->w, secbuffer->h, redColor);

    positionToAnimate[0] += vectorr[0];
    positionToAnimate[1] += vectorr[1];

    if(positionToAnimate[0] + secbuffer->w > _screenWidth || positionToAnimate[0] < 0)
        vectorr[0] *= -1;
    if(positionToAnimate[1] + secbuffer->h > _screenHeight || positionToAnimate[1] < 0)
        vectorr[1] *= -1;

    blit(secbuffer, buffer, 0, 0, positionToAnimate[0], positionToAnimate[1], secbuffer->w, secbuffer->h);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
}

};


int main(){

    int screenWidth= 800;
    int screenHeight= 600;
    srand(time(NULL));
    allegro_init();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, screenWidth, screenHeight, 0, 0);
    install_keyboard();
    install_mouse();
    install_timer();

    show_mouse(screen);
    movingBox mm(screenWidth,screenHeight);

    while(true){
        mm.animate();
    };


    return 0;
}
END_OF_MAIN();

