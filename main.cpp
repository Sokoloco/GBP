#include <stdio.h>
#include <allegro5/allegro.h>//must be here no matter what
#include <iostream>
#include "GUI/Map.h"
//#include "Pathfinding/PathFinding.h"

#include "Structures/LinkedList.cpp"

struct mapNode{
    int x;
    int y;
    mapNode* prev;
    int cost;
    bool operator ==(mapNode a){
        return( a.x == x
                && a.y == y);
    }
    bool operator>(mapNode a){
        return (cost > a.cost);
    }
};

int main(int argc, char **argv){

    return 0;
}
void sortingTest(){
//Map* ok = new Map();
LinkedList<mapNode>* ok = new LinkedList<mapNode>;
mapNode one ={1,1,NULL,5};
mapNode two ={1,2,NULL,24};
mapNode three={1,3,NULL,78};
mapNode four = {1,4,NULL,3};
mapNode five = {1,5,NULL,1};
mapNode six = {1,6,NULL,9};
mapNode mapArr[6] = {one,two,three,four,five,six};
for(int i = 0;i<6;i++){
//mapArr[i].cost = i;
ok->add(mapArr[i]);
}
ok->remove(mapArr[4]);
ok->sort();
ok->remove(three);
ok->run();}

