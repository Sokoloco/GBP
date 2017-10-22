//
// Created by luis on 02/10/17.
//

#include "Map.h"
#include </usr/include/allegro5/allegro_image.h>
#include <iostream>

#define ScreenWidth 800
#define ScreenHeight 600
#define BlockSize 40
int xCounter = 0,yCounter =0, mapSizeX, mapSizeY;



void LoadMap(const char* file, int** map){
    std::ifstream openfile(file);
    if(openfile.is_open()){
        openfile >> mapSizeX >> mapSizeY;
        while(!openfile.eof()){
            openfile >> map[xCounter][yCounter];
            xCounter++;
            if(xCounter >= mapSizeX){
                xCounter = 0;
                yCounter++;
            }
        }
    }
}

void DrawMap(int** map){//somthn weird
    for(int i =0;i< mapSizeX;i++){
        for(int j = 0; j<mapSizeY;j++){
            if(map[i][j] == 0)
                al_draw_rectangle(i * BlockSize, j*BlockSize,
                i*BlockSize+BlockSize,j*BlockSize+BlockSize,al_map_rgb(0,0,255),3.00);
        }
    }
}

Map::Map() {
     ALLEGRO_DISPLAY *display = NULL;

    if(!al_init()) {
        al_show_native_message_box(NULL,NULL,NULL,"failed to initialize allegro!",NULL,NULL);
        return;
    }
     if(!al_init_image_addon()){
         al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
                                    NULL, ALLEGRO_MESSAGEBOX_ERROR);
         return;
     }
     //al_set_new_display_flags(ALLEGRO_WINDOWED|ALLEGRO_RESIZABLE);
     display = al_create_display(800, 600);
     al_set_window_position(display,200,100);
     al_set_window_title(display,"Millenian Falcon");
     if(!display) {
         al_show_native_message_box(display,"Sample Tile","Display Settings","Display window couldn't be created"
                ,NULL,ALLEGRO_MESSAGEBOX_ERROR);
         return;
     }
     //al_show_native_message_box(display,"Message Title","Error","Couldnt be shown",NULL,ALLEGRO_MESSAGEBOX_ERROR);
     ALLEGRO_BITMAP *player = al_load_bitmap("/home/luis/CLionProjects/GBP/Images/MF1.jpg");

     if(!player){
         al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                    NULL, ALLEGRO_MESSAGEBOX_ERROR);
         al_destroy_display(display);
         return;
     }
    //al_draw_rotated_bitmap(player,100,100,300,300,4.7,ALLEGRO_FLIP_VERTICAL);
    //al_draw_scaled_bitmap(player,100,100,);
    al_draw_bitmap(player,100,100, ALLEGRO_FLIP_VERTICAL   );
    al_flip_display();
     al_rest(3.0);
     al_destroy_bitmap(player);

     al_destroy_display(display);
 }
