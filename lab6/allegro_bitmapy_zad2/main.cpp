#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>





class bitmapOperation{

BITMAP *bitmap;
BITMAP *tmpBitmap;
PALETTE palette;
float avgX,avgY;
float maxX,maxY;
float bitmapWidth,bitmapHeight;
float bitmapCenterX,bitmapCenterY;
int angle;


public:

bitmapOperation(){

    startUp();


}

void startUp(){
bitmap = load_bitmap("bitmapa.bmp",palette);

    //std::cout<<"chuj"<<std::endl;

    maxX=SCREEN_W;
    maxY=SCREEN_H;

    tmpBitmap=create_bitmap_ex(24,maxX,maxY);

    avgX=maxX/2;
    avgY=maxY/2;

    bitmapWidth=(bitmap->w);
    bitmapHeight=(bitmap->h);
    bitmapCenterX=bitmapWidth/2;
    bitmapCenterY=bitmapHeight/2;

    angle=0;

    blit(bitmap,tmpBitmap,0,0,avgX-bitmapCenterX,avgY-bitmapCenterY,maxX,maxY);
    blit(tmpBitmap,screen,0,0,0,0,maxX,maxY);
}

void drawBitmap(){

blit(tmpBitmap,screen,0,0,0,0,maxX,maxY);

}

void rotateBitmap(){
// KLAWISZ R
     clear_bitmap(tmpBitmap);
    key_shifts & KB_SHIFT_FLAG ? angle+=5 : angle-=5;

     rotate_sprite(tmpBitmap,bitmap,avgX-bitmapCenterX,avgY-bitmapCenterY,itofix(angle));
     drawBitmap();
}


void scaleBitmap(){
    // KLAWISZ S
     clear_bitmap(tmpBitmap);
     if(key_shifts & KB_SHIFT_FLAG){
         bitmapWidth *= 1.01;
         bitmapHeight *= 1.01;
         }else {
        bitmapWidth *= 0.99;
        bitmapHeight *= 0.99;
      }

        stretch_sprite(tmpBitmap,bitmap,avgX-bitmapWidth/2,avgY-bitmapHeight/2,bitmapWidth,bitmapHeight);
        drawBitmap();

}

void rotateByPoint(){
// KLAWISZ P
    clear_bitmap(tmpBitmap);
    key_shifts & KB_SHIFT_FLAG ? angle+=5 : angle-=5;

    pivot_sprite(tmpBitmap,bitmap,avgX-bitmapCenterX,avgY-bitmapCenterY,0,0,itofix(angle));
    drawBitmap();

}

void verdicalRef(){
// KLAWISZ V
 clear_bitmap(tmpBitmap);

              if(!(key_shifts & KB_SHIFT_FLAG ))draw_sprite_v_flip(tmpBitmap,bitmap,avgX-bitmapCenterX,avgY-bitmapCenterY);
              else startUp();
             drawBitmap();
}

void horizontalRef(){

//  KLAWISZ H
 clear_bitmap(tmpBitmap);


              if(!(key_shifts & KB_SHIFT_FLAG )) draw_sprite_h_flip(tmpBitmap,bitmap,avgX-bitmapCenterX,avgY-bitmapCenterY);
              else startUp();
              drawBitmap();


}

void vhRef(){
    //KLAWISZ O
clear_bitmap(tmpBitmap);
        if(!(key_shifts & KB_SHIFT_FLAG )) draw_sprite_vh_flip(tmpBitmap,bitmap,avgX-bitmapCenterX,avgY-bitmapCenterY);
              else startUp();
              drawBitmap();

}

void rotateAndScale(){
    // klawisz T
        clear_bitmap(tmpBitmap);

             key_shifts & KB_SHIFT_FLAG ? angle+=5 : angle-=5;
             rotate_scaled_sprite(tmpBitmap,bitmap,0,0,itofix(angle),itofix(2));
             drawBitmap();
}

void roatateByPointAndScale(){
//Klawisz K
      clear_bitmap(tmpBitmap);
     if(key_shifts & KB_SHIFT_FLAG){
         bitmapWidth *= 1.01;
         bitmapHeight *= 1.01;
         angle+=5;
         }else {
        bitmapWidth *= 0.99;
        bitmapHeight *= 0.99;
         angle-=5;
      }
             pivot_scaled_sprite(tmpBitmap,bitmap,avgX-bitmapWidth/2,avgY-bitmapHeight/2,0,0,itofix(angle),itofix(2));
        drawBitmap();
}


};

int main(int argc, char *argv[]){

    allegro_init();
    install_keyboard();
    srand(time(NULL));
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_color_depth(24);
    bitmapOperation bb;

    while (!key[KEY_ESC]){
          if (key[KEY_R]) {
            bb.rotateBitmap();
          }
          if (key[KEY_S]) {
           bb.scaleBitmap();
          }
          if (key[KEY_P]) {
           bb.rotateByPoint();
          }
          if (key[KEY_V]) {
           bb.verdicalRef();
          }
          if (key[KEY_H]) {
           bb.horizontalRef();
          }
          if (key[KEY_O]) {
           bb.vhRef();
          }
          if (key[KEY_T]) {
                bb.rotateAndScale();
          }
          if (key[KEY_K]) {
          bb.roatateByPointAndScale();
          }

    }


    allegro_exit();
    return 0;
}
END_OF_MAIN();

