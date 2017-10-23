#include <iostream>
#include <iostream>
#include <allegro.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int screenX = 640;
    int screenY = 640;
    allegro_init();
    install_keyboard();
    install_mouse();
    set_gfx_mode(GFX_AUTODETECT,screenX,screenY,0,0);

    int posX = 140;
    int posY = 300;

    int maxSize = 100;

    for(int i= 0 ; i < maxSize; i++){

        for(int j = 0 ; j< maxSize; j++) putpixel(screen, posX + i,  posY + j, makecol(255,0,0));





    }




    readkey();


    return 0;
}
END_OF_MAIN();
