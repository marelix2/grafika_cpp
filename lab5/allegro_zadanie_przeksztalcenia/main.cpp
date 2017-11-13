#include <iostream>
#include <allegro.h>
#include <math.h>
#include <time.h>

using namespace std;

class Home{

    float houseGridX[12][2];
    float houseGridY[12][2];

    float avgX;
    float avgY;


public:

    Home(){

        houseGridX[0][0] = 200;
        houseGridX[0][1] = 200;
        houseGridX[1][0] = 200;
        houseGridX[1][1] = 300;
        houseGridX[2][0] = 300;
        houseGridX[2][1] = 300;
        houseGridX[3][0] = 250;
        houseGridX[3][1] = 300;
        houseGridX[4][0] = 200;
        houseGridX[4][1] = 250;
        houseGridX[5][0] = 233;
        houseGridX[5][1] = 233;
        houseGridX[6][0] = 266;
        houseGridX[6][1] = 266;
        houseGridX[7][0] = 233;
        houseGridX[7][1] = 266;
        houseGridX[8][0] = 266;
        houseGridX[8][1] = 280;
        houseGridX[9][0] = 266;
        houseGridX[9][1] = 266;
        houseGridX[10][0] = 280;
        houseGridX[10][1] = 280;
        houseGridX[11][0] = 266;
        houseGridX[11][1] = 280;

        houseGridY[0][0] = 200;
        houseGridY[0][1] = 300;
        houseGridY[1][0] = 300;
        houseGridY[1][1] = 300;
        houseGridY[2][0] = 200;
        houseGridY[2][1] = 300;
        houseGridY[3][0] = 150;
        houseGridY[3][1] = 200;
        houseGridY[4][0] = 200;
        houseGridY[4][1] = 150;
        houseGridY[5][0] = 250;
        houseGridY[5][1] = 300;
        houseGridY[6][0] = 250;
        houseGridY[6][1] = 300;
        houseGridY[7][0] = 250;
        houseGridY[7][1] = 250;
        houseGridY[8][0] = 200;
        houseGridY[8][1] = 200;
        houseGridY[9][0] = 150;
        houseGridY[9][1] = 200;
        houseGridY[10][0] = 150;
        houseGridY[10][1] = 200;
        houseGridY[11][0] = 150;
        houseGridY[11][1] = 150;




    }

    void printHouse(){

    for(int i= 0; i< 12 ; i++) line(screen, houseGridX[i][0],houseGridY[i][0],houseGridX[i][1],houseGridY[i][1],makecol(255,0,0));

    }

    void findCenter(){
    float minX = houseGridX[0][0];
    float maxX = houseGridX[0][0];
    float minY = houseGridY[0][0];
    float maxY = houseGridY[0][0];


    for(int i =1; i < 12 ; i++){
        if(houseGridX[i][0] < minX) minX = houseGridX[i][0];
        if(houseGridX[i][0] > maxX) maxX = houseGridX[i][0];
        if(houseGridX[i][1] < minX) minX = houseGridX[i][1];
        if(houseGridX[i][1] > maxX) maxX = houseGridX[i][1];
        if(houseGridY[i][0] < minY) minY = houseGridY[i][0];
        if(houseGridY[i][0] > maxY) maxY = houseGridY[i][0];
        if(houseGridY[i][1] < minY) minY = houseGridY[i][1];
        if(houseGridY[i][1] > maxY) maxY = houseGridY[i][1];
    }

    avgX = (minX+maxX)/2.0;
    avgY = (minY+maxY)/2.0;

    }

    void zoomOut(){

    findCenter();

        for(int i= 0; i< 12 ; i++){

            houseGridX[i][0] = houseGridX[i][0] *0.95+ avgX*0.05 ;
            houseGridY[i][0] = houseGridY[i][0] *0.95+ avgY*0.05;
            houseGridX[i][1] = houseGridX[i][1]*0.95 + avgX*0.05;
            houseGridY[i][1] = houseGridY[i][1] *0.95+ avgY*0.05;

        }



    }

    void zoomIn(){
    findCenter();
         for(int i= 0; i< 12 ; i++){
          houseGridX[i][0] = houseGridX[i][0] *1.05+ avgX*(-0.05) ;
            houseGridY[i][0] = houseGridY[i][0] *1.05+ avgY*(-0.05);
            houseGridX[i][1] = houseGridX[i][1]*1.05 + avgX*(-0.05);
            houseGridY[i][1] = houseGridY[i][1] *1.05+ avgY*(-0.05);

        }



    }

    void moveLeft(){

    for(int i= 0; i< 12 ; i++){

            houseGridX[i][0] = houseGridX[i][0] +10;
            houseGridX[i][1] = houseGridX[i][1] +10;

        }

}

    void moveRight(){

 for(int i= 0; i< 12 ; i++){

            houseGridX[i][0] = houseGridX[i][0] -10;
            houseGridX[i][1] = houseGridX[i][1] -10;

        }

}

    void rotateLeft(){

    findCenter();

        for(int i= 0; i< 12 ; i++){

            houseGridX[i][0] = avgX + (houseGridX[i][0]- avgX)* cos( -0.05)- (houseGridY[i][0] -avgY)*sin(-0.05) ;
            houseGridY[i][0] = avgY + (houseGridX[i][0]- avgX)* sin(-0.05)+ (houseGridY[i][0] -avgY)*cos(-0.05) ;
            houseGridX[i][1] = avgX + (houseGridX[i][1]- avgX)* cos(-0.05)- (houseGridY[i][1] -avgY)*sin(-0.05) ;
            houseGridY[i][1] = avgY + (houseGridX[i][1]- avgX)* sin(-0.05)+ (houseGridY[i][1] -avgY)*cos(-0.05) ;

        }


    }


    void rotateRight(){

    findCenter();

        for(int i= 0; i< 12 ; i++){

            houseGridX[i][0] = avgX + (houseGridX[i][0]- avgX)* cos(0.05)- (houseGridY[i][0] -avgY)*sin(0.05) ;
            houseGridY[i][0] = avgY + (houseGridX[i][0]- avgX)* sin(0.05)+ (houseGridY[i][0] -avgY)*cos(0.05) ;
            houseGridX[i][1] = avgX + (houseGridX[i][1]- avgX)* cos(0.05)- (houseGridY[i][1] -avgY)*sin(0.05) ;
            houseGridY[i][1] = avgY + (houseGridX[i][1]- avgX)* sin(0.05)+ (houseGridY[i][1] -avgY)*cos(0.05) ;

        }


    }


};

int main()
{

    allegro_init();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 600, 0, 0);
    install_keyboard();
    srand(time(NULL));

cout<<"dla s powieksz "<<endl;
cout<<"dla S pomniejsz"<<endl;
cout<<"dla t przesun w Lewo"<<endl;
cout<<"dla T przesun w Prawo"<<endl;
cout<<"dla o obroc w Lewo"<<endl;
cout<<"dla O obroc w Prawo"<<endl;


char c;


        Home hh;
while(!key[KEY_ESC]){
        clear_bitmap(screen);
        hh.printHouse();
    c = readkey();
    cout<<c<<endl;
    if(c == 's')hh.zoomIn();
    if(c == 'S')hh.zoomOut();
    if(c == 'T')hh.moveRight();
    if(c == 't')hh.moveLeft();
    if(c == 'o')hh.rotateRight();
    if(c == 'O')hh.rotateLeft();




}
exit(1);

     return 0;
 }

END_OF_MAIN()
