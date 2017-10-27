//
// Created by luis on 19/10/17.
//

#include "PathFinding.h"


int PathFinding::backTracking(int i, int j,int destinyX,int destinyY) {
    if(i == destinyX && j == destinyY){
        return 1;
    }
    if(*((map+j*sizeX)+i) == 1){
        *(path+j*sizeX+i) = 1;
        if(j+1 < sizeY && *(path+(j+1)*(sizeX+1)+i) != 1 && backTracking(i,j+1,destinyX,destinyY) == 1)return 1;
        if(i+1 < sizeX && *(path+(j)*(sizeX+1)+i+1) != 1 && backTracking(i+1,j,destinyX,destinyY) == 1)return 1;
        if(i-1 > 0     && *(path+(j)*(sizeX+1)+i-1) != 1 && backTracking(i-1,j,destinyX,destinyY) == 1)return 1;
        if(j-1 > 0     && *(path+(j-1)*(sizeX+1)+i) != 1 && backTracking(i,j-1,destinyX,destinyY) == 1)return 1;
    }
    return 0;
}


int* PathFinding::aStar(int destinyX,int destinyY,int i, int j,mapNode* current){
    if(closed.empty()) {
        mapNode newN = {i,j,NULL,0};
        closed.add(newN);
        return aStar(destinyX,destinyY,0,0,&newN);
    }else if (closed.has(*current)){
        open.remove(*current);
        closed.add(*current);
    }else{
        open.remove(*current);
        closed.add(*current);
    }
    if(abs(i-destinyX) <2 && abs(j-destinyY) < 2) {//sends a pointer of thenext step aka right after the first space aka first that whose past isnt NULL};
        int* movingPos = getNextMove();
        return(movingPos);
    }
    for(int m = -1;m<2;m++){
        for(int n = -1;n<2;n++){
            if(m == 0 && n == 0 );
            else if(j+m >= 0 && i+n >= 0){
                if(map[((j+m)*(sizeX+1) +(i+n))] == 1){ //que no este en el mapa y que no sea recorrible
                mapNode newN = {0};
                newN.y = j+m; newN.x = i+n;
                newN.parent = current;
                int H = abs(newN.x-destinyX) +abs(newN.y-destinyY);
                int G = (abs(m+n) == 1) ? 10 : 14;
                newN.cost = G+H;
                if(closed.has(newN));
                else if(open.has(newN)){
                    mapNode check = open.search(newN);
                    if(check > newN){
                        check.parent = current;
                        check.cost = newN.cost;
                    }
                }
                else
                    open.add(newN);}}
            }
        }

    mapNode next = getLowest();
    return aStar(destinyX,destinyY,next.x,next.y,&next);
}


PathFinding::mapNode PathFinding::getLowest() {
    mapNode lowest;
    open.sort();
    lowest = open.get(0)->getData();
    return lowest;
}

int* PathFinding::getNextMove() {
    mapNode ans = closed.get(closed.getSize()-1)->getData();
    mapNode* ansParent = ans.parent;
    while((ansParent) != NULL){
        ans = *ansParent;
        ansParent = ansParent->parent;
    }
    int ansArr[2] = {ans.x,ans.y};
    int* ansA = ansArr;
    return ansA;
}

PathFinding::PathFinding(int *map, int sizeX, int sizeY, int *path) {
    this->map = map;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->path = path;
}

PathFinding::PathFinding(int *map, int sizeX, int sizeY){
    this->map = map;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->path = NULL;
}