//
// Created by melany on 02/10/17.
//

#include "Map.h"
#include <allegro5/allegro_image.h>
#include "../Pathfinding/PathFinding.h"
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <stdlib.h>


#define ScreenWidth 800
#define ScreenHeight 600
#define BlockSize 40






/**
 * Genera los asterioides en forma aleatoria en el mapa
 * @param map
 * @param sizeX
 * @param sizeY
 */
void genASt(int *map, int sizeX, int sizeY){
    srand(time(NULL));
    for (int j=0; j<sizeY; j++){
        for (int i=0; i<sizeX; i++){
            if((rand()%100) > 95 && map[j*(sizeX+1)+i] == 0){
                map[j*(sizeX+1)+i] = 3;
            } else if((rand()%100) > 97 && map[j*(sizeX+1)+i] == 0){
                map[j*(sizeX+1)+i] = 2;
            } else if((rand()%100) > 98 && map[j*(sizeX+1)+i] == 0){
                map[j*(sizeX+1)+i] = 5;
            }
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
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return;
    }
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(1400, 800);
    al_set_window_position(display,200,100);
    al_set_window_title(display,"Millenian Falcon");


    if(!display) {
        al_show_native_message_box(display,"Sample Tile","Display Settings","Display window couldn't be created"
                ,NULL,ALLEGRO_MESSAGEBOX_ERROR);

        return;
    }


    ALLEGRO_BITMAP *fondo = al_load_bitmap("../Images/EspacioFondo.png");
    ALLEGRO_BITMAP *fondomovil = al_load_bitmap("../Images/Estrellas.png");
    ALLEGRO_BITMAP *player = al_load_bitmap("../Images/MilleniumFalcom.png");
    ALLEGRO_BITMAP *asteroideG = al_load_bitmap("../Images/AsteriodeG.png");
    ALLEGRO_BITMAP *asteroideP = al_load_bitmap("../Images/AsteriodeP.png");
    ALLEGRO_BITMAP *meta = al_load_bitmap("../Images/Astillero.png");
    ALLEGRO_BITMAP *enemigo = al_load_bitmap("../Images/TieFighter.png");

    if(!fondo){
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return;
    }

    if(!fondomovil){
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return;
    }


    if(!player){
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return;
    }

    if(!asteroideG){
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return;
    }

    if(!asteroideP){
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return;
    }

    if(!enemigo){
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return;
    }

    int map[8][14]={0};

    //Sacar el random de la posición inicial del jugador y el destino
    srand(time(NULL));
    int Jx =0, Jy =(rand()%8);
    int Mx =13, My =(rand()%8);

    map[Jy][Jx] = 1;
    map[My][Mx] = 4;


    genASt(*map, 14, 8);


    al_draw_bitmap(fondo,0,0, ALLEGRO_FLIP_VERTICAL);
    al_draw_bitmap(fondomovil,0,0, ALLEGRO_FLIP_VERTICAL);
    al_draw_bitmap(fondomovil,-1400,0, ALLEGRO_FLIP_VERTICAL);


    for (int j=0; j<8; j++){
        for (int i=0; i<14; i++){
            if (map[j][i]==1)
                al_draw_bitmap(player, i*100, j*100+25, ALLEGRO_FLIP_HORIZONTAL);
            else if (map[j][i]==2)
                al_draw_bitmap(asteroideG, i*100+15, j*100+10, ALLEGRO_FLIP_HORIZONTAL);
            else if (map[j][i]==3)
                al_draw_bitmap(asteroideP, i*100+30, j*100+30, ALLEGRO_FLIP_HORIZONTAL);
            else if (map[j][i]==4)
                al_draw_bitmap(meta, i*100, j*100, ALLEGRO_FLIP_HORIZONTAL);
            else if (map[j][i]==5)
                al_draw_bitmap(enemigo, i*100+30, j*100+30, ALLEGRO_FLIP_HORIZONTAL);
        }
    }
    //al_draw_bitmap(player, Jx, Jy, ALLEGRO_FLIP_HORIZONTAL);
    //al_draw_bitmap(final, Mx, My, ALLEGRO_FLIP_HORIZONTAL);
    al_flip_display();

    al_init_primitives_addon();
    al_install_keyboard();
    ALLEGRO_EVENT_QUEUE *event_queue= al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    bool done = false;
    int moveSpeed = 5;

    //int state = NULL;
    Jx=Jx*100;
    Jy=Jy*100;

    PathFinding *ruta = new PathFinding(*map, 14, 8);
    int a=0;
    while (!done){
        a+=2;
        int *next= ruta->aStar(Mx, My, Jx/100, Jy/100, NULL);
        int nextX = *next*100;
        int nextY = next[1]*100;
        while (Jx!=nextX || Jy!=nextY) {
            a+=1;

            if (nextX > Jx) {
                Jx += moveSpeed;
            } else if (nextX < Jx) {
                Jx -= moveSpeed;
            }

            if (nextY > Jy) {
                Jy += moveSpeed;
            } else if (nextY < Jy) {
                Jy -= moveSpeed;
            }

            al_draw_bitmap(fondo,0,0, ALLEGRO_FLIP_VERTICAL);
            al_draw_bitmap(fondomovil,0+a,0, ALLEGRO_FLIP_VERTICAL);
            al_draw_bitmap(fondomovil,-1400+a ,0, ALLEGRO_FLIP_VERTICAL);
            al_draw_bitmap(player, Jx, Jy, ALLEGRO_FLIP_HORIZONTAL);
            for (int j=0; j<8; j++){
                for (int i=0; i<14; i++){
                    if (map[j][i]==1);
                    else if (map[j][i]==2)
                        al_draw_bitmap(asteroideG, i*100+15, j*100+10, ALLEGRO_FLIP_HORIZONTAL);
                    else if (map[j][i]==3)
                        al_draw_bitmap(asteroideP, i*100+30, j*100+30, ALLEGRO_FLIP_HORIZONTAL);
                    else if (map[j][i]==4)
                        al_draw_bitmap(meta, i*100, j*100, ALLEGRO_FLIP_HORIZONTAL);
                    else if (map[j][i]==5)
                        al_draw_bitmap(enemigo, i*100+30, j*100+30, ALLEGRO_FLIP_HORIZONTAL);

                }
            }

            //al_draw_bitmap(player, Jx*100, Jy*100, ALLEGRO_FLIP_HORIZONTAL);
            al_flip_display();


        }
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        sleep(0.1);
        if(events.type = ALLEGRO_EVENT_KEY_DOWN){
            switch (events.keyboard.keycode){
                //case ALLEGRO_KEY_DOWN:
                    //Jy +=moveSpeed;
                    //break;
                //case ALLEGRO_KEY_UP:
                    //Jy -=moveSpeed;
                    //break;
                //case ALLEGRO_KEY_RIGHT:
                    //Jx +=moveSpeed;
                    break;
                //case ALLEGRO_KEY_LEFT:
                    //Jx -=moveSpeed;
                    //break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;

            }

        }


        al_draw_bitmap(fondo,0,0, ALLEGRO_FLIP_VERTICAL);
        al_draw_bitmap(fondomovil,0+a,0, ALLEGRO_FLIP_VERTICAL);
        al_draw_bitmap(fondomovil,-1400+a ,0, ALLEGRO_FLIP_VERTICAL);
        for (int j=0; j<8; j++){
            for (int i=0; i<14; i++){
                if (map[j][i]==1)
                    al_draw_bitmap(player, Jx, Jy, ALLEGRO_FLIP_HORIZONTAL);
                else if (map[j][i]==2)
                    al_draw_bitmap(asteroideG, i*100+15, j*100+10, ALLEGRO_FLIP_HORIZONTAL);
                else if (map[j][i]==3)
                    al_draw_bitmap(asteroideP, i*100+30, j*100+30, ALLEGRO_FLIP_HORIZONTAL);
                else if (map[j][i]==4)
                    al_draw_bitmap(meta, i*100, j*100, ALLEGRO_FLIP_HORIZONTAL);
                else if (map[j][i]==5)
                    al_draw_bitmap(enemigo, i*100+30, j*100+30, ALLEGRO_FLIP_HORIZONTAL);

            }
        }

        //al_draw_bitmap(player, Jx*100, Jy*100, ALLEGRO_FLIP_HORIZONTAL);
        al_flip_display();

    }

    al_destroy_display(display);
    return;







}


