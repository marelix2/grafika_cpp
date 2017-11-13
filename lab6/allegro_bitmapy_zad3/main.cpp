#include <allegro.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



class alphaChannel{

int _screenWidth;
int _screenHeight;
BITMAP *buffer;
BITMAP *buffForImg;
BITMAP *buffForImg2;

COLOR_MAP trans_table;

public:
int pos[2] = {50, 50};

alphaChannel(int screenWidth, int screenHeight){

    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

    create_trans_table(&trans_table, default_palette, 128, 128, 128, NULL);

    if (get_color_depth() == 8)
        color_map = &trans_table;
    else
        set_trans_blender(128, 128, 128, 128);

    buffer = create_bitmap(screenWidth, screenHeight);
    clear_to_color(buffer, makecol(222,222,222));

    buffForImg = load_bitmap("bitmapa.bmp", default_palette);
    buffForImg2 = load_bitmap("bitmapa.bmp", default_palette);
}


void refresh(){
    clear_to_color(buffer, makecol(0,0,255));

    draw_sprite(buffer, buffForImg, _screenWidth/2, _screenHeight/2);
    draw_trans_sprite(buffer, buffForImg2, pos[0], pos[1]);
    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
}

};
int main(){
    int screenWidth = 800;
    int screenHeight = 600;
    srand(time(NULL));
    allegro_init();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, screenWidth, screenHeight, 0, 0);
    install_keyboard();
    install_mouse();

   alphaChannel aa( screenWidth, screenHeight);

    while(1){
        aa.refresh();

        if(key[KEY_ESC])
            break;

        if(key[KEY_W])
           aa.pos[1]--;
        if(key[KEY_S])
           aa.pos[1]++;
        if(key[KEY_A])
            aa.pos[0]--;
        if(key[KEY_D])
           aa.pos[0]++;
    };

    return 0;
}
END_OF_MAIN();

