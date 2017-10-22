//
// Created by luis on 19/10/17.
//

#include <cstdlib>
#include "PathFinding.h"


int PathFinding::backTracking(int i, int j) {
    if(i == sizeX-1 && j == sizeY-1){
        return 1;
    }
    if(*((map+i*sizeY)+j) == 1){
        *(path+i*sizeY+j) = 1;
        if(backTracking(i,j+1) == 1)return 1;
        if(backTracking(i+1,j) == 1)return 1;
        *(path+i*sizeY+j) = 0;
    }
    return 0;
}


int* PathFinding::aStar(int destinyX,int destinyY,int i, int j,mapNode current){
    if(closed.empty()) {
        current ={i,j,NULL,0};
        closed.add(current);
    }else{
        open.remove(current);
        closed.add(current);
    }
    if(abs(i-destinyX + j-destinyY) == 1) {//sends a pointer of thenext step aka right after the first space aka first that whose past isnt NULL};
        int* movingPos = getNextMove();
        return(movingPos);
    }
    for(int m = -1;m<2;m++){
        for(int n = -1;n<2;n++){
            if(m == n == 0 );
            else if((i+m < 0 || j+n < 0) && *(map+(i+m)*sizeY+(j+n)) == 0); //que no este en el mapa y que no sea recorrible
            else{
                mapNode newN = {0};
                newN.x = i+m; newN.y = j+n;
                newN.parent = current;
                int H = abs(newN.x-destinyX) +abs(newN.y-destinyY);
                int G = (abs(m+n) == 1) ? 10 : 14;
                newN.cost = G+H;
                mapNode* check;
                if(closed.search(newN)!=NULL);
                if((check = open.search(newN)) != NULL)
                    if(*check > newN){
                        check->parent = current;
                        check->cost = newN.cost;
                    }
                open.add(newN);
        }}
    }
    mapNode next = getLowest();
    aStar(destinyX,destinyY,next.x,next.y,next);
}



PathFinding::PathFinding(int *map, int sizeX, int sizeY, int *path, int destinyY, int destinyX) {
    this->map = map;
    this->path = path;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

PathFinding::mapNode PathFinding::getLowest() {
    mapNode* lowest;
    open.sort();
    lowest = open.get(0);
    return *lowest;
}

int* PathFinding::getNextMove() {
    mapNode* ans = closed.get(closed.getSize());
    mapNode* ansParent = &(ans->parent);
    while((ansParent) != NULL){
        ans = ansParent;
        ansParent = &(ansParent->parent);
    }
    int ansArr[2] = {ans->x,ans->y};
    return ansArr;
}
